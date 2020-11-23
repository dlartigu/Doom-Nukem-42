/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolfcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:28 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/13 19:10:02 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int			ft_wolfcheck(t_elem *floor)
{
	int		i;
	int		j;
	int		k;

	floor->min = 0;
	i = -1;
	while (++i < floor->max_floor)
	{
		j = -1;
		while (floor[i].map[++j])
		{
			k = -1;
			while (floor[i].map[j][++k])
			{
				floor->max = ft_strlen(floor[i].map[j][k]);
				if (floor->max > floor->min)
					floor->min = floor->max;
			}
		}
	}
	return (0);
}

static int	ft_checkvalue2(t_elem *floor, int i, int j, int k)
{
	if (floor[i].map[j][k][0] != '0' && floor[i].map[j][k][0] != '1'
		&& floor[i].map[j][k][0] != '#'
			&& floor[i].map[j][k][0] != '2'
				&& floor[i].map[j][k][0] != '3'
					&& floor[i].map[j][k][0] != '4'
						&& floor[i].map[j][k][0] != '5'
							&& floor[i].map[j][k][0] != '6'
								&& floor[i].map[j][k][0] != '7'
									&& floor[i].map[j][k][0] != '8'
										&& floor[i].map[j][k][0] != '9')
		return (1);
	else
		return (0);
}

int			ft_checkvalue(t_elem *floor)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < floor->max_floor)
	{
		j = 0;
		while (floor[i].map[j])
		{
			k = 0;
			while (floor[i].map[j][k])
			{
				if (ft_checkvalue2(floor, i, j, k) == 1)
					return (1);
				else
					k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
