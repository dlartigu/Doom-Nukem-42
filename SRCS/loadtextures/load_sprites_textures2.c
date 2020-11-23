/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_textures2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:45:58 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:56:32 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	load_sprites_textures_p6(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_B_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_R_4);
	load_sprites_textures_p7(floor, i);
}

void	load_sprites_textures_p7(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_DEAD_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_16);
	load_sprites_textures_p8(floor, i);
}

void	load_sprites_textures_p8(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_F_L_20);
	load_sprites_textures_p9(floor, i);
}

void	load_sprites_textures_p9(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_L_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_3);
	load_sprites_textures_p10(floor, i);
}

void	load_sprites_textures_p10(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_10);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_11);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_12);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_13);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_14);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_15);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_16);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_17);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_18);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_19);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_L_20);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_B_6);
	load_sprites_textures_p11(floor, i);
}
