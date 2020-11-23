/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:09:55 by niboute           #+#    #+#             */
/*   Updated: 2020/10/18 06:04:45 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	draw_map(t_editor *data, uint8_t access)
{
	int	i;
	int	j;

	i = 0;
	data->draw_only = access;
	while (i < data->map.size)
	{
		j = 0;
		while (j < data->map.size)
		{
			place_block_pos(data, &data->map.blocks[i][j], i, j);
			j++;
		}
		i++;
	}
	data->draw_only = 0;
}

void	render_map(t_editor *data, t_sdl_data *win, SDL_Rect dst)
{
	if (data->current_menu == OPTIONS_MENU)
		return ;
	dst.x = data->win.map_texture.rect.x;
	dst.y = data->win.map_texture.rect.y;
	if (dst.x >= win->map_res.w || dst.x + dst.w < 0 || dst.y >= win->win_res.h
		|| dst.y + dst.h < 0)
		return ;
	SDL_RenderCopy(win->renderer, win->map_texture.texture, NULL, &dst);
}
