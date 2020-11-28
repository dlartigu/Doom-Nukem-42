/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:32:52 by niboute           #+#    #+#             */
/*   Updated: 2020/11/26 14:55:00 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void				set_sprite_dist(t_env *env, t_elem *floor,
						t_sprite *sprite, int *i)
{
	double	dist;

	dist = (floor->posx - sprite->posx) * (floor->posx - sprite->posx)
	+ (floor->posy - sprite->posy) * (floor->posy - sprite->posy);
	if (fabs(dist) > 0.0001)
	{
		env->spriteorder[*i] = sprite;
		env->spritedistance[*i] = dist;
		sprite->dist = dist;
		(*i)++;
	}
}

static void				store_projectiles(t_env *env, t_elem *floor, int *i)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = floor->projectiles;
	while (ptr)
	{
		if (((t_sprite*)ptr->content)->hp == -1)
		{
			tmp = ptr->next;
			remove_sprite(&floor->projectiles, (t_sprite*)ptr->content);
			ptr = tmp;
		}
		else if (ptr)
		{
			if (((t_sprite*)ptr->content)->hp != 0)
				set_sprite_dist(env, floor, (t_sprite*)ptr->content, i);
			ptr = ptr->next;
		}
	}
}

static void				store_enemies(t_env *env, t_elem *floor, int *i)
{
	t_list	*ptr;
	t_list	*tmp;
	int		j;
	int		k;

	ptr = floor->enemies;
	j = 0;
	k = 0;
	while (ptr)
	{
		if (((t_sprite*)ptr->content)->hp == 0 && ((t_sprite*)ptr->content)
		->type >= ENEMY_1 && ((t_sprite*)ptr->content)->type <= ENEMY_BOSS)
		{
			tmp = ptr->next;
			killed_enemy(floor, (t_sprite *)ptr->content);
			ptr = tmp;
		}
		else if (ptr)
		{
			if (((t_sprite*)ptr->content)->wave <= floor->fire_stat)
				set_sprite_dist(env, floor, (t_sprite*)ptr->content, i);
			ptr = ptr->next;
			k++;
		}
	}
}

void					store_sprites(t_env *env, t_elem *floor)
{
	t_list	*ptr;
	int		i;

	i = 0;
	(void)floor;
	ptr = floor->items;
	floor->nb_sprites = 0;
	ft_bzero((void*)env->spriteorder, 4096 * sizeof(t_sprite*));
	ft_bzero((void*)env->spritedistance, 4096 * sizeof(double));
	while (ptr)
	{
		set_sprite_dist(env, floor, (t_sprite*)ptr->content, &i);
		ptr = ptr->next;
	}
	store_enemies(env, floor, &i);
	store_projectiles(env, floor, &i);
	floor->nb_sprites = i;
}
