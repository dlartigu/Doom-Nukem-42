/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:50:22 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/25 17:35:10 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		attack_enemy_p2(t_elem *floor, t_sprite *target)
{
	if (floor->pistol_selected == 1)
	{
		target->hit = 1;
		target->hp -= 20 * floor->difficulty;
	}
	else if (floor->shotgun_selected == 1)
	{
		target->hit = 1;
		if (target->dist < 4)
			target->hp -= 50 * floor->difficulty;
		else
			target->hp -= (50 / ((target->dist - 3) / 4)) * floor->difficulty;
	}
	else if (floor->fist_selected == 1)
	{
		if (target->dist < 2)
		{
			target->hit = 1;
			target->hp -= 10 * floor->difficulty;
		}
	}
}

void				attack_enemy(t_elem *floor, t_sprite *target,
			t_sprite *projectile, double dist)
{
	if (!target || target->wave > floor->fire_stat)
		return ;
	if (projectile)
	{
		if (dist > 1)
			target->hp -= projectile->hp / dist;
		else
			target->hp -= projectile->hp;
		target->hit = 1;
	}
	else
		attack_enemy_p2(floor, target);
	if (target->hp > 0 && target->hit)
		SDL_AddTimer(400, timer_hit, (void*)&target->hit);
	else if (target->hp < 0 && target->hit)
	{
		floor[floor->currentstair].new[(int)target->posy][(int)target->posx]
			[SPRITE] = '0';
		target->hp = 0;
	}
}
