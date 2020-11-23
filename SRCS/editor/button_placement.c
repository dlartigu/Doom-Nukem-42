/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_placement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:57:20 by niboute           #+#    #+#             */
/*   Updated: 2020/10/18 09:27:58 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	center_x_ttf(t_ttf_text **text, SDL_Rect *dst, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		center_rect_middle(&text[i]->textbox, dst, i + 1, nb);
		i++;
	}
}

void	fit_x_buttons(SDL_Rect *src, SDL_Rect *dst, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		button_to_rect(src + i, dst, i, nb);
		i++;
	}
}

void	center_wall_size_ttf(t_editor *data, SDL_Rect *dst)
{
	int	i;

	i = 0;
	center_rect_right(&data->ttf_wall_size[0]->textbox, dst, 1, 1);
	center_rect_right(&data->ttf_wall_size[1]->textbox, dst, 1, 1);
	while (i < 10)
	{
		center_rect_right(&data->ttf_digits[i]->textbox, dst, 1, 1);
		data->ttf_digits[i]->textbox.x -= (data->
		ttf_wall_size[0]->textbox.w) + 10;
		i++;
	}
}

void	center_menu_buttons_p2(t_editor *data, int i, int j, int y)
{
	SDL_Rect	dest;
	int			k;

	k = -1;
	while (++k < data->menus[i].nb_menu_sections)
	{
		y += assign_menu_rect(&dest, y, &data->win.menu_res);
		if (i == PRESET_MENU && j == 3)
			dest.y = data->win.map_res.h - dest.h;
		if (i == BLOCK_WALL_MENU && j == 10)
			center_rect_left(&data->menus[i].ttf[j]->textbox, &dest, 0, 1);
		if (i == WAVE_MENU && j == 1)
			center_rect_right(&data->ttf_wave->textbox, &dest, 1, 1);
		if (i == BLOCK_WALL_MENU && j == 10)
			center_wall_size_ttf(data, &dest);
		else if ((i == WALL_FEATURE_MENU || i == WAVE_MENU) && j == 1)
			center_rect_left(&data->menus[i].ttf[j]->textbox, &dest, 0, 1);
		else
			center_x_ttf(&data->menus[i].ttf[j], &dest,
			data->menus[i].button_per_sec[k]);
		fit_x_buttons(&data->menus[i].buttons_pos[j], &dest,
			data->menus[i].button_per_sec[k]);
		j += data->menus[i].button_per_sec[k];
	}
}

void	center_menu_buttons(t_editor *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_menus)
		center_menu_buttons_p2(data, i, 0, 0);
}
