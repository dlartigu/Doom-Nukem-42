/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:58:49 by niboute           #+#    #+#             */
/*   Updated: 2020/11/25 17:56:11 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	init_sprites_data_p8(t_sprite_data *sprites_data)
{
	sprites_data[ENEMY_3_PROJECTILE].hscale = 0.2;
	sprites_data[ENEMY_3_PROJECTILE].wscale = 0.2;
	sprites_data[ENEMY_3_PROJECTILE].grounded = 0;
	sprites_data[ENEMY_3_PROJECTILE].max_dir = 1;
	sprites_data[ENEMY_3_PROJECTILE].max_anims = 1;
	sprites_data[ENEMY_3_PROJECTILE].speed = 0.125;
	sprites_data[ENEMY_4_PROJECTILE].hscale = 0.4;
	sprites_data[ENEMY_4_PROJECTILE].wscale = 0.4;
	sprites_data[ENEMY_4_PROJECTILE].grounded = 0;
	sprites_data[ENEMY_4_PROJECTILE].max_dir = 1;
	sprites_data[ENEMY_4_PROJECTILE].max_anims = 1;
	sprites_data[ENEMY_4_PROJECTILE].speed = 0.25;
	sprites_data[ENEMY_BOSS_PROJECTILE].hscale = 0.8;
	sprites_data[ENEMY_BOSS_PROJECTILE].wscale = 0.8;
	sprites_data[ENEMY_BOSS_PROJECTILE].grounded = 0;
	sprites_data[ENEMY_BOSS_PROJECTILE].max_dir = 1;
	sprites_data[ENEMY_BOSS_PROJECTILE].max_anims = 1;
	sprites_data[ENEMY_BOSS_PROJECTILE].speed = 0.2;
}

void	init_sprites_data_p7(t_sprite_data *sprites_data)
{
	sprites_data[ENEMY_BOSS].max_hp = 5000;
	sprites_data[ENEMY_BOSS].range = 100;
	sprites_data[ENEMY_BOSS].sight = 100;
	sprites_data[ENEMY_DEAD_BOSS].hscale = 3;
	sprites_data[ENEMY_DEAD_BOSS].wscale = 3;
	sprites_data[ENEMY_DEAD_BOSS].grounded = -2;
	sprites_data[ENEMY_DEAD_BOSS].max_dir = 1;
	sprites_data[ENEMY_DEAD_BOSS].max_anims = 8;
	sprites_data[WARP_NXT_FLOOR].hscale = 0.5;
	sprites_data[WARP_NXT_FLOOR].wscale = 0.5;
	sprites_data[WARP_NXT_FLOOR].grounded = 0;
	sprites_data[WARP_NXT_FLOOR].max_dir = 1;
	sprites_data[WARP_NXT_FLOOR].max_anims = 23;
	sprites_data[WARP_TO_WARP].hscale = 1;
	sprites_data[WARP_TO_WARP].wscale = 1;
	sprites_data[WARP_TO_WARP].grounded = 0;
	sprites_data[WARP_TO_WARP].max_dir = 1;
	sprites_data[WARP_TO_WARP].max_anims = 12;
	sprites_data[EXPLOSION].hscale = 1;
	sprites_data[EXPLOSION].wscale = 1;
	sprites_data[EXPLOSION].grounded = 0;
	sprites_data[EXPLOSION].max_dir = 1;
	sprites_data[EXPLOSION].max_anims = 5;
	init_sprites_data_p8(sprites_data);
}

void	init_sprites_data_p6(t_sprite_data *sprites_data)
{
	sprites_data[ENEMY_DEAD_3].hscale = 1;
	sprites_data[ENEMY_DEAD_3].wscale = 0.75;
	sprites_data[ENEMY_DEAD_3].grounded = 0.25;
	sprites_data[ENEMY_DEAD_3].max_dir = 1;
	sprites_data[ENEMY_DEAD_3].max_anims = 9;
	sprites_data[ENEMY_4].hscale = 0.85;
	sprites_data[ENEMY_4].wscale = 0.85;
	sprites_data[ENEMY_4].grounded = -0.2;
	sprites_data[ENEMY_4].max_dir = 8;
	sprites_data[ENEMY_4].max_anims = 7;
	sprites_data[ENEMY_4].max_hp = 400;
	sprites_data[ENEMY_4].range = 6;
	sprites_data[ENEMY_4].sight = 12;
	sprites_data[ENEMY_4].speed = 3;
	sprites_data[ENEMY_DEAD_4].hscale = 0.85;
	sprites_data[ENEMY_DEAD_4].wscale = 0.85;
	sprites_data[ENEMY_DEAD_4].grounded = 0.6;
	sprites_data[ENEMY_DEAD_4].max_dir = 1;
	sprites_data[ENEMY_DEAD_4].max_anims = 9;
	sprites_data[ENEMY_BOSS].hscale = 3;
	sprites_data[ENEMY_BOSS].wscale = 3;
	sprites_data[ENEMY_BOSS].grounded = -2;
	sprites_data[ENEMY_BOSS].max_dir = 1;
	sprites_data[ENEMY_BOSS].max_anims = 8;
	init_sprites_data_p7(sprites_data);
}
