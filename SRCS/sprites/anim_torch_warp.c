/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_torch_warp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:55:41 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:56:36 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t			torch_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->state == 1)
		sprite->animation = sprite->animation % 7 + 1;
	else
		sprite->animation = 0;
	return (interval);
}

uint32_t			warptowarp_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 12)
		sprite->animation = 0;
	sprite->animation++;
	return (interval);
}

uint32_t			warpfloor_anim(uint32_t interval, void *param)
{
	t_sprite *sprite;

	sprite = param;
	if (sprite->animation >= 23)
		sprite->animation = 0;
	sprite->animation++;
	return (interval);
}
