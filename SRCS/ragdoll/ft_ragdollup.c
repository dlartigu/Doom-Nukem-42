/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ragdollup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:28:34 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 17:21:25 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			ft_ragdoll_base_up(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->crouchsensi >= floor->ragdollsensi)
		floor->crouchsensi = floor->crouchsensi - 0.05;
	else if (floor->crouchsensi <= floor->ragdollsensi)
	{
		if (floor->ragdollsensi == 1)
			floor->crouchsensi = 1;
		if (floor->timerragdollup)
			SDL_RemoveTimer(floor->timerragdollup);
	}
	return (interval);
}

static	void		ft_ragdoll_below50up(t_elem *floor)
{
	if (floor->prevlife < 50 && floor->life >= 50)
		ft_ragdoll_timerup(floor, 0.008, 1, 1);
	else if (floor->life < 50 && floor->life >= 40)
		ft_ragdoll_timerup(floor, 0.009, 1, 1.5);
	else if (floor->life < 40 && floor->life >= 20)
		ft_ragdoll_timerup(floor, 0.009, 1, 2);
	else if (floor->life < 20 && floor->life >= 10)
		ft_ragdoll_timerup(floor, 0.01, 1, 3);
	else if (floor->life < 10 && floor->life >= 0)
		ft_ragdoll_timerup(floor, 0.015, 1, 5);
}

void				ft_ragdoll_up(t_elem *floor)
{
	ft_ragdoll_above50(floor);
	ft_ragdoll_below50up(floor);
}
