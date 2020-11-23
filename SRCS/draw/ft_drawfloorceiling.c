/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawfloorceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:28:27 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 09:49:45 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_floorhelper(t_ray *ray)
{
	if (ray->side == 0 && ray->rdirx > 0)
	{
		ray->floorwallx = ray->mapx;
		ray->floorwally = ray->mapy + ray->wallx;
	}
	else if (ray->side == 0 && ray->rdirx < 0)
	{
		ray->floorwallx = ray->mapx + 1.0;
		ray->floorwally = ray->mapy + ray->wallx;
	}
	else if (ray->side == 1 && ray->rdiry > 0)
	{
		ray->floorwallx = ray->mapx + ray->wallx;
		ray->floorwally = ray->mapy;
	}
	else
	{
		ray->floorwallx = ray->mapx + ray->wallx;
		ray->floorwally = ray->mapy + 1.0;
	}
	ray->disttowall = ray->perwalldist;
	ray->playerdist = 0.0;
	ray->dend = ft_max_2(ray->dend, 0);
}

static void		get_floorceiling_pixel(t_elem *floor, t_ray *ray)
{
	if (isinf(ray->dist))
		ray->dist = -225;
	ray->weight = (ray->dist - ray->playerdist)
	/ (ray->disttowall - ray->playerdist);
	ray->floorx = ray->weight * ray->floorwallx
		+ (1.0 - ray->weight) * ray->posx;
	ray->floory = ray->weight * ray->floorwally
		+ (1.0 - ray->weight) * ray->posy;
	ray->ftx = (int)(ray->floorx * (floor->texture_res * TEXT_W - 1))
		& (floor->texture_res * TEXT_W - 1);
	ray->fty = (int)(ray->floory * (floor->texture_res * TEXT_H - 1))
		& (floor->texture_res * TEXT_H - 1);
}

static	void	ft_drawceiling(t_env *env, t_elem *floor, t_ray *ray)
{
	int			y;
	uint32_t	color;

	ft_floorhelper(ray);
	y = ray->old_dst + 1;
	if (y > env->res_hight)
		y = env->res_hight;
	while (--y >= 0)
	{
		ray->dist = env->res_hight / -(2.0 * y - (env->res_hight
			- (floor->lookupdown * 2)
				+ (env->res_hight / (8 * floor->crouchsensi)
					- env->res_hight / (8 * floor->flysensi)) * 2) + 1);
		get_floorceiling_pixel(floor, ray);
		ft_ceiling_textnum(floor, ray, &color);
		if (ray->ceiling_txtnum != 0)
		{
			color = floor_fog(floor, ray, color);
			ft_putpixel(env->surf, ray->x, y, color);
		}
	}
}

static	void	ft_drawfloor(t_env *env, t_elem *floor, t_ray *ray)
{
	int			y;
	uint32_t	color;

	ft_floorhelper(ray);
	y = ray->dend - 1;
	while (++y < env->res_hight)
	{
		ray->dist = env->res_hight / (2.0 * y - (env->res_hight
			- (floor->lookupdown * 2)
				+ (env->res_hight / (8 * floor->crouchsensi)
					- env->res_hight / (8 * floor->flysensi)) * 2) + 1);
		get_floorceiling_pixel(floor, ray);
		ft_floor_textnum(floor, ray, &color);
		if (floor->reflections || (floor->rain && floor->rained))
			color = mix_colors(env, ray, color, y);
		color = floor_fog(floor, ray, color);
		ft_putpixel(env->surf, ray->x, y, color);
	}
}

void			ft_drawfloorceiling(t_env *env, t_elem *floor, t_ray *ray,
				int draw)
{
	if (ray->old_dst > ray->dst)
		ray->old_dst = ray->dst;
	if (ray->old_dend < ray->dend)
		ray->old_dend = ray->dend;
	if (!draw)
		ft_drawfloor(env, floor, ray);
	if (!draw && !floor[floor->currentstair].max_blockheight)
		ft_drawceiling(env, floor, ray);
}
