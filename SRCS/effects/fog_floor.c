/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:09:30 by idris             #+#    #+#             */
/*   Updated: 2020/10/07 01:27:49 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t	shadowfloor(t_ray *ray, uint32_t colora, uint32_t colorb, int dens)
{
	double			dist;

	dist = hypot(ray->floorx - ray->posx, ray->floory
	- ray->posy);
	if (dist > (double)dens)
		dist = (double)dens;
	dist = ft_dmap(dist, (double)dens, 0, 100);
	return (color_grad(colora >> 8, colorb, dist) + (colora & 0xff));
}

uint32_t	floor_fog(t_elem *floor, t_ray *ray, uint32_t col)
{
	if (floor->shadow == 1)
		return (shadowfloor(ray, col, 0x00000000, 4));
	else if (floor->fog == 1)
		return (shadowfloor(ray, col, 0xA7A69D, 4));
	else if (floor->lava_glow == 1)
		return (shadowfloor(ray, col, 0xCB541C, 4));
	return (col);
}
