/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_timers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:36:02 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/05 16:39:50 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_remove_timers4(t_env *env)
{
	if (env->hud.shoot_pistol_timer)
		SDL_RemoveTimer(env->hud.shoot_pistol_timer);
	if (env->hud.reload_pistol_timer)
		SDL_RemoveTimer(env->hud.reload_pistol_timer);
	if (env->hud.shoot_shotgun_timer)
		SDL_RemoveTimer(env->hud.shoot_shotgun_timer);
	if (env->hud.reload_shotgun_timer)
		SDL_RemoveTimer(env->hud.reload_shotgun_timer);
	if (env->hud.left_fist_timer)
		SDL_RemoveTimer(env->hud.left_fist_timer);
	if (env->hud.right_fist_timer)
		SDL_RemoveTimer(env->hud.right_fist_timer);
	if (env->hud.kick_timer)
		SDL_RemoveTimer(env->hud.kick_timer);
}

static void		ft_remove_timers3(t_env *env)
{
	if (env->timer)
		SDL_RemoveTimer(env->timer);
	if (env->timer2)
		SDL_RemoveTimer(env->timer2);
	if (env->hud.weapon_timer)
		SDL_RemoveTimer(env->hud.weapon_timer);
	if (env->hud.head_guy_timer)
		SDL_RemoveTimer(env->hud.head_guy_timer);
	if (env->hud.shoot_dev_timer)
		SDL_RemoveTimer(env->hud.shoot_dev_timer);
	if (env->hud.reload_dev_timer)
		SDL_RemoveTimer(env->hud.reload_dev_timer);
	ft_remove_timers4(env);
}

static void		ft_remove_timers2(t_env *env, t_elem *floor)
{
	if (floor->chrono)
		SDL_RemoveTimer(floor->chrono);
	if (floor->negatifflashtimer)
		SDL_RemoveTimer(floor->negatifflashtimer);
	if (floor->timer_flashtoflash)
		SDL_RemoveTimer(floor->timer_flashtoflash);
	if (floor->timerragdolldown)
		SDL_RemoveTimer(floor->timerragdolldown);
	if (floor->timerragdollup)
		SDL_RemoveTimer(floor->timerragdollup);
	if (floor->timerwarp)
		SDL_RemoveTimer(floor->timerwarp);
	if (floor->timerballoon)
		SDL_RemoveTimer(floor->timerballoon);
	if (floor->timerlollipop)
		SDL_RemoveTimer(floor->timerlollipop);
	if (floor->test_shot)
		SDL_RemoveTimer(floor->test_shot);
	if (floor->shoot_delay)
		SDL_RemoveTimer(floor->shoot_delay);
	if (floor->timetext)
		SDL_RemoveTimer(floor->timetext);
	ft_remove_timers3(env);
}

void			ft_remove_timers(t_env *env, t_elem *floor)
{
	if (floor->timercrouchdown)
		SDL_RemoveTimer(floor->timercrouchdown);
	if (floor->timercrouchup)
		SDL_RemoveTimer(floor->timercrouchup);
	if (floor->timerjump)
		SDL_RemoveTimer(floor->timerjump);
	if (floor->timerwalk)
		SDL_RemoveTimer(floor->timerwalk);
	if (floor->timerflyup)
		SDL_RemoveTimer(floor->timerflyup);
	if (floor->timerflydown)
		SDL_RemoveTimer(floor->timerflydown);
	if (floor->timer3)
		SDL_RemoveTimer(floor->timer3);
	if (floor->timer_rain)
		SDL_RemoveTimer(floor->timer_rain);
	if (floor->time_rain_fog)
		SDL_RemoveTimer(floor->time_rain_fog);
	if (floor->timer_bubble)
		SDL_RemoveTimer(floor->timer_bubble);
	if (floor->timer_bubble_progress)
		SDL_RemoveTimer(floor->timer_bubble_progress);
	ft_remove_timers2(env, floor);
}
