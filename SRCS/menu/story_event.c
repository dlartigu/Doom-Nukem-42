/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   story_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:43:48 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/31 10:14:11 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			story_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->story_difficulty = (env->story_difficulty + 1) % 4;
	else if (env->events.type == SDL_KEYDOWN
		&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->story_difficulty = (env->story_difficulty + 3) % 4;
	else if (env->events.type == SDL_MOUSEMOTION && x > 133 && x < 666)
	{
		if (y >= 150 && y < 210)
			env->story_difficulty = 0;
		else if (y >= 210 && y < 255)
			env->story_difficulty = 1;
		else if (y >= 255 && y < 300)
			env->story_difficulty = 2;
		else if (y >= 300 && y < 345)
			env->story_difficulty = 3;
	}
}

void			apply_story(t_env *env, SDL_Event *event)
{
	env->story_menu = 0;
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)) && env->story_difficulty != 3)
		env->play_ready = 1;
	else if (test_return(env->story_difficulty == 3, event))
	{
		env->play_menu = 1;
		env->play_choice = 0;
	}
	else
		env->story_menu = 1;
}
