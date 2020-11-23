/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:44:16 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 17:07:23 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				ft_escape(t_env *env, t_elem *floor, t_thread *threads)
{
	if (floor->endgame == 1 && floor->currentstair == 3)
		ft_credits(env, floor);
	ft_memdel((void**)&threads);
	env->play_ready = 0;
	env->startmenu_choice = 1;
	env->startmenu = 1;
	env->intro = floor->currentstair + 1;
	if (env->timer)
		SDL_RemoveTimer(env->timer);
	if (floor->timer_rain)
		SDL_RemoveTimer(floor->timer_rain);
	if (floor->timer_bubble)
		SDL_RemoveTimer(floor->timer_bubble);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_MENU],
	&env->audio.channels[CH_MUSIC], env->music_op);
	pause_soundeffects(&env->audio);
	ft_free_hud(&env->hud);
}

int					game_events(t_env *env, t_elem *floor, t_thread *threads)
{
	if (env->events.window.event == SDL_WINDOWEVENT_CLOSE)
	{
		env->play_ready = 0;
		if (env->timer)
			SDL_RemoveTimer(env->timer);
		return (1);
	}
	ft_movements(env, floor);
	if ((env->events.key.keysym.sym == SDLK_ESCAPE)
	&& (env->play_ready == 1) && (env->events.type == SDL_KEYDOWN))
	{
		ft_escape(env, floor, threads);
		return (1);
	}
	return (0);
}
