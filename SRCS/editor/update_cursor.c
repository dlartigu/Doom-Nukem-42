/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 20:16:51 by niboute           #+#    #+#             */
/*   Updated: 2020/09/04 20:19:19 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	update_cursor(SDL_Event *event, t_editor *data)
{
	int	old;

	old = data->button_pressed;
	if (event->type == SDL_MOUSEBUTTONUP)
		data->button_pressed = 0;
	else if (event->type == SDL_MOUSEBUTTONDOWN)
		data->button_pressed = 1;
	if (old != data->button_pressed)
		data->changed = 1;
}
