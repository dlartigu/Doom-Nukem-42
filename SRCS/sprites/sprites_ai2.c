/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_ai2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:58:45 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 09:59:42 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				raycast_sight(t_elem *floor, t_ray *ray)
{
	ft_step(ray);
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx
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
		sight_hit(floor, ray);
	}
}

int					check_sight(t_env *env, t_elem *floor, t_sprite *enemy,
					t_ray *ray)
{
	double			ratio;

	if ((int)floor->posx == (int)enemy->posx
	&& (int)floor->posy == (int)enemy->posy)
		return (1);
	ray->rdirx = floor->posx - enemy->posx;
	ray->rdiry = floor->posy - enemy->posy;
	normalize_vec2d(&ray->rdirx, &ray->rdiry);
	ray->posx = floor->posx;
	ray->posy = floor->posy;
	ratio = ((double)ray->x - (double)env->res_width / 2)
		/ (double)(env->res_width / 2);
	ray->mapx = (int)enemy->posx;
	ray->mapy = (int)enemy->posy;
	ray->deltadistx = 0;
	if (ray->rdiry != 0)
		ray->deltadistx = (ray->rdirx == 0) ? 1 : fabs(1 / ray->rdirx);
	ray->deltadisty = 0;
	if (ray->rdirx != 0)
		ray->deltadisty = (ray->rdiry == 0) ? 1 : fabs(1 / ray->rdiry);
	ray->windows_hit = 0;
	raycast_sight(floor, ray);
	if (ray->hit == 2)
		return (0);
	return (1);
}

int					check_enemy(t_env *env, t_elem *floor, t_sprite *enemy)
{
	t_ray			ray;

	if (enemy->asleep || enemy->hp <= 0 || (enemy->type < ENEMY_4
	&& enemy->state == 1) || enemy->wave > floor->fire_stat)
		return (-1);
	enemy->dist = hypot(floor->posx - enemy->posx, floor->posy - enemy->posy);
	if (enemy->dist >= floor->sprites_data[enemy->type].sight)
		return (0);
	if (!check_sight(env, floor, enemy, &ray))
		return (0);
	enemy->dirx = ray.rdirx;
	enemy->diry = ray.rdiry;
	if (enemy->dist <= floor->sprites_data[enemy->type].range)
		return (1);
	else if (!ray.windows_hit)
		return (2);
	enemy->state = 0;
	return (-1);
}

void				enemy_action(t_elem *floor, t_sprite *sprite,
					int action)
{
	double			nextposx;
	double			nextposy;

	if (sprite->idle)
		sprite->idle = 0;
	if (sprite->timer_idle)
		SDL_RemoveTimer(sprite->timer_idle);
	sprite->timer_idle = 0;
	if (sprite->state != action)
	{
		sprite->state = action;
		sprite->animation = 0;
	}
	if (action == 2 && sprite->state == 2 && sprite->dist > 0.8)
	{
		nextposx = sprite->posx + sprite->dirx
			* floor->sprites_data[sprite->type].speed * 0.02;
		nextposy = sprite->posy + sprite->diry
			* floor->sprites_data[sprite->type].speed * 0.02;
		if ((int)nextposy != (int)sprite->posy || (int)nextposx
		!= (int)sprite->posx)
			place_sprite_hitbox(floor, sprite, nextposy, nextposx);
		sprite->posy = nextposy;
		sprite->posx = nextposx;
	}
}

uint32_t			timer_idle(uint32_t interval, void *param)
{
	t_sprite		*sprite;
	int				angle;
	double			fangle;

	sprite = (t_sprite*)param;
	sprite->idle = 1;
	sprite->posx = floor(sprite->posx) + 0.5;
	sprite->posy = floor(sprite->posy) + 0.5;
	angle = (int)(((atan2(sprite->diry, sprite->dirx) + M_PI) * 180) / M_PI);
	fangle = (((angle / 90) * 90) * M_PI) / 180;
	sprite->dirx = cos(fangle);
	sprite->diry = sin(fangle);
	sprite->state = 2;
	sprite->animation = 0;
	interval = 0;
	return (0);
}
