/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:59:56 by niboute           #+#    #+#             */
/*   Updated: 2020/10/14 08:31:13 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

char	*skip_info(char *str)
{
	if (*str == '"')
	{
		while (*str && *str != ':')
			str++;
		if (*str == ':')
			str++;
	}
	return (str);
}

int		skip_to_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int		read_btn_pos(int *tab, int nb, char *str, int max)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (nb > 0 && str[i] && count < max)
	{
		*tab = ft_atoi(str + i);
		count += *tab;
		if (*tab < 1 || *tab > MAX_BUTTONS_LINE)
			return (ft_printerror("ERROR: MAX_BUTTONS_LINE invalid."));
		i += skip_to_number(str + i);
		tab++;
		nb--;
	}
	return (1);
}

int		parse_menu_fonts_p2(t_editor *data, int fd, char **fonts_path,
						int nb_fonts_path)
{
	char	*str;

	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: (GNL (1))"));
	data->nb_fonts = ft_atoi(skip_info(str));
	ft_strdel(&str);
	if (data->nb_fonts < 1 || data->nb_fonts > 10)
		return (ft_printerror("ERROR: Font size number should be"
		" between 1 and 10"));
	if (!(data->fonts = (TTF_Font**)ft_calloc(sizeof(TTF_Font*),
			data->nb_fonts)))
		return (ft_printerror("ERROR: malloc (1) couldn't allocate memory."));
	return (load_fonts(data, fd, fonts_path, nb_fonts_path));
}

int		parse_menu_fonts(t_editor *data, int fd)
{
	int		i;
	int		nb_fonts_path;
	char	**fonts_path;
	char	*str;

	if (get_next_line(fd, &str) < 1)
		return (ft_printerror("ERROR: GNL (2)"));
	nb_fonts_path = ft_atoi(skip_info(str));
	ft_strdel(&str);
	if (nb_fonts_path < 1 || nb_fonts_path > 3)
		return (ft_printerror("ERROR: Number of fonts path isn't valid"));
	if (!(fonts_path = (char**)ft_calloc(sizeof(char*), nb_fonts_path)))
		return (ft_printerror("ERROR: Malloc"));
	i = -1;
	while (++i < nb_fonts_path)
	{
		if (get_next_line(fd, &str) < 1)
			return (ft_printerror("ERROR: GNL (3)"));
		if (!(fonts_path[i] = ft_strdup(skip_info(str))))
			ft_tabdel((void***)&fonts_path, i);
		if (!fonts_path[i])
			return (ft_errordel("ERROR: ft_strdup", (void**)&str));
		ft_strdel(&str);
	}
	return (parse_menu_fonts_p2(data, fd, fonts_path, nb_fonts_path));
}
