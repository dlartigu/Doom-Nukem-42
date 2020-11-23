/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:43:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 19:47:46 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				explode_projectile(t_elem *floor, t_sprite *sprite)
{
	double			dist;
	t_list			*ptr;

	ptr = floor->enemies;
	if (sprite->type != DEVASTATOR_PROJECTILE)
	{
		sprite->hp = -1;
		return ;
	}
	while (ptr)
	{
		dist = hypot(sprite->posx - ((t_sprite*)ptr->content)->posx,
			sprite->posy - ((t_sprite*)ptr->content)->posy);
		if (dist < floor->sprites_data[sprite->type].range)
			attack_enemy(floor, (t_sprite*)ptr->content, sprite, dist);
		ptr = ptr->next;
	}
	if (sprite->timer)
		SDL_RemoveTimer(sprite->timer);
	sprite->type = EXPLOSION;
	sprite->animation = 0;
	sprite->state = 0;
	play_simple(floor->audio, EFF_EXPLOSION, CH_EXPLOSION, 1);
	sprite->floor = floor;
	sprite->timer = SDL_AddTimer(200, explosion_anim, (void*)sprite);
}

int					try_hit_enemies(t_elem *floor, t_sprite *sprite,
					double nextx, double nexty)
{
	double			dist;
	t_list			*ptr;

	ptr = floor->enemies;
	while (ptr)
	{
		if (((t_sprite*)ptr->content)->wave <= floor->fire_stat
			&& ((t_sprite*)ptr->content)->type >= ENEMY_1
			&& ((t_sprite*)ptr->content)->type <= ENEMY_BOSS)
		{
			dist = hypot(nextx - ((t_sprite*)ptr->content)->posx, nexty
				- ((t_sprite*)ptr->content)->posy);
			if (dist < 0.5)
			{
				explode_projectile(floor, sprite);
				return (1);
			}
		}
		ptr = ptr->next;
	}
	return (0);
}

int					try_hit_player(t_elem *floor, t_sprite *sprite,
					double nextx, double nexty)
{
	double			dist;

	dist = hypot(nextx - floor->posx, nexty - floor->posy);
	if (dist < 0.5)
	{
		floor->player_hit = 1;
		SDL_AddTimer(200, timer_hit, (void*)&floor->player_hit);
		if (sprite->type == ENEMY_3_PROJECTILE)
			floor->life -= 15;
		else if (sprite->type == ENEMY_4_PROJECTILE)
			floor->life -= 25;
		else if (sprite->type == ENEMY_BOSS_PROJECTILE)
			floor->life -= 30;
		sprite->hp = -1;
		return (1);
	}
	return (0);
}

int					check_projectile_hit_wall(t_elem *floor,
					t_sprite *sprite, double nextx, double nexty)
{
	if (floor[floor->currentstair].new[(int)sprite->posy][(int)nextx][WALL]
	!= '0')
		return (1);
	else if (floor[floor->currentstair].new[(int)nexty][(int)sprite->posx]
	[WALL] != '0')
		return (1);
	if (floor[floor->currentstair].new[(int)nexty][(int)nextx][WALL] != '0'
	|| (sprite->posz + sprite->dirz) * sprite->dist > floor->lookupcap)
		return (1);
	return (0);
}

int					try_hit_projectile(t_elem *floor, t_sprite *sprite,
					double nextx, double nexty)
{
	if (sprite->posy > 0 && sprite->posy
	< floor[floor->currentstair].hight - 1 && sprite->posx > 0
	&& sprite->posx < floor[floor->currentstair].width - 1)
	{
		if (check_projectile_hit_wall(floor, sprite, nextx, nexty))
		{
			explode_projectile(floor, sprite);
			return (0);
		}
		else if (sprite->type == DEVASTATOR_PROJECTILE)
		{
			if (try_hit_enemies(floor, sprite, nextx, nexty))
				return (0);
		}
		else if (try_hit_player(floor, sprite, nextx, nexty))
			return (0);
	}
	return (1);
}
