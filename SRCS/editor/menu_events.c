/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:28:51 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:39:51 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	texture_menu_event(t_editor *data, SDL_MouseButtonEvent *event)
{
	int		i;
	t_block	*target;

	target = data->target.block ? data->target.block : &data->current_block;
	if (data->last_menu == FEATURE_MENU || data->last_menu == WALL_FEATURE_MENU)
		target = &data->current_block;
	i = 0;
	while (i < data->nb_scroll_rects
	&& !is_in_rect(&data->scroll_rects[i], event->y, event->x))
		i++;
	i = i == data->nb_scroll_rects ? 0 : i;
	if (data->current_menu == WALL_TEXTURE_MENU)
		target->wall_text = i;
	else if (data->current_menu == FLOOR_TEXTURE_MENU)
		target->floor_text = i;
	else if (data->current_menu == ROOF_TEXTURE_MENU)
		target->roof_text = i;
	else if (data->current_menu == ENEMY_TEXTURE_MENU
		|| data->current_menu == ITEM_TEXTURE_MENU)
		target->feature_text = i;
	if (data->last_menu >= BLOCK_EMPTY_MENU
	&& data->last_menu <= BLOCK_WALL_MENU)
		change_menu(data, data->last_menu, data->current_menu);
	else
		change_menu(data, FEATURE_MENU, data->current_menu);
}

void	validate_menu_event(t_editor *data, int button)
{
	if (button == 1)
	{
		if (data->spawn_x == 0 || data->spawn_y == 0)
			return ;
		else
			data->editor_exit = 1;
	}
}

void	mousebutton_menuevent_p2(t_editor *data, SDL_MouseButtonEvent *event,
		int button)
{
	if (data->current_menu == WALL_ERASE_MENU && button == 1)
		change_menu(data, data->last_menu, data->current_menu);
	else if (data->current_menu == WALL_FEATURE_MENU)
		wall_feature_event(data, event, button);
	else if (data->current_menu == VALIDATE_MENU)
		validate_menu_event(data, button);
	else if (data->current_menu == WAVE_MENU)
		wave_menu_event(data, event, button);
	else
		texture_menu_event(data, event);
}

void	mousebutton_menuevent(t_editor *data, SDL_MouseButtonEvent *event)
{
	int	button;

	button = which_button(data, event->y, event->x);
	if ((button == -1 && data->current_menu >= BLOCK_EMPTY_MENU
	&& data->current_menu <= BLOCK_WALL_MENU))
		return ;
	else if (data->current_menu == FEATURE_MENU)
		feature_menu_event(data, button);
	else if (data->current_menu == PRESET_MENU)
		preset_menu_event(data, event, button);
	else if (data->current_menu >= BLOCK_EMPTY_MENU
	&& data->current_menu <= BLOCK_WALL_MENU && button <= 4)
		block_menu_defaultbuttons_event(data, button);
	else if (data->current_menu == BLOCK_EMPTY_MENU)
		block_menu_empty_event(data, button);
	else if (data->current_menu == BLOCK_WALL_MENU)
		block_menu_wall_event(data, button, event);
	else
		mousebutton_menuevent_p2(data, event, button);
}
