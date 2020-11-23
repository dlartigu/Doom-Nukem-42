/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 02:24:42 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 22:15:57 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		init_map_p2(t_editor *data)
{
	if (!(data->win.map_texture.texture = SDL_CreateTexture(data->win.renderer,
	SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, data->map.size
	* BLOCK_SIZE, data->map.size * BLOCK_SIZE)))
		return (ft_printerror((char*)SDL_GetError()));
	data->win.map_texture.rect.h = data->map.size * BLOCK_SIZE;
	data->win.map_texture.rect.w = data->map.size * BLOCK_SIZE;
	data->win.map_texture.rect.y = 0;
	data->win.map_texture.rect.x = 0;
	if (!load_textures(data))
		return (ft_printerror("ERROR: load_textures"));
	draw_map(data, 0);
	return (1);
}

int		init_map(t_editor *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.size)
	{
		j = -1;
		while (++j < data->map.size)
			if (!i || !j || i == data->map.size - 1 || j == data->map.size - 1)
			{
				data->map.blocks[i][j].type = 1;
				data->map.blocks[i][j].wall_text = 17;
				data->map.blocks[i][j].height = 9;
			}
	}
	return (init_map_p2(data));
}
