/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:00:01 by niboute           #+#    #+#             */
/*   Updated: 2020/09/04 20:29:52 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int			keyboard_event(t_editor *data, SDL_KeyboardEvent *event)
{
	if (event->repeat)
		return (0);
	if (event->keysym.sym == SDLK_ESCAPE && event->state == SDL_PRESSED)
	{
		data->editor_exit = 1;
		return (0);
	}
	else if (event->keysym.sym == SDLK_SPACE && event->state == SDL_PRESSED)
	{
		data->draw_menu_textures ^= 1;
		data->changed = 1;
	}
	else if (event->keysym.sym == SDLK_LSHIFT)
		data->events.shift = event->state == SDL_PRESSED ? 1 : 0;
	else if (event->keysym.sym == SDLK_LCTRL)
		data->events.ctrl = event->state == SDL_PRESSED ? 1 : 0;
	else if (event->keysym.sym == SDLK_z && event->state == SDL_PRESSED)
	{
		data->fit_in_win = 1;
		data->win.map_texture.rect.x = 0;
		data->win.map_texture.rect.y = 0;
		data->changed = 1;
	}
	return (1);
}

int			mousewheel_event(t_editor *data, SDL_MouseWheelEvent *event)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	if (x >= 0 && x <= data->win.map_res.w && y >= 0 && y < data->win.win_res.h)
		change_zoom(data, event->y, y, x);
	if (data->current_menu != PRESET_MENU || x < data->win.map_res.w
	|| x > data->win.win_res.w || y < data->win.map_res.h / 6
	+ data->win.map_res.h / 9.6 || y >= data->win.win_res.h)
		return (0);
	if (event->y > 0 && data->scroll > 0)
		data->scroll--;
	else if (event->y < 0 && data->scroll < data->nb_presets - 8)
		data->scroll++;
	else
		return (0);
	data->changed = 1;
	return (1);
}

static void	mousemotion_event_p2(t_editor *data, SDL_MouseMotionEvent *event)
{
	int			x;
	int			y;

	x = (int)ft_dmap(event->x, data->win.win_res.w, 0, 640);
	y = (int)ft_dmap(event->y, data->win.win_res.h, 0, 480);
	if (x >= 270 && x <= 355 && y >= 385 && y <= 435)
	{
		if (!data->premenu_textures.hover)
			data->changed = 1;
		data->premenu_textures.hover = 1;
	}
	else if (data->premenu_textures.hover)
	{
		data->premenu_textures.hover = 0;
		data->changed = 1;
	}
}

void		mousemotion_event(t_editor *data, SDL_MouseMotionEvent *event)
{
	t_block		*block;

	data->events.mousey = event->y;
	data->events.mousex = event->x;
	data->changed = 1;
	if ((event->state & SDL_BUTTON_LMASK) && !data->events.shift
	&& !data->events.ctrl && data->current_menu != VALIDATE_MENU
	&& data->current_menu != OPTIONS_MENU)
	{
		block = data->target.block ? data->target.block : &data->current_block;
		block = data->current_menu == PRESET_MENU ? preset_select(data) : block;
		if (!block)
			return ;
		place_block_px(data, block, event->y, event->x);
	}
	else if (data->current_menu == OPTIONS_MENU)
		mousemotion_event_p2(data, event);
}

int			handle_events(t_editor *data, SDL_Event *event)
{
	update_cursor(event, data);
	if (event->type == SDL_QUIT)
		wipeout(data, EXIT_SUCCESS);
	else if (data->waitforinput == 1)
	{
		if (event->type == SDL_KEYDOWN)
			prompt_event(data, &event->key);
		else if (event->type == SDL_TEXTINPUT)
			read_input(data, &event->text);
	}
	else if (event->type == SDL_MOUSEMOTION)
		mousemotion_event(data, &event->motion);
	else if (event->type == SDL_MOUSEBUTTONUP
	|| event->type == SDL_MOUSEBUTTONDOWN)
	{
		if (!mousebutton_event(data, &event->button))
			return (ft_printerror("ERROR: mousebutton_event"));
	}
	else if (event->type == SDL_MOUSEWHEEL
	&& data->current_menu != OPTIONS_MENU)
		mousewheel_event(data, &event->wheel);
	else if (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP)
		keyboard_event(data, &event->key);
	return (1);
}
