/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:07:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:37:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"
#include "../../INCLUDES/prog.h"

int	load_items_p2(t_editor *data)
{
	if (!load_bmp(data->win.renderer, SPR_AMMO_PISTOL, &data->item_text[11], 1))
		return (ft_printerror("ERROR: couldn't load bmp(12)."));
	if (!load_bmp(data->win.renderer, SPR_AMMO_SHOTGUN, &data->item_text[12],
		1))
		return (ft_printerror("ERROR: couldn't load bmp(13)."));
	if (!load_bmp(data->win.renderer, SPR_AMMO_DEVAST, &data->item_text[13], 1))
		return (ft_printerror("ERROR: couldn't load bmp(14)."));
	if (!load_bmp(data->win.renderer, WARP_TO_WARP_1, &data->item_text[14], 1))
		return (ft_printerror("ERROR: couldn't load bmp(16)."));
	return (1);
}

int	load_items(t_editor *data)
{
	if (!load_bmp(data->win.renderer, SPR_TORCH_F_OFF, &data->item_text[0], 1))
		return (ft_printerror("ERROR: couldn't load bmp(1)."));
	if (!load_bmp(data->win.renderer, SPR_TORCH_F_ON1, &data->item_text[1], 1))
		return (ft_printerror("ERROR: couldn't load bmp(2)."));
	if (!load_bmp(data->win.renderer, BALLON_ON, &data->item_text[2], 1))
		return (ft_printerror("ERROR: couldn't load bmp(3)."));
	if (!load_bmp(data->win.renderer, LOLLIPOP_ON, &data->item_text[3], 1))
		return (ft_printerror("ERROR: couldn't load bmp(4)."));
	if (!load_bmp(data->win.renderer, TICKET_ON, &data->item_text[4], 1))
		return (ft_printerror("ERROR: couldn't load bmp(5)."));
	if (!load_bmp(data->win.renderer, SPR_MEDKIT_10_1, &data->item_text[5], 1))
		return (ft_printerror("ERROR: couldn't load bmp(6)."));
	if (!load_bmp(data->win.renderer, SPR_MEDKIT_20_1, &data->item_text[6], 1))
		return (ft_printerror("ERROR: couldn't load bmp(7)."));
	if (!load_bmp(data->win.renderer, SPR_MEDKIT_50_1, &data->item_text[7], 1))
		return (ft_printerror("ERROR: couldn't load bmp(8)."));
	if (!load_bmp(data->win.renderer, SPR_PISTOL, &data->item_text[8], 1))
		return (ft_printerror("ERROR: couldn't load bmp(9)."));
	if (!load_bmp(data->win.renderer, SPR_SHOTGUN, &data->item_text[9], 1))
		return (ft_printerror("ERROR: couldn't load bmp(10)."));
	if (!load_bmp(data->win.renderer, SPR_DEVASTATOR, &data->item_text[10], 1))
		return (ft_printerror("ERROR: couldn't load bmp(11)."));
	return (load_items_p2(data));
}

int	load_sprites(t_editor *data)
{
	if (!load_bmp(data->win.renderer, SPR_ENMY1_F_1, &data->enemy_text[0], 1))
		return (ft_printerror("ERROR: couldn't load bmp(12)."));
	if (!load_bmp(data->win.renderer, SPR_ENMY_2_F_1, &data->enemy_text[1], 1))
		return (ft_printerror("ERROR: couldn't load bmp(13)."));
	if (!load_bmp(data->win.renderer, SPR_ENMY_3_F_1, &data->enemy_text[2], 1))
		return (ft_printerror("ERROR: couldn't load bmp(14)."));
	if (!load_bmp(data->win.renderer, SPR_ENMY_4_F_1, &data->enemy_text[3], 1))
		return (ft_printerror("ERROR: couldn't load bmp(15)."));
	if (!load_bmp(data->win.renderer, SPR_BOSS_1, &data->enemy_text[4], 1))
		return (ft_printerror("ERROR: couldn't load bmp(16)."));
	return (1);
}
