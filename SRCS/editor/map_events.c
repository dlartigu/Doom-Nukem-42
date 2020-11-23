/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:55:45 by niboute           #+#    #+#             */
/*   Updated: 2020/10/15 01:06:38 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		identify_block(t_editor *data, SDL_MouseButtonEvent *event)
{
	int	y;
	int	x;

	y = (event->y - data->win.map_texture.rect.y) / BLOCK_SIZE;
	x = (event->x - data->win.map_texture.rect.x) / BLOCK_SIZE;
	return (1);
}

void	save_button(t_editor *data, SDL_MouseButtonEvent *event)
{
	if (event->button == SDL_BUTTON_LEFT
	&& (data->events.shift || data->events.ctrl))
	{
		data->events.lb_sx = event->x;
		data->events.lb_sy = event->y;
	}
	else if (event->button == SDL_BUTTON_RIGHT)
	{
		data->events.rb_sx = event->x;
		data->events.rb_sy = event->y;
	}
	else if (event->button == SDL_BUTTON_MIDDLE)
	{
		data->events.mb_sx = event->x;
		data->events.mb_sy = event->y;
	}
}

void	map_event(t_editor *data, SDL_MouseButtonEvent *event)
{
	t_block	*target;

	data->changed = 1;
	target = data->target.block ? data->target.block : &data->current_block;
	if (event->button == SDL_BUTTON_MIDDLE && !data->events.shift
	&& !data->events.ctrl)
	{
		data->win.map_texture.rect.x += event->x - data->events.mb_sx;
		data->win.map_texture.rect.y += event->y - data->events.mb_sy;
	}
	else if (event->button == SDL_BUTTON_LEFT && data->events.shift
	&& data->current_menu != VALIDATE_MENU)
		draw_block_line(data, event, target);
	else if (event->button == SDL_BUTTON_LEFT && data->events.ctrl
	&& data->current_menu != VALIDATE_MENU)
		draw_block_rect(data, event, target);
}

int		mousebutton_mapevent(t_editor *data, SDL_MouseButtonEvent *event)
{
	t_block		*block;

	if (event->button == SDL_BUTTON_LEFT && event->state == SDL_PRESSED
	&& data->current_menu == VALIDATE_MENU)
		place_spawn(data, event->y, event->x);
	else if (event->button == SDL_BUTTON_LEFT && event->state == SDL_PRESSED
	&& !data->events.shift && !data->events.ctrl
	&& data->current_menu != VALIDATE_MENU)
	{
		block = data->target.block ? data->target.block : &data->current_block;
		block = data->current_menu == PRESET_MENU ? preset_select(data) : block;
		if (!block)
			return (0);
		place_block_px(data, block, event->y, event->x);
		data->changed = 1;
	}
	else if (event->state == SDL_RELEASED)
		map_event(data, event);
	save_button(data, event);
	return (1);
}

int		mousebutton_event(t_editor *data, SDL_MouseButtonEvent *event)
{
	if (event->x < 0 || event->x >= data->win.win_res.w
	|| event->y < 0 || event->y >= data->win.win_res.h)
		return (0);
	if (event->x < data->win.map_res.w && data->current_menu != OPTIONS_MENU)
		mousebutton_mapevent(data, event);
	else if (event->x >= data->win.menu_res.x && event->state == SDL_RELEASED
	&& event->button == SDL_BUTTON_LEFT && data->current_menu != OPTIONS_MENU)
		mousebutton_menuevent(data, event);
	else if (data->current_menu == OPTIONS_MENU && event->state == SDL_RELEASED
	&& event->button == SDL_BUTTON_LEFT)
		if (!(options_menu_event(data, event)))
			return (ft_printerror("ERROR: options_menu_event"));
	return (1);
}
