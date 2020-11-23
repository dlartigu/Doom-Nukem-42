/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_wasd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:16:39 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 01:32:04 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		ft_strafe_left(t_elem *floor, double framespeed)
{
	floor->tmpx = floor->posx - ((floor->speed * floor->speedshift * framespeed)
		* cos(floor->angle - 1.5708));
	if (floor[floor->currentstair].new[(int)floor->posy]
	[(int)floor->tmpx][WALL] != '1'
		&& floor[floor->currentstair].new[(int)floor->posy]
	[(int)floor->tmpx][WALL] != '4'
		&& floor[floor->currentstair].new[(int)floor->posy]
	[(int)floor->tmpx][SPRITE] != '6')
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy - ((floor->speed * floor->speedshift * framespeed)
		* sin(floor->angle - 1.5708));
	if (floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)floor->posx][WALL] != '1'
		&& floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)floor->posx][WALL] != '4'
		&& floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)floor->posx][SPRITE] != '6')
		floor->posy = floor->tmpy;
}

static	void		ft_strafe_right(t_elem *floor, double framespeed)
{
	floor->tmpx = floor->posx + ((floor->speed * floor->speedshift * framespeed)
		* cos(floor->angle - 1.5708));
	if (floor[floor->currentstair].new[(int)floor->posy]
	[(int)(floor->tmpx)][WALL] != '1'
		&& floor[floor->currentstair].new[(int)floor->posy]
	[(int)(floor->tmpx)][WALL] != '4'
		&& floor[floor->currentstair].new[(int)floor->posy]
	[(int)(floor->tmpx)][SPRITE] != '6')
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed * floor->speedshift * framespeed)
		* sin(floor->angle - 1.5708));
	if (floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)(floor->posx)][WALL] != '1'
		&& floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)(floor->posx)][WALL] != '4'
		&& floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)(floor->posx)][SPRITE] != '6')
		floor->posy = floor->tmpy;
}

void				ft_move_front_back(t_elem *floor, int nb, double framespeed)
{
	floor->tmpx = floor->posx + ((floor->speed * floor->speedshift * framespeed)
		* cos(floor->angle)) * nb;
	if (floor[floor->currentstair].new[(int)floor->posy]
	[(int)floor->tmpx][WALL] != '1'
		&& floor[floor->currentstair].new[(int)floor->posy]
	[(int)floor->tmpx][WALL] != '4'
		&& floor[floor->currentstair].new[(int)floor->posy]
	[(int)floor->tmpx][SPRITE] != '6')
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed * floor->speedshift * framespeed)
		* sin(floor->angle)) * nb;
	if (floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)floor->posx][WALL] != '1'
		&& floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)floor->posx][WALL] != '4'
		&& floor[floor->currentstair].new[(int)floor->tmpy]
	[(int)floor->posx][SPRITE] != '6')
		floor->posy = floor->tmpy;
}

void				ft_moves_wasd(t_elem *floor)
{
	if (floor->pistol_selected == 1)
		floor->speed = floor->speed / 1.15;
	if (floor->shotgun_selected == 1)
		floor->speed = floor->speed / 1.30;
	if (floor->devastator_selected == 1)
		floor->speed = floor->speed / 1.7;
	if (floor->keystat[SDL_SCANCODE_W])
		ft_move_front_back(floor, 1, floor->framespeed);
	if (floor->keystat[SDL_SCANCODE_S])
		ft_move_front_back(floor, -1, floor->framespeed);
	if (floor->keystat[SDL_SCANCODE_A])
		ft_strafe_left(floor, floor->framespeed);
	if (floor->keystat[SDL_SCANCODE_D])
		ft_strafe_right(floor, floor->framespeed);
}
