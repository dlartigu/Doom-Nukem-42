/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfloor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:42:03 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 11:42:38 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_filmap(t_elem *floor)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < floor->max_floor)
	{
		j = 0;
		floor[i].max_blockheight = 0;
		while (floor[i].map[j])
		{
			k = 0;
			while (floor[i].map[j][k])
			{
				ft_strcpy(floor[i].new[j + 1][k + 1], floor[i].map[j][k]);
				ft_strcpy(floor[i].new_backup[j + 1][k + 1],
					floor[i].map[j][k]);
				if ((ft_ctoi(&floor[i].map[j][k][4]) + 1)
					> floor[i].max_blockheight)
					floor[i].max_blockheight = ft_ctoi(&floor[i].map[j][k][4]);
				k++;
			}
			j++;
		}
	}
}

static	void	ft_newmapmalloc(t_elem *floor, int i, int j, int k)
{
	size_t	len;

	if (j < floor[i].nh && k < floor[i].nw)
	{
		len = 10;
		floor[i].new[j][k] = (char *)ft_memalloc(sizeof(char)
			* (len < 10 ? 10 : len));
		floor[i].new_backup[j][k] = (char *)ft_memalloc(sizeof(char)
			* (len < 10 ? 10 : len));
	}
	else
	{
		floor[i].new[j][k] = (char *)ft_memalloc(sizeof(char) * 10);
		floor[i].new_backup[j][k] = (char *)ft_memalloc(sizeof(char) * 10);
	}
	ft_strcpy(floor[i].new[j][k], "1H009000");
	ft_strcpy(floor[i].new_backup[j][k], "1H009000");
}

static	void	ft_newmapinit(t_elem *floor)
{
	int	i;

	i = -1;
	while (++i < floor->max_floor)
	{
		floor[i].nh = floor[i].hight;
		floor[i].nw = floor[i].width;
		floor[i].hight = floor[i].hight + 2;
		floor[i].width = floor[i].width + 2;
	}
}

void			ft_newmap(t_elem *floor)
{
	int	i;
	int	j;
	int	k;

	ft_newmapinit(floor);
	i = -1;
	while (++i < floor->max_floor)
	{
		floor[i].new =
			(char ***)ft_memalloc(sizeof(char **) * (floor[i].hight + 1));
		floor[i].new_backup =
			(char ***)ft_memalloc(sizeof(char **) * (floor[i].hight + 1));
		j = -1;
		while (++j < floor[i].hight)
		{
			k = -1;
			floor[i].new[j] = (char **)ft_memalloc(sizeof(char *)
				* (floor[i].width + 1));
			floor[i].new_backup[j] = (char **)ft_memalloc(sizeof(char *)
				* (floor[i].width + 1));
			while (++k < floor[i].width)
				ft_newmapmalloc(floor, i, j, k);
		}
	}
	ft_filmap(floor);
}
