/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:25:44 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/31 11:37:01 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	gameplay_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->game_choice = (env->game_choice + 1) % 5;
	else if (env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->game_choice = (env->game_choice + 4) % 5;
	else if (env->events.type == SDL_MOUSEMOTION && x > 205 && x < 593)
	{
		if (y >= 90 && y < 135)
			env->game_choice = 0;
		else if (y >= 135 && y < 162)
			env->game_choice = 1;
		else if (y >= 162 && y < 207)
			env->game_choice = 2;
		else if (y >= 297 && y < 351)
			env->game_choice = 3;
		else if (y >= 351 && y < 414)
			env->game_choice = 4;
	}
}

void	apply_gameplay(t_env *env, t_elem *floor, SDL_Event *event)
{
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)) && env->game_choice != 4)
	{
		if (env->game_choice == 0)
			env->dif_op = (env->dif_op + 1) % 3;
		else if (env->game_choice == 1)
			env->sens_value = (env->sens_value % 9) + 1;
		else if (env->game_choice == 2)
		{
			env->controls_menu = 1;
			env->gameplay_menu = 0;
		}
		else if (env->game_choice == 3)
			floor->sensitivity_setup = env->sens_value;
	}
	else if (test_return(env->game_choice == 4, event))
	{
		env->settings_choice = 3;
		env->settings_menu = 1;
		env->gameplay_menu = 0;
	}
}
