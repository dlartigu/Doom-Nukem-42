/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:06:24 by niboute           #+#    #+#             */
/*   Updated: 2020/10/19 02:33:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		choice_button_row(t_editor *data, int button, int start, int end)
{
	if (data->menus[data->current_menu].nb_buttons <= end)
		return (0);
	while (start <= end)
	{
		data->menus[data->current_menu].skin_id[start] = DEFAULT_BUTTON_ID;
		start++;
	}
	data->menus[data->current_menu].skin_id[button] = CHOICE_BUTTON_ID;
	data->changed = 1;
	return (1);
}

int		is_in_rect(SDL_Rect *rect, int y, int x)
{
	if (y >= rect->y && y < rect->y + rect->h && x >= rect->x
	&& x < rect->x + rect->w)
		return (1);
	return (0);
}

int		which_button(t_editor *data, int y, int x)
{
	int		i;
	t_menu	*menu;

	i = 0;
	menu = &data->menus[data->current_menu];
	while (i < menu->nb_buttons)
	{
		if (is_in_rect(&menu->buttons_pos[i], y, x))
			return (i);
		i++;
	}
	return (-1);
}

void	set_highlight_buttons(t_editor *data, int next_menu, t_block *target)
{
	if (next_menu == BLOCK_EMPTY_MENU)
		choice_button_row(data, 7, 7, 9);
	if (next_menu == BLOCK_EMPTY_MENU)
		choice_button_row(data, target->skybox + 11, 11, 12);
	if (next_menu == BLOCK_WALL_MENU)
		choice_button_row(data, 7, 7, 8);
	if (next_menu == BLOCK_WALL_MENU)
		choice_button_row(data, target->skybox + 12, 12, 13);
}

int		change_menu(t_editor *data, int next_menu, int curr_menu)
{
	t_block *target;

	data->last_menu = curr_menu;
	data->current_menu = next_menu;
	data->changed = 1;
	target = data->target.block ? data->target.block : &data->current_block;
	if (data->current_menu == PRESET_MENU || data->current_menu == FEATURE_MENU)
		data->draw_mode = data->current_menu == PRESET_MENU ? 0 : 1;
	if (next_menu >= BLOCK_EMPTY_MENU && next_menu <= BLOCK_WALL_MENU
	&& curr_menu >= BLOCK_EMPTY_MENU && curr_menu <= BLOCK_WALL_MENU)
	{
		target->type = next_menu - BLOCK_EMPTY_MENU;
		set_highlight_buttons(data, next_menu, target);
	}
	return (0);
}
