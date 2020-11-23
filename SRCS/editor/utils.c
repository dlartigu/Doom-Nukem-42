/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:09:54 by niboute           #+#    #+#             */
/*   Updated: 2020/09/04 20:38:29 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	change_zoom_p2(t_editor *data, int y, int x)
{
	int	old_zoom_w;
	int	old_zoom_h;

	old_zoom_w = data->win.zoomed_map.w;
	old_zoom_h = data->win.zoomed_map.h;
	data->win.zoomed_map.w = (BLOCK_SIZE * data->map.size) / data->zoom;
	data->win.zoomed_map.h = (BLOCK_SIZE * data->map.size) / data->zoom;
	data->changed = 1;
	data->win.map_texture.rect.x = x - ((ft_dmap(x
	- data->win.map_texture.rect.x, old_zoom_w, 0, data->win.zoomed_map.w)));
	data->win.map_texture.rect.y = y - ((ft_dmap(y
	- data->win.map_texture.rect.y, old_zoom_h, 0, data->win.zoomed_map.h)));
}

void	change_zoom(t_editor *data, int dir, int y, int x)
{
	if (data->fit_in_win)
	{
		data->fit_in_win = 0;
		data->changed = 1;
		return ;
	}
	if (get_map_texture_px_y(data, y - data->win.map_texture.rect.y) == -1
	|| get_map_texture_px_x(data, x - data->win.map_texture.rect.x) == -1)
		return ;
	if ((dir < 0 && data->zoom >= 16) || (dir > 0 && data->zoom <= 1))
		return ;
	if (dir < 0)
		data->zoom++;
	if (dir > 0)
		data->zoom--;
	change_zoom_p2(data, y, x);
}
