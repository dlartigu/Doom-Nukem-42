/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 01:15:49 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 19:21:33 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	int		ft_check_warp(t_elem *floor, int j, int k, int l)
{
	if (floor->map[j][k][SPRITE] == '7')
	{
		floor->warp[l].x = k + 1.5;
		floor->warp[l].y = j + 1.5;
		return (1);
	}
	return (0);
}

static	void	ft_checkspawninit(t_elem *floor, int j, int k)
{
	if (floor->map[j][k][0] == '#')
	{
		floor->spawn_x = k + 1.5;
		floor->spawn_y = j + 1.5;
	}
}

void			ft_checkspawneditor(t_elem *floor)
{
	int i;
	int j;
	int k;

	i = 7;
	j = -1;
	while (floor->map[++j])
	{
		k = -1;
		while (floor->map[j][++k])
			ft_checkspawninit(floor, j, k);
	}
	floor->new = floor->map;
	floor->map = NULL;
}

int				ft_checkspawn(t_elem *floor, int i, int j)
{
	int k;
	int	l;

	i = -1;
	while (++i < floor->max_floor)
	{
		j = -1;
		l = 0;
		if (!(floor[i].warp = ft_memalloc(sizeof(t_warp) * 2500)))
			ft_fct_error("malloc failed");
		while (floor[i].map[++j])
		{
			k = -1;
			while (floor[i].map[j][++k])
			{
				ft_checkspawninit(&floor[i], j, k);
				if (ft_check_warp(&floor[i], j, k, l) == 1)
					l++;
			}
		}
		floor[i].max_warp = l;
	}
	return (0);
}
