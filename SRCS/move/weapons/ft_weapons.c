/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:46:00 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 11:27:37 by niboute          ###   ########.fr       */
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

static	void	ft_pistol(t_elem *floor)
{
	if (floor->pistol == 1)
	{
		floor->max_ammo_pistol = floor->max_ammo_pistol + 8;
		if (floor->max_ammo_pistol > 40)
			floor->max_ammo_pistol = 40;
	}
	else
	{
		floor->pistol = 1;
		floor->usable_ammo_pistol = 8;
	}
	ft_reinitsprite(floor);
}

static	void	ft_shotgun(t_elem *floor)
{
	if (floor->shotgun == 1)
	{
		floor->max_ammo_pistol = floor->max_ammo_shotgun + 4;
		if (floor->max_ammo_shotgun > 20)
			floor->max_ammo_shotgun = 20;
	}
	else
	{
		floor->shotgun = 1;
		floor->usable_ammo_shotgun = 4;
	}
	ft_reinitsprite(floor);
}

static	void	ft_devastator(t_elem *floor)
{
	if (floor->devastator == 1)
	{
		floor->max_ammo_legendary = floor->max_ammo_legendary + 1;
		if (floor->max_ammo_legendary > 1)
			floor->max_ammo_legendary = 1;
	}
	else
	{
		floor->devastator = 1;
		floor->usable_ammo_legendary = 1;
	}
	ft_reinitsprite(floor);
}

void			ft_weapons(t_elem *floor)
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
			[(int)floor->posx][SPRITE_TEXT] == '4')
			ft_pistol(floor);
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '5')
			ft_shotgun(floor);
		else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][SPRITE_TEXT] == '6')
			ft_devastator(floor);
	}
}
