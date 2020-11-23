/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 02:35:38 by niboute           #+#    #+#             */
/*   Updated: 2020/09/04 20:11:24 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

static void	set_optmenu_textures_rects_p3(t_editor *data)
{
	int	i;

	data->premenu_textures.dest[6].x = ft_dmap(415, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[6].y = ft_dmap(265 - data->premenu_textures.
	icon.rect.h / 2, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[7].x = ft_dmap(270, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[7].y = ft_dmap(320 - data->premenu_textures.
	icon.rect.h / 2, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[8].x = ft_dmap(410, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[8].y = ft_dmap(320 - data->premenu_textures.
	icon.rect.h / 2, 480, 0, data->win.win_res.h);
	i = 2;
	while (++i < 9)
	{
		data->premenu_textures.dest[i].w = ft_dmap(data->premenu_textures.
		icon.rect.w, 640, 0, data->win.win_res.w);
		data->premenu_textures.dest[i].h = ft_dmap(data->premenu_textures.
		icon.rect.h, 480, 0, data->win.win_res.h);
	}
}

static void	set_optmenu_textures_rects_p2(t_editor *data)
{
	data->premenu_textures.dest[2].y = ft_dmap(175 - data->premenu_textures.
	grav->textbox.h / 2, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[2].h = ft_dmap(data->premenu_textures.
	grav->textbox.h, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[3].x = ft_dmap(270, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[3].y = ft_dmap(220 - data->premenu_textures.
	icon.rect.h / 2, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[4].x = ft_dmap(445, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[4].y = ft_dmap(220 - data->premenu_textures.
	icon.rect.h / 2, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[5].x = ft_dmap(250, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[5].y = ft_dmap(265 - data->premenu_textures.
	icon.rect.h / 2, 480, 0, data->win.win_res.h);
	set_optmenu_textures_rects_p3(data);
}

void		set_optmenu_textures_rects(t_editor *data)
{
	data->premenu_textures.dest[0].x = ft_dmap(305, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[0].w = ft_dmap(100, 640, 0,
	data->win.win_res.w);
	data->premenu_textures.dest[0].y = ft_dmap(72, 480, 0,
	data->win.win_res.h);
	data->premenu_textures.dest[0].h = ft_dmap(25, 480, 0,
	data->win.win_res.h);
	data->premenu_textures.dest[1].x = ft_dmap(263 - data->premenu_textures.
	size->textbox.w / 2, 640, 0, data->win.win_res.w);
	data->premenu_textures.dest[1].w = ft_dmap(data->premenu_textures.
	size->textbox.w, 640, 0, data->win.win_res.w);
	data->premenu_textures.dest[1].y = ft_dmap(130 - data->premenu_textures.
	size->textbox.h / 2, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[1].h = ft_dmap(data->premenu_textures.
	size->textbox.h, 480, 0, data->win.win_res.h);
	data->premenu_textures.dest[2].x = ft_dmap(263 - data->premenu_textures.
	grav->textbox.w / 2, 640, 0, data->win.win_res.w);
	data->premenu_textures.dest[2].w = ft_dmap(data->premenu_textures.
	grav->textbox.w, 640, 0, data->win.win_res.w);
	set_optmenu_textures_rects_p2(data);
}

static void	draw_editor_optmenu_p2(t_editor *data)
{
	if (data->map.lighting)
		SDL_RenderCopy(data->win.renderer, data->premenu_textures.icon.texture,
		NULL, &data->premenu_textures.dest[3]);
	if (data->map.shadow)
		SDL_RenderCopy(data->win.renderer, data->premenu_textures.icon.texture,
		NULL, &data->premenu_textures.dest[4]);
	if (data->map.rain)
		SDL_RenderCopy(data->win.renderer, data->premenu_textures.icon.texture,
		NULL, &data->premenu_textures.dest[5]);
	if (data->map.fog)
		SDL_RenderCopy(data->win.renderer, data->premenu_textures.icon.texture,
		NULL, &data->premenu_textures.dest[6]);
	if (data->map.bubbles)
		SDL_RenderCopy(data->win.renderer, data->premenu_textures.icon.texture,
		NULL, &data->premenu_textures.dest[7]);
	if (data->map.psy)
		SDL_RenderCopy(data->win.renderer, data->premenu_textures.icon.texture,
		NULL, &data->premenu_textures.dest[8]);
}

void		draw_editor_optmenu(t_editor *data)
{
	int			x;
	int			y;

	SDL_GetMouseState(&x, &y);
	if (data->premenu_textures.hover)
		SDL_RenderCopy(data->win.renderer, data->menu_textures
		[data->menus[data->current_menu].texture_blur_id].texture, NULL, NULL);
	else
		SDL_RenderCopy(data->win.renderer, data->menu_textures
		[data->menus[data->current_menu].texture_id].texture, NULL, NULL);
	SDL_RenderCopy(data->win.renderer, data->premenu_textures.skybox
	[data->map.skybox_id].texture, NULL, &data->premenu_textures.dest[0]);
	SDL_RenderCopy(data->win.renderer, data->premenu_textures.size->texture,
	NULL, &data->premenu_textures.dest[1]);
	SDL_RenderCopy(data->win.renderer, data->premenu_textures.grav->texture,
	NULL, &data->premenu_textures.dest[2]);
	draw_editor_optmenu_p2(data);
	render_cursor(data->win.renderer, data->cursor[data->button_pressed],
		data->events.mousex, data->events.mousey);
}
