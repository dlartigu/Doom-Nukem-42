/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:27:54 by niboute           #+#    #+#             */
/*   Updated: 2020/10/18 02:26:21 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	draw_block(t_editor *data, int y, int x, t_sdl_text *texture)
{
	SDL_Rect dest;

	dest.w = data->win.map_texture.rect.w / data->map.size;
	dest.h = data->win.map_texture.rect.h / data->map.size;
	dest.x = x;
	dest.y = y;
	SDL_RenderCopy(data->win.renderer, texture->texture, NULL, &dest);
}

void	draw_block_rect(t_editor *data, SDL_MouseButtonEvent *event,
		t_block *block)
{
	int	x;
	int	y;
	int	xmax;
	int	ymax;

	get_draw_y(data, event, &y, &ymax);
	while (y <= ymax && y < data->map.size)
	{
		get_draw_x(data, event, &x, &xmax);
		while (x <= xmax && x < data->map.size)
		{
			place_block_pos(data, block, y, x);
			x++;
		}
		y++;
	}
}
