/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_editor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:40:11 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 09:50:47 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"
#include "../../INCLUDES/prog.h"

static void		set_window_size(t_sdl_data *win, t_sdl *sdl, t_env *env)
{
	win->win = env->win;
	win->renderer = env->ren;
	win->win_res.w = (int)sdl->res_width;
	win->win_res.h = (int)sdl->res_hight;
	win->map_res.h = win->win_res.h;
	win->map_res.w = ft_dmap(480, 640, 0, win->win_res.w);
	win->menu_res.x = win->map_res.w;
	win->menu_res.h = win->win_res.h;
	win->menu_res.w = win->win_res.w - win->map_res.w;
}

static void		set_editor_defaults(t_editor *data)
{
	data->map.gravity = 1;
	data->draw_menu_textures = 1;
	data->current_block.skybox = 1;
	data->zoom = 1;
	data->map.size = 20;
	data->win.zoomed_map.w = (BLOCK_SIZE * data->map.size);
	data->win.zoomed_map.h = (BLOCK_SIZE * data->map.size);
	data->fit_in_win = 1;
	data->win.map_texture.rect.x = 0;
	data->win.map_texture.rect.y = 0;
}

int				check_warp_editor(t_elem *elem)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	k = 0;
	if (!(elem->warp = ft_memalloc(sizeof(t_warp) * 2500)))
		return (ft_printerror("check_warp_editor"));
	while (elem->map[++i])
	{
		j = -1;
		while (elem->map[i][++j])
		{
			if (SPRITE < ft_strlen(elem->map[i][j]))
				if (elem->map[i][j][SPRITE] == '7')
				{
					elem->warp[k].x = j + 0.5;
					elem->warp[k].y = i + 0.5;
					k++;
				}
		}
	}
	elem->max_warp = k;
	return (1);
}

int				start_editor_p2(t_editor *data, t_elem *elem,
				int ret)
{
	data->changed = 1;
	data->current_menu = OPTIONS_MENU;
	if (ret)
		ret = loop(data);
	free_editor(data);
	if (ret && data->spawn_x && data->spawn_y)
		if (!save_map(data, elem))
			return (ft_printerror("ERROR: save_map"));
	elem->hight = data->map.size;
	elem->width = data->map.size;
	if (ret && elem->map)
	{
		elem->spawn_x = data->spawn_x + 0.5;
		elem->spawn_y = data->spawn_y + 0.5;
		if (!check_warp_editor(elem))
			return (0);
		elem->new = elem->map;
		elem->map = NULL;
	}
	return (ret ? ret : ft_printerror("ERROR: Editor crashed"));
}

int				start_editor(t_env *env, t_sdl *sdl, t_elem *elem)
{
	t_editor	data;
	int			ret;

	env->startmenu = 1;
	ft_bzero(&data, sizeof(data));
	SDL_GetMouseState(&data.events.mousex, &data.events.mousey);
	render_cursor(env->ren, env->cursors[1], data.events.mousex,
		data.events.mousey);
	data.cursor[0] = env->cursors[1];
	data.cursor[1] = env->cursors[0];
	set_window_size(&data.win, sdl, env);
	set_editor_defaults(&data);
	ret = init_editor(&data);
	return (start_editor_p2(&data, elem, ret));
}
