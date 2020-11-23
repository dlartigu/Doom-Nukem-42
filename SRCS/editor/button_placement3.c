/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_placement3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:15:47 by niboute           #+#    #+#             */
/*   Updated: 2020/10/14 09:14:34 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	set_menu_texture_rects_p2(t_editor *data, int nb_textures,
		int texture_size, SDL_Rect *dest)
{
	int			nb_col;
	int			i;

	nb_col = data->win.menu_res.w / (texture_size / 2 + 2)
		- (data->win.menu_res.w % (texture_size / 2 + 2) <= 2 ? 1 : 0);
	dest->h = texture_size / 2 + 2;
	dest->y += 2;
	i = 0;
	while (i < nb_textures)
	{
		data->scroll_rects[i].w = texture_size;
		data->scroll_rects[i].h = texture_size;
		center_rect_middle(&data->scroll_rects[i], dest, i % nb_col + 1,
							nb_col);
		i++;
		if (i % nb_col == 0)
			dest->y += texture_size / 2 + 2;
	}
}

void	set_menu_textures_rects(t_editor *data, int nb_textures,
			int texture_size)
{
	SDL_Rect	dest;
	t_menu		*menu;

	data->nb_scroll_rects = nb_textures;
	dest.x = data->win.menu_res.x;
	menu = &data->menus[data->current_menu];
	dest.y = menu->buttons_pos[menu->nb_buttons - 1].y
		+ menu->buttons_pos[menu->nb_buttons - 1].h;
	dest.w = data->win.menu_res.w;
	set_menu_texture_rects_p2(data, nb_textures, texture_size, &dest);
}
