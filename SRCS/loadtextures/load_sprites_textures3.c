/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_textures3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:45:51 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:55:51 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	load_sprites_textures_p11(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_10);
	load_sprites_textures_p12(floor, i);
}

void	load_sprites_textures_p12(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_R_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_14);
	load_sprites_textures_p13(floor, i);
}

void	load_sprites_textures_p13(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_R_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_18);
	load_sprites_textures_p14(floor, i);
}

void	load_sprites_textures_p14(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_R_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_L_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_4);
	load_sprites_textures_p15(floor, i);
}

void	load_sprites_textures_p15(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_L_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_L_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_1);
	load_sprites_textures_p16(floor, i);
}
