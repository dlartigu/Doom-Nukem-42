/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:13:38 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/15 00:54:25 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static char			*ft_read(int fd, char *str)
{
	int				ret;
	char			*ptr;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
		{
			free(str);
			return (NULL);
		}
		buf[ret] = '\0';
		ptr = str;
		str = ft_strjoin(str, buf);
		ft_memdel((void **)&ptr);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (str);
}

static void			ft_sline(char **save, char **line)
{
	size_t			size;
	char			*tmp;

	size = 0;
	tmp = NULL;
	while ((*save)[size] != '\n' && (*save)[size] != '\0')
		size++;
	if ((*save)[size] == '\n')
	{
		*line = ft_strsub(*save, 0, size);
		tmp = *save;
		*save = ft_strsub(*save, size + 1, ft_strlen(*save) - ft_strlen(*line));
		ft_memdel((void **)&tmp);
	}
	else if ((*save)[size] == '\0')
	{
		*line = ft_strdup(*save);
		ft_memdel((void **)save);
	}
}

int					get_next_line(const int fd, char **line)
{
	static	t_tab	*save[4096] = {0x0};

	if ((fd < 0) || (line == NULL) || (read(fd, 0, 0) < 0))
		return (-1);
	if (!save[fd])
	{
		if (!(save[fd] = (t_tab *)ft_memalloc(sizeof(t_tab))))
			return (-1);
		save[fd]->fd = fd;
		save[fd]->str = ft_strnew(0);
	}
	if (!save[fd]->str)
		save[fd]->str = ft_strnew(0);
	save[fd]->str = ft_read(fd, save[fd]->str);
	ft_sline(&(save[fd])->str, line);
	if (!save[fd]->str && *line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}
