/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:23:21 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/14 22:41:09 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

uint32_t		ft_shotgun_amount_steps(t_env *env)
{
	if (env->hud.weapon_step == 4)
	{
		if (env->hud.amount == 1)
			env->hud.weapon_step = 14;
		if (env->hud.amount == 2)
			env->hud.weapon_step = 11;
		if (env->hud.amount == 3)
			env->hud.weapon_step = 8;
		if (env->hud.amount == 4)
			env->hud.weapon_step = 5;
	}
	if (env->hud.weapon_step > 18)
	{
		env->hud.shotgun_flag = 2;
		env->hud.weapon_step = 0;
		if (env->hud.weapon_timer)
			SDL_RemoveTimer(env->hud.weapon_timer);
		env->hud.weapon_timer = 0;
	}
	return (150);
}

int				ft_shotgun_reload_amount(t_elem *floor)
{
	int amount;

	amount = 4 - floor->usable_ammo_shotgun;
	if (amount <= floor->max_ammo_shotgun)
		return (amount);
	return (floor->max_ammo_shotgun);
}

void			ft_set_floor_to_hud_weapons(t_env *env, t_elem *floor)
{
	env->hud.pistol_selected = floor->pistol_selected;
	env->hud.fist_selected = floor->fist_selected;
	env->hud.shotgun_selected = floor->shotgun_selected;
	env->hud.devastator_selected = floor->devastator_selected;
	env->hud.usable_ammo_shotgun = floor->usable_ammo_shotgun;
	env->hud.max_ammo_shotgun = floor->max_ammo_shotgun;
}

void			ft_set_weapon(t_elem *floor, int pistol, int shotgun, int dev)
{
	floor->fist_selected = 0;
	floor->pistol_selected = pistol;
	floor->shotgun_selected = shotgun;
	floor->devastator_selected = dev;
	if (!pistol && !shotgun && !dev)
		floor->fist_selected = 1;
}

void			ft_set_weapon_struct(t_env *env)
{
	env->hud.fire_step = 0;
	env->hud.weapon_step = 0;
	env->hud.fist_flag = 3;
	env->hud.pistol_flag = 2;
	env->hud.shotgun_flag = 2;
}
