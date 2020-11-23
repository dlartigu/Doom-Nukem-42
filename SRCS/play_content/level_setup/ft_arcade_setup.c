/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arcade_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:00:24 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 18:11:55 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void			ft_setup_arcade_helper(t_env *env, t_elem *floor)
{
	ft_setup_level_helper(env, floor);
	init_counter(floor, 120);
	floor->difficulty = 2;
	floor->devastator = 1;
	floor->pistol = 1;
	floor->shotgun = 1;
	floor->usable_ammo_legendary = 0;
	floor->usable_ammo_pistol = 0;
	floor->usable_ammo_shotgun = 0;
	floor->max_ammo_legendary = 0;
	floor->max_ammo_pistol = 0;
	floor->max_ammo_shotgun = 0;
	floor->drawceiling = 1;
	floor->printscore = 1;
}

void				ft_arcade_custom(t_env *env, t_elem *floor)
{
	ft_setup_arcade_helper(env, floor);
	floor->gravity = floor[7].custom_gravity;
	floor->fog = floor[7].custom_lighting;
	floor->shadow = floor[7].custom_shadow;
	floor->rain = floor[7].custom_rain;
	floor->lava_glow = floor[7].custom_fog;
	floor->underwater = floor[7].custom_bubbles;
	floor->negative = floor[7].custom_psy;
	load_skyboxes(env, floor);
	floor->angle = M_PI / 2;
	floor->last_rain_state = floor->rain;
}

void				ft_arcade_magma(t_env *env, t_elem *floor)
{
	ft_restore_backup(floor);
	ft_setup_arcade_helper(env, floor);
	floor->shadow = 0;
	floor->lava_glow = 1;
	floor->underwater = 1;
	load_skyboxes(env, floor);
	floor->angle = M_PI / 2;
}

void				ft_arcade_mine(t_env *env, t_elem *floor)
{
	ft_restore_backup(floor);
	ft_setup_arcade_helper(env, floor);
	floor->shadow = 1;
	floor->rain = 0;
	floor->angle = M_PI / 2;
}

void				ft_arcade_circus(t_env *env, t_elem *floor)
{
	ft_restore_backup(floor);
	ft_setup_arcade_helper(env, floor);
	floor->rain = 1;
	load_skyboxes(env, floor);
	floor->angle = M_PI;
	floor->last_rain_state = floor->rain;
}
