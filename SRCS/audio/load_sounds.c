/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 03:21:04 by niboute           #+#    #+#             */
/*   Updated: 2020/11/05 15:44:00 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		load_sounds_p4(t_audio *audio)
{
	if (FMOD_System_CreateSound(audio->system, SHOTGUN_RELOAD_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_SHOTGUN_RELOAD]))
		ft_fct_error("Couldn't create sound(20)\n");
	if (FMOD_System_CreateSound(audio->system, WATER_BREATHING_EFFECT_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL,
	&audio->loop_effects[L_EFF_WATER_BREATHING]))
		ft_fct_error("Couldn't create sound(21)\n");
	if (FMOD_System_CreateSound(audio->system, BOSS_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_BOSS]))
		ft_fct_error("Couldn't create sound(22)\n");
	if (FMOD_System_CreateSound(audio->system, TRAIN_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL,
	&audio->loop_effects[L_EFF_TRAIN]))
		ft_fct_error("Couldn't create sound(23)\n");
	if (FMOD_System_CreateSound(audio->system, HEARTBEAT_EFFECT_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL,
	&audio->loop_effects[L_EFF_HEARTBEAT]))
		ft_fct_error("Couldn't create sound(24)\n");
	if (FMOD_System_CreateSound(audio->system, LOL_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_LOL]))
		ft_fct_error("Couldn't create sound(25)\n");
	load_sounds_p5(audio);
}

static void		load_sounds_p3(t_audio *audio)
{
	if (FMOD_System_CreateSound(audio->system, DEVASTATOR_RELOAD_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_DEVASTATOR_RELOAD]))
		ft_fct_error("Couldn't create sound(14)\n");
	if (FMOD_System_CreateSound(audio->system, PISTOL_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_PISTOL]))
		ft_fct_error("Couldn't create sound(15)\n");
	if (FMOD_System_CreateSound(audio->system, PISTOL_RELOAD_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_PISTOL_RELOAD]))
		ft_fct_error("Couldn't create sound(16)\n");
	if (FMOD_System_CreateSound(audio->system, PISTOL_EMPTY_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_PISTOL_EMPTY]))
		ft_fct_error("Couldn't create sound(17)\n");
	if (FMOD_System_CreateSound(audio->system, SHOTGUN_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_SHOTGUN]))
		ft_fct_error("Couldn't create sound(18)\n");
	if (FMOD_System_CreateSound(audio->system, SHOTGUN_LOAD_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_SHOTGUN_LOAD]))
		ft_fct_error("Couldn't create sound(19)\n");
	load_sounds_p4(audio);
}

static void		load_sounds_p2(t_audio *audio)
{
	if (FMOD_System_CreateSound(audio->system, RAIN_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_RAIN]))
		ft_fct_error("Couldn't create sound(8)\n");
	if (FMOD_System_CreateSound(audio->system, WALKING_EFFECT_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL,
	&audio->loop_effects[L_EFF_WALK]))
		ft_fct_error("Couldn't create sound(9)\n");
	if (FMOD_System_CreateSound(audio->system, RUNNING_EFFECT_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL,
	&audio->loop_effects[L_EFF_RUN]))
		ft_fct_error("Couldn't create sound(10)\n");
	if (FMOD_System_CreateSound(audio->system, JUMP_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_JUMP]))
		ft_fct_error("Couldn't create sound(11)\n");
	if (FMOD_System_CreateSound(audio->system, PUNCH_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_PUNCH]))
		ft_fct_error("Couldn't create sound(12)\n");
	if (FMOD_System_CreateSound(audio->system, DEVASTATOR_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_DEVASTATOR]))
		ft_fct_error("Couldn't create sound(13)\n");
	load_sounds_p3(audio);
}

void			load_sounds(t_audio *audio)
{
	if (FMOD_System_CreateSound(audio->system, MENU_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_MENU]))
		ft_fct_error("Couldn't create sound(1)\n");
	if (FMOD_System_CreateSound(audio->system, ARCADE_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_ARCADE]))
		ft_fct_error("Couldn't create sound(2)\n");
	if (FMOD_System_CreateSound(audio->system, INTRO_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_INTRO]))
		ft_fct_error("Couldn't create sound(3)\n");
	if (FMOD_System_CreateSound(audio->system, LEVEL1_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_LVL1]))
		ft_fct_error("Couldn't create sound(4)\n");
	if (FMOD_System_CreateSound(audio->system, LEVEL2_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_LVL2]))
		ft_fct_error("Couldn't create sound(5)\n");
	if (FMOD_System_CreateSound(audio->system, LEVEL3_MUSIC_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL, &audio->musics[MUS_LVL3]))
		ft_fct_error("Couldn't create sound(6)\n");
	if (FMOD_System_CreateSound(audio->system, GAMEOVER_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
	&audio->sound_effects[EFF_GAMEOVER]))
		ft_fct_error("Couldn't create sound(7)\n");
	load_sounds_p2(audio);
}
