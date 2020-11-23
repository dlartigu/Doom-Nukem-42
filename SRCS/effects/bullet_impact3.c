/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_impact3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:09:11 by niboute           #+#    #+#             */
/*   Updated: 2020/11/15 03:20:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			fill_poswall2(t_elem *floor, t_ray *ray, t_wall *mywall)
{
	mywall->mapx = ray->mapx;
	mywall->mapy = ray->mapy;
	mywall->side = ray->wall_side;
	mywall->blockheight = (((int)ray->texpos - TEXT_H
	* floor->texture_res)) / (TEXT_H * floor->texture_res);
}

void			fill_poswall_add(t_elem *floor, t_wall *mywall)
{
	mywall->mapx = floor->lastwall.mapx;
	mywall->mapy = floor->lastwall.mapy;
	mywall->side = floor->lastwall.side;
	mywall->blockheight = floor->lastwall.blockheight;
}

void			fusion_surface(SDL_Surface *src, SDL_Surface *dst)
{
	int			x;
	int			y;
	uint32_t	cs;
	uint32_t	cd;

	y = 0;
	while (y < src->h && y < dst->h)
	{
		x = 0;
		while (x < src->w && x < dst->w)
		{
			cs = ft_readpixel(src, x, y);
			cd = ft_readpixel(dst, x, y);
			ft_putpixel(src, x, y, (color_grad(cs >> 8, cd >> 8, 25)
			& 0xFFFFFF00) | (cs & 0xFF));
			x++;
		}
		y++;
	}
}

void			fusion_bullet(t_elem *floor, t_tab_wall *tab)
{
	int i;

	i = 0;
	while (i < tab->number_wall)
	{
		fusion_surface(tab->wall_impact[i].tex,
		floor->animatedwalltext[floor->ntext]);
		i++;
	}
}

uint32_t		ft_ntext(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	floor->ntext++;
	if (floor->ntext == 30)
	{
		floor->ntext = 0;
		floor->wall_toclean = 1;
	}
	fusion_bullet(floor, &floor->tab[1]);
	return (interval);
}
