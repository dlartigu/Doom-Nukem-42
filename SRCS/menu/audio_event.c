/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 02:40:05 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/01 22:02:55 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	audio_menu_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->audio_choice = (env->audio_choice + 1) % 5;
	else if (env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->audio_choice = (env->audio_choice + 4) % 5;
	else if (env->events.type == SDL_MOUSEMOTION && x > 205 && x < 593)
	{
		if (y >= 90 && y < 135)
			env->audio_choice = 0;
		else if (y >= 135 && y < 162)
			env->audio_choice = 1;
		else if (y >= 162 && y < 216)
			env->audio_choice = 2;
		else if (y >= 306 && y < 360)
			env->audio_choice = 3;
		else if (y >= 360 && y < 405)
			env->audio_choice = 4;
	}
}

void	menu_apply_audio_params(t_env *env)
{
	env->apply_audio_op = 0;
	if (env->audio_menu == 1)
	{
		FMOD_Channel_SetVolume(env->audio.channels[0],
			(float)env->int_volume_value / 10.0f);
		FMOD_Channel_SetPaused(env->audio.channels[0], !env->music_op);
	}
}

void	apply_menu_audio(t_env *env, SDL_Event *event)
{
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
		&& event->key.keysym.sym == SDLK_RETURN)) && env->audio_choice != 4)
	{
		if (env->audio_choice == 0)
		{
			env->int_volume_value = (env->int_volume_value % 9) + 1;
			env->audio.volume = (float)env->int_volume_value / 10.0f;
		}
		else if (env->audio_choice == 1)
			env->music_op ^= 1;
		else if (env->audio_choice == 2)
			env->effect_op ^= 1;
		else if (env->audio_choice == 3)
			env->apply_audio_op = 1;
	}
	else if (test_return(env->audio_choice == 4, event))
	{
		env->settings_menu = 1;
		env->audio_menu = 0;
	}
}
