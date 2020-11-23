/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_block_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:06:11 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:54:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		block_menu_defaultbuttons_event(t_editor *data, int button)
{
	t_block *target;

	target = data->target.block ? data->target.block : &data->current_block;
	if (button == 1 && data->nb_presets < 20)
	{
		data->waitforinput = 1;
		data->changed = 1;
		SDL_StartTextInput();
	}
	else if (button == 2)
		change_menu(data, PRESET_MENU, data->current_menu);
	else if (button >= 3 && button <= 5)
	{
		data->draw_ceiling = 0;
		draw_map(data, 1);
		change_menu(data, button - 3 + BLOCK_EMPTY_MENU, data->current_menu);
	}
	return (1);
}

void	block_menu_empty_event_p2(t_editor *data, int button, t_block *target)
{
	if (button == 10 && target->feature == 2)
		change_menu(data, ITEM_TEXTURE_MENU, data->current_menu);
	else if (button == 11 || button == 12)
	{
		data->draw_ceiling = 1;
		draw_map(data, 1);
		target->skybox = button - 11;
		choice_button_row(data, button, 11, 12);
	}
	else if (button == 13 && target->skybox == 1)
	{
		data->draw_ceiling = 1;
		draw_map(data, 1);
		change_menu(data, ROOF_TEXTURE_MENU, data->current_menu);
	}
}

int		block_menu_empty_event(t_editor *data, int button)
{
	t_block *target;

	target = data->target.block ? data->target.block : &data->current_block;
	if (button == 5)
	{
		data->draw_ceiling = 0;
		draw_map(data, 1);
		change_menu(data, WALL_ERASE_MENU, data->current_menu);
	}
	else if (button == 6)
	{
		data->draw_ceiling = 0;
		draw_map(data, 1);
		change_menu(data, FLOOR_TEXTURE_MENU, data->current_menu);
	}
	else if (button >= 7 && button <= 9)
	{
		target->feature = button - 7;
		choice_button_row(data, button, 7, 9);
	}
	else if (button == 10 && target->feature == 1)
		change_menu(data, WAVE_MENU, data->current_menu);
	else
		block_menu_empty_event_p2(data, button, target);
	return (1);
}

void	block_menu_wall_event_p2(t_editor *data, int button, t_block *target)
{
	if (button == 6)
	{
		data->draw_ceiling = 0;
		draw_map(data, 1);
		change_menu(data, WALL_TEXTURE_MENU, data->current_menu);
	}
	if (button >= 7 && button <= 8)
	{
		target->feature = button - 7;
		choice_button_row(data, button, 7, 8);
	}
	else if (button == 12 || button == 13)
	{
		data->draw_ceiling = 1;
		draw_map(data, 1);
		target->skybox = button - 12;
		choice_button_row(data, button, 12, 13);
	}
	else if (button == 14 && target->skybox == 1)
	{
		data->draw_ceiling = 1;
		draw_map(data, 1);
		change_menu(data, ROOF_TEXTURE_MENU, data->current_menu);
	}
}

void	block_menu_wall_event(t_editor *data, int button,
		SDL_MouseButtonEvent *event)
{
	t_block *target;

	target = data->target.block ? data->target.block : &data->current_block;
	if (button == 10)
	{
		if (event->x - data->win.menu_res.x < data->win.menu_res.w / 2)
			if (target->height > 0)
				target->height--;
		if (event->x - data->win.menu_res.x >= data->win.menu_res.w / 2)
			if (target->height < 9)
				target->height++;
		data->changed = 1;
	}
	else if (button == 5)
	{
		data->draw_ceiling = 0;
		draw_map(data, 1);
		change_menu(data, WALL_ERASE_MENU, data->current_menu);
	}
	else if (button == 9 && target->feature == 1)
		change_menu(data, WAVE_MENU, data->current_menu);
	else
		block_menu_wall_event_p2(data, button, target);
}
