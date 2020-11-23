/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_audio.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:26:11 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/08 01:17:01 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void			draw_menu_music(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 3.7);
	set_ttf_rect_wh(env, sdl->res_width / 10, sdl->res_hight / 12);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->music_op == 0 ? "OFF" : "ON", env->red)))
		ft_ttf_error(NULL);
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error(NULL);
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

static void			draw_menu_effect(t_sdl *sdl, t_env *env)
{
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 2.8);
	set_ttf_rect_wh(env, sdl->res_width / 10, sdl->res_hight / 12);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->effect_op == 0 ? "OFF" : "ON", env->red)))
		ft_ttf_error("draw_effect_1");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("draw_effect_2");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

static void			draw_menu_volume(t_sdl *sdl, t_env *env)
{
	if (env->char_volume_value)
		ft_strdel(&env->char_volume_value);
	if (!(env->char_volume_value = ft_itoa(env->int_volume_value)))
		ft_fct_error("itoa");
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 4.5);
	set_ttf_rect_wh(env, sdl->res_width / 22, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->char_volume_value, env->red)))
		ft_ttf_error(NULL);
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error(NULL);
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

static	void		audio_menu_setup(t_env *env)
{
	if (env->audio_choice == 0 && !(env->texte = SDL_LoadBMP(TEXT_VOL)))
		ft_sdl_error(NULL);
	else if (env->audio_choice == 1 && !(env->texte = SDL_LoadBMP(TEXT_MUS)))
		ft_sdl_error(NULL);
	else if (env->audio_choice == 2 && !(env->texte = SDL_LoadBMP(TEXT_EFFECT)))
		ft_sdl_error(NULL);
	else if (env->audio_choice == 3 && !(env->texte = SDL_LoadBMP(TEXT_APL)))
		ft_sdl_error(NULL);
	else if (env->audio_choice == 4 && !(env->texte = SDL_LoadBMP(TEXT_RET)))
		ft_sdl_error(NULL);
}

void				draw_menu_audio(t_sdl *sdl, t_env *env)
{
	load_font(env);
	audio_menu_setup(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren,
		env->texte)))
		ft_sdl_error("audio_menu 2");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
	draw_menu_volume(sdl, env);
	draw_menu_effect(sdl, env);
	draw_menu_music(sdl, env);
}
