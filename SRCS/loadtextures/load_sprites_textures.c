/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:03:49 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:55:26 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	load_sprites_textures(t_elem *floor)
{
	int	i;

	if (!(floor->sprites = (SDL_Surface**)ft_memalloc(sizeof(SDL_Surface*)
	* 1000)))
		ft_fct_error("load_sprites_textures");
	i = 0;
	floor->sprites[i++] = ft_load_texture(SPR_BALLOON);
	floor->sprites[i++] = ft_load_texture(SPR_LOLLIPOP);
	floor->sprites[i++] = ft_load_texture(SPR_TICKET);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_10_1);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_10_2);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_10_3);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_10_4);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_20_1);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_20_2);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_50_1);
	floor->sprites[i++] = ft_load_texture(SPR_MEDKIT_50_2);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_OFF);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_ON1);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_ON2);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_ON3);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_ON4);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_ON5);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_F_ON6);
	load_sprites_textures_p2(floor, i);
}

void	load_sprites_textures_p2(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_OFF);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_ON1);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_ON2);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_ON3);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_ON4);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_ON5);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_R_ON6);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_OFF);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_ON1);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_ON2);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_ON3);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_ON4);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_ON5);
	floor->sprites[i++] = ft_load_texture(SPR_TORCH_L_ON6);
	floor->sprites[i++] = ft_load_texture(SPR_PISTOL);
	floor->sprites[i++] = ft_load_texture(SPR_SHOTGUN);
	floor->sprites[i++] = ft_load_texture(SPR_DEVASTATOR);
	floor->sprites[i++] = ft_load_texture(SPR_AMMO_PISTOL);
	floor->sprites[i++] = ft_load_texture(SPR_AMMO_SHOTGUN);
	load_sprites_textures_p3(floor, i);
}

void	load_sprites_textures_p3(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_AMMO_DEVAST);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_1);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_2);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_3);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_4);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_5);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_6);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_7);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_8);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_9);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_10);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_11);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_12);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_13);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_14);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_15);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_16);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_17);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_18);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_19);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_20);
	load_sprites_textures_p4(floor, i);
}

void	load_sprites_textures_p4(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_21);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_22);
	floor->sprites[i++] = ft_load_texture(WARP_NXT_FLOOR_23);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_1);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_2);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_3);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_4);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_5);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_6);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_7);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_8);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_9);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_10);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_11);
	floor->sprites[i++] = ft_load_texture(WARP_TO_WARP_12);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_F);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_F_L);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_L);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_B_L);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_B);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_B_R);
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_R);
	load_sprites_textures_p5(floor, i);
}

void	load_sprites_textures_p5(t_elem *floor, int i)
{
	floor->sprites[i++] = ft_load_texture(SPR_PROJ_DEVAST_F_R);
	floor->sprites[i++] = ft_load_texture(DEV_FIRE_STAT1);
	floor->sprites[i++] = ft_load_texture(DEV_FIRE_STAT2);
	floor->sprites[i++] = ft_load_texture(DEV_FIRE_STAT3);
	floor->sprites[i++] = ft_load_texture(DEV_FIRE_STAT4);
	floor->sprites[i++] = ft_load_texture(DEV_FIRE_STAT5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_F_L_5);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_L_1);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_L_2);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_L_3);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_L_4);
	floor->sprites[i++] = ft_load_texture(SPR_ENMY1_L_5);
	load_sprites_textures_p6(floor, i);
}
