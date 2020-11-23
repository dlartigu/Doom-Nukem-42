/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fist_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:58:02 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/13 21:08:37 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_event_fist2(t_env *env, t_elem *floor)
{
	if (env->events.type == SDL_MOUSEBUTTONDOWN &&
		env->events.button.button == SDL_BUTTON_MIDDLE)
	{
		if (!env->hud.weapon_timer)
		{
			attack_enemy(floor, floor->enemy_target, NULL, 0);
			env->hud.fist_flag = 2;
			env->switchlock = 1;
			env->hud.weapon_timer = SDL_AddTimer(0, ft_weapons_timer,
				env);
		}
	}
}

void			ft_event_fist(t_env *env, t_elem *floor)
{
	if (env->events.type == SDL_MOUSEBUTTONDOWN && env->events.button.button
		== SDL_BUTTON_LEFT)
	{
		if (!env->hud.weapon_timer)
		{
			attack_enemy(floor, floor->enemy_target, NULL, 0);
			env->hud.fist_flag = 1;
			env->switchlock = 1;
			env->hud.weapon_timer = SDL_AddTimer(0, ft_weapons_timer, env);
		}
	}
	else if (env->events.type == SDL_MOUSEBUTTONDOWN &&
		env->events.button.button == SDL_BUTTON_RIGHT)
	{
		if (!env->hud.weapon_timer)
		{
			attack_enemy(floor, floor->enemy_target, NULL, 0);
			env->hud.fist_flag = 0;
			env->switchlock = 1;
			env->hud.weapon_timer = SDL_AddTimer(0, ft_weapons_timer,
				env);
		}
	}
	else
		ft_event_fist2(env, floor);
}

void			ft_draw_fist(t_env *env)
{
	if (env->hud.fist_flag == 1)
	{
		SDL_RenderCopy(env->ren, env->hud.fist_text[env->hud.weapon_step], NULL,
			&env->hud.rect_fist_p1);
	}
	else if (env->hud.fist_flag == 0)
	{
		SDL_RenderCopy(env->ren, env->hud.fist_text[env->hud.weapon_step + 3],
			NULL, &env->hud.rect_fist_p1);
	}
	else if (env->hud.fist_flag == 2)
	{
		SDL_RenderCopy(env->ren, env->hud.fist_text[env->hud.weapon_step + 6],
			NULL, &env->hud.rect_fist_p1);
	}
	else
	{
		SDL_RenderCopy(env->ren, env->hud.fist_text[0], NULL,
			&env->hud.rect_fist_p1);
	}
}
