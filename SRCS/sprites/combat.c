/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 06:28:41 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 18:44:16 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			timer_hit(uint32_t interval, void *param)
{
	(void)interval;
	*(int*)param = 0;
	return (0);
}

static	void		killed_enemy_p2(t_elem *floor, t_sprite *target)
{
	if (target->type == ENEMY_DEAD_1)
	{
		target->timer = SDL_AddTimer(250, enemy1_dead_anim,
			(void*)target);
	}
	else if (target->type == ENEMY_DEAD_BOSS)
	{
		target->timer = SDL_AddTimer(250,
			enemy_dead_boss_anim, (void*)target);
		floor->endgame_timer = SDL_AddTimer(5000, timer_endgame, floor);
	}
	else
		target->timer = SDL_AddTimer(250, enemy_dead_anim,
			(void*)target);
}

void				killed_enemy(t_elem *floor, t_sprite *target)
{
	if (target->timer_idle)
		SDL_RemoveTimer(target->timer_idle);
	target->timer_idle = 0;
	if (target->timer)
		SDL_RemoveTimer(target->timer);
	target->timer = 0;
	floor->score += (target->type - ENEMY_1 + 1) * 100;
	floor->fire_stat = ft_range(floor->score / 500, 0, 5);
	update_enemies(floor);
	target->type += 5;
	target->hp = -1;
	target->hit = 0;
	target->state = 0;
	target->animation = 0;
	ft_strncpy(floor[floor->currentstair].new[(int)target->posy]
		[(int)target->posx] + SPRITE, target->mapbuffer, 2);
	killed_enemy_p2(floor, target);
}
