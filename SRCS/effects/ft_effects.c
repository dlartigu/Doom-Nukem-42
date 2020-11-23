/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:03:26 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 16:48:21 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_enable_underwater(t_env *env, t_elem *floor)
{
	if (floor->underwater == 1)
		start_bubbles(env, floor);
	if (floor->underwater == 0 && floor->timer_bubble)
		SDL_RemoveTimer(floor->timer_bubble);
	if (floor->underwater == 0 && floor->timer_bubble_progress)
		SDL_RemoveTimer(floor->timer_bubble_progress);
}

void			ft_disable_rain(t_env *env, t_elem *floor)
{
	if (!floor->rain)
	{
		floor->timedrain = 0;
		floor->rained = 0;
		floor->fog = 0;
		FMOD_Channel_Stop(env->audio.channels[CH_RAIN]);
		if (floor->timer_rain)
			SDL_RemoveTimer(floor->timer_rain);
		if (floor->time_rain_fog)
			SDL_RemoveTimer(floor->time_rain_fog);
		floor->time_rain_fog = 0;
		floor->timer_rain = 0;
	}
}

void			ft_enable_rain(t_env *env, t_elem *floor)
{
	unsigned int	duration;

	if (floor->rain)
	{
		FMOD_Sound_GetLength(env->audio.sound_effects[EFF_RAIN], &duration,
			FMOD_TIMEUNIT_MS);
		init_rain(0, (void*)floor);
		floor->timedrain = 1;
		if (!floor->timer_rain)
			floor->timer_rain = SDL_AddTimer(10000 - rand() % 5000, init_rain,
			floor);
		if (!floor->time_rain_fog)
			floor->time_rain_fog = SDL_AddTimer(30000, fog_rain, floor);
	}
}

void			ft_effects(t_env *env, t_elem *floor)
{
	if (floor->shadow)
		search_items(floor, TORCH, 0);
	else
		search_items(floor, TORCH, 1);
	ft_enable_rain(env, floor);
	ft_disable_rain(env, floor);
	ft_enable_underwater(env, floor);
	flashnegatif(floor);
}
