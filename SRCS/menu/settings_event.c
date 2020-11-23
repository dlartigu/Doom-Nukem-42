/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:21:52 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 18:20:55 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			settings_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.sym == SDLK_s)
		env->settings_choice = (env->settings_choice + 1) % 4;
	else if (env->events.type == SDL_KEYDOWN
		&& env->events.key.keysym.sym == SDLK_w)
		env->settings_choice = (env->settings_choice + 3) % 4;
	else if (env->events.type == SDL_MOUSEMOTION && x > 205 && x < 592)
	{
		if (y >= 90 && y < 162)
			env->settings_choice = 0;
		else if (y >= 162 && y < 216)
			env->settings_choice = 1;
		else if (y >= 216 && y < 270)
			env->settings_choice = 2;
		else if (y >= 360 && y < 405)
			env->settings_choice = 3;
	}
}

void			apply_settings(t_env *env, SDL_Event *event)
{
	env->settings_menu = 0;
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)) && env->settings_choice != 3)
	{
		if (env->settings_choice == 0)
		{
			env->vid_menu = 1;
			env->video_choice = 0;
		}
		else if (env->settings_choice == 1)
		{
			env->audio_menu = 1;
			env->audio_choice = 0;
		}
		else if (env->settings_choice == 2)
		{
			env->gameplay_menu = 1;
			env->game_choice = 0;
		}
	}
	else if (test_return(env->settings_choice == 3, event))
		env->startmenu = 1;
	else
		env->settings_menu = 1;
}
