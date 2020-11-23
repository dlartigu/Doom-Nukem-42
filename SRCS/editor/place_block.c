/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:05:32 by niboute           #+#    #+#             */
/*   Updated: 2020/11/12 18:39:57 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		try_block(t_editor *data, t_block *block, int y, int x)
{
	if (y <= 0 || y > data->map.size - 2 || x <= 0 || x > data->map.size - 2)
		return (-1);
	if (data->current_menu == WALL_ERASE_MENU
	|| (data->draw_mode == 1 && (data->selected_feature == 0))
	|| (block->type != 1 && data->draw_mode == 0))
		if (y == 0 || y == data->map.size - 1
		|| x == 0 || x == data->map.size - 1)
			return (-1);
	if (data->current_menu == WALL_ERASE_MENU)
		data->map.blocks[y][x].type = 0;
	else if (data->draw_mode == 0 && !data->draw_only)
		data->map.blocks[y][x] = *block;
	else if (!data->draw_only)
		set_block_feature(&data->map.blocks[y][x], block,
		data->selected_feature);
	return (0);
}

void	place_block(t_editor *data, t_block *block, int y, int x)
{
	int	roof;

	SDL_SetRenderTarget(data->win.renderer, data->win.map_texture.texture);
	roof = 0;
	if (data->draw_ceiling && block->skybox)
		roof = 1;
	else if (block->type == 1)
		draw_block(data, y, x, &data->wall_text[block->wall_text]);
	else
		draw_block(data, y, x, &data->floor_text[block->floor_text]);
	if (block->feature == 1)
		draw_block(data, y, x,
		&data->enemy_text[block->feature_text]);
	else if (block->feature == 2 && !block->type)
		draw_block(data, y, x,
		&data->item_text[block->feature_text]);
	if (roof)
		draw_block(data, y, x, &data->roof_text[block->roof_text]);
	SDL_SetRenderTarget(data->win.renderer, NULL);
}

int		place_block_px(t_editor *data, t_block *block, int y, int x)
{
	y = get_map_texture_px_y(data, y - data->win.map_texture.rect.y);
	x = get_map_texture_px_x(data, x - data->win.map_texture.rect.x);
	if (y == -1 || x == -1)
		return (0);
	y -= y % BLOCK_SIZE;
	x -= x % BLOCK_SIZE;
	if (try_block(data, block, y / BLOCK_SIZE, x / BLOCK_SIZE) == -1)
		return (0);
	block = &data->map.blocks[y / BLOCK_SIZE][x / BLOCK_SIZE];
	place_block(data, block, y, x);
	return (1);
}

int		place_block_pos(t_editor *data, t_block *block, int y, int x)
{
	int	px_y;
	int	px_x;

	if (try_block(data, block, y, x) == -1)
		return (0);
	px_y = (y * data->win.map_texture.rect.h) / data->map.size;
	px_x = (x * data->win.map_texture.rect.w) / data->map.size;
	place_block(data, block, px_y, px_x);
	return (1);
}
