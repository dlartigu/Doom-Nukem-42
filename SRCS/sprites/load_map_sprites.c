/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:06:25 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 18:50:48 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

t_sprite		*set_sprite_type_p2(t_sprite *sprite, char *type)
{
	if (type[0] == '6')
	{
		if (type[1] == '1')
			sprite->type = ENEMY_1;
		else if (type[1] == '2')
			sprite->type = ENEMY_2;
		else if (type[1] == '3')
			sprite->type = ENEMY_3;
		else if (type[1] == '4')
			sprite->type = ENEMY_4;
		else if (type[1] == '5')
			sprite->type = ENEMY_BOSS;
		sprite->wave = type[3] - '0';
	}
	else if (type[0] == '7')
		sprite->type = WARP_TO_WARP;
	else if (type[0] == '8')
		sprite->type = WARP_NXT_FLOOR;
	else
	{
		ft_memdel((void**)&sprite);
		return (NULL);
	}
	return (sprite);
}

t_sprite		*set_sprite_type(t_sprite *sprite, char *type)
{
	if (type[0] == '2')
	{
		if (type[1] == '1')
			sprite->type = MEDKIT_10;
		else if (type[1] == '2')
			sprite->type = MEDKIT_20;
		else if (type[1] == '3')
			sprite->type = MEDKIT_50;
		else if (type[1] == '4')
			sprite->type = PISTOL;
		else if (type[1] == '5')
			sprite->type = SHOTGUN;
		else if (type[1] == '6')
			sprite->type = DEVASTATOR;
		else if (type[1] == '7')
			sprite->type = PISTOL_AMMO;
		else if (type[1] == '8')
			sprite->type = SHOTGUN_AMMO;
		else if (type[1] == '9')
			sprite->type = DEVASTATOR_AMMO;
	}
	else
		return (set_sprite_type_p2(sprite, type));
	return (sprite);
}

void			set_sprite_dir_p2(t_elem *floor, t_sprite *sprite, int y, int x)
{
	if (floor[floor->currentstair].new[y][x + 1][WALL] == '1'
	&& floor[floor->currentstair].new[y][x][WALL] == '0')
	{
		sprite->dirx = 1;
		sprite->diry = 0;
	}
	if (sprite->type == TORCH)
	{
		if (sprite->diry == 0)
			sprite->posy = y + 0.5;
		else
			sprite->posy = y + (sprite->diry == -1 ? 0.10 : 0.90);
		if (sprite->dirx == 0)
			sprite->posx = x + 0.5;
		else
			sprite->posx = x + (sprite->dirx == -1 ? 0.10 : 0.90);
	}
	else
	{
		sprite->posx = x + 0.5;
		sprite->posy = y + 0.5;
	}
}

void			set_sprite_dir(t_sprite *sprite, t_elem *floor, int y,
				int x)
{
	if (sprite->type >= ENEMY_1 && sprite->type <= ENEMY_BOSS)
	{
		floor[floor->currentstair].new[y][x][SPRITE] = '0';
		floor[floor->currentstair].new[y][x][SPRITE + 1] = '0';
	}
	if (!sprite)
		return ;
	sprite->diry = 1;
	sprite->dirx = 0;
	if (floor[floor->currentstair].new[y - 1][x][WALL] == '1'
	&& floor[floor->currentstair].new[y][x][WALL] == '0')
	{
		sprite->diry = -1;
		sprite->dirx = 0;
	}
	else if (floor[floor->currentstair].new[y][x - 1][WALL] == '1'
	&& floor[floor->currentstair].new[y][x][WALL] == '0')
	{
		sprite->dirx = -1;
		sprite->diry = 0;
	}
	set_sprite_dir_p2(floor, sprite, y, x);
}

void			load_map_sprites(t_env *env, t_elem *floor)
{
	int			y;
	int			x;
	t_sprite	*sprite;

	y = 0;
	while (++y < floor[floor->currentstair].hight - 2)
	{
		x = 0;
		while (++x < floor[floor->currentstair].width - 2)
		{
			if (floor[floor->currentstair].new[y][x][WALL] == '0')
			{
				if (floor[floor->currentstair].new[y][x][SPRITE] > '0'
				&& floor[floor->currentstair].new[y][x][SPRITE] < '9')
				{
					sprite = add_sprite(env, floor,
						floor[floor->currentstair].new[y][x] + SPRITE);
					set_sprite_dir(sprite, floor, y, x);
				}
			}
		}
	}
	update_enemies(floor);
}
