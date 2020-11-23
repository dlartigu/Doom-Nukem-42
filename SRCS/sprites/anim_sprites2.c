/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_sprites2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:14:11 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 22:51:51 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			enemy3_anim_p2(t_sprite *sprite)
{
	if (sprite->animation < 1 || sprite->animation > 2)
		sprite->animation = 1;
	else
		sprite->animation++;
	return (200);
}

uint32_t			enemy3_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->state == 0)
		sprite->animation = 0;
	else if (sprite->state == 1)
	{
		interval = 300;
		if (sprite->animation < 4 || sprite->animation >= 6)
			sprite->animation = 4;
		else
			sprite->animation++;
		if (sprite->animation == 5)
			enemy_attack(sprite->env, sprite->floor, sprite);
		if (sprite->animation == 6)
			sprite->state = 0;
	}
	else if (sprite->state == 2)
		return (enemy3_anim_p2(sprite));
	return (interval);
}

uint32_t			enemy4_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	interval = 250;
	if (sprite->state == 0)
		sprite->animation = 0;
	else if (sprite->state == 1)
	{
		if (sprite->animation < 3 || sprite->animation >= 7)
			sprite->animation = 3;
		else
			sprite->animation++;
		interval = 300 + (sprite->animation - 4) * 100;
		if (sprite->animation == 7)
		{
			enemy_attack(sprite->env, sprite->floor, sprite);
			sprite->state = 0;
			interval = 1000;
		}
	}
	else if (sprite->state == 2)
		sprite->animation = 0;
	return (interval);
}

uint32_t			boss_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->state == 0)
		sprite->animation = 0;
	else if (sprite->state == 1)
	{
		if (sprite->animation < 2 || sprite->animation >= 8)
			sprite->animation = 2;
		else
			sprite->animation++;
		if (sprite->animation == 5)
			enemy_attack(sprite->env, sprite->floor, sprite);
		if (sprite->animation == 8)
			sprite->state = 0;
	}
	else if (sprite->state == 2)
		sprite->animation = 0;
	return (interval);
}
