/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:18:02 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 18:19:26 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		settings_menu_set(t_env *env)
{
	if (env->settings_choice == 0
	&& !(env->texte = SDL_LoadBMP(SET_VIDEO)))
		ft_sdl_error(NULL);
	else if (env->settings_choice == 1
	&& !(env->texte = SDL_LoadBMP(SET_AUDIO)))
		ft_sdl_error(NULL);
	else if (env->settings_choice == 2
	&& !(env->texte = SDL_LoadBMP(SET_GAMEPLAY)))
		ft_sdl_error(NULL);
	else if (env->settings_choice == 3
	&& !(env->texte = SDL_LoadBMP(SET_BACK)))
		ft_sdl_error(NULL);
}

void				draw_menu_settings(t_env *env)
{
	settings_menu_set(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren,
		env->texte)))
		ft_sdl_error("draw_settings_menu");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
}
