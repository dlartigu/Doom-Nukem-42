/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_impact2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:04:07 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 21:38:10 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	verif_shotgun(t_elem *floor, int nwall,
		SDL_Rect *rect, t_wall *wall_impact)
{
	SDL_Rect verif;

	if (rect->x + floor->bullet->w / 2 < wall_impact[nwall].tex->w / 2)
		verif.x = rect->x;
	else
		verif.x = rect->x + floor->bullet->w;
	if (rect->y + floor->bullet->h / 2 < wall_impact[nwall].tex->w / 2)
		verif.y = rect->y;
	else
		verif.y = rect->y + floor->bullet->h;
	if ((verif.x > 0 && verif.x < wall_impact[nwall].tex->w
	&& verif.y > 0 && verif.y < wall_impact[nwall].tex->h)
	&& ft_readpixel(wall_impact[nwall].tex, verif.x, verif.y) && 0xFF
	> 0)
		SDL_BlitSurface(floor->bullet, NULL, wall_impact[nwall].tex,
		rect);
}

int		ft_side(int side, double rdirx, double rdiry)
{
	if (side == 0)
	{
		if (rdirx < 0.0)
			return (1);
		if (rdirx > 0.0)
			return (2);
	}
	else
	{
		if (rdiry < 0.0)
			return (3);
		if (rdiry > 0.0)
			return (4);
	}
	return (0);
}

void	bullet_impact_init(t_elem *floor)
{
	ft_free_twall(&floor->tab[0]);
	ft_free_twall(&floor->tab[1]);
	if (floor->bullet)
		ft_free_surface(&floor->bullet);
	if (floor->texture_res == 1)
		floor->bullet = ft_load_texture("./RSCS/texture/weapons/pistol/impact/"
		"pistolnormal.bmp");
	if (floor->texture_res == 2)
		floor->bullet = ft_load_texture("./RSCS/texture/weapons/pistol/impact/"
		"pistolhigh.bmp");
	if (floor->texture_res == 4)
		floor->bullet = ft_load_texture("./RSCS/texture/weapons/pistol/impact/"
		"pistolepic.bmp");
}

int		search_wall(t_elem *floor, t_ray *ray, t_tab_wall *tab)
{
	int	i;

	i = 0;
	while (i < tab->number_wall)
	{
		if (tab->wall_impact[i].mapx == ray->mapx
		&& tab->wall_impact[i].mapy == ray->mapy
		&& tab->wall_impact[i].side ==
		ft_side(ray->side, ray->rdirx, ray->rdiry)
		&& tab->wall_impact[i].blockheight == (((int)ray->texpos - TEXT_H
		* floor->texture_res)) / (TEXT_H * floor->texture_res))
			return (i);
		i++;
	}
	return (-1);
}

int		search_wall2(t_elem *floor, t_ray *ray, t_tab_wall *tab)
{
	int	i;

	i = 0;
	while (i < tab->number_wall)
	{
		if (tab->wall_impact[i].mapx == ray->mapx
		&& tab->wall_impact[i].mapy == ray->mapy
		&& tab->wall_impact[i].side == ray->wall_side
		&& tab->wall_impact[i].blockheight == (((int)ray->texpos - TEXT_H
		* floor->texture_res)) / (TEXT_H * floor->texture_res))
			return (i);
		i++;
	}
	return (-1);
}
