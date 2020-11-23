/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medkit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:03:02 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 11:26:24 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static	void	ft_medkit_hp(t_elem *floor, int hp)
{
	floor->life += hp;
	if (floor->life > 100)
		floor->life = 100;
	if (floor->life >= 50 || floor->prevlife >= 50)
	{
		floor->ragdollsensi = 1;
		floor->crouchsensi = 1;
		floor->flysensi = 1;
	}
	floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] = '0';
	floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE] = '0';
	remove_item(&floor->items, (int)floor->posx, (int)floor->posy);
}

static	void	ft_medkit_exception(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '0'
				|| !(floor[floor->currentstair].new[(int)floor->posy]
					[(int)floor->posx][SPRITE_TEXT]))
		floor->message = 0;
}

void			ft_medkit(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '2')
	{
		ft_medkit_exception(floor);
		if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '1' && floor->life < 100)
			ft_medkit_hp(floor, 10);
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '2' && floor->life < 100)
			ft_medkit_hp(floor, 20);
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '3' && floor->life < 100)
		{
			floor->message = 4;
			if (floor->keystat[SDL_SCANCODE_E])
				ft_medkit_hp(floor, 50);
		}
	}
}
