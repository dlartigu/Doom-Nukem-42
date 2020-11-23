/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:14:15 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 18:46:44 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_sound_events2(t_env *env, t_elem *floor)
{
	if (floor->fire_stat > floor->prev_fire_stat)
	{
		play_simple(&env->audio, EFF_LOL, CH_LOL, 1);
		update_enemies(floor);
		floor->prev_fire_stat = floor->fire_stat;
	}
	if (floor->lightop == 1)
		change_channel_state(env, env->audio.channels[CH_FIRE], 2);
	else if (floor->lightop == 0)
		change_channel_state(env, env->audio.channels[CH_FIRE], 3);
}

void			ft_sound_events(t_env *env, t_elem *floor)
{
	if (floor->currentstair == 1)
	{
		if (floor->autorunswitch == 1)
			change_channel_state(env, env->audio.channels[CH_TRAIN], 2);
		else if (floor->autorunswitch == 0)
			change_channel_state(env, env->audio.channels[CH_TRAIN], 3);
	}
	else if (floor->currentstair == 2)
	{
		if (floor->underwater == 1)
			change_channel_state(env, env->audio.channels[CH_WATER_BREATHING],
				2);
		else if (floor->underwater == 0)
			change_channel_state(env, env->audio.channels[CH_WATER_BREATHING],
				3);
	}
	if (floor->life < 50)
		change_channel_state(env, env->audio.channels[CH_HEARTBEAT], 2);
	else if (floor->life > 50)
		change_channel_state(env, env->audio.channels[CH_HEARTBEAT], 3);
	ft_sound_events2(env, floor);
}

void			set_loop_sound(FMOD_SOUND *sound)
{
	float	frequency;
	int		tmp;

	if (FMOD_Sound_SetMode(sound, FMOD_LOOP_NORMAL))
		ft_fct_error("Couldn't make sound loop");
	FMOD_Sound_GetDefaults(sound, &frequency, &tmp);
	if (FMOD_Sound_SetDefaults(sound, frequency, 0))
		ft_fct_error("Couldn't change sound priority");
}

static void		init_music(t_audio *audio)
{
	audio->volume = 0.5;
	load_sounds(audio);
	if (FMOD_System_PlaySound(audio->system, audio->loop_effects[L_EFF_WALK],
	NULL, 1, &audio->channels[CH_WALK]))
		ft_fct_error("Couldn't play sound(1)\n");
	if (FMOD_System_PlaySound(audio->system, audio->loop_effects[L_EFF_TRAIN],
	NULL, 1, &audio->channels[CH_TRAIN]))
		ft_fct_error("Couldn't play sound(2)\n");
	if (FMOD_System_PlaySound(audio->system, audio->loop_effects
	[L_EFF_WATER_BREATHING], NULL, 1, &audio->channels[CH_WATER_BREATHING]))
		ft_fct_error("Couldn't play sound(3)\n");
	if (FMOD_System_PlaySound(audio->system, audio->loop_effects
	[L_EFF_HEARTBEAT], NULL, 1, &audio->channels[CH_HEARTBEAT]))
		ft_fct_error("Couldn't play sound(4)\n");
	if (FMOD_System_PlaySound(audio->system, audio->loop_effects
	[L_EFF_FIRE], NULL, 1, &audio->channels[CH_FIRE]))
		ft_fct_error("Couldn't play sound(5)\n");
}

int				init_fmod(t_audio *audio, int music_op)
{
	if (FMOD_System_Create(&audio->system))
		ft_fct_error("Couldn't create fmod system");
	if (FMOD_System_Init(audio->system, NB_CHANNELS, FMOD_INIT_NORMAL, NULL))
		ft_fct_error("Couldn't init fmod\n");
	init_music(audio);
	change_sound_in_channel(audio, audio->musics[MUS_MENU],
	&audio->channels[CH_MUSIC], music_op);
	return (1);
}
