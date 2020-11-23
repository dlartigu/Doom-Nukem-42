/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speedshift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:11:54 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/15 15:36:01 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_speedshift(t_env *env, t_elem *floor)
{
	if (floor->fly == 0 && floor->crouch == 0)
	{
		if ((env->events.key.keysym.sym == SDLK_LSHIFT)
			&& (env->events.type == SDL_KEYUP))
			floor->speedshift = 1.0 / 2;
		if ((env->events.key.keysym.sym == SDLK_LSHIFT)
			&& (env->events.type == SDL_KEYDOWN))
			floor->speedshift = 1.0 / 1;
	}
}
