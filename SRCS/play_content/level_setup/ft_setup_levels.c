/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_levels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:38:11 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 18:11:36 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void				ft_setup_level4(t_env *env, t_elem *floor)
{
	ft_intro_lvl3(env, floor);
	floor->autorun = 0;
	floor->autorunswitch = 0;
	floor->lava_glow = 0;
	floor->underwater = 0;
	floor->swim = 0;
	floor->gravity = 2;
	floor->angle = M_PI / 2;
	floor->negative = 1;
	floor->negatifflash = 1;
	ft_setup_level_helper(env, floor);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_BOSS],
	&env->audio.channels[CH_MUSIC], env->music_op);
	load_skyboxes(env, floor);
}

void				ft_setup_level3(t_env *env, t_elem *floor)
{
	ft_intro_lvl2(env, floor);
	floor->autorun = 0;
	floor->autorunswitch = 0;
	floor->shadow = 0;
	floor->lava_glow = 1;
	floor->underwater = 1;
	floor->swim = 1;
	floor->angle = 0;
	floor->game_msg = 2;
	ft_setup_level_helper(env, floor);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_LVL3],
	&env->audio.channels[CH_MUSIC], env->music_op);
	load_skyboxes(env, floor);
}

void				ft_setup_level2(t_env *env, t_elem *floor)
{
	ft_intro_lvl1(env, floor);
	floor->autorun = 1;
	floor->autorunswitch = 1;
	floor->shadow = 1;
	floor->rain = 0;
	floor->reflections = 0;
	floor->angle = -(M_PI / 2);
	floor->fire_stat = -1;
	ft_setup_level_helper(env, floor);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_LVL2],
	&env->audio.channels[CH_MUSIC], env->music_op);
}

void				ft_setup_level1(t_env *env, t_elem *floor)
{
	ft_restore_backup(floor);
	ft_intro(env, floor);
	floor->autorun = 0;
	floor->autorunswitch = 0;
	floor->rain = 1;
	floor->angle = M_PI / 2;
	load_skyboxes(env, floor);
	floor->devastator = 0;
	floor->pistol = 1;
	floor->shotgun = 0;
	floor->usable_ammo_legendary = 0;
	floor->usable_ammo_pistol = 0;
	floor->usable_ammo_shotgun = 0;
	floor->max_ammo_legendary = 0;
	floor->max_ammo_pistol = 0;
	floor->max_ammo_shotgun = 0;
	floor->gravity = 1;
	floor->negative = 0;
	floor->negatifflash = 0;
	ft_setup_level_helper(env, floor);
	floor->score = 500;
	floor->last_rain_state = floor->rain;
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_LVL1],
	&env->audio.channels[CH_MUSIC], env->music_op);
}
