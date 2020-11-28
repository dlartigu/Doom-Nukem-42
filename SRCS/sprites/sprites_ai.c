/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:04:40 by niboute           #+#    #+#             */
/*   Updated: 2020/11/25 17:37:42 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				sight_hit(t_elem *floor, t_ray *ray)
{
	char			*str;

	str = floor[floor->currentstair].new[(int)ray->mapy][(int)ray->mapx];
	if ((int)ray->mapy == (int)floor->posy
		&& (int)ray->mapx == (int)floor->posx)
		ray->hit = 1;
	if (str[WALL] == '1' || str[SPRITE] >= '6')
		ray->hit = 2;
	else if (str[0] == '4')
		ray->windows_hit++;
}

int					check_sprite_move(char ***map, t_sprite *sprite,
					double *next, double *hbox)
{
	if (map[(int)sprite->posy][(int)next[0]][WALL] != '0')
		return (0);
	if (map[(int)sprite->posy][(int)(next[0] + hbox[0])][WALL] != '0')
		return (0);
	if (map[(int)next[1]][(int)(sprite->posx)][WALL] != '0')
		return (0);
	if (map[(int)(next[1] + hbox[1])][(int)(sprite->posx)][WALL] != '0')
		return (0);
	if (map[(int)next[1]][(int)next[0]][WALL] != '0')
		return (0);
	if (map[(int)(next[1] + hbox[1])][(int)(next[0] + hbox[0])][WALL] != '0')
		return (0);
	if (((int)sprite->posx != (int)next[0] || (int)sprite->posy != (int)next[1])
	&& map[(int)next[1]][(int)next[0]][SPRITE] >= '6')
		return (0);
	return (1);
}

int					try_move(t_elem *floor, t_sprite *sprite, double speed)
{
	double			next[2];
	double			hitbox[2];

	next[0] = sprite->posx + sprite->dirx * speed * 0.02;
	next[1] = sprite->posy + sprite->diry * speed * 0.02;
	hitbox[0] = 0;
	if (sprite->dirx)
		hitbox[0] = sprite->dirx > 0 ? 0.4 : -0.4;
	hitbox[1] = 0;
	if (sprite->diry)
		hitbox[1] = sprite->diry > 0 ? 0.4 : -0.4;
	if (!check_sprite_move(floor[floor->currentstair].new, sprite, &next[0],
	&hitbox[0]))
		return (0);
	if ((int)sprite->posx != (int)next[0] || (int)sprite->posy != (int)next[1])
		place_sprite_hitbox(floor, sprite, next[1], next[0]);
	sprite->posx = next[0];
	sprite->posy = next[1];
	return (1);
}

void				rotate_enemy(t_sprite *sprite)
{
	int				angle;
	double			fangle;

	angle = (int)(((atan2(sprite->diry, sprite->dirx) + M_PI) * 180) / M_PI);
	fangle = ((((1 + (angle / 90)) * 90) % 360) * M_PI) / 180;
	sprite->dirx = cos(fangle);
	sprite->diry = sin(fangle);
}

void				handle_enemies(t_env *env, t_elem *floor)
{
	t_list			*ptr;
	int				ret;

	ptr = floor->enemies;
	while (ptr)
	{
		ret = check_enemy(env, floor, (t_sprite*)ptr->content);
		if (ret == 1 || ret == 2)
			enemy_action(floor, (t_sprite*)ptr->content, ret);
		else if (ret == 0)
			enemy_idle(floor, (t_sprite*)ptr->content);
		ptr = ptr->next;
	}
}
