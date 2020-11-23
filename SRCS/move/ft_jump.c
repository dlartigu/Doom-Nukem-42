/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:03:33 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 11:25:46 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static uint32_t		ft_jumpint(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->flysensi <= 2 && floor->jump == 0)
		floor->flysensi = floor->flysensi + 0.05;
	else if (floor->flysensi >= 2)
		floor->jump = 1;
	if (floor->flysensi >= 1 && floor->jump == 1)
		floor->flysensi = floor->flysensi - 0.05;
	if (floor->jump == 1 && floor->flysensi <= 1 && floor->timerjump)
		SDL_RemoveTimer(floor->timerjump);
	return (interval);
}

void				ft_jump(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_SPACE
		&& env->events.type == SDL_KEYDOWN
		&& floor->flysensi <= 1 && floor->crouchsensi <= 1
		&& floor->swim == 0 && floor->ragdoll == 0)
	{
		play_simple(&env->audio, EFF_JUMP, CH_JUMP, 1);
		if (!(floor->timerjump = SDL_AddTimer(10 * floor->gravity, ft_jumpint,
			floor)))
			ft_sdl_error(NULL);
		floor->jump = 0;
	}
}
