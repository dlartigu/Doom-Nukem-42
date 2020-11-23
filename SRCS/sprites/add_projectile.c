/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_projectile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:35:53 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:05:33 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				try_move_projectile(t_elem *floor,
					t_sprite *sprite)
{
	double			nextx;
	double			nexty;

	nextx = sprite->posx + sprite->dirx
		* floor->sprites_data[sprite->type].speed;
	nexty = sprite->posy + sprite->diry
		* floor->sprites_data[sprite->type].speed;
	if (sprite->posy < -10 || sprite->posy > floor[floor->currentstair].hight
		+ 10 || sprite->posx < -10
		|| sprite->posx > floor[floor->currentstair].width + 10
		|| sprite->posz + sprite->dirz < -floor->lookupcap)
	{
		sprite->hp = -1;
		return ;
	}
	else if (!try_hit_projectile(floor, sprite, nextx, nexty))
		return ;
	sprite->posx = nextx;
	sprite->posy = nexty;
	sprite->posz += sprite->dirz;
}

uint32_t			player_projectile_timer(uint32_t interval, void *param)
{
	t_elem			*floor;
	t_sprite		*sprite;
	t_env			*env;

	interval = 25;
	sprite = (t_sprite*)param;
	floor = (t_elem*)sprite->floor;
	env = (t_env*)sprite->env;
	if (!sprite->hp)
	{
		sprite->hp = floor->sprites_data[sprite->type].max_hp;
		sprite->posx = floor->posx + cos(floor->angle) / 2;
		sprite->posy = floor->posy + sin(floor->angle) / 2;
		sprite->dirx = cos(floor->angle);
		sprite->diry = sin(floor->angle);
		normalize_vec2d(&sprite->dirx, &sprite->diry);
		sprite->posz = floor->lookupdown + env->res_hight
			/ (2 * floor->crouchsensi) - env->res_hight / (2 * floor->flysensi);
		sprite->dirz = ft_dmap(floor->lookupdown + floor->lookupcap,
			floor->lookupcap * 2, 0, 0.1) - 0.05;
	}
	else if (sprite->hp > 0)
		try_move_projectile(floor, sprite);
	return (interval);
}

uint32_t			enemy_projectile_timer(uint32_t interval, void *param)
{
	t_elem			*floor;
	t_sprite		*sprite;

	sprite = (t_sprite*)param;
	floor = (t_elem*)sprite->floor;
	if (sprite->hp > 0)
		try_move_projectile(floor, sprite);
	return (interval);
}

t_sprite			*add_projectile_p2(t_env *env, t_elem *floor,
					t_sprite *sprite, t_sprite *param)
{
	sprite->env = (void*)env;
	sprite->floor = (void*)floor;
	sprite->posx = param->posx + param->dirx / 2;
	sprite->posy = param->posy + param->diry / 2;
	sprite->dirx = param->dirx;
	sprite->diry = param->diry;
	init_sprite(floor, sprite);
	sprite->hp = 1;
	sprite->timer = SDL_AddTimer(25, enemy_projectile_timer,
		(void*)sprite);
	return (sprite);
}

t_sprite			*add_projectile(t_env *env, t_elem *floor, int type,
					t_sprite *param)
{
	t_sprite	*sprite;

	if (!(sprite = (t_sprite*)ft_memalloc(sizeof(t_sprite))))
		ft_fct_error("add_sprite(1)");
	if (type == 0)
	{
		sprite->type = DEVASTATOR_PROJECTILE;
		sprite->env = (void*)env;
		sprite->floor = (void*)floor;
		init_sprite(floor, sprite);
		sprite->timer = SDL_AddTimer(1225, player_projectile_timer,
			(void*)sprite);
	}
	else if (param)
	{
		sprite->type = type;
		return (add_projectile_p2(env, floor, sprite, param));
	}
	return (sprite);
}
