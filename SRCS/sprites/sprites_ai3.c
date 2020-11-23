/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_ai3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:01:26 by niboute           #+#    #+#             */
/*   Updated: 2020/11/13 23:39:42 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			normalize_vec2d(double *dirx, double *diry)
{
	double		length;

	length = sqrt(*dirx * *dirx + *diry * *diry);
	*dirx = *dirx / length;
	*diry = *diry / length;
}

void			place_sprite_hitbox(t_elem *floor, t_sprite *sprite,
					double nextposy, double nextposx)
{
	ft_strncpy(floor[floor->currentstair].new[(int)sprite->posy]
		[(int)sprite->posx] + SPRITE, sprite->mapbuffer, 2);
	ft_strncpy(sprite->mapbuffer, floor[floor->currentstair].new
		[(int)nextposy][(int)nextposx] + SPRITE, 2);
	floor[floor->currentstair].new
		[(int)nextposy][(int)nextposx][SPRITE] = '6';
}

void			enemy_idle(t_elem *floor, t_sprite *sprite)
{
	if (!sprite->idle)
		sprite->state = 0;
	if (!sprite->idle && !sprite->timer_idle)
		sprite->timer_idle = SDL_AddTimer(1000, timer_idle, (void*)sprite);
	else if (sprite->idle)
	{
		if (!try_move(&floor[floor->currentstair], sprite,
		floor->sprites_data[sprite->type].speed))
			rotate_enemy(sprite);
	}
}
