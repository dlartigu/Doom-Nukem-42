/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arcade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 03:25:20 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 09:53:54 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	init_arcade_retry(t_env *env, t_elem *floor)
{
	floor->arcade_retry = 0;
	if (floor->currentstair == 4)
		ft_arcade_circus(env, floor);
	else if (floor->currentstair == 5)
		ft_arcade_mine(env, floor);
	else if (floor->currentstair == 6)
		ft_arcade_magma(env, floor);
	else if (floor->currentstair == 7)
		ft_arcade_custom(env, floor);
}

void			init_arcade(t_env *env, t_elem *floor)
{
	if (!floor->arcade_retry)
	{
		floor->currentstair = 4 + env->arcade_map;
		if (floor->currentstair == 4)
			ft_arcade_circus(env, floor);
		else if (floor->currentstair == 5)
			ft_arcade_mine(env, floor);
		else if (floor->currentstair == 6)
			ft_arcade_magma(env, floor);
		else if (floor->currentstair == 7)
			ft_arcade_custom(env, floor);
	}
	else if (floor->arcade_retry)
		init_arcade_retry(env, floor);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_ARCADE],
			&env->audio.channels[CH_MUSIC], env->music_op);
}
