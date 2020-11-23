/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rayhelper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 00:36:10 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 11:42:37 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_hithelper(t_env *env, t_elem *floor, t_ray *ray,
				int iteration)
{
	if (floor[floor->currentstair].new[(int)ray->mapy]
		[(int)ray->mapx][WALL] == '1')
	{
		ray->hit = 1;
		ray->blocksize =
			floor[floor->currentstair].new[(int)ray->mapy]
			[(int)ray->mapx][BLOCK_H] + 1 - '0';
		if (floor[floor->currentstair].max_blockheight < ray->blocksize)
			ray->blocksize = floor[floor->currentstair].max_blockheight;
	}
	else if (iteration == 0 && floor[floor->currentstair].new[(int)ray->mapy]
	[(int)ray->mapx][0] == '4')
		env->window_buffer[ray->x]++;
}

void			ft_setupray(t_env *env, t_elem *floor, t_ray *ray)
{
	double		ratio;

	ratio = ((double)ray->x - (double)env->res_width / 2)
		/ (double)(env->res_width / 2);
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->rdirx = cos(floor->angle)
		+ cos(floor->angle - 1.5708) * ratio;
	ray->rdiry = sin(floor->angle)
		+ sin(floor->angle - 1.5708) * ratio;
	ray->deltadistx = sqrt(1 + (pow(ray->rdiry, 2) / pow(ray->rdirx, 2)));
	ray->deltadisty = sqrt(1 + (pow(ray->rdirx, 2) / pow(ray->rdiry, 2)));
	ray->old_dst = INT_MAX;
	ray->maxheight = -1;
	ray->old_dend = INT_MIN;
}

void			ft_step(t_ray *ray)
{
	if (ray->rdirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx)
			* ray->deltadistx;
	}
	if (ray->rdiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy)
			* ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy)
			* ray->deltadisty;
	}
}

void			ft_rayside(t_ray *ray)
{
	if (ray->side == 0)
		ray->perwalldist = fabs((ray->mapx - ray->posx
			+ (1 - ray->stepx) / 2) / ray->rdirx);
	else
		ray->perwalldist = fabs((ray->mapy - ray->posy
			+ (1 - ray->stepy) / 2) / ray->rdiry);
}

void			ft_hit(t_env *env, t_elem *floor, t_ray *ray, int iteration)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if ((ray->sidedistx >= 0 || ray->sidedisty <= 0) && ray->sidedistx
			< ray->sidedisty)
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
		ft_hithelper(env, floor, ray, iteration);
	}
	ft_rayside(ray);
	if (ray->hit && !iteration)
		env->zbuffer[ray->x] = ray->perwalldist;
}
