/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_gameplay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:55:39 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/08 00:55:20 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			draw_sensitivity(t_sdl *sdl, t_env *env)
{
	if (env->sensitivity_value)
		ft_strdel(&env->sensitivity_value);
	if (!(env->sensitivity_value = ft_itoa(env->sens_value)))
		ft_fct_error("itoa");
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 3.5);
	set_ttf_rect_wh(env, sdl->res_width / 22, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->sensitivity_value, env->red)))
		ft_ttf_error("choose_sensitivity 1/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("choose_sensitivity 2/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			draw_difficulty(t_sdl *sdl, t_env *env)
{
	const char	*str;

	if (env->dif_op == 0)
		str = "EASY";
	else if (env->dif_op == 1)
		str = "NORMAL";
	else if (env->dif_op == 2)
		str = "HIGH";
	set_ttf_rect_xy(env, sdl->res_width / 1.7, sdl->res_hight / 4.7);
	set_ttf_rect_wh(env, sdl->res_width / 8, sdl->res_hight / 12);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2, str, env->red)))
		ft_ttf_error("draw_difficulty 1/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("draw_difficulty 2/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

static	void	load_menu_gameplay(t_env *env)
{
	if (env->game_choice == 0 && !(env->texte = SDL_LoadBMP(GAME_DIF)))
		ft_sdl_error(NULL);
	else if (env->game_choice == 1 && !(env->texte = SDL_LoadBMP(GAME_SENS)))
		ft_sdl_error(NULL);
	else if (env->game_choice == 2 && !(env->texte = SDL_LoadBMP(GAME_CONTROL)))
		ft_sdl_error(NULL);
	else if (env->game_choice == 3 && !(env->texte = SDL_LoadBMP(GAME_APPLY)))
		ft_sdl_error(NULL);
	else if (env->game_choice == 4 && !(env->texte = SDL_LoadBMP(GAME_RETURN)))
		ft_sdl_error(NULL);
}

void			draw_menu_gameplay(t_sdl *sdl, t_env *env)
{
	load_font(env);
	load_menu_gameplay(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren,
	env->texte)))
		ft_sdl_error("gameplay_menu 2/n");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
	draw_difficulty(sdl, env);
	draw_sensitivity(sdl, env);
}
