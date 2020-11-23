/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_story.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 03:25:20 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 18:40:25 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_play_intros(t_env *env, t_elem *floor)
{
	env->next_stage = 0;
	env->play_ready = 1;
	env->startmenu_choice = 0;
	env->startmenu = 0;
	ft_display_game(env, floor);
}

void	init_story(t_env *env, t_elem *floor)
{
	if (floor->retry == 0)
		ft_setup_level1(env, floor);
	if (floor->retry == 1)
	{
		floor->retry = 0;
		ft_restore_backup(floor);
		if (floor->currentstair == 0)
			ft_setup_level1(env, floor);
		else if (floor->currentstair == 1)
			ft_setup_level2(env, floor);
		else if (floor->currentstair == 2)
			ft_setup_level3(env, floor);
		else if (floor->currentstair == 3)
			ft_setup_level4(env, floor);
	}
	if (floor->skybox)
		ft_free_texture(&floor->skybox);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_LVL1],
	&env->audio.channels[CH_MUSIC], env->music_op);
	if (floor->rain)
		play_simple(floor->audio, EFF_RAIN, CH_RAIN, 0);
}
