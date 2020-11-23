/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 03:00:47 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/05 09:51:52 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	start_menu_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->startmenu_choice = (env->startmenu_choice + 1) % 4;
	else if (env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->startmenu_choice = (env->startmenu_choice + 3) % 4;
	else if (env->events.type == SDL_MOUSEMOTION && x > 205 && x < 593)
	{
		if (y >= 150 && y < 210)
			env->startmenu_choice = 0;
		else if (y >= 210 && y < 255)
			env->startmenu_choice = 1;
		else if (y >= 255 && y < 300)
			env->startmenu_choice = 2;
		else if (y >= 300 && y < 345)
			env->startmenu_choice = 3;
	}
}

int		apply_menu(t_env *env, t_sdl *sdl, t_elem *floor, SDL_Event *event)
{
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
		&& event->key.keysym.sym == SDLK_RETURN)) && env->startmenu_choice != 3)
	{
		env->startmenu = 0;
		if (env->startmenu_choice == 0)
		{
			env->play_menu = 1;
			env->play_choice = 0;
		}
		else if (env->startmenu_choice == 2)
		{
			env->settings_menu = 1;
			env->settings_choice = 1;
		}
		else if (env->startmenu_choice == 1)
			return (start_editor(env, sdl, &floor[7]));
	}
	else if (test_return(env->startmenu_choice == 3, event))
		env->escape = 1;
	return (1);
}
