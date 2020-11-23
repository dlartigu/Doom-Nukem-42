/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:37:59 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:10:20 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		wall_feature_event(t_editor *data,
		SDL_MouseButtonEvent *event, int button)
{
	if (button == 1
	&& event->x - data->win.menu_res.x < data->win.menu_res.w / 2)
		if (data->current_block.height > 0)
			data->current_block.height--;
	if (button == 1
	&& event->x - data->win.menu_res.x >= data->win.menu_res.w / 2)
		if (data->current_block.height < 9)
			data->current_block.height++;
	data->changed = 1;
	if (button == 0)
		change_menu(data, WALL_TEXTURE_MENU, WALL_FEATURE_MENU);
	return (1);
}

int		wave_menu_event(t_editor *data,
		SDL_MouseButtonEvent *event, int button)
{
	if (button == 1
	&& event->x - data->win.menu_res.x < data->win.menu_res.w / 2)
		if (data->current_block.wave > 0)
			data->current_block.wave--;
	if (button == 1
	&& event->x - data->win.menu_res.x >= data->win.menu_res.w / 2)
		if (data->current_block.wave < 5)
			data->current_block.wave++;
	data->changed = 1;
	if (button == 0)
		change_menu(data, ENEMY_TEXTURE_MENU, data->last_menu);
	return (1);
}

int		feature_menu_event_p2(t_editor *data)
{
	if (data->selected_feature == 2)
		change_menu(data, WALL_ERASE_MENU, data->current_menu);
	else if (data->selected_feature == 4)
		change_menu(data, WAVE_MENU, data->current_menu);
	else if (data->selected_feature == 5)
		change_menu(data, ITEM_TEXTURE_MENU, data->current_menu);
	else if (data->selected_feature == 7)
	{
		data->draw_ceiling = 1;
		draw_map(data, 1);
		change_menu(data, ROOF_TEXTURE_MENU, data->current_menu);
	}
	return (1);
}

int		feature_menu_event(t_editor *data, int button)
{
	if (button < 0)
		return (0);
	ft_bzero(&data->current_block, sizeof(t_block));
	data->selected_feature = button - 1;
	choice_button_row(data, button, 0, 7);
	set_block_feature(&data->current_block, &data->current_block,
		data->selected_feature);
	if (button == 0)
		change_menu(data, PRESET_MENU, data->current_menu);
	else if (data->selected_feature == 0 || data->selected_feature == 1)
	{
		data->draw_ceiling = 0;
		draw_map(data, 1);
	}
	if (data->selected_feature == 0)
		change_menu(data, FLOOR_TEXTURE_MENU, data->current_menu);
	else if (data->selected_feature == 1)
		change_menu(data, WALL_FEATURE_MENU, data->current_menu);
	else
		feature_menu_event_p2(data);
	return (1);
}
