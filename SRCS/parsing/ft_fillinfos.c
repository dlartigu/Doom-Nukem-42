/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillinfos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:50:33 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:45:02 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_fillwidthstart(t_elem *floor)
{
	int		i;
	int		k;

	i = -1;
	while (++i < floor->max_floor)
	{
		k = 0;
		while (floor[i].map[0][k])
			k++;
		floor[i].width = k;
	}
}

int				ft_filwidth(t_elem *floor)
{
	int		i;
	int		j;
	int		k;

	ft_fillwidthstart(floor);
	i = -1;
	while (++i < floor->max_floor)
	{
		j = 0;
		while (floor[i].map[j])
		{
			k = 0;
			while (floor[i].map[j][k])
				k++;
			if (k != floor[i].width)
				return (1);
			j++;
		}
		floor[i].hight = j;
	}
	floor->j = 0;
	floor->k = 0;
	return (0);
}
