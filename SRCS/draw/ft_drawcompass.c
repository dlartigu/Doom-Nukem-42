/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawcompass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:09:06 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 19:46:03 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_drawcompass(int x, int y, t_env *env, t_elem *floor)
{
	int		cray;
	int		cmpr;
	t_pixel	cmppixela;
	t_pixel	cmppixelb;

	env = NULL;
	cray = 0;
	cmpr = 30;
	while (cray < 10)
	{
		cmppixela.x = x;
		cmppixela.y = y;
		cmppixelb.x = cmppixela.x + cos(floor->angle) * cmpr + cray;
		cmppixelb.y = cmppixela.y - sin(floor->angle) * cmpr;
		ft_bresenham(floor->radarsurf, cmppixela, cmppixelb, floor->red);
		cray++;
	}
}
