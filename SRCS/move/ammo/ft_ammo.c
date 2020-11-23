/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ammo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:04:50 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:27:38 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static	void	ft_reinitsprite(t_elem *floor)
{
	floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] = '0';
	floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE] = '0';
	remove_item(&floor->items, (int)floor->posx, (int)floor->posy);
}

static	void	ft_pistol_ammo(t_elem *floor)
{
	floor->max_ammo_pistol = floor->max_ammo_pistol + 12;
	if (floor->max_ammo_pistol > 40)
		floor->max_ammo_pistol = 40;
	ft_reinitsprite(floor);
}

static	void	ft_shotgun_ammo(t_elem *floor)
{
	floor->max_ammo_shotgun = floor->max_ammo_shotgun + 6;
	if (floor->max_ammo_shotgun > 20)
		floor->max_ammo_shotgun = 20;
	ft_reinitsprite(floor);
}

static	void	ft_devastator_ammo(t_elem *floor)
{
	if (floor->usable_ammo_legendary >= 1)
		;
	else if (floor->usable_ammo_legendary == 0)
	{
		floor->usable_ammo_legendary = 1;
		ft_reinitsprite(floor);
	}
}

void			ft_ammos(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '2')
	{
		if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '0'
				|| !(floor[floor->currentstair].new[(int)floor->posy]
					[(int)floor->posx][SPRITE_TEXT]))
			;
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '7'
			&& floor->max_ammo_pistol < 40)
			ft_pistol_ammo(floor);
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '8'
			&& floor->max_ammo_shotgun < 20)
			ft_shotgun_ammo(floor);
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '9'
			&& floor->usable_ammo_legendary < 1)
			ft_devastator_ammo(floor);
	}
}
