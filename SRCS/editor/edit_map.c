/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:07:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 22:15:21 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	set_block_feature(t_block *dst, t_block *src, int feature)
{
	if (feature == 1)
		dst->type = 1;
	if (feature == 0)
		dst->floor_text = src->floor_text;
	else if (feature == 1)
		dst->wall_text = src->wall_text;
	if (feature == 1)
		dst->height = src->height;
	else if (feature >= 3 && feature <= 5)
	{
		dst->feature = feature - 3;
		if (feature == 4)
			dst->wave = src->wave;
		dst->feature_text = src->feature_text;
	}
	else if (feature == 6 || feature == 7)
	{
		dst->skybox = feature - 6;
		dst->roof_text = src->roof_text;
	}
}

int		get_map_texture_px_x(t_editor *data, int px)
{
	if (data->fit_in_win)
	{
		if (px < 0 || px >= data->win.map_res.w)
			return (-1);
		return (ft_dmap(px, data->win.map_res.w, 0,
		data->win.map_texture.rect.w));
	}
	else
	{
		if (px < 0 || px >= data->win.zoomed_map.w)
			return (-1);
		return (ft_dmap(px, data->win.zoomed_map.w, 0,
		data->win.map_texture.rect.w));
	}
	return (0);
}

int		get_map_texture_px_y(t_editor *data, int px)
{
	if (data->fit_in_win)
	{
		if (px < 0 || px >= data->win.map_res.h)
			return (-1);
		return (ft_dmap(px, data->win.map_res.h, 0,
		data->win.map_texture.rect.h));
	}
	else
	{
		if (px < 0 || px >= data->win.zoomed_map.h)
			return (-1);
		return (ft_dmap(px, data->win.zoomed_map.h, 0,
		data->win.map_texture.rect.h));
	}
	return (0);
}

int		remove_old_spawn(t_editor *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size)
	{
		j = 0;
		while (j < data->map.size)
		{
			if (data->map.blocks[i][j].is_spawn)
			{
				data->map.blocks[i][j].is_spawn = 0;
				place_block_pos(data, &data->map.blocks[i][j], i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		place_spawn(t_editor *data, int px_y, int px_x)
{
	int	y;
	int	x;

	px_y = get_map_texture_px_y(data, px_y - data->win.map_texture.rect.y);
	px_x = get_map_texture_px_x(data, px_x - data->win.map_texture.rect.x);
	y = px_y / BLOCK_SIZE;
	x = px_x / BLOCK_SIZE;
	if (x <= 0 || x >= data->map.size - 1 || y <= 0 || y >= data->map.size - 1)
		return (0);
	data->spawn_x = x;
	data->spawn_y = y;
	data->map.blocks[y][x].feature = 0;
	data->map.blocks[y][x].type = 0;
	px_y = (y * data->win.map_texture.rect.h) / data->map.size;
	px_x = (x * data->win.map_texture.rect.w) / data->map.size;
	remove_old_spawn(data);
	data->map.blocks[y][x].is_spawn = 1;
	SDL_SetRenderTarget(data->win.renderer, data->win.map_texture.texture);
	draw_block(data, px_y, px_x, &data->spawn_texture);
	SDL_SetRenderTarget(data->win.renderer, NULL);
	data->changed = 1;
	return (1);
}
