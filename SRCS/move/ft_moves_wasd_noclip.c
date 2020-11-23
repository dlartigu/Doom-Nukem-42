/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_wasd_noclip.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:08:18 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/03 15:22:10 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		ft_strafe_left(t_elem *floor, double framespeed)
{
	floor->tmpx = floor->posx - ((floor->speed * floor->speedshift * framespeed)
		* cos(floor->angle - 1.5708));
	if ((int)floor->tmpx >= 1
		&& (int)floor->tmpx < floor[floor->currentstair].width - 1)
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy - ((floor->speed * floor->speedshift * framespeed)
		* sin(floor->angle - 1.5708));
	if ((int)floor->tmpy >= 1
		&& (int)floor->tmpy != floor[floor->currentstair].hight - 1)
		floor->posy = floor->tmpy;
}

static	void		ft_strafe_right(t_elem *floor, double framespeed)
{
	floor->tmpx = floor->posx + ((floor->speed * floor->speedshift * framespeed)
		* cos(floor->angle - 1.5708));
	if ((int)floor->tmpx >= 1
		&& (int)floor->tmpx < floor[floor->currentstair].width - 1)
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed * floor->speedshift * framespeed)
		* sin(floor->angle - 1.5708));
	if ((int)floor->tmpy >= 1
		&& (int)floor->tmpy != floor[floor->currentstair].hight - 1)
		floor->posy = floor->tmpy;
}

static void			ft_move_front_back_noclip(t_elem *floor, int nb,
					double framespeed)
{
	floor->tmpx = floor->posx + ((floor->speed * floor->speedshift * framespeed)
		* cos(floor->angle)) * nb;
	if ((int)floor->tmpx >= 1
		&& (int)floor->tmpx < floor[floor->currentstair].width - 1)
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed * floor->speedshift * framespeed)
		* sin(floor->angle)) * nb;
	if ((int)floor->tmpy >= 1
		&& (int)floor->tmpy != floor[floor->currentstair].hight - 1)
		floor->posy = floor->tmpy;
}

void				ft_moves_wasd_noclip(t_elem *floor)
{
	if (floor->pistol_selected == 1)
		floor->speed = floor->speed / 1.15;
	if (floor->shotgun_selected == 1)
		floor->speed = floor->speed / 1.30;
	if (floor->devastator_selected == 1)
		floor->speed = floor->speed / 1.7;
	if (floor->keystat[SDL_SCANCODE_W])
		ft_move_front_back_noclip(floor, 1, floor->framespeed);
	if (floor->keystat[SDL_SCANCODE_S])
		ft_move_front_back_noclip(floor, -1, floor->framespeed);
	if (floor->keystat[SDL_SCANCODE_A])
		ft_strafe_left(floor, floor->framespeed);
	if (floor->keystat[SDL_SCANCODE_D])
		ft_strafe_right(floor, floor->framespeed);
}
