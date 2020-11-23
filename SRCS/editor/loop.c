/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:06:03 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 05:11:01 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	draw_prompt(t_editor *data)
{
	SDL_Rect rect;

	rect.w = 360;
	rect.h = 100;
	rect.x = (data->win.win_res.w - 360) / 2;
	rect.y = data->win.win_res.h / 2 - 100;
	center_rect_middle(&data->ttf_prompt->textbox, &rect, 1, 1);
	SDL_RenderCopy(data->win.renderer, data->button_skins[2].texture, NULL,
					&rect);
	SDL_RenderCopy(data->win.renderer, data->ttf_prompt->texture, NULL,
					&data->ttf_prompt->textbox);
	rect.y = data->win.win_res.h / 2;
	SDL_RenderCopy(data->win.renderer, data->button_skins[2].texture, NULL,
					&rect);
	if (data->ttf_text_input && data->ttf_text_input->texture)
	{
		center_rect_middle(&data->ttf_text_input->textbox, &rect, 1, 1);
		SDL_RenderCopy(data->win.renderer, data->ttf_text_input->texture, NULL,
						&data->ttf_text_input->textbox);
	}
}

int		loop(t_editor *data)
{
	SDL_Event	event;

	data->changed = 1;
	while (!data->editor_exit)
	{
		while (SDL_PollEvent(&event))
			if (!(handle_events(data, &event)))
				return (ft_printerror("handle_events"));
		if (data->waitforinput && data->changed)
		{
			draw_prompt(data);
			SDL_RenderPresent(data->win.renderer);
			data->changed = 0;
		}
		if (data->changed && !data->waitforinput)
		{
			SDL_RenderClear(data->win.renderer);
			render_map(data, &data->win, data->fit_in_win
				? data->win.map_res : data->win.zoomed_map);
			draw_editor_menu(data);
			SDL_RenderPresent(data->win.renderer);
			data->changed = 0;
		}
	}
	return (1);
}
