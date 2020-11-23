/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ragdoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:24:10 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:44:02 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t				ft_ragdoll_base_down(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->crouchsensi <= floor->ragdollsensi)
		floor->crouchsensi = floor->crouchsensi + 0.05;
	else if (floor->crouchsensi >= floor->ragdollsensi
		&& floor->timerragdolldown)
		SDL_RemoveTimer(floor->timerragdolldown);
	return (interval);
}

static	void			ft_ragdoll_below50dwn(t_elem *floor)
{
	if (floor->life < 50 && floor->life >= 40)
		ft_ragdoll_timerdown(floor, 0.009, 1, 1.5);
	else if (floor->life < 40 && floor->life >= 20)
		ft_ragdoll_timerdown(floor, 0.009, 1, 2);
	else if (floor->life < 20 && floor->life >= 10)
		ft_ragdoll_timerdown(floor, 0.01, 1, 3);
	else if (floor->life < 10 && floor->life >= 0)
		ft_ragdoll_timerdown(floor, 0.015, 1, 5);
}

void					ft_ragdoll(t_elem *floor)
{
	if (floor->prevlife > floor->life)
	{
		ft_ragdoll_above50(floor);
		ft_ragdoll_below50dwn(floor);
	}
	else if (floor->prevlife < floor->life)
		ft_ragdoll_up(floor);
	floor->prevlife = floor->life;
	if (floor->life >= 50)
		floor->ragdoll = 0;
}
