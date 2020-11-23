/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:36:07 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:41:37 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int			options_menu_buttons_p2(t_editor *data, int x, int y)
{
	if (x >= 160 && x <= 270 && y >= 250 && y <= 280)
		data->map.rain ^= 1;
	else if (x >= 330 && x <= 435 && y >= 250 && y <= 280)
		data->map.fog ^= 1;
	else if (x >= 160 && x <= 290 && y >= 305 && y <= 335)
		data->map.bubbles ^= 1;
	else if (x >= 330 && x <= 430 && y >= 305 && y <= 335)
		data->map.psy ^= 1;
	else if (x >= 270 && x <= 385 && y >= 385 && y <= 435)
	{
		change_menu(data, PRESET_MENU, OPTIONS_MENU);
		if (!(init_map(data)))
			return (ft_printerror("ERROR: init_map"));
	}
	else
		data->changed = 0;
	return (1);
}

int			options_menu_buttons(t_editor *data, int x, int y)
{
	if (x >= 260 && x <= 300 && y >= 70 && y <= 100)
		data->map.skybox_id = ft_max_2(data->map.skybox_id - 1, 0);
	else if (x >= 415 && x <= 455 && y >= 70 && y <= 100)
		data->map.skybox_id = ft_min_2(data->map.skybox_id + 1, 2);
	else if (x >= 225 && x <= 250 && y >= 120 && y <= 145)
		data->map.size = ft_max_2(data->map.size - 1, 10);
	else if (x >= 275 && x <= 300 && y >= 120 && y <= 145)
		data->map.size = ft_min_2(data->map.size + 1, 50);
	else if (x >= 225 && x <= 250 && y >= 165 && y <= 190)
		data->map.gravity = ft_max_2(data->map.gravity - 1, 1);
	else if (x >= 275 && x <= 300 && y >= 165 && y <= 190)
		data->map.gravity = ft_min_2(data->map.gravity + 1, 5);
	else if (x >= 160 && x <= 290 && y >= 205 && y <= 235)
		data->map.lighting ^= 1;
	else if (x >= 330 && x <= 465 && y >= 205 && y <= 235)
		data->map.shadow ^= 1;
	else if (!(options_menu_buttons_p2(data, x, y)))
		return (ft_printerror("ERROR: options_menu_buttons_p2"));
	return (1);
}

static int	change_options_textures_p2(t_editor *data, t_edmap *oldmap,
SDL_Color col)
{
	char		*str;

	if (!oldmap || oldmap->size != data->map.size)
	{
		delete_texture_tab_ttf(data->premenu_textures.size, 1);
		ft_memdel((void**)&data->premenu_textures.size);
		if (!(str = ft_itoa(data->map.size)))
			return (ft_printerror("ERROR: ft_itoa"));
		if (!(data->premenu_textures.size = create_str_texture(
		data->win.renderer, str, col, data->fonts[2])))
			return (ft_errordel("ERROR: create_str_texture", (void**)&str));
		ft_strdel(&str);
	}
	return (1);
}

int			change_options_textures(t_editor *data, t_edmap *oldmap)
{
	char		*str;
	SDL_Color	col;

	ft_memset((void*)&col, 0x00, sizeof(SDL_Color));
	col.r = 255;
	col.g = 255;
	if (!oldmap || oldmap->gravity != data->map.gravity)
	{
		delete_texture_tab_ttf(data->premenu_textures.grav, 1);
		ft_memdel((void**)&data->premenu_textures.grav);
		if (!(str = ft_itoa(data->map.gravity)))
			return (ft_printerror("ERROR: ft_itoa"));
		if (!(data->premenu_textures.grav = create_str_texture(
		data->win.renderer, str, col, data->fonts[2])))
			return (ft_errordel("ERROR: create_str_texture", (void**)&str));
		ft_strdel(&str);
	}
	return (change_options_textures_p2(data, oldmap, col));
}

int			options_menu_event(t_editor *data, SDL_MouseButtonEvent *event)
{
	t_edmap		old;

	old = data->map;
	data->changed = 1;
	if (!(options_menu_buttons(data,
	(int)ft_dmap(event->x, data->win.win_res.w, 0, 640),
	(int)ft_dmap(event->y, data->win.win_res.h, 0, 480))))
		return (ft_printerror("ERROR: options_menu_buttons"));
	if (!(change_options_textures(data, &old)))
		return (ft_printerror("ERROR: change_options_textures"));
	return (1);
}
