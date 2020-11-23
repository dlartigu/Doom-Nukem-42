/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:08:41 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 18:25:48 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	load_menu_start(t_env *env)
{
	if (env->startmenu_choice == 0 && !(env->texte = SDL_LoadBMP(PLAY)))
		ft_sdl_error(NULL);
	else if (env->startmenu_choice == 1
	&& !(env->texte = SDL_LoadBMP(MAPEDIT)))
		ft_sdl_error(NULL);
	else if (env->startmenu_choice == 2
	&& !(env->texte = SDL_LoadBMP(SET_HOME)))
		ft_sdl_error(NULL);
	else if (env->startmenu_choice == 3 && !(env->texte = SDL_LoadBMP(EXIT)))
		ft_sdl_error(NULL);
}

void			draw_menu_start(t_env *env)
{
	load_menu_start(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren,
		env->texte)))
		ft_sdl_error("start_menu 2/n");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
}
