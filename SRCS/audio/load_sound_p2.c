/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sound_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:42:06 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:43:58 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		load_sounds_p6(t_audio *audio)
{
	if (FMOD_System_CreateSound(audio->system, ENEMY_3_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
		&audio->sound_effects[EFF_ENEMY_3_ATTACK]))
		ft_fct_error("Couldn't create sound(30)\n");
	if (FMOD_System_CreateSound(audio->system, ENEMY_4_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
		&audio->sound_effects[EFF_ENEMY_4_ATTACK]))
		ft_fct_error("Couldn't create sound(31)\n");
	if (FMOD_System_CreateSound(audio->system, ENEMY_BOSS_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
		&audio->sound_effects[EFF_ENEMY_BOSS_ATTACK]))
		ft_fct_error("Couldn't create sound(32)\n");
}

void			load_sounds_p5(t_audio *audio)
{
	if (FMOD_System_CreateSound(audio->system, FIRE_EFFECT_PATH,
	FMOD_LOOP_NORMAL | FMOD_CREATESTREAM, NULL,
		&audio->loop_effects[L_EFF_FIRE]))
		ft_fct_error("Couldn't create sound(26)\n");
	if (FMOD_System_CreateSound(audio->system, EXPLOSION_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
		&audio->sound_effects[EFF_EXPLOSION]))
		ft_fct_error("Couldn't create sound(27)\n");
	if (FMOD_System_CreateSound(audio->system, ENEMY_1_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
		&audio->sound_effects[EFF_ENEMY_1_ATTACK]))
		ft_fct_error("Couldn't create sound(28)\n");
	if (FMOD_System_CreateSound(audio->system, ENEMY_2_EFFECT_PATH,
	FMOD_LOOP_OFF | FMOD_CREATESAMPLE, NULL,
		&audio->sound_effects[EFF_ENEMY_2_ATTACK]))
		ft_fct_error("Couldn't create sound(29)\n");
	load_sounds_p6(audio);
}
