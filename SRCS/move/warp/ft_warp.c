/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:15:16 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/17 00:44:15 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

uint32_t	ft_timerwarp(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	floor->warp_enable = 1;
	if (floor->timerwarp)
		SDL_RemoveTimer(floor->timerwarp);
	floor->timerwarp = 0;
	return (interval);
}

int			ft_rand_range(int min, int max, int except)
{
	int	res;

	res = (rand() % (max - min + 1)) + min;
	while (res == except)
		res = (rand() % (max - min + 1)) + min;
	return (res);
}

static void	ft_warptowarpsetup(t_elem *floor, int except)
{
	int i;

	i = ft_rand_range(0, floor[floor->currentstair].max_warp - 1, except);
	floor->posx = floor[floor->currentstair].warp[i].x;
	floor->posy = floor[floor->currentstair].warp[i].y;
	floor->warp_enable = 0;
	if (!floor->timerwarp)
		floor->timerwarp = SDL_AddTimer(5000, ft_timerwarp, floor);
}

void		ft_warptowarp(t_elem *floor)
{
	int i;
	int except;

	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '7' && floor->warp_enable == 1)
	{
		if (floor[floor->currentstair].max_warp > 1)
		{
			i = 0;
			while (i <= floor[floor->currentstair].max_warp)
			{
				if ((int)floor->posx
					== (int)floor[floor->currentstair].warp[i].x
						&& (int)floor->posy
							== (int)floor[floor->currentstair].warp[i].y)
					except = i;
				i++;
			}
			ft_warptowarpsetup(floor, except);
		}
	}
}
