/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:24:20 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:11:42 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	draw_texture_menu_p2(t_editor *data)
{
	int	i;

	if (data->current_menu == ENEMY_TEXTURE_MENU)
	{
		i = 0;
		while (i < MAX_ENEMY_TEXTURES)
			SDL_RenderCopy(data->win.renderer, data->white_text.texture, NULL,
				&data->scroll_rects[i++]);
		draw_menu_textures_rects(data, data->enemy_text, MAX_ENEMY_TEXTURES);
	}
	else if (data->current_menu == ITEM_TEXTURE_MENU)
	{
		i = 0;
		while (i < MAX_ITEM_TEXTURES)
			SDL_RenderCopy(data->win.renderer, data->white_text.texture, NULL,
				&data->scroll_rects[i++]);
		draw_menu_textures_rects(data, data->item_text, MAX_ITEM_TEXTURES);
	}
}

void	draw_texture_menu(t_editor *data)
{
	if (data->current_menu == ENEMY_TEXTURE_MENU)
		set_menu_textures_rects(data, 5, 128);
	else
		set_menu_textures_rects(data, 20, 64);
	if (data->current_menu == WALL_TEXTURE_MENU)
		draw_menu_textures_rects(data, data->wall_text, MAX_WALL_TEXTURES);
	else if (data->current_menu == FLOOR_TEXTURE_MENU)
		draw_menu_textures_rects(data, data->floor_text,
		MAX_FLOOR_TEXTURES);
	else if (data->current_menu == ROOF_TEXTURE_MENU)
		draw_menu_textures_rects(data, data->roof_text,
		MAX_ROOF_TEXTURES);
	else
		draw_texture_menu_p2(data);
}
