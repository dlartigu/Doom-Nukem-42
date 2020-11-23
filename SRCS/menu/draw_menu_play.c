/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:45:03 by niboute           #+#    #+#             */
/*   Updated: 2020/09/05 10:18:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	load_menu_play(t_env *env)
{
	if (env->play_choice == 0 && !(env->texte = SDL_LoadBMP(PLAY_STORY)))
		ft_sdl_error(NULL);
	else if (env->play_choice == 1 && !(env->texte = SDL_LoadBMP(PLAY_ARCADE)))
		ft_sdl_error(NULL);
	else if (env->play_choice == 2 && !(env->texte = SDL_LoadBMP(PLAY_RETURN)))
		ft_sdl_error(NULL);
}

void			draw_menu_play(t_env *env)
{
	load_menu_play(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren,
		env->texte)))
		ft_sdl_error("play_menu 2/n");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
}
