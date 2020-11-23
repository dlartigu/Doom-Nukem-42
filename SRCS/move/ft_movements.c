/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:17:53 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 09:51:32 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_crouchflyjump(t_env *env, t_elem *floor)
{
	if (floor->time - floor->oldtime > 10
		&& env->events.key.repeat == 0 && floor->swim == 0
		&& floor->ragdoll == 0)
	{
		ft_crouch(env, floor);
		if (floor->balloon == 1)
			ft_fly(env, floor);
		ft_jump(env, floor);
	}
}

void			ft_movements(t_env *env, t_elem *floor)
{
	ft_mousemotion(env, floor);
	if (env->events.type == SDL_KEYDOWN || env->events.type == SDL_KEYUP)
	{
		if (env->events.key.keysym.sym == SDLK_LSHIFT
		&& !env->events.key.repeat && env->events.type == SDL_KEYDOWN
		&& !floor->swim)
			change_sound_in_channel(&env->audio, env->audio.loop_effects
			[L_EFF_RUN], &env->audio.channels[CH_WALK],
			floor->walking & env->effect_op);
		else if (env->events.key.keysym.sym == SDLK_LSHIFT
		&& !env->events.key.repeat && env->events.type == SDL_KEYUP
		&& !floor->swim)
			change_sound_in_channel(&env->audio, env->audio.loop_effects
			[L_EFF_WALK], &env->audio.channels[CH_WALK],
			floor->walking & env->effect_op);
		ft_dispminimap(env, floor);
		ft_torch_toogle(env, floor);
		ft_speedshift(env, floor);
		ft_crouchflyjump(env, floor);
	}
}
