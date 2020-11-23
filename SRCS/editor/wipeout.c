/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:07:21 by niboute           #+#    #+#             */
/*   Updated: 2020/11/01 16:06:38 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	free_editor(t_editor *data)
{
	free_editor_menu(data);
	free_editor_textures(data);
	free_editor_ttf(data);
	free_editor_presets(data);
	free_editor_premenu(data);
}

/*
**	void	free_doom
**	{
**	free_doom_menu();
**	free_doom_game();
**	free_doom_surfaces_zzzz();
**	}
*/

void	free_sdl(t_sdl_data *win)
{
	if (win->renderer)
		SDL_DestroyRenderer(win->renderer);
	win->renderer = NULL;
	if (win->win)
		SDL_DestroyWindow(win->win);
	win->win = NULL;
	TTF_Quit();
	SDL_Quit();
}

void	wipeout(t_editor *data, int ret)
{
	free_editor(data);
	free_sdl(&data->win);
	get_next_line(0, NULL);
	exit(ret);
}
