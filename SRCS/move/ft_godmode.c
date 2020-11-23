/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_godmode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 00:29:03 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/19 16:43:20 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_godmode_toggle_off(t_elem *floor)
{
	floor->godmode = 0;
	floor->devastator = floor->s_dev;
	floor->pistol = floor->s_pistol;
	floor->shotgun = floor->s_shot;
	floor->usable_ammo_legendary = floor->s_dev_use_ammo;
	floor->usable_ammo_pistol = floor->s_pistol_use_ammo;
	floor->usable_ammo_shotgun = floor->s_shot_use_ammo;
	floor->max_ammo_legendary = floor->s_dev_ammo;
	floor->max_ammo_pistol = floor->s_pistol_ammo;
	floor->max_ammo_shotgun = floor->s_shot_ammo;
	floor->pistol_selected = 0;
	floor->shotgun_selected = 0;
	floor->devastator_selected = 0;
	floor->fist_selected = 1;
}

void		ft_godmode_toggle_on(t_elem *floor)
{
	floor->godmode = 1;
	floor->ragdollsensi = 1;
	floor->crouchsensi = 1;
	floor->speedragdoll = 0.00;
	floor->s_dev = floor->devastator;
	floor->s_pistol = floor->pistol;
	floor->s_shot = floor->shotgun;
	floor->s_dev_use_ammo = floor->usable_ammo_legendary;
	floor->s_pistol_use_ammo = floor->usable_ammo_pistol;
	floor->s_shot_use_ammo = floor->usable_ammo_shotgun;
	floor->s_dev_ammo = floor->max_ammo_legendary;
	floor->s_pistol_ammo = floor->max_ammo_pistol;
	floor->s_shot_ammo = floor->max_ammo_shotgun;
}

void		ft_godmode_toggle(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_4 && env->events.type == SDL_KEYDOWN)
	{
		if (!floor->godmode)
			ft_godmode_toggle_on(floor);
		else if (floor->godmode)
			ft_godmode_toggle_off(floor);
	}
}

void		ft_godmode(t_elem *floor)
{
	if (floor->godmode)
	{
		floor->prevlife = 100;
		floor->life = 100;
		floor->noclip = 1;
		floor->speed = floor->speed * 20;
		floor->devastator = 1;
		floor->pistol = 1;
		floor->shotgun = 1;
		floor->usable_ammo_legendary = 1;
		floor->usable_ammo_pistol = 8;
		floor->usable_ammo_shotgun = 4;
		floor->max_ammo_legendary = 1;
		floor->max_ammo_pistol = 20;
		floor->max_ammo_shotgun = 40;
	}
	if (!floor->godmode)
		floor->noclip = 0;
}
