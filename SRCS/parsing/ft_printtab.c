/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:16 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/17 13:53:16 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_printspawn(t_elem *floor)
{
	ft_putendl("Player position:");
	ft_putstr("Starting floor: ");
	ft_putnbr(floor->spawn_floor);
	ft_putchar('\n');
	ft_putstr("X Position:     ");
	ft_putnbr(floor->spawn_x);
	ft_putchar('\n');
	ft_putstr("Y Position:     ");
	ft_putnbr(floor->spawn_y);
	ft_putchar('\n');
}

void			ft_printmap(t_elem *floor)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < floor->max_floor + 1)
	{
		ft_putstr("Etage: ");
		ft_putnbr(i);
		ft_putchar('\n');
		j = 0;
		while (j < floor[i].hight)
		{
			k = -1;
			while (++k < floor[i].width)
			{
				ft_putstr(floor[i].new[j][k]);
				ft_putchar(' ');
			}
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
	}
	ft_printspawn(floor);
}
