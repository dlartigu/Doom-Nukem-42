/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:04:09 by niboute           #+#    #+#             */
/*   Updated: 2020/10/15 23:52:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	draw_menu_textures_rects(t_editor *data, t_sdl_text *textures, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		SDL_RenderCopy(data->win.renderer, textures[i].texture, NULL,
						&data->scroll_rects[i]);
		i++;
	}
}

void	render_button_blurred(t_editor *data, t_menu *menu, int i)
{
	SDL_Rect	src;

	src.x = ft_dmap(menu->buttons_pos[i].x - data->win.menu_res.x,
	data->win.menu_res.w, 0, 160);
	src.w = ft_dmap(menu->buttons_pos[i].w, data->win.menu_res.w, 0, 160);
	src.y = ft_dmap(menu->buttons_pos[i].y, data->win.menu_res.h, 0, 480);
	src.h = ft_dmap(menu->buttons_pos[i].h, data->win.menu_res.h, 0, 480);
	SDL_RenderCopy(data->win.renderer,
	data->menu_textures[menu->texture_blur_id].texture, &src,
	&menu->buttons_pos[i]);
}

void	draw_menu_buttons(t_editor *data, t_menu *menu)
{
	int	i;

	i = 0;
	while (i < menu->nb_buttons)
	{
		SDL_RenderCopy(data->win.renderer,
			data->button_skins[menu->skin_id[i]].texture, NULL,
			&menu->buttons_pos[i]);
		if (menu->ttf[i])
			SDL_RenderCopy(data->win.renderer, menu->ttf[i]->texture,
			NULL, &menu->ttf[i]->textbox);
		i++;
	}
}

void	draw_editor_menu(t_editor *data)
{
	if (data->current_menu == OPTIONS_MENU)
	{
		draw_editor_optmenu(data);
		return ;
	}
	SDL_RenderCopy(data->win.renderer, data->menu_textures[0].texture, NULL,
	&data->win.menu_res);
	if (data->current_menu >= BLOCK_EMPTY_MENU
	&& data->current_menu <= BLOCK_WALL_MENU)
		SDL_RenderCopy(data->win.renderer,
		data->menu_textures[data->menus[data->current_menu].texture_id]
		.texture, NULL, &data->win.menu_res);
	if (data->menus[data->current_menu].nb_buttons)
		draw_menu_buttons(data, &data->menus[data->current_menu]);
	draw_menu_specific_data(data);
	render_cursor(data->win.renderer, data->cursor[data->button_pressed],
		data->events.mousex, data->events.mousey);
}
