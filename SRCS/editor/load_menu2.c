/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:00:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:42:06 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int	read_button_data(t_menu *menu, int fd, t_editor *data, char *str)
{
	int			i;
	SDL_Color	col;

	ft_memset(&col, 0x00, sizeof(SDL_Color));
	col.r = 255;
	i = -1;
	while (++i < menu->nb_buttons)
	{
		if (get_next_line(fd, &str) < 1)
			return (ft_printerror("ERROR: GNL (4)"));
		menu->skin_id[i] = ft_atoi(skip_info(str));
		ft_strdel(&str);
		if (menu->skin_id[i] < 0 || menu->skin_id[i] >= data->nb_btn_skins)
			return (ft_printerror("ERROR: Invalid button skin id"));
		if (get_next_line(fd, &str) < 1)
			return (ft_printerror("ERROR: GNL (5)"));
		if (!(menu->button_str[i] = ft_strdup(skip_info(str))))
			return (ft_errordel("ERROR: ft_strdup", (void**)&str));
		ft_strdel(&str);
		if (menu->button_str[i][0])
			if (!(menu->ttf[i] = create_str_texture(data->win.renderer,
				menu->button_str[i], col, data->fonts[i == 0 ? 0 : 1])))
				return (ft_printerror("ERROR: Create_str_texture"));
	}
	return (1);
}

int	init_menu_tabs(t_menu *menu)
{
	if (!(menu->button_str = (char**)ft_calloc(sizeof(char*),
		menu->nb_buttons)))
		return (ft_printerror("ERROR: malloc (1) couldn't allocate memory."));
	if (!(menu->skin_id = (int*)ft_calloc(sizeof(int), menu->nb_buttons)))
		return (ft_printerror("ERROR: malloc (2) couldn't allocate memory."));
	if (!(menu->ttf = (t_ttf_text**)ft_calloc(sizeof(t_ttf_text*),
			menu->nb_buttons)))
		return (ft_printerror("ERROR: malloc (3) couldn't allocate memory."));
	if (!(menu->buttons_pos = (SDL_Rect*)ft_calloc(sizeof(SDL_Rect),
			menu->nb_buttons)))
		return (ft_printerror("ERROR: malloc (4) couldn't allocate memory."));
	return (1);
}

int	parse_menu_p2(t_menu *menu, int fd, t_editor *data)
{
	char	*str;

	if (!init_menu_tabs(menu))
		return (ft_printerror("ERROR: init_menu_tabs"));
	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (11)"));
	menu->nb_menu_sections = ft_atoi(skip_info(str));
	ft_strdel(&str);
	if (menu->nb_menu_sections < 1 || menu->nb_menu_sections > MAX_BUTTONS)
		return (ft_printerror("ERROR: Invalid nb of sections in menu."));
	if (!(menu->button_per_sec = (int*)ft_calloc(sizeof(int),
			menu->nb_menu_sections)))
		return (ft_printerror("ERROR: malloc couldn't allocate memory."));
	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (12)"));
	if (!read_btn_pos(menu->button_per_sec, menu->nb_menu_sections,
		skip_info(str), menu->nb_buttons))
		return (ft_errordel("ERROR: read_btn_pos", (void**)&str));
	ft_strdel(&str);
	if (!read_button_data(menu, fd, data, NULL))
		return (ft_printerror("ERROR: read_button_data"));
	return (1);
}

int	parse_menu(t_menu *menu, int fd, t_editor *data)
{
	char	*str;

	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (13)"));
	ft_strdel(&str);
	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (14)"));
	menu->nb_buttons = ft_atoi(skip_info(str));
	ft_strdel(&str);
	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (15)"));
	menu->texture_id = ft_atoi(skip_info(str));
	if (menu->texture_id < 0 || menu->texture_id >= data->nb_menu_textures)
		return (ft_errordel("ERROR: Invalid texture id (1)", (void**)&str));
	menu->texture_blur_id = ft_atoi(skip_info(str)
	+ skip_to_number(skip_info(str)));
	ft_strdel(&str);
	if (menu->texture_blur_id < 0
	|| menu->texture_blur_id >= data->nb_menu_textures)
		return (ft_printerror("ERROR: Invalid texture id (2)"));
	if (menu->nb_buttons == 0)
		return (1);
	if (menu->nb_buttons < 0 || menu->nb_buttons > MAX_BUTTONS)
		return (ft_printerror("ERROR: Invalid nb of buttons in menu."));
	return (parse_menu_p2(menu, fd, data));
}

int	load_fonts(t_editor *data, int fd, char **fonts_path,
						int nb_fonts_path)
{
	int		i;
	int		font_id;
	int		font_size;
	char	*str;
	int		j;

	i = 0;
	while (i < data->nb_fonts)
	{
		if (get_next_line(fd, &str) < 1)
			return (ft_printerror("ERROR: GNL (16)"));
		font_id = ft_atoi(skip_info(str));
		j = skip_to_number(skip_info(str));
		font_size = ft_atoi(skip_info(str) + j);
		ft_strdel(&str);
		if (font_id < 0 || font_id > data->nb_fonts || font_size < 1)
			return (ft_printerror("ERROR: Font id or Font size is invalid."));
		if (!(data->fonts[i] = TTF_OpenFont(fonts_path[font_id], font_size)))
			return (ft_printerror("ERROR: TTF_OpenFont"));
		i++;
	}
	ft_tabdel((void***)&fonts_path, nb_fonts_path);
	return (1);
}
