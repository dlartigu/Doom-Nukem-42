/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shoot_timers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:29:38 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/19 16:38:14 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static uint32_t		ft_spend_dev_ammo(t_elem *floor)
{
	if (floor->usable_ammo_legendary > 0)
		floor->usable_ammo_legendary--;
	if (floor->shoot_delay)
		SDL_RemoveTimer(floor->shoot_delay);
	floor->shoot_delay = 0;
	return (50);
}

static uint32_t		ft_spend_shotgun_ammo(t_elem *floor)
{
	if (floor->usable_ammo_shotgun > 0)
		floor->usable_ammo_shotgun--;
	if (floor->shoot_delay)
		SDL_RemoveTimer(floor->shoot_delay);
	floor->shoot_delay = 0;
	return (100);
}

static uint32_t		ft_spend_pistol_ammo(t_elem *floor)
{
	if (floor->usable_ammo_pistol > 0)
		floor->usable_ammo_pistol--;
	if (floor->shoot_delay)
		SDL_RemoveTimer(floor->shoot_delay);
	floor->shoot_delay = 0;
	return (10);
}

uint32_t			ft_spend_ammo_timer(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->pistol_selected == 1)
		return (ft_spend_pistol_ammo(floor));
	if (floor->shotgun_selected == 1)
		return (ft_spend_shotgun_ammo(floor));
	if (floor->devastator_selected == 1)
		return (ft_spend_dev_ammo(floor));
	return (interval);
}
