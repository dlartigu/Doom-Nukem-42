/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fist_timers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:01:10 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/19 16:37:41 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static	uint32_t		ft_set_fist_timer_p3(t_env *env)
{
	env->hud.weapon_step = 0;
	env->hud.fist_flag = 3;
	env->switchlock = 0;
	if (env->hud.weapon_timer)
		SDL_RemoveTimer(env->hud.weapon_timer);
	env->hud.weapon_timer = 0;
	return (100);
}

static	uint32_t		ft_set_fist_timer_p2(t_env *env)
{
	env->hud.weapon_step = 0;
	env->hud.fist_flag = 3;
	env->switchlock = 0;
	if (env->hud.weapon_timer)
		SDL_RemoveTimer(env->hud.weapon_timer);
	env->hud.weapon_timer = 0;
	return (100);
}

uint32_t				ft_set_fist_timer(t_env *env)
{
	env->hud.weapon_step++;
	if (env->hud.weapon_step == 1)
		play_simple(&env->audio, EFF_PUNCH, CH_PUNCH, 1);
	if (env->hud.fist_flag == 2)
	{
		if (env->hud.weapon_step > 2)
			ft_set_fist_timer_p2(env);
	}
	if (env->hud.weapon_step > 3)
		ft_set_fist_timer_p3(env);
	return (100);
}
