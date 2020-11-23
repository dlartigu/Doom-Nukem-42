/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons_timers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:29:11 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/19 16:40:39 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static uint32_t			ft_shotgun_timer(t_env *env)
{
	if (env->hud.shotgun_flag == 1)
		return (ft_shotgun_timer2(env));
	if (env->hud.shotgun_flag == 0)
	{
		env->hud.weapon_step++;
		if (env->hud.weapon_step == 4)
			play_simple(&env->audio, EFF_SHOTGUN_RELOAD, CH_SHOTGUN_RELOAD, 1);
		if (env->hud.weapon_step == 7)
			play_simple(&env->audio, EFF_SHOTGUN_RELOAD, CH_SHOTGUN_RELOAD, 1);
		if (env->hud.weapon_step == 10)
			play_simple(&env->audio, EFF_SHOTGUN_RELOAD, CH_SHOTGUN_RELOAD, 1);
		if (env->hud.weapon_step == 13)
			play_simple(&env->audio, EFF_SHOTGUN_RELOAD, CH_SHOTGUN_RELOAD, 1);
		if (env->hud.weapon_step == 15)
			play_simple(&env->audio, EFF_SHOTGUN_LOAD, CH_SHOTGUN_LOAD, 1);
		return (ft_shotgun_amount_steps(env));
	}
	return (100);
}

static uint32_t			ft_set_dev_timer(t_env *env)
{
	env->hud.weapon_step++;
	if (env->hud.weapon_step == 1)
		play_simple(&env->audio, EFF_DEVASTATOR_RELOAD, CH_DEVASTATOR, 1);
	if (env->hud.weapon_step == 5)
		play_simple(&env->audio, EFF_DEVASTATOR, CH_DEVASTATOR, 1);
	if (env->hud.weapon_step > 12)
	{
		env->hud.weapon_step = 0;
		env->hud.dev_flag = 0;
		env->switchlock = 0;
		if (env->hud.weapon_timer)
			SDL_RemoveTimer(env->hud.weapon_timer);
		env->hud.weapon_timer = 0;
	}
	return (150);
}

static uint32_t			ft_pistol_timer(t_env *env)
{
	if (env->hud.pistol_flag == 1)
		return (ft_pistol_timer2(env));
	if (env->hud.pistol_flag == 0)
	{
		env->hud.weapon_step++;
		if (env->hud.weapon_step == 1)
			play_simple(&env->audio, EFF_PISTOL_RELOAD, CH_PISTOL_RELOAD, 1);
		if (env->hud.weapon_step > 11)
		{
			env->hud.pistol_flag = 2;
			env->hud.weapon_step = 0;
			env->switchlock = 0;
			if (env->hud.weapon_timer)
				SDL_RemoveTimer(env->hud.weapon_timer);
			env->hud.weapon_timer = 0;
		}
		return (200);
	}
	return (100);
}

uint32_t				ft_weapons_timer(uint32_t interval, void *param)
{
	t_env	*env;

	env = param;
	if (env->hud.devastator_selected == 1 && env->hud.dev_flag == 1)
		return (ft_set_dev_timer(env));
	else if (env->hud.pistol_selected == 1)
		return (ft_pistol_timer(env));
	else if (env->hud.shotgun_selected == 1)
		return (ft_shotgun_timer(env));
	else
		return (ft_set_fist_timer(env));
	return (interval);
}
