/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload_timers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:29:43 by jcharrou          #+#    #+#             */
/*   Updated: 2020/10/16 22:31:24 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void			ft_reload_shotgun2(t_elem *floor)
{
	if (floor->usable_ammo_shotgun + floor->max_ammo_shotgun > 4)
	{
		floor->max_ammo_shotgun = (floor->usable_ammo_shotgun +
			floor->max_ammo_shotgun) - 4;
		floor->usable_ammo_shotgun = 4;
	}
	else
	{
		floor->usable_ammo_shotgun = floor->usable_ammo_shotgun +
			floor->max_ammo_shotgun;
		floor->max_ammo_shotgun = 0;
	}
}

static uint32_t		ft_reload_shotgun(t_elem *floor)
{
	int amount;

	amount = 4 - floor->usable_ammo_shotgun;
	if (floor->max_ammo_shotgun > 3)
	{
		floor->max_ammo_shotgun = floor->max_ammo_shotgun -
			(4 - floor->usable_ammo_shotgun);
		floor->usable_ammo_shotgun = 4;
	}
	else
		ft_reload_shotgun2(floor);
	if (floor->shoot_delay)
		SDL_RemoveTimer(floor->shoot_delay);
	floor->shoot_delay = 0;
	return (100);
}

static uint32_t		ft_reload_pistol(t_elem *floor)
{
	if (floor->max_ammo_pistol > 7)
	{
		floor->max_ammo_pistol = floor->max_ammo_pistol -
			(8 - floor->usable_ammo_pistol);
		floor->usable_ammo_pistol = 8;
	}
	else
	{
		if (floor->usable_ammo_pistol + floor->max_ammo_pistol > 8)
		{
			floor->max_ammo_pistol = (floor->usable_ammo_pistol +
				floor->max_ammo_pistol) - 8;
			floor->usable_ammo_pistol = 8;
		}
		else
		{
			floor->usable_ammo_pistol = floor->usable_ammo_pistol +
				floor->max_ammo_pistol;
			floor->max_ammo_pistol = 0;
		}
	}
	if (floor->shoot_delay)
		SDL_RemoveTimer(floor->shoot_delay);
	floor->shoot_delay = 0;
	return (10);
}

uint32_t			ft_reload_timer(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->pistol_selected == 1)
		return (ft_reload_pistol(floor));
	if (floor->shotgun_selected == 1)
		return (ft_reload_shotgun(floor));
	return (interval);
}
