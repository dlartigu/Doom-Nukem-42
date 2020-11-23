/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:40:18 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 22:48:49 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			enemy1_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->state == 0)
		sprite->animation = 0;
	else if (sprite->state == 1)
	{
		interval = 200;
		if (sprite->animation < 1 || sprite->animation >= 3)
			sprite->animation = 1;
		else
			sprite->animation++;
		if (sprite->animation == 2)
			enemy_attack(sprite->env, sprite->floor, sprite);
		if (sprite->animation == 3)
			sprite->state = 0;
	}
	else if (sprite->state == 2)
	{
		interval = 200;
		sprite->animation = sprite->animation == 4 ? 0 : 4;
	}
	return (interval);
}

uint32_t			enemy2_anim_p2(t_sprite *sprite)
{
	if (sprite->animation < 1 || sprite->animation > 9)
		sprite->animation = 1;
	else
		sprite->animation++;
	return (80);
}

uint32_t			enemy2_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->state == 0)
		sprite->animation = 0;
	else if (sprite->state == 1)
	{
		interval = 100;
		if (sprite->animation < 12 || sprite->animation >= 20)
			sprite->animation = 12;
		else
			sprite->animation++;
		if (sprite->animation == 16)
			enemy_attack(sprite->env, sprite->floor, sprite);
		if (sprite->animation == 20)
			sprite->state = 0;
	}
	else if (sprite->state == 2)
		return (enemy2_anim_p2(sprite));
	return (interval);
}
