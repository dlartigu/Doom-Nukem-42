/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:06 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:45:39 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int						ft_parsemapret(t_elem *floor)
{
	ft_putstr("Multithreading on ");
	floor->nb_threads = sysconf(_SC_NPROCESSORS_CONF);
	ft_putnbr(floor->nb_threads);
	ft_putendl(" logical CPU");
	if (ft_checkspawn(floor, 0, 0) == 1)
		return (ft_error(BAD_SPAWN));
	if (ft_filwidth(floor) == 1)
		return (ft_error(6));
	if (ft_wolfcheck(floor) == 1)
		return (ft_error(8));
	if (ft_checkvalue(floor) == 1)
		return (ft_error(8));
	else
		return (0);
}

static void				ft_create_floors_malloc(t_elem *floor, int i)
{
	int			j;

	j = 0;
	floor[i].map = (char ***)ft_memalloc(sizeof(char **) * 100);
	while (floor[i].box[j])
	{
		floor[i].map[j] = ft_strsplit(floor[i].box[j], ' ');
		j++;
	}
}

static t_elem			*ft_create_floors(t_map *map)
{
	t_elem		*floor;
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(map->tmp, '|');
	while (tab[i] != NULL)
		i++;
	floor = (t_elem *)ft_memalloc(sizeof(t_elem) * (i + 1));
	floor->max_floor = i;
	i = -1;
	while (++i < floor->max_floor)
		floor[i].box = ft_strsplit(tab[i], '\n');
	i = -1;
	while (++i < floor->max_floor)
		ft_create_floors_malloc(floor, i);
	ft_memdel((void **)&map->line);
	ft_memdel((void **)&map->tmp);
	ft_freetab(&tab);
	return (floor);
}

static	void			ft_while_gnl(t_map *map)
{
	while (get_next_line(map->fd, &map->line))
	{
		if (map->line[0] == '/' || map->line[0] == 13)
			;
		else
		{
			map->tmp = join_free(map->tmp, map->line);
			map->tmp = join_free(map->tmp, "\n");
		}
		ft_strdel(&map->line);
	}
}

int						ft_parse_map_param(t_map *map)
{
	t_elem		*floor;
	int			ret;

	ret = 0;
	map->fd = (open(map->file, O_RDONLY));
	if (map->fd == -1)
		return (1);
	map->tmp = ft_strnew(0);
	ft_while_gnl(map);
	ft_strdel(&map->line);
	close(map->fd);
	floor = ft_create_floors(map);
	init_sprites_data(&floor->sprites_data[0]);
	load_sprites_textures(floor);
	ret = ft_parsemapret(floor);
	if (!ret)
		ft_newmap(floor);
	map->floor = floor;
	map->floor->sensitivity_setup = 1;
	map->floor->texture_res = 1;
	return (ret);
}
