/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:29:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/13 20:09:42 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				init_sprite_timer(t_sprite *sprite)
{
	if (sprite->type == TORCH)
		sprite->timer = SDL_AddTimer(150, torch_anim, (void*)sprite);
	else if (sprite->type == ENEMY_1)
		sprite->timer = SDL_AddTimer(150, enemy1_anim, (void*)sprite);
	else if (sprite->type == ENEMY_2)
		sprite->timer = SDL_AddTimer(150, enemy2_anim, (void*)sprite);
	else if (sprite->type == ENEMY_3)
		sprite->timer = SDL_AddTimer(225, enemy3_anim, (void*)sprite);
	else if (sprite->type == ENEMY_4)
		sprite->timer = SDL_AddTimer(325, enemy4_anim, (void*)sprite);
	else if (sprite->type == ENEMY_BOSS)
		sprite->timer = SDL_AddTimer(150, boss_anim, (void*)sprite);
	else if (sprite->type == WARP_TO_WARP)
		sprite->timer = SDL_AddTimer(150, warptowarp_anim, (void*)sprite);
	else if (sprite->type == WARP_NXT_FLOOR)
		sprite->timer = SDL_AddTimer(150, warpfloor_anim, (void*)sprite);
}

void				init_sprite(t_elem *floor, t_sprite *sprite)
{
	t_list			*ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		ft_fct_error("init_sprite");
	ptr->content = sprite;
	if (sprite->type < DEVASTATOR_PROJECTILE)
		ft_lstadd(&floor->items, ptr);
	else if (sprite->type < ENEMY_1)
	{
		sprite->hp = 0;
		ft_lstadd(&floor->projectiles, ptr);
	}
	else
	{
		sprite->hp = floor->sprites_data[sprite->type].max_hp;
		ft_lstadd(&floor->enemies, ptr);
	}
	ft_strcpy(sprite->mapbuffer, "00");
	init_sprite_timer(sprite);
}

t_sprite			*add_sprite(t_env *env, t_elem *floor, char *type)
{
	t_sprite	*sprite;

	if (!(sprite = (t_sprite*)ft_memalloc(sizeof(t_sprite))))
		ft_fct_error("add_sprite(1)");
	sprite->env = env;
	sprite->floor = floor;
	if (type[0] == '1')
	{
		sprite->type = TORCH;
		sprite->state = type[1] - '0';
	}
	else if (type[0] == '3')
		sprite->type = BALLOON;
	else if (type[0] == '4')
		sprite->type = LOLLIPOP;
	else if (type[0] == '5')
		sprite->type = TICKET;
	else
		set_sprite_type(sprite, type);
	init_sprite(floor, sprite);
	return (sprite);
}
