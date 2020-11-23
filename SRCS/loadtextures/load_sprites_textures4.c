/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_textures4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:45:37 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:58:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	load_sprites_textures_p16(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_B_R_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_R_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_7);
	load_sprites_textures_p17(floor, i);
}

void	load_sprites_textures_p17(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_2_DEAD_F_R_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_5);
	load_sprites_textures_p18(floor, i);
}

void	load_sprites_textures_p18(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_B_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_1);
	load_sprites_textures_p19(floor, i);
}

void	load_sprites_textures_p19(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_F_R_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_8);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_3_DEAD_9);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_2);
	load_sprites_textures_p20(floor, i);
}

void	load_sprites_textures_p20(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_F_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_6);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_L_7);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY_4_B_L_5);
	load_sprites_textures_p21(floor, i);
}
