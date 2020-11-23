/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_video_settings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:18:10 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 16:01:15 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			draw_fullscreen_text(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 2.8);
	set_ttf_rect_wh(env, sdl->res_width / 17, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->fs_op == 0 ? "OFF" : "ON", env->red)))
		ft_ttf_error("choose_fs/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n3/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			draw_gpu_text(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 2.3);
	set_ttf_rect_wh(env, sdl->res_width / 17, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->gpu_op == 0 ? "OFF" : "ON", env->red)))
		ft_ttf_error("draw_gpu 2/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n5/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			draw_res_text(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 2, sdl->res_hight / 5.4);
	set_ttf_rect_wh(env, sdl->res_width / 6.8, sdl->res_hight / 9);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
	env->res_op == 0 ? "800 x 450" : "THE HIGHEST", env->red)))
		ft_ttf_error("draw_res 2/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n12/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			draw_vsync_text(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 3.5);
	set_ttf_rect_wh(env, sdl->res_width / 17, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->vsync_op == 0 ? "OFF" : "ON", env->red)))
		ft_ttf_error("draw_vsync 2/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n14/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}
