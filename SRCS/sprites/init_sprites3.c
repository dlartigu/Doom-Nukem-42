/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:59:16 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:11:36 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	set_sprites_texture_ids_p5(t_sprite_data *sprites_data, int i)
{
	int	j;
	int k;

	j = -1;
	while (++j < 9)
		sprites_data[ENEMY_DEAD_3].texid[0][j] = i++;
	j = -1;
	while (++j < 8)
	{
		k = -1;
		while (++k < 7)
			sprites_data[ENEMY_4].texid[j][k] = i++;
	}
	j = -1;
	while (++j < 9)
		sprites_data[ENEMY_DEAD_4].texid[0][j] = i++;
	j = -1;
	while (++j < 8)
		sprites_data[ENEMY_BOSS].texid[0][j] = i++;
	j = -1;
	while (++j < 8)
		sprites_data[ENEMY_DEAD_BOSS].texid[0][j] = i++;
	sprites_data[ENEMY_3_PROJECTILE].texid[0][0] = i++;
	sprites_data[ENEMY_4_PROJECTILE].texid[0][0] = i++;
	sprites_data[ENEMY_BOSS_PROJECTILE].texid[0][0] = i++;
}

void	set_sprites_texture_ids_p4(t_sprite_data *sprites_data, int i)
{
	int	j;
	int	k;

	j = -1;
	while (++j < 8)
	{
		k = -1;
		while (++k < 20)
			sprites_data[ENEMY_2].texid[j][k] = i++;
	}
	j = -1;
	while (++j < 8)
	{
		k = -1;
		while (++k < 9)
			sprites_data[ENEMY_DEAD_2].texid[j][k] = i++;
	}
	j = -1;
	while (++j < 8)
	{
		k = -1;
		while (++k < 7)
			sprites_data[ENEMY_3].texid[j][k] = i++;
	}
	set_sprites_texture_ids_p5(sprites_data, i);
}

void	set_sprites_texture_ids_p3(t_sprite_data *sprites_data, int i, int j)
{
	int	k;

	while (++j < 23)
		sprites_data[WARP_NXT_FLOOR].texid[0][j] = i++;
	j = -1;
	while (++j < 12)
		sprites_data[WARP_TO_WARP].texid[0][j] = i++;
	j = -1;
	while (++j < 8)
		sprites_data[DEVASTATOR_PROJECTILE].texid[j][0] = i++;
	j = -1;
	while (++j < 5)
		sprites_data[EXPLOSION].texid[0][j] = i++;
	j = -1;
	while (++j < 8)
	{
		k = -1;
		while (++k < 5)
			sprites_data[ENEMY_1].texid[j][k] = i++;
	}
	j = -1;
	while (++j < 7)
		sprites_data[ENEMY_DEAD_1].texid[0][j] = i++;
	set_sprites_texture_ids_p4(sprites_data, i);
}

void	set_sprites_texture_ids_p2(t_sprite_data *sprites_data, int i)
{
	int	j;
	int	k;

	j = -1;
	while (++j < 4)
		sprites_data[MEDKIT_10].texid[j][0] = i++;
	j = -1;
	while (++j < 2)
		sprites_data[MEDKIT_20].texid[j][0] = i++;
	j = -1;
	while (++j < 2)
		sprites_data[MEDKIT_50].texid[0][j] = i++;
	j = -1;
	while (++j < 4)
	{
		k = -1;
		while (j != 2 && ++k < 7)
			sprites_data[TORCH].texid[j][k] = i++;
	}
	ft_memcpy((void*)sprites_data[TORCH].texid[2],
		(void*)sprites_data[TORCH].texid[0], sizeof(int) * 7);
	j = PISTOL - 1;
	while (++j < WARP_NXT_FLOOR)
		sprites_data[j].texid[0][0] = i++;
	set_sprites_texture_ids_p3(sprites_data, i, -1);
}

void	set_sprites_texture_ids(t_sprite_data *sprites_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < NB_SPRITE_TYPES)
	{
		if (!(sprites_data[i].texid = (int**)ft_memalloc(sizeof(int*)
		* sprites_data[i].max_dir)))
			ft_fct_error("set_sprites_texture_ids(0)");
		j = 0;
		while (j < sprites_data[i].max_dir)
		{
			if (!(sprites_data[i].texid[j] = (int*)ft_memalloc(sizeof(int)
			* sprites_data[i].max_anims)))
				ft_fct_error("set_sprites_texture_ids(0)");
			j++;
		}
		i++;
	}
	i = 0;
	sprites_data[BALLOON].texid[0][0] = i++;
	sprites_data[LOLLIPOP].texid[0][0] = i++;
	sprites_data[TICKET].texid[0][0] = i++;
	set_sprites_texture_ids_p2(sprites_data, i);
}
