/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:44:54 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/19 16:15:58 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_radarblock(t_elem *floor)
{
	if (!floor[floor->currentstair].new[floor->j][floor->k][0])
		floor->color = floor->white;
	if (floor[floor->currentstair].new[floor->j][floor->k][0] == '1'
	|| floor[floor->currentstair].new[floor->j][floor->k][0] == '4')
		floor->color = floor->grey;
	else
		floor->color = floor->white;
	if (((int)floor->posy == floor->j)
		&& ((int)floor->posx == floor->k))
		floor->color = floor->blue;
}

static	void	ft_minimapinit(t_env *env, t_elem *floor)
{
	if (floor[floor->currentstair].width >= floor[floor->currentstair].hight)
	{
		floor->rect.w = env->res_width / floor[floor->currentstair].width / 2;
		floor->rect.h = floor->rect.w;
	}
	else if (floor[floor->currentstair].width
		<= floor[floor->currentstair].hight)
	{
		floor->rect.h = env->res_width / floor[floor->currentstair].hight / 2;
		floor->rect.w = floor->rect.h;
	}
}

static	void	ft_miniblock(t_elem *floor)
{
	if (floor[floor->currentstair].new[floor->j][floor->k][0] == '1')
		floor->color = floor->grey;
	else
		floor->color = floor->white;
	if (((int)floor->posy == floor->j) && ((int)floor->posx == floor->k))
	{
		floor->color = floor->blue;
		floor->playerrect.x = floor->rect.x + floor->rect.h / 2;
		floor->playerrect.y = floor->rect.y + floor->rect.h / 2;
	}
}

void			ft_minimap(t_env *env, t_elem *floor)
{
	floor->j = floor[floor->currentstair].hight;
	ft_minimapinit(env, floor);
	floor->rect.y = (env->res_hight / 2)
		- ((floor[floor->currentstair].hight * floor->rect.w
			+ floor[floor->currentstair].hight) / 2);
	while (--floor->j > 0)
	{
		floor->k = -1;
		floor->rect.x = (env->res_width / 2)
			- ((floor[floor->currentstair].width * floor->rect.w
				+ floor[floor->currentstair].width) / 2);
		while (++floor->k < floor[floor->currentstair].width)
		{
			ft_miniblock(floor);
			ft_drawrect(floor->minimapsurf, floor->color, floor->rect);
			floor->rect.x = floor->rect.x + floor->rect.w;
		}
		floor->rect.y = floor->rect.y + floor->rect.h;
	}
}

void			ft_radar(t_env *env, t_elem *floor)
{
	floor->radar.w = 20;
	floor->radar.h = 20;
	floor->radar.y = 10;
	floor->j = (int)floor->posy + 1;
	while (floor->j > (int)floor->posy - 2)
	{
		floor->k = (int)floor->posx - 1;
		floor->radar.x = 10;
		while (floor->k < (int)floor->posx + 2)
		{
			ft_radarblock(floor);
			ft_drawrect(floor->radarsurf, floor->color, floor->radar);
			floor->k++;
			floor->radar.x = floor->radar.x + floor->radar.w + 1;
		}
		floor->j--;
		floor->radar.y = floor->radar.y + floor->radar.h + 1;
	}
	ft_drawcompass(40, 40, env, floor);
}
