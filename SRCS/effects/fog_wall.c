/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:45:04 by idris             #+#    #+#             */
/*   Updated: 2020/10/09 20:04:58 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		found_dist(t_ray *ray)
{
	double dist;

	if (ray->side == 1)
		dist = hypot(ray->mapx + ray->wallx - ray->posx, ray->mapy
			- ray->posy) + 1;
	else
		dist = hypot(ray->mapx - ray->posx, ray->mapy + ray->wallx
			- ray->posy) + 1;
	if (dist > (double)6)
		dist = (double)6;
	ray->dperc = ft_dmap(dist, (double)6, 0, 100);
}

uint32_t	color_grad(unsigned int cola, unsigned int colb, int percent)
{
	short	r;
	short	g;
	short	b;

	r = (colb >> 16) - (cola >> 16);
	g = ((colb >> 8) & 0x000000FF) - ((cola >> 8) & 0x000000FF);
	b = (colb & 255) - (cola & 255);
	return ((cola + ((((r * percent) / 100) << 16)
	+ (((g * percent) / 100) << 8) + (b * percent) / 100)) << 8);
}

uint32_t	wall_fog(t_elem *floor, int percent, uint32_t col)
{
	if (floor->shadow == 1)
	{
		return (color_grad(col >> 8, 0, percent)
			+ (col & 0xff));
	}
	else if (floor->fog == 1)
	{
		return (color_grad(col >> 8, 0xDCDBDF, percent)
			+ (col & 0xff));
	}
	else if (floor->lava_glow == 1)
	{
		return (color_grad(col >> 8, 0xCB541C, percent)
			+ (col & 0xff));
	}
	return (col);
}
