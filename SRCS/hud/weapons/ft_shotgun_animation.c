/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shotgun_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:58:23 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/05 16:34:37 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_event_shotgun2(t_env *env, t_elem *floor)
{
	if ((env->events.key.keysym.sym == SDLK_r && env->events.type
	== SDL_KEYDOWN && floor->usable_ammo_shotgun < 4
	&& floor->max_ammo_shotgun > 0) || (env->events.type == SDL_MOUSEBUTTONDOWN
	&& env->events.button.button == SDL_BUTTON_LEFT
	&& floor->usable_ammo_shotgun == 0 && floor->max_ammo_shotgun > 0))
	{
		if (!env->hud.weapon_timer)
		{
			env->hud.shotgun_flag = 0;
			env->switchlock = 1;
			env->hud.amount = ft_shotgun_reload_amount(floor);
			env->hud.weapon_timer = SDL_AddTimer(0, ft_weapons_timer,
				env);
			if (!floor->shoot_delay)
				floor->shoot_delay = SDL_AddTimer(0, ft_reload_timer, floor);
		}
	}
}

uint32_t		ft_shotgun_timer2(t_env *env)
{
	env->hud.weapon_step++;
	if (env->hud.weapon_step == 1)
		play_simple(&env->audio, EFF_SHOTGUN, CH_SHOTGUN, 1);
	if (env->hud.weapon_step == 4)
		play_simple(&env->audio, EFF_SHOTGUN_LOAD, CH_SHOTGUN_LOAD, 1);
	if (env->hud.weapon_step > 4 && env->hud.weapon_step < 8)
		return (200);
	if (env->hud.weapon_step > 8)
	{
		env->hud.shotgun_flag = 2;
		env->hud.weapon_step = 0;
		env->switchlock = 0;
		if (env->hud.weapon_timer)
			SDL_RemoveTimer(env->hud.weapon_timer);
		env->hud.weapon_timer = 0;
	}
	return (80);
}

void			ft_event_shotgun(t_env *env, t_elem *floor)
{
	if (env->events.type == SDL_MOUSEBUTTONDOWN && env->events.button.button
	== SDL_BUTTON_LEFT && floor->usable_ammo_shotgun == 0
	&& floor->max_ammo_shotgun == 0)
		play_simple(&env->audio, EFF_PISTOL_EMPTY, CH_PISTOL, 1);
	if (env->events.type == SDL_MOUSEBUTTONDOWN && env->events.button.button
	== SDL_BUTTON_LEFT && floor->usable_ammo_shotgun > 0)
	{
		if (!env->hud.weapon_timer)
		{
			attack_enemy(floor, floor->enemy_target, NULL, 0);
			floor->impact = 1;
			env->hud.shotgun_flag = 1;
			env->switchlock = 1;
			env->hud.weapon_timer = SDL_AddTimer(0, ft_weapons_timer,
				env);
			if (!floor->shoot_delay)
				floor->shoot_delay = SDL_AddTimer(0,
					ft_spend_ammo_timer, floor);
		}
	}
	else
		ft_event_shotgun2(env, floor);
}

void			ft_draw_shotgun(t_env *env, t_elem *floor)
{
	if (floor->shotgun_selected == 1)
	{
		if (env->hud.shotgun_flag == 1)
		{
			SDL_RenderCopy(env->ren,
				env->hud.shotgun_text[env->hud.weapon_step], NULL,
					&env->hud.rect_sho_p1);
		}
		else if (env->hud.shotgun_flag == 0)
		{
			SDL_RenderCopy(env->ren,
				env->hud.shotgun_text[env->hud.weapon_step + 7], NULL,
					&env->hud.rect_sho_p1);
		}
		else if (env->hud.shotgun_flag == 2)
		{
			SDL_RenderCopy(env->ren, env->hud.shotgun_text[0],
				NULL, &env->hud.rect_sho_p1);
		}
	}
}
