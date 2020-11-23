/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:11:40 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 09:50:29 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

static void	save_map_block_p2(t_block *block, char *str)
{
	str[5] = block->wave + '0';
	if (block->roof_text != 2)
		str[6] = (block->skybox ? block->roof_text + 1 : 0) + '0';
	else
		str[6] = 'A';
	str[7] = '0';
	if (block->type != 1 && block->floor_text < MAX_FLOOR_TEXTURES - 1)
		str[7] = block->floor_text + '0';
	else if (!block->type)
		str[7] = 'A';
	str[8] = '\0';
}

static char	*save_map_block(t_block *block, char *str, int limit)
{
	if (!limit && block->type == 1 && (block->wall_text <= 2
	|| block->wall_text == 8 || block->wall_text >= 13))
		block->type = 4;
	str[0] = block->type + '0';
	str[2] = '0';
	str[3] = '0';
	if (block->wall_text < 10)
		str[1] = block->wall_text + '0';
	else
		str[1] = block->wall_text + 'A' - 10;
	if (limit)
		str[0] = '1';
	if (limit)
		str[1] = 'H';
	if (block->type != 1)
		save_block_sprite(block, str);
	str[4] = (block->type > 0 ? block->height : 0) + '0';
	if (limit)
		str[4] = '9';
	save_map_block_p2(block, str);
	return (str);
}

static int	copy_map(t_editor *data, t_elem *elem)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	elem->max_blockheight = 1;
	while (++i < data->map.size)
	{
		if (!(elem->map[i] = (char**)ft_memalloc(sizeof(char*)
		* (data->map.size + 1))))
			return (ft_printerror("ERROR: malloc"));
		j = -1;
		while (++j < data->map.size)
		{
			if (!(str = (char*)ft_memalloc(sizeof(char) * 10)))
				return (ft_printerror("ERROR: malloc"));
			elem->map[i][j] = str;
			save_map_block(&data->map.blocks[i][j], str, (i == 0 || j == 0
				|| i == data->map.size - 1 || j == data->map.size - 1));
			if (i && j && i < data->map.size - 1 && j < data->map.size - 1
			&& elem->map[i][j][BLOCK_H] - '0' + 1 > elem->max_blockheight)
				elem->max_blockheight = elem->map[i][j][BLOCK_H] - '0' + 1;
		}
	}
	return (1);
}

int			save_map(t_editor *data, t_elem *elem)
{
	ft_freebigtab(&elem->map);
	if (!(elem->map = (char***)ft_memalloc(sizeof(char**)
	* (data->map.size + 1))))
		return (ft_printerror("ERROR: malloc"));
	if (!copy_map(data, elem))
		return (ft_printerror("ERROR: copy_map"));
	elem->custom_gravity = data->map.gravity;
	elem->custom_lighting = data->map.lighting;
	elem->custom_shadow = data->map.shadow;
	elem->custom_rain = data->map.rain;
	elem->custom_fog = data->map.fog;
	elem->custom_bubbles = data->map.bubbles;
	elem->custom_psy = data->map.psy;
	elem->custom_skybox = data->map.skybox_id;
	return (1);
}
