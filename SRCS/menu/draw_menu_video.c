/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_video.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:16:44 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/08 00:55:22 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void			draw_aliasing_text(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 2);
	set_ttf_rect_wh(env, sdl->res_width / 17, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->aliasing_op == 0 ? "OFF" : "ON", env->red)))
		ft_ttf_error("choose_aliasing 2/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n7/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

static void			draw_texture_res_text(t_sdl *sdl, t_env *env)
{
	const char		*str;

	if (env->text_q_op == 0)
		str = "NORMAL";
	else if (env->text_q_op == 1)
		str = "HIGH";
	else if (env->text_q_op == 2)
		str = "ULTRA";
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 1.7);
	set_ttf_rect_wh(env, sdl->res_width / 10, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		str, env->red)))
		ft_ttf_error("choose_texture 1/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n9/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void				draw_error_option(t_sdl *sdl, t_env *env)
{
	if (env->error_vid == 1)
	{
		set_ttf_rect_xy(env, sdl->res_width / 3, sdl->res_hight / 3);
		set_ttf_rect_wh(env, sdl->res_width / 15, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
			"error test", env->red)))
			ft_ttf_error("error_option 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n15/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
		env->error_vid = 0;
	}
}

static void			load_menu_video(t_env *env)
{
	load_font(env);
	if (env->video_choice == 0 && !(env->texte = SDL_LoadBMP(VID_RES)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 1 && !(env->texte = SDL_LoadBMP(VID_VSYNC)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 2 && !(env->texte = SDL_LoadBMP(VID_FS)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 3 && !(env->texte = SDL_LoadBMP(VID_GPU)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 4 && !(env->texte = SDL_LoadBMP(VID_ALIAS)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 5 && !(env->texte = SDL_LoadBMP(VID_TEXTURE)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 6 && !(env->texte = SDL_LoadBMP(VID_APPLY)))
		ft_sdl_error(NULL);
	else if (env->video_choice == 7 && !(env->texte = SDL_LoadBMP(VID_RET)))
		ft_sdl_error(NULL);
}

void				draw_menu_video(t_sdl *sdl, t_env *env)
{
	load_menu_video(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
		ft_sdl_error("video_menu 2");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
	draw_res_text(sdl, env);
	draw_texture_res_text(sdl, env);
	draw_vsync_text(sdl, env);
	draw_fullscreen_text(sdl, env);
	draw_gpu_text(sdl, env);
	draw_aliasing_text(sdl, env);
	draw_error_option(sdl, env);
}
