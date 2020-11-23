/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:46:11 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 01:29:17 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		ft_ragdoll_life_setup(t_elem *floor)
{
	if (floor->crouch == 1)
		floor->speed = 0.01 / floor->gravity - floor->speedragdoll;
	else if (floor->fly == 1)
		floor->speed = 0.04 / floor->gravity - floor->speedragdoll;
	else if (floor->crouch == 0 || floor->fly == 0)
		floor->speed = 0.02 / floor->gravity - floor->speedragdoll;
	else if (floor->swim == 1)
		floor->speed = 0.015 / floor->gravity - floor->speedragdoll;
	else
		floor->speed = 0.02 / floor->gravity - floor->speedragdoll;
}

void				ft_dispminimap(t_env *env, t_elem *floor)
{
	if ((env->events.key.keysym.sym == SDLK_m)
		&& (env->events.type == SDL_KEYUP))
		floor->m = 0;
	if ((env->events.key.keysym.sym == SDLK_m)
		&& (env->events.type == SDL_KEYDOWN))
		floor->m = 1;
}

void				ft_inputs(t_env *env, t_elem *floor)
{
	ft_ragdoll_life_setup(floor);
	floor->keystat = SDL_GetKeyboardState(NULL);
	floor->framespeed = (double)(floor->time - floor->oldtime) / 5.5f;
	if (floor->autorunmove == 0 && !floor->noclip)
		ft_moves_wasd(floor);
	else if (floor->noclip)
		ft_moves_wasd_noclip(floor);
	ft_warp(env, floor);
	ft_items_hud(floor);
	ft_sprite_torch(floor);
	ft_medkit(floor);
	ft_weapons(floor);
	ft_ammos(floor);
	ft_ragdoll(floor);
	ft_dive(floor);
	ft_walk(floor);
	ft_stoprain(env, floor);
}
