/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_devastator_explosion.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:58:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 09:57:28 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			devastator_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 5)
		sprite->animation = 0;
	sprite->animation++;
	return (interval);
}

uint32_t			explosion_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 4)
	{
		sprite->hp = -1;
		return (0);
	}
	sprite->animation++;
	return (interval);
}
