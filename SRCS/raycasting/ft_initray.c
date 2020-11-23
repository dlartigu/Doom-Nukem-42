/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:39 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/19 02:22:42 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_initcolors(t_elem *floor)
{
	floor->red = 0xFF0000FF;
	floor->green = 0x00FF00FF;
	floor->blue = 0x0000FFFF;
	floor->grey = 0xC0C0C0FF;
	floor->black = 0x000000FF;
	floor->white = 0xFFFFFFFF;
}

static void		ft_initraycasting_p2(t_elem *floor)
{
	floor->shadow = 0;
	floor->fog = 0;
	floor->underwater = 0;
	floor->lava_glow = 0;
	floor->rain = 0;
	floor->timedrain = 0;
	floor->warp_enable = 1;
	floor->reflections = 0;
	floor->impact = 0;
	floor->negative = 0;
	floor->time = SDL_GetTicks();
	srand(time(NULL));
}

void			ft_initraycasting(t_elem *floor)
{
	floor->sensitivity_x = 5;
	floor->sensitivity_y = 1;
	floor->angle = 0;
	floor->rotatespeed = 0.02;
	ft_initraycasting_p2(floor);
}
