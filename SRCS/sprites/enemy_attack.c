/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:48:56 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 10:08:40 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		enemy_attack_p2(t_elem *floor, t_sprite *sprite)
{
	double	sprite_angle;
	double	player_angle;

	player_angle = atan2(floor->posy - sprite->posy, floor->posx
		- sprite->posx);
	sprite_angle = atan2(sprite->diry, sprite->dirx);
	if (fabs(sprite_angle - player_angle) > (M_PI / 4))
		return ;
	else
	{
		if (sprite->type == ENEMY_1)
			floor->life -= 5 / floor->difficulty;
		else if (sprite->dist < 1.5)
			floor->life -= 20 / floor->difficulty;
		else
			return ;
		floor->player_hit = 1;
		SDL_AddTimer(200, timer_hit, (void*)&floor->player_hit);
	}
}

void				enemy_attack(t_env *env, t_elem *floor, t_sprite *sprite)
{
	if (sprite->type == ENEMY_1)
		play_simple(floor->audio, EFF_ENEMY_1_ATTACK, CH_ENEMY_1_ATTACK, 1);
	if (sprite->type == ENEMY_2)
		play_simple(floor->audio, EFF_ENEMY_2_ATTACK, CH_ENEMY_2_ATTACK, 1);
	if (sprite->type == ENEMY_3)
		play_simple(floor->audio, EFF_ENEMY_3_ATTACK, CH_ENEMY_3_ATTACK, 1);
	if (sprite->type == ENEMY_4)
		play_simple(floor->audio, EFF_ENEMY_4_ATTACK, CH_ENEMY_4_ATTACK, 1);
	if (sprite->type == ENEMY_BOSS)
		play_simple(floor->audio, EFF_ENEMY_BOSS_ATTACK,
			CH_ENEMY_BOSS_ATTACK, 1);
	if (sprite->type == ENEMY_1 || sprite->type == ENEMY_2)
		enemy_attack_p2(floor, sprite);
	else
		add_projectile(env, floor, sprite->type - ENEMY_3 + ENEMY_3_PROJECTILE,
			sprite);
}
