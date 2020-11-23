/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:41:33 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/14 22:40:45 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_switch_weapon_down2(t_hud *hud, t_elem *floor)
{
	if (floor->shotgun == 0 && (hud->weapon_choosen == 2
		|| hud->weapon_choosen == -2))
		ft_switch_weapon_down(hud, floor);
	if (floor->shotgun == 1 && (hud->weapon_choosen == 2
		|| hud->weapon_choosen == -2))
		ft_set_weapon(floor, 0, 1, 0);
	if (floor->pistol == 0 && (hud->weapon_choosen == 1
		|| hud->weapon_choosen == -3))
		ft_switch_weapon_down(hud, floor);
	if (floor->pistol == 1 && (hud->weapon_choosen == 1
		|| hud->weapon_choosen == -3))
		ft_set_weapon(floor, 1, 0, 0);
}

static void		ft_switch_weapon_up2(t_hud *hud, t_elem *floor)
{
	if (floor->shotgun == 1 && (hud->weapon_choosen == 2
		|| hud->weapon_choosen == -2))
		ft_set_weapon(floor, 0, 1, 0);
	if (floor->shotgun == 0 && (hud->weapon_choosen == 2
		|| hud->weapon_choosen == -2))
		ft_switch_weapon_up(hud, floor);
	if (floor->devastator == 1 && (hud->weapon_choosen == 3
		|| hud->weapon_choosen == -1))
		ft_set_weapon(floor, 0, 0, 1);
	if (floor->devastator == 0 && (hud->weapon_choosen == 3
		|| hud->weapon_choosen == -1))
		ft_switch_weapon_up(hud, floor);
}

void			ft_switch_weapon_down(t_hud *hud, t_elem *floor)
{
	hud->weapon_choosen--;
	if (hud->weapon_choosen == 5)
		hud->weapon_choosen = 1;
	if (hud->weapon_choosen == 4 || hud->weapon_choosen == 0
		|| hud->weapon_choosen == -4)
	{
		hud->weapon_choosen = 4;
		ft_set_weapon(floor, 0, 0, 0);
	}
	if (floor->devastator == 0 && (hud->weapon_choosen == 3
		|| hud->weapon_choosen == -1))
		ft_switch_weapon_down(hud, floor);
	if (floor->devastator == 1 && (hud->weapon_choosen == 3
		|| hud->weapon_choosen == -1))
		ft_set_weapon(floor, 0, 0, 1);
	ft_switch_weapon_down2(hud, floor);
}

void			ft_switch_weapon_up(t_hud *hud, t_elem *floor)
{
	hud->weapon_choosen++;
	if (hud->weapon_choosen == 5)
	{
		hud->weapon_choosen = 1;
	}
	if (hud->weapon_choosen == 4 || hud->weapon_choosen == 0
		|| hud->weapon_choosen == -4)
	{
		hud->weapon_choosen = 0;
		ft_set_weapon(floor, 0, 0, 0);
	}
	if (floor->pistol == 0 && (hud->weapon_choosen == 1
		|| hud->weapon_choosen == -3))
		ft_switch_weapon_up(hud, floor);
	if (floor->pistol == 1 && (hud->weapon_choosen == 1
		|| hud->weapon_choosen == -3))
		ft_set_weapon(floor, 1, 0, 0);
	ft_switch_weapon_up2(hud, floor);
}

void			ft_weapons_events(t_env *env, t_elem *floor)
{
	ft_set_floor_to_hud_weapons(env, floor);
	if (floor->devastator_selected == 1)
		ft_event_dev(env, floor);
	else if (floor->pistol_selected == 1)
		ft_event_pistol(env, floor);
	else if (floor->shotgun_selected == 1)
		ft_event_shotgun(env, floor);
	else if (floor->fist_selected == 1)
		ft_event_fist(env, floor);
	if (env->switchlock == 0)
	{
		if (env->events.wheel.type == SDL_MOUSEWHEEL && env->events.wheel.y < 0)
			ft_switch_weapon_down(&env->hud, floor);
		if (env->events.wheel.type == SDL_MOUSEWHEEL && env->events.wheel.y > 0)
			ft_switch_weapon_up(&env->hud, floor);
	}
}
