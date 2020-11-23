/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flydive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:17:53 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 19:13:56 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_dive(t_elem *floor)
{
	if (floor->swim == 1 && floor->ragdoll == 0)
	{
		if (floor->keystat[SDL_SCANCODE_V] && floor->flysensi < 4
			&& floor->crouchsensi <= 1)
		{
			floor->game_msg = 0;
			floor->flysensi = floor->flysensi + 0.1;
		}
		if (floor->keystat[SDL_SCANCODE_C] && floor->flysensi > 1)
		{
			floor->game_msg = 0;
			floor->flysensi = floor->flysensi - 0.1;
		}
		if (floor->keystat[SDL_SCANCODE_C] && floor->flysensi == 1
			&& floor->crouchsensi <= 4)
		{
			floor->game_msg = 0;
			floor->crouchsensi = floor->crouchsensi + 0.1;
		}
		if (floor->keystat[SDL_SCANCODE_V] && floor->crouchsensi >= 1)
		{
			floor->game_msg = 0;
			floor->crouchsensi = floor->crouchsensi - 0.1;
		}
	}
}
