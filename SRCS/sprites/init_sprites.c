/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:33:07 by niboute           #+#    #+#             */
/*   Updated: 2020/11/25 17:49:13 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	init_sprites_data_p5(t_sprite_data *sprites_data)
{
	sprites_data[ENEMY_2].max_anims = 20;
	sprites_data[ENEMY_2].max_hp = 200;
	sprites_data[ENEMY_2].range = 1;
	sprites_data[ENEMY_2].sight = 9;
	sprites_data[ENEMY_2].speed = 4;
	sprites_data[ENEMY_DEAD_2].hscale = 0.8;
	sprites_data[ENEMY_DEAD_2].wscale = 0.8;
	sprites_data[ENEMY_DEAD_2].grounded = 1;
	sprites_data[ENEMY_DEAD_2].max_dir = 8;
	sprites_data[ENEMY_DEAD_2].max_anims = 9;
	sprites_data[ENEMY_3].hscale = 1;
	sprites_data[ENEMY_3].wscale = 0.75;
	sprites_data[ENEMY_3].grounded = 0;
	sprites_data[ENEMY_3].max_dir = 8;
	sprites_data[ENEMY_3].max_anims = 7;
	sprites_data[ENEMY_3].max_hp = 300;
	sprites_data[ENEMY_3].range = 4;
	sprites_data[ENEMY_3].sight = 9;
	sprites_data[ENEMY_3].speed = 2;
	init_sprites_data_p6(sprites_data);
}

void	init_sprites_data_p4(t_sprite_data *sprites_data)
{
	sprites_data[DEVASTATOR_PROJECTILE].wscale = 0.5;
	sprites_data[DEVASTATOR_PROJECTILE].max_dir = 8;
	sprites_data[DEVASTATOR_PROJECTILE].max_anims = 1;
	sprites_data[DEVASTATOR_PROJECTILE].speed = 0.2;
	sprites_data[DEVASTATOR_PROJECTILE].range = 2;
	sprites_data[DEVASTATOR_PROJECTILE].max_hp = 5000;
	sprites_data[ENEMY_1].hscale = 0.4;
	sprites_data[ENEMY_1].wscale = 0.4;
	sprites_data[ENEMY_1].grounded = 0;
	sprites_data[ENEMY_1].max_dir = 8;
	sprites_data[ENEMY_1].max_anims = 5;
	sprites_data[ENEMY_1].max_hp = 100;
	sprites_data[ENEMY_1].range = 2;
	sprites_data[ENEMY_1].sight = 4;
	sprites_data[ENEMY_1].speed = 0.7;
	sprites_data[ENEMY_DEAD_1].hscale = 0.4;
	sprites_data[ENEMY_DEAD_1].wscale = 0.4;
	sprites_data[ENEMY_DEAD_1].grounded = 0.3;
	sprites_data[ENEMY_DEAD_1].max_dir = 1;
	sprites_data[ENEMY_DEAD_1].max_anims = 7;
	sprites_data[ENEMY_2].hscale = 0.8;
	sprites_data[ENEMY_2].wscale = 0.8;
	sprites_data[ENEMY_2].grounded = 1;
	sprites_data[ENEMY_2].max_dir = 8;
	init_sprites_data_p5(sprites_data);
}

void	init_sprites_data_p3(t_sprite_data *sprites_data)
{
	sprites_data[SHOTGUN].max_anims = 1;
	sprites_data[DEVASTATOR].hscale = 0.35;
	sprites_data[DEVASTATOR].wscale = 0.7;
	sprites_data[DEVASTATOR].grounded = 0.3;
	sprites_data[DEVASTATOR].max_dir = 1;
	sprites_data[DEVASTATOR].max_anims = 1;
	sprites_data[PISTOL_AMMO].hscale = 0.2;
	sprites_data[PISTOL_AMMO].wscale = 0.2;
	sprites_data[PISTOL_AMMO].grounded = 0.4;
	sprites_data[PISTOL_AMMO].max_dir = 1;
	sprites_data[PISTOL_AMMO].max_anims = 1;
	sprites_data[SHOTGUN_AMMO].hscale = 0.15;
	sprites_data[SHOTGUN_AMMO].wscale = 0.15;
	sprites_data[SHOTGUN_AMMO].grounded = 0.4;
	sprites_data[SHOTGUN_AMMO].max_dir = 1;
	sprites_data[SHOTGUN_AMMO].max_anims = 1;
	sprites_data[DEVASTATOR_AMMO].hscale = 0.3;
	sprites_data[DEVASTATOR_AMMO].wscale = 0.3;
	sprites_data[DEVASTATOR_AMMO].grounded = 0.4;
	sprites_data[DEVASTATOR_AMMO].max_dir = 1;
	sprites_data[DEVASTATOR_AMMO].max_anims = 1;
	sprites_data[DEVASTATOR_PROJECTILE].hscale = 0.5;
	init_sprites_data_p4(sprites_data);
}

void	init_sprites_data_p2(t_sprite_data *sprites_data)
{
	sprites_data[MEDKIT_20].hscale = 0.2;
	sprites_data[MEDKIT_20].wscale = 0.2;
	sprites_data[MEDKIT_20].grounded = 0.4;
	sprites_data[MEDKIT_20].max_dir = 2;
	sprites_data[MEDKIT_20].max_anims = 1;
	sprites_data[MEDKIT_50].hscale = 0.35;
	sprites_data[MEDKIT_50].wscale = 0.35;
	sprites_data[MEDKIT_50].grounded = 0.3;
	sprites_data[MEDKIT_50].max_dir = 1;
	sprites_data[MEDKIT_50].max_anims = 2;
	sprites_data[TORCH].hscale = 0.5;
	sprites_data[TORCH].wscale = 0.5;
	sprites_data[TORCH].grounded = 0;
	sprites_data[TORCH].max_dir = 4;
	sprites_data[TORCH].max_anims = 7;
	sprites_data[PISTOL].hscale = 0.25;
	sprites_data[PISTOL].wscale = 0.25;
	sprites_data[PISTOL].grounded = 0.4;
	sprites_data[PISTOL].max_dir = 1;
	sprites_data[PISTOL].max_anims = 1;
	sprites_data[SHOTGUN].hscale = 0.3;
	sprites_data[SHOTGUN].wscale = 0.3;
	sprites_data[SHOTGUN].grounded = 0.4;
	sprites_data[SHOTGUN].max_dir = 1;
	init_sprites_data_p3(sprites_data);
}

void	init_sprites_data(t_sprite_data *sprites_data)
{
	sprites_data[BALLOON].hscale = 0.3;
	sprites_data[BALLOON].wscale = 0.3;
	sprites_data[BALLOON].grounded = 0;
	sprites_data[BALLOON].max_dir = 1;
	sprites_data[BALLOON].max_anims = 1;
	sprites_data[LOLLIPOP].hscale = 0.25;
	sprites_data[LOLLIPOP].wscale = 0.25;
	sprites_data[LOLLIPOP].grounded = 0.5;
	sprites_data[LOLLIPOP].max_dir = 1;
	sprites_data[LOLLIPOP].max_anims = 1;
	sprites_data[TICKET].hscale = 0.25;
	sprites_data[TICKET].wscale = 0.25;
	sprites_data[TICKET].grounded = 0.25;
	sprites_data[TICKET].max_dir = 1;
	sprites_data[TICKET].max_anims = 1;
	sprites_data[MEDKIT_10].hscale = 0.10;
	sprites_data[MEDKIT_10].wscale = 0.10;
	sprites_data[MEDKIT_10].grounded = 0.4;
	sprites_data[MEDKIT_10].max_dir = 4;
	sprites_data[MEDKIT_10].max_anims = 1;
	init_sprites_data_p2(sprites_data);
	set_sprites_texture_ids(sprites_data);
}
