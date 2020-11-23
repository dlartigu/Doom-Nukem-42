/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soundeffects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:16:56 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 20:13:55 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		change_channel_state(t_env *env, FMOD_CHANNEL *channel,
			int flags)
{
	FMOD_BOOL isplaying;

	FMOD_Channel_IsPlaying(channel, &isplaying);
	if ((flags & 1) == 0 && (((flags & 2) == 0 && env->music_op == 0)
		|| ((flags & 2) == 2 && env->effect_op == 0)))
		return ;
	if (FMOD_Channel_SetPaused(channel, (flags & 1)))
		ft_fct_error("Couldn't resume sound\n");
}

void		change_walk_audio(t_env *env, t_elem *elem)
{
	if (!(elem->keystat = SDL_GetKeyboardState(NULL)))
		return ;
	if (!elem->swim && elem->walking == 1 && (elem->jump == 0
	|| (!elem->keystat[SDL_SCANCODE_W] && !elem->keystat[SDL_SCANCODE_A]
	&& !elem->keystat[SDL_SCANCODE_S] && !elem->keystat[SDL_SCANCODE_D])))
	{
		change_channel_state(env, env->audio.channels[CH_WALK], 3);
		elem->walking = 0;
	}
	else if (!elem->swim && elem->walking == 0 && elem->jump == 1
	&& (elem->keystat[SDL_SCANCODE_W] || elem->keystat[SDL_SCANCODE_A]
	|| elem->keystat[SDL_SCANCODE_S] || elem->keystat[SDL_SCANCODE_D]))
	{
		change_channel_state(env, env->audio.channels[CH_WALK], 2);
		elem->walking = 1;
	}
}

void		pause_soundeffects(t_audio *audio)
{
	int		i;

	i = 1;
	while (i < 32)
	{
		if (audio->channels[i])
			FMOD_Channel_SetPaused(audio->channels[i], 1);
		i++;
	}
}

void		play_simple(t_audio *audio, t_soundeffects_ids sound,
			t_channels channel, int force)
{
	int		isplaying;

	if (!audio->effect_op)
		return ;
	if (audio->channels[channel])
	{
		FMOD_Channel_IsPlaying(audio->channels[channel], &isplaying);
		if (isplaying && !force)
			return ;
		if (isplaying)
			FMOD_Channel_Stop(audio->channels[channel]);
	}
	if (FMOD_System_PlaySound(audio->system,
	audio->sound_effects[sound], NULL, 0, &audio->channels[channel]))
		ft_fct_error("Couldn't play sound\n");
	if (FMOD_Channel_SetVolume(audio->channels[channel], audio->volume))
		ft_fct_error("Couldn't change volume\n");
}

int			change_sound_in_channel(t_audio *audio, FMOD_SOUND *sound,
				FMOD_CHANNEL **channel, int play)
{
	FMOD_BOOL isplaying;

	isplaying = 0;
	if (*channel)
		FMOD_Channel_IsPlaying(*channel, &isplaying);
	if (isplaying == 1)
		FMOD_Channel_Stop(*channel);
	if (FMOD_System_PlaySound(audio->system, sound, NULL, 1,
		channel))
		ft_fct_error("Couldn't play sound\n");
	if (FMOD_Channel_SetVolume(*channel, audio->volume))
		ft_fct_error("Couldn't change volume\n");
	if (play && FMOD_Channel_SetPaused(*channel, 0))
		ft_fct_error("Couldn't resume sound\n");
	return (1);
}
