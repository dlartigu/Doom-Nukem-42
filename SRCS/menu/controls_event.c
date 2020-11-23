/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:01:28 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/01 18:33:56 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			controls_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->controls_choice = (env->controls_choice + 1) % 2;
	else if (env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->controls_choice = (env->controls_choice + 1) % 2;
	if (env->events.type == SDL_MOUSEMOTION
	&& x > 205 && x < 592 && y >= 360 && y < 405)
		env->controls_choice = 1;
	else if (env->events.type == SDL_MOUSEMOTION)
		env->controls_choice = 0;
}

void			apply_controls(t_env *env, SDL_Event *event)
{
	env->controls_menu = 0;
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)) && env->controls_choice != 1)
		env->controls_menu = 1;
	else if (test_return(env->controls_choice == 1, event))
		env->gameplay_menu = 1;
	else
		env->controls_menu = 1;
}
