/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:07:51 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 19:21:30 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_move_front_back_auto(t_elem *floor, int nb,
							double framespeed)
{
	floor->tmpx = floor->posx + ((floor->speed
		* 4 * floor->speedshift * framespeed)
		* cos(floor->angle)) * nb;
	if ((int)floor->tmpx >= 1 && (int)floor->tmpx
		< floor[floor->currentstair].width - 1)
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed
		* 4 * floor->speedshift * framespeed)
		* sin(floor->angle)) * nb;
	if ((int)floor->tmpy >= 1 && (int)floor->tmpy
		!= floor[floor->currentstair].hight - 1)
		floor->posy = floor->tmpy;
}

static	void	ft_walkint_off(t_elem *floor)
{
	floor->autorun = 0;
	floor->autorunmove = 0;
	floor->autorunswitch = 0;
	floor->fire_stat = 0;
}

static uint32_t	ft_walkint(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][WALL] != '9' && floor->autorun == 1)
	{
		floor->autorunmove = 1;
		floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][WALL] = '4';
		floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][WALL_TEXT] = 'F';
		floor->prevlife = 100;
		floor->life = 100;
		ft_move_front_back_auto(floor, 1, 2);
	}
	else if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][WALL] == '9')
	{
		ft_walkint_off(floor);
		SDL_RemoveTimer(floor->timerwalk);
	}
	else
		SDL_RemoveTimer(floor->timerwalk);
	return (interval);
}

void			ft_walk(t_elem *floor)
{
	if (floor->posx == floor[floor->currentstair].spawn_x
		&& floor->posy == floor[floor->currentstair].spawn_y
		&& floor->autorunswitch == 1)
	{
		if (floor->autorun == 1)
		{
			if (!(floor->timerwalk = SDL_AddTimer(100, ft_walkint, floor)))
				ft_sdl_error(NULL);
		}
		else if (floor->timerwalk)
			SDL_RemoveTimer(floor->timerwalk);
	}
}
