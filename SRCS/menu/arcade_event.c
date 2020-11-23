/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arcade_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:23:34 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/05 12:50:57 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			arcade_event(t_env *env, int x, int y, int max)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->arcade_choice = (env->arcade_choice + 1) % 2;
	else if (env->events.type == SDL_KEYDOWN
		&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->arcade_choice = (env->arcade_choice + 1) % 2;
	else if (env->events.type == SDL_MOUSEMOTION && x > 150 && x < 656)
	{
		if (y >= 353 && y < 390)
			env->arcade_choice = 0;
		else if (y >= 390 && y < 426)
			env->arcade_choice = 1;
	}
	else if ((env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_A)
	|| (env->events.type == SDL_MOUSEBUTTONUP && x > 150 && x < 260
	&& y > 250 && y < 353))
		env->arcade_map = (env->arcade_map + max - 1) % max;
	else if ((env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_D)
	|| (env->events.type == SDL_MOUSEBUTTONUP && x > 540 && x < 656
	&& y > 250 && y < 353))
		env->arcade_map = (env->arcade_map + 1) % max;
}

void			apply_arcade(t_env *env, SDL_Event *event, int y)
{
	env->arcade_menu = 0;
	if (((event->type == SDL_MOUSEBUTTONUP && y >= 353 && y < 390)
	|| (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RETURN))
	&& env->arcade_choice == 0)
		env->play_ready = 1;
	else if (((event->type == SDL_MOUSEBUTTONUP && y >= 390 && y < 426)
	|| (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RETURN))
	&& env->arcade_choice == 1)
		env->play_menu = 1;
	else
		env->arcade_menu = 1;
}
