/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:00:13 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 19:14:15 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			mix_pixels(t_env *env, t_elem *floor, t_ray *ray, int pitch)
{
	uint32_t	col;
	uint32_t	surfcol;
	double		perc;
	uint8_t		alpha;

	col = ft_readpixel(ray->usethiswall,
	ray->texx, ray->texy);
	col = wall_fog(floor, ray->dperc, col);
	surfcol = ((int*)(env->foresurf->pixels))[ray->y * env->foresurf->w
		+ ray->x];
	perc = ft_dmap((col & 0xFF), 0xFF, 0, 100);
	if (!(col & 0xFF))
		return (surfcol);
	else if (env->sprite_zbuffer[ray->x + pitch] && ray->perwalldist
	> env->sprite_zbuffer[ray->x + pitch])
		return (surfcol);
	else if ((col & 0xFF) == 0xFF)
		return (col);
	alpha = (col & 0xFF) + ((surfcol & 0xFF) * (0xFF - (col & 0xFF))) / 0xFF;
	return (color_grad(surfcol >> 8, col >> 8, (int)perc) + alpha);
}

static void			ft_choose_wall_win(t_elem *floor, t_ray *ray)
{
	int			nwall;

	nwall = search_wall2(floor, ray, &floor->tab[0]);
	if (nwall >= 0)
		ray->usethiswall = floor->tab[0].wall_impact[nwall].tex;
	else
		ray->usethiswall = floor->walltext[ray->txtnum];
}

void				calc_impact_win(t_env *env, t_elem *floor,
					t_ray *ray, int *memtexy)
{
	int			blockheight;

	if (ray->txtnum == 16)
		return ;
	ray->texpos += ray->step;
	if (floor->enemy_target)
		return ;
	blockheight = (((int)ray->texpos) - TEXT_H * floor->texture_res)
	/ (TEXT_H * floor->texture_res);
	if (ray->x == env->width / 2 && ray->y == env->height / 2
	&& floor->impact >= 1)
	{
		fill_poswall2(floor, ray, &floor->lastwall);
		floor->taketexx = ray->texx;
		floor->taketexy = ray->texy;
		floor->taketxtnum = ray->txtnum;
		floor->impact = 2;
	}
	if (*memtexy < blockheight)
		ft_choose_wall_win(floor, ray);
	*memtexy = blockheight;
}

void				draw_window(t_env *env, t_elem *floor, t_ray *ray, int i)
{
	uint32_t	col;
	int			memtexy;

	setup_wall(env, floor, ray, NULL);
	ray->txtnum = ray->window_strbuffer[i][WALL_TEXT];
	if (ray->txtnum == 'A')
		ray->txtnum = 0;
	else
		ray->txtnum -= ray->txtnum < 'B' ? '0' : '8';
	ray->usethiswall = floor->walltext[ray->txtnum];
	memtexy = -1024;
	if (!floor->debug_wall)
		while (ray->y <= ray->dend)
		{
			if (ray->y >= 0 && ray->y < env->foresurf->h)
			{
				ray->texy = (int)ray->texpos & ((TEXT_H * floor->texture_res)
					- 1);
				calc_impact_win(env, floor, ray, &memtexy);
				col = mix_pixels(env, floor, ray, ray->y * env->res_width);
				ft_putpixel(env->foresurf, ray->x, ray->y, col);
			}
			ray->y++;
		}
}
