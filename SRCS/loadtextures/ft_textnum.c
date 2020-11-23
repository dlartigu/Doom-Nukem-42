/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:11:42 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:43:59 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_floor_textnum(t_elem *floor, t_ray *ray, uint32_t *color)
{
	if (ray->floorx < 0)
		ray->floorx = 0;
	else if (ray->floorx >= floor[floor->currentstair].width)
		ray->floorx = floor[floor->currentstair].width - 1;
	if (ray->floory < 0)
		ray->floory = 0;
	else if (ray->floory >= floor[floor->currentstair].hight)
		ray->floory = floor[floor->currentstair].hight - 1;
	if (!(floor[floor->currentstair].new[(int)ray->floory]
	[(int)ray->floorx][FLOOR_TXT]))
		ray->floor_txtnum = 0;
	else
		ray->floor_txtnum =
	floor[floor->currentstair].new[(int)ray->floory]
	[(int)ray->floorx][FLOOR_TXT] - '0';
	if (ray->floor_txtnum + '0' == 'A')
		*color = ft_readpixel(floor->animatedwalltext[floor->ntext],
				ray->ftx, ray->fty);
	else
		*color = ft_readpixel(floor->floortext[ray->floor_txtnum],
				ray->ftx, ray->fty);
}

void		ft_ceiling_textnum(t_elem *floor, t_ray *ray, uint32_t *color)
{
	if (ray->floorx < 0)
		ray->floorx = 0;
	else if (ray->floorx >= floor[floor->currentstair].width)
		ray->floorx = floor[floor->currentstair].width - 1;
	if (ray->floory < 0)
		ray->floory = 0;
	else if (ray->floory >= floor[floor->currentstair].hight)
		ray->floory = floor[floor->currentstair].hight - 1;
	if (!(floor[floor->currentstair].new[(int)ray->floory]
	[(int)ray->floorx][CEILING_TXT]))
		ray->ceiling_txtnum = 0;
	else
		ray->ceiling_txtnum =
			floor[floor->currentstair].new[(int)ray->floory]
			[(int)ray->floorx][CEILING_TXT] - '0';
	if (ray->ceiling_txtnum == 17)
	{
		*color = ft_readpixel(floor->animatedwalltext[floor->ntext],
			ray->ftx, ray->fty);
	}
	else if (ray->ceiling_txtnum != 0)
		*color = ft_readpixel(floor->ceilingtext[ray->ceiling_txtnum - 1],
			ray->ftx, ray->fty);
}

void		ft_wall_textnum(t_elem *floor, t_ray *ray)
{
	if (!(floor[floor->currentstair].new[ray->mapy]
	[ray->mapx][WALL_TEXT]))
		ray->txtnum = 0;
	else if (floor[floor->currentstair].new[ray->mapy][ray->mapx][WALL_TEXT]
	>= 'B' && floor[floor->currentstair].new[ray->mapy][ray->mapx][WALL_TEXT]
	<= 'H')
		ray->txtnum = (floor[floor->currentstair].new
		[ray->mapy][ray->mapx][WALL_TEXT] - '0') - 8;
	else
		ray->txtnum = floor[floor->currentstair].new
		[ray->mapy][ray->mapx][WALL_TEXT] - '0';
}
