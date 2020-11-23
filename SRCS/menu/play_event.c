/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:24:27 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/05 10:17:50 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	play_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->play_choice = (env->play_choice + 1) % 3;
	else if (env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->play_choice = (env->play_choice + 2) % 3;
	else if (env->events.type == SDL_MOUSEMOTION && x > 205 && x < 593)
	{
		if (y >= 150 && y < 210)
			env->play_choice = 0;
		else if (y >= 210 && y < 255)
			env->play_choice = 1;
		else if (y >= 300 && y < 345)
			env->play_choice = 2;
	}
}

void	apply_play(t_env *env, SDL_Event *event)
{
	env->play_menu = 0;
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)) && env->play_choice != 2)
	{
		if (env->play_choice == 0)
		{
			env->story_menu = 1;
			env->story_difficulty = 0;
		}
		else if (env->play_choice == 1)
		{
			env->arcade_menu = 1;
			env->arcade_choice = 0;
		}
	}
	else if (test_return(env->play_choice == 2, event))
		env->startmenu = 1;
	else
		env->play_menu = 1;
}
