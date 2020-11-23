/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:35:31 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:11:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int	parse_button_skins(t_editor *data, int fd)
{
	int		i;
	char	*str;

	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (6)"));
	data->nb_btn_skins = ft_atoi(skip_info(str));
	ft_strdel(&str);
	if (data->nb_btn_skins < 1 || data->nb_btn_skins > 20)
		return (ft_printerror("ERROR: Invalid number of button skins"));
	if (!(data->button_skins = (t_sdl_text*)ft_calloc(sizeof(t_sdl_text),
			data->nb_btn_skins)))
		return (ft_printerror("ERROR: Malloc"));
	i = 0;
	while (i < data->nb_btn_skins)
	{
		if (get_next_line(fd, &str) < 1)
			return (ft_printerror("ERROR: GNL (7)"));
		if (!load_bmp(data->win.renderer,
		skip_info(str), &data->button_skins[i], 1))
			return (ft_errordel("COULDN'T LOAD BUTTON SKIN", (void**)&str));
		ft_strdel(&str);
		i++;
	}
	return (1);
}

int	parse_menu_textures(t_editor *data, int fd)
{
	int		i;
	char	*str;

	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (8)"));
	data->nb_menu_textures = ft_atoi(skip_info(str));
	ft_strdel(&str);
	if (data->nb_menu_textures < 1 || data->nb_menu_textures > 10)
		return (ft_printerror("ERROR: Number of menu textures "
		"isn't between 1 and 10."));
	if (!(data->menu_textures = (t_sdl_text*)ft_calloc(sizeof(t_sdl_text),
	data->nb_menu_textures)))
		return (ft_printerror("ERROR: Malloc"));
	i = 0;
	while (i < data->nb_menu_textures)
	{
		if (get_next_line(fd, &str) < 1)
			return (ft_printerror("ERROR: GNL (9)"));
		if (!load_bmp(data->win.renderer, skip_info(str),
		&data->menu_textures[i], 0))
			return (ft_errordel("COULDN'T LOAD MENU TEXTURE", (void**)&str));
		ft_strdel(&str);
		i++;
	}
	return (1);
}

int	load_counters_ttf_p2(t_editor *data, TTF_Font *font)
{
	SDL_Color	col;
	char		*tmp;
	int			i;

	ft_memset(&col, 0x00, sizeof(SDL_Color));
	col.r = 255;
	i = 0;
	while (i < 10)
	{
		if (!(tmp = ft_itoa(i)))
			return (ft_printerror("ERROR: ft_itoa"));
		if (!(data->ttf_digits[i] = create_str_texture(data->win.renderer,
				tmp, col, font)))
			return (ft_errordel("ERROR: create_str_texture", (void**)&tmp));
		ft_strdel(&tmp);
		i++;
	}
	if (!(data->ttf_wave = create_str_texture(data->win.renderer,
			"+", col, font)))
		return (ft_printerror("ERROR: create_str_texture"));
	return (1);
}

int	load_menu_p2(t_editor *data, int fd)
{
	int	i;

	if (!(data->menus = (t_menu*)ft_calloc(sizeof(t_menu), data->nb_menus)))
		return (ft_printerror("ERROR: Malloc"));
	i = -1;
	while (++i < data->nb_menus)
		if (!(parse_menu(&data->menus[i], fd, data)))
			return (ft_printerror("ERROR: parse_menu"));
	if (!(load_counters_ttf(data, data->fonts[1])))
		return (ft_printerror("ERROR: load_counters_ttf"));
	data->inited = 1;
	return (1);
}

int	load_menu(t_editor *data)
{
	char	*str;
	int		fd;

	if ((fd = open(MENU_CONF, O_RDONLY)) <= 0)
		return (ft_printerror("ERROR: open"));
	if (!(parse_menu_fonts(data, fd)))
		return (ft_printerror("ERROR: parse_menu_fonts"));
	if (!(parse_button_skins(data, fd)))
		return (ft_printerror("ERROR: parse_button_skins"));
	if (!(parse_menu_textures(data, fd)))
		return (ft_printerror("ERROR: parse_menu_textures"));
	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (10)"));
	data->nb_menus = ft_atoi(skip_info(str));
	ft_strdel(&str);
	return (load_menu_p2(data, fd));
}
