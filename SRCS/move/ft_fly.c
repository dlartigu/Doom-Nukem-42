/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:03:26 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/16 22:41:20 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			ft_flydown(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->flysensi >= 1)
		floor->flysensi = floor->flysensi - 0.05;
	else if (floor->flysensi <= 1)
	{
		floor->flysensi = 1;
		if (floor->timerflydown)
			SDL_RemoveTimer(floor->timerflydown);
		floor->fly = 0;
	}
	return (interval);
}

uint32_t			ft_flyup(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->flysensi <= 4)
		floor->flysensi = floor->flysensi + 0.05;
	else if (floor->flysensi >= 4)
	{
		floor->flysensi = 4;
		if (floor->timerflyup)
			SDL_RemoveTimer(floor->timerflyup);
		floor->fly = 1;
	}
	return (interval);
}

void				ft_fly(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_f
		&& env->events.type == SDL_KEYDOWN
		&& floor->fly == 0 && floor->crouch == 0 && floor->ragdoll == 0)
	{
		floor->game_msg = 0;
		if (!(floor->timerflyup = SDL_AddTimer(10 * floor->gravity, ft_flyup,
			floor)))
			ft_sdl_error(NULL);
	}
	if (env->events.key.keysym.sym == SDLK_f
		&& env->events.type == SDL_KEYDOWN
		&& floor->fly == 1 && floor->ragdoll == 0)
	{
		if (!(floor->timerflydown = SDL_AddTimer(10
			* floor->gravity, ft_flydown, floor)))
			ft_sdl_error(NULL);
	}
}
