/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_items_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:44:10 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:29:30 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static uint32_t	ft_timerpsy(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->timerlollipop)
		SDL_RemoveTimer(floor->timerlollipop);
	floor->lollipop = 0;
	floor->negative = 0;
	floor->timerlollipop = 0;
	return (interval);
}

static uint32_t	ft_timerballoon(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->timerballoon)
		SDL_RemoveTimer(floor->timerballoon);
	floor->balloon = 0;
	floor->timerballoon = 0;
	floor->game_msg = 0;
	if (floor->fly == 1)
		floor->timerflydown = SDL_AddTimer(10
			* floor->gravity, ft_flydown, floor);
	return (interval);
}

void			ft_ticket(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '5')
	{
		floor->ticket = 1;
		floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE] = '0';
		remove_item(&floor->items, (int)floor->posx, (int)floor->posy);
	}
}

void			ft_lollipop(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '4' && floor->lollipop == 0)
	{
		floor->lollipop = 1;
		floor->negative = 1;
		floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE] = '0';
		remove_item(&floor->items, (int)floor->posx, (int)floor->posy);
		if (!floor->timerlollipop)
			floor->timerlollipop = SDL_AddTimer(15000, ft_timerpsy, floor);
	}
}

void			ft_balloon(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '3' && floor->balloon == 0)
	{
		floor->balloon = 1;
		floor->game_msg = 1;
		floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE] = '0';
		remove_item(&floor->items, (int)floor->posx, (int)floor->posy);
		if (!floor->timerballoon)
			floor->timerballoon = SDL_AddTimer(15000, ft_timerballoon, floor);
	}
}
