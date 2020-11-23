/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_textures5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:03:18 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:58:59 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	load_sprites_textures_p21(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_R_7);
	load_sprites_textures_p22(floor, i);
}

void	load_sprites_textures_p22(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_DEAD_9);
	load_sprites_textures_p23(floor, i);
}

void	load_sprites_textures_p23(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_1);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_2);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_3);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_4);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_5);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_6);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_7);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_8);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_1);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_2);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_3);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_4);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_5);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_6);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_7);
	floor->sprites[i++] = ft_load_texture(SPR_BOSS_DEAD_8);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_ENEMY_3);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_ENEMY_4);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_ENEMY_BOSS);
}
