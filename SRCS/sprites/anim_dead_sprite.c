/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dead_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:22 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:58:15 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			enemy1_dead_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 6)
		return (0);
	sprite->animation++;
	return (interval);
}

uint32_t			enemy_dead_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 8)
		return (0);
	sprite->animation++;
	return (interval);
}

uint32_t			enemy_dead_boss_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 7)
		return (0);
	sprite->animation++;
	return (interval);
}
