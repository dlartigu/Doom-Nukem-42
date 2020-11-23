/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_story.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:06:17 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 18:18:55 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	load_menu_story(t_env *env)
{
	if (env->story_difficulty == 0
	&& !(env->texte = SDL_LoadBMP(STORY_NORMAL)))
		ft_sdl_error(NULL);
	else if (env->story_difficulty == 1
	&& !(env->texte = SDL_LoadBMP(STORY_HARD)))
		ft_sdl_error(NULL);
	else if (env->story_difficulty == 2
	&& !(env->texte = SDL_LoadBMP(STORY_HELL)))
		ft_sdl_error(NULL);
	else if (env->story_difficulty == 3
	&& !(env->texte = SDL_LoadBMP(STORY_RETURN)))
		ft_sdl_error(NULL);
}

void			draw_menu_story(t_env *env)
{
	load_menu_story(env);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex = SDL_CreateTextureFromSurface(env->ren,
	env->texte)))
		ft_sdl_error("story_menu 2/n");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
}
