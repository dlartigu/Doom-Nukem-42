/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:23:23 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 22:47:11 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

double			ray_calc_dist(t_ray *ray)
{
	if (ray->side == 0)
		return (fabs((ray->mapx - ray->posx
			+ (1 - ray->stepx) / 2) / ray->rdirx));
	else
		return (fabs((ray->mapy - ray->posy
			+ (1 - ray->stepy) / 2) / ray->rdiry));
}

void			check_hit(t_elem *floor, t_ray *ray, int *count)
{
	if (floor[floor->currentstair].new[(int)ray->mapy]
		[(int)ray->mapx][WALL] == '1')
		ray->hit = 1;
	else if (floor[floor->currentstair].new[(int)ray->mapy]
		[(int)ray->mapx][WALL] == '4')
	{
		ray->window_zbuffers[*count] = ray_calc_dist(ray);
		ray->window_strbuffer[*count] = floor[floor->currentstair].new
			[(int)ray->mapy][(int)ray->mapx];
		ray->window_sidebuffer[*count] = ray->side;
		ray->wall_mapxbuffer[*count] = ray->mapx;
		ray->wall_mapybuffer[*count] = ray->mapy;
		ray->wall_sidebuffer[*count] = ft_side(ray->side, ray->rdirx,
			ray->rdiry);
		if (floor->fog || floor->shadow || floor->lava_glow)
		{
			found_dist(ray);
			ray->window_depthbuffer[*count] = ray->dperc;
		}
		(*count)++;
	}
}

int				hit_windows(t_elem *floor, t_ray *ray, int max)
{
	int			win_count;

	ray->hit = 0;
	win_count = 0;
	while (win_count < max && win_count < 9 && ray->hit == 0)
	{
		if ((ray->sidedistx >= 0 || ray->sidedisty <= 0)
		&& ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		check_hit(floor, ray, &win_count);
	}
	return (win_count);
}

static void		calc_window_p2(t_ray *ray, t_env *env, t_elem *floor, int i)
{
	int			psyeffect;

	ray->deltafly = ray->deltaline <= 0 ? 0 : ray->deltaline;
	if (ray->blocksize > 1)
		ray->blocksize = (ray->blocksize - 1) * ray->linehight;
	psyeffect = floor->psy == 0 ? 0 : env->res_width / 8;
	ray->dst = (-ray->linehight / (2 * floor->flysensi)
	+ env->res_hight / 2
	- floor->lookupdown - ray->blocksize) + ray->deltacrouch;
	ray->dend = (ray->linehight / (2 * floor->crouchsensi)
	+ env->res_hight / 2
	- floor->lookupdown - psyeffect) + ray->deltafly;
	ray->dend =
		ray->dend >= env->res_hight ? (env->res_hight - 1) : ray->dend;
	ray->yrefl = ray->dend - ((ray->dst - psyeffect) - ray->dend);
	ray->dst = ray->dst < 0 ? 0 : ray->dst;
	ray->y = ray->dst - psyeffect;
	ray->y = ft_range(ray->y, 0, env->res_hight - 1);
	ray->yrefl = ft_range(ray->yrefl, 0, env->res_hight - 1);
	ray->yreflend = ray->yrefl;
	draw_window(env, floor, ray, i);
}

void			calc_window(t_env *env, t_elem *floor, t_ray *ray, int i)
{
	ray->blocksize = ray->window_strbuffer[i][BLOCK_H] - '0' + 1;
	ray->linehight = abs((int)(env->res_hight / ray->perwalldist));
	ray->crouchds = ray->linehight / (2 * floor->flysensi);
	ray->crouchde = ray->linehight / (2 * floor->crouchsensi);
	ray->deltaline = ray->crouchde - ray->crouchds;
	ray->deltacrouch = ray->deltaline >= 0 ? 0 : ray->deltaline;
	calc_window_p2(ray, env, floor, i);
}
