/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_block_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:29:27 by niboute           #+#    #+#             */
/*   Updated: 2020/09/04 20:39:47 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		set_linealg_values(int xy[4], int delta[4], int sign[2])
{
	delta[0] = ft_abs(xy[0] - xy[1]);
	delta[1] = ft_abs(xy[2] - xy[3]);
	sign[0] = xy[0] < xy[1] ? 1 : -1;
	sign[1] = xy[2] < xy[3] ? 1 : -1;
	delta[2] = 0;
	delta[3] = ft_max_2(delta[0], delta[1]);
	delta[3] = ft_max_2(ft_max_2(delta[0], delta[1]), 1);
	return (delta[0] > delta[1] ? delta[0] / 2 : -delta[1] / 2);
}

int		draw_line(t_editor *data, int *xy, t_block *block)
{
	int	delta[4];
	int	diff[2];
	int	sign[2];

	diff[0] = set_linealg_values(xy, delta, sign);
	while (1)
	{
		if (xy[0] >= 0 && xy[0] < data->map.size
		&& xy[2] >= 0 && xy[2] < data->map.size)
			place_block_pos(data, block, xy[2], xy[0]);
		if (xy[0] == xy[1] && xy[2] == xy[3])
			return (0);
		diff[1] = diff[0];
		if (diff[1] > -delta[0])
			diff[0] -= delta[1];
		if (diff[1] > -delta[0])
			xy[0] += sign[0];
		if (diff[1] < delta[1])
			diff[0] += delta[0];
		if (diff[1] < delta[1])
			xy[2] += sign[1];
	}
}

void	get_draw_y(t_editor *data, SDL_MouseButtonEvent *event, int *y,
		int *ymax)
{
	*y = (int)get_map_texture_px_y(data, data->events.lb_sy
	- data->win.map_texture.rect.y) / BLOCK_SIZE;
	*ymax = (int)get_map_texture_px_y(data, event->y
	- data->win.map_texture.rect.y) / BLOCK_SIZE;
	if (*y > *ymax)
		ft_swap_int_2(y, ymax);
	if (*y < 0)
		*y = 0;
}

void	get_draw_x(t_editor *data, SDL_MouseButtonEvent *event, int *x,
		int *xmax)
{
	*x = (int)get_map_texture_px_x(data, data->events.lb_sx
	- data->win.map_texture.rect.x) / BLOCK_SIZE;
	*xmax = (int)get_map_texture_px_x(data, event->x
	- data->win.map_texture.rect.x) / BLOCK_SIZE;
	if (*x > *xmax)
		ft_swap_int_2(x, xmax);
	if (*x < 0)
		*x = 0;
}

void	draw_block_line(t_editor *data, SDL_MouseButtonEvent *event,
		t_block *block)
{
	int	xy[4];

	xy[0] = (int)get_map_texture_px_x(data, data->events.lb_sx
	- data->win.map_texture.rect.x) / BLOCK_SIZE;
	xy[1] = (int)get_map_texture_px_x(data, event->x
	- data->win.map_texture.rect.x) / BLOCK_SIZE;
	xy[2] = (int)get_map_texture_px_y(data, data->events.lb_sy
	- data->win.map_texture.rect.y) / BLOCK_SIZE;
	xy[3] = (int)get_map_texture_px_y(data, event->y
	- data->win.map_texture.rect.y) / BLOCK_SIZE;
	draw_line(data, &xy[0], block);
}
