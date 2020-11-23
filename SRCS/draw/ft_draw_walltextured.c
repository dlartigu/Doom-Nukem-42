/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walltextured.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:43:51 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 19:17:40 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_wall_reflections(t_env *env, t_elem *floor, t_ray *ray,
				int dend)
{
	uint32_t	col;
	int			y;

	y = dend;
	ray->texpos = ((y + floor->lookupdown - env->res_hight / 2
		+ ray->linehight / 2) - ray->deltaline) * ray->step;
	while (y <= ray->yrefl)
	{
		ray->texy = (int)ray->texpos & ((TEXT_H * floor->texture_res)
		- 1);
		ray->texpos -= ray->step;
		col = ft_readpixel(ray->usethiswall, ray->texx, ray->texy);
		ft_putpixel(env->surf, ray->x, y - dend + ray->dend, col);
		y++;
	}
}

void			setup_wall(t_env *env, t_elem *floor, t_ray *ray, int *dend)
{
	if (dend && ray->old_dst < ray->dend)
		*dend = ray->old_dst - 1;
	else if (dend)
		*dend = ray->dend;
	ray->wallx = ray->side == 0 ? (ray->posy + ray->perwalldist
	* ray->rdiry) : (ray->posx + ray->perwalldist * ray->rdirx);
	ray->wallx -= ft_floor((ray->wallx));
	ray->texx = (int)(ray->wallx * (double)(TEXT_W * floor->texture_res));
	if (ray->side == 0 && ray->rdirx > 0)
		ray->texx = (TEXT_W * floor->texture_res) - ray->texx - 1;
	if (ray->side == 1 && ray->rdiry < 0)
		ray->texx = (TEXT_W * floor->texture_res) - ray->texx - 1;
	ray->step = 1.0 * (TEXT_H * floor->texture_res) / ray->linehight;
	ray->texpos = ((ray->dst + floor->lookupdown - env->res_hight / 2
		+ ray->linehight / 2) - ray->deltaline) * ray->step;
	ray->y = ray->y - 1;
	if (floor->fog || floor->shadow || floor->lava_glow)
		found_dist(ray);
	if (ray->txtnum == 17)
		ray->usethiswall = floor->animatedwalltext[floor->ntext];
	else
		ray->usethiswall = floor->walltext[ray->txtnum];
}

static void		ft_choose_wall(t_elem *floor, t_ray *ray)
{
	int nwall;

	if (ray->txtnum == 17)
	{
		nwall = search_wall(floor, ray, &floor->tab[1]);
		if (nwall >= 0)
			ray->usethiswall = floor->tab[1].wall_impact[nwall].tex;
		else
			ray->usethiswall = floor->animatedwalltext[floor->ntext];
	}
	else
	{
		nwall = search_wall(floor, ray, &floor->tab[0]);
		if (nwall >= 0)
			ray->usethiswall = floor->tab[0].wall_impact[nwall].tex;
		else
			ray->usethiswall = floor->walltext[ray->txtnum];
	}
}

void			calc_impact(t_env *env, t_elem *floor, t_ray *ray, int *memtexy)
{
	int			blockheight;

	if (ray->txtnum == 16)
		return ;
	blockheight = (((int)ray->texpos) - TEXT_H * floor->texture_res)
		/ (TEXT_H * floor->texture_res);
	if (floor->enemy_target)
		return ;
	if (ray->x == env->width / 2 && ray->y == env->height / 2
	&& floor->impact >= 1)
	{
		fill_poswall(floor, ray, &floor->lastwall);
		floor->taketexx = ray->texx;
		floor->taketexy = ray->texy;
		floor->taketxtnum = ray->txtnum;
		floor->impact = 2;
	}
	if (*memtexy < blockheight)
		ft_choose_wall(floor, ray);
	*memtexy = blockheight;
}

void			ft_draw_walltextured(t_env *env, t_elem *floor, t_ray *ray,
				int i)
{
	uint32_t	col;
	int			memtexy;
	int			dend;

	setup_wall(env, floor, ray, &dend);
	if (ray->txtnum == 14 && ray->side == 1)
		ray->txtnum = 15;
	if (ray->dst < ray->old_dst)
		ray->old_dst = ray->dst;
	memtexy = -1024;
	while (ray->y <= dend)
	{
		ray->texy = (int)ray->texpos & ((TEXT_H * floor->texture_res) - 1);
		ray->texpos += ray->step;
		calc_impact(env, floor, ray, &memtexy);
		col = ft_readpixel(ray->usethiswall, ray->texx, ray->texy);
		col = wall_fog(floor, ray->dperc, col);
		ft_putpixel(env->surf, ray->x, ray->y, col);
		ray->y++;
	}
	if (!i && (floor->reflections || (floor->rain && floor->rained)))
		ft_wall_reflections(env, floor, ray, dend);
}
