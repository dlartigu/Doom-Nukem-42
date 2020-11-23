/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crouch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:03:20 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:44:26 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static uint32_t		ft_crouch_up(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->crouchsensi >= 1)
		floor->crouchsensi = floor->crouchsensi - 0.05;
	else if (floor->crouchsensi <= 1)
	{
		floor->crouchsensi = 1;
		if (floor->timercrouchup)
			SDL_RemoveTimer(floor->timercrouchup);
		floor->timercrouchup = 0;
		floor->crouch = 0;
	}
	return (interval);
}

static uint32_t		ft_crouchdown(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->crouchsensi <= 1.5)
		floor->crouchsensi = floor->crouchsensi + 0.05;
	else if (floor->crouchsensi >= 1.5)
	{
		floor->crouchsensi = 1.5;
		if (floor->timercrouchdown)
			SDL_RemoveTimer(floor->timercrouchdown);
		floor->timercrouchdown = 0;
		floor->crouch = 1;
	}
	return (interval);
}

void				ft_crouch(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_LCTRL
		&& env->events.type == SDL_KEYDOWN
		&& floor->fly == 0 && floor->crouch == 0 && floor->ragdoll == 0
		&& !floor->timercrouchdown)
	{
		if (!(floor->timercrouchdown = SDL_AddTimer(20
			* floor->gravity, ft_crouchdown, floor)))
			ft_sdl_error(NULL);
	}
	if (env->events.key.keysym.sym == SDLK_LCTRL
		&& env->events.type == SDL_KEYDOWN
		&& floor->crouch == 1 && floor->ragdoll == 0
		&& !floor->timercrouchup)
	{
		if (!(floor->timercrouchup = SDL_AddTimer(40
			* floor->gravity, ft_crouch_up, floor)))
			ft_sdl_error(NULL);
	}
}
