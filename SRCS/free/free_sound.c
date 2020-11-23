/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:52:06 by niboute           #+#    #+#             */
/*   Updated: 2020/10/07 01:54:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		free_sound2(t_audio *audio)
{
	int	i;

	i = 0;
	while (i < NB_LOOP_EFFECTS)
	{
		if (audio->loop_effects[i])
			FMOD_Sound_Release(audio->loop_effects[i]);
		i++;
	}
	if (audio->system)
		FMOD_System_Release(audio->system);
}

void			free_sound(t_audio *audio)
{
	int	i;

	i = 0;
	while (i < NB_CHANNELS)
	{
		if (audio->channels[i])
			FMOD_Channel_Stop(audio->channels[i]);
		i++;
	}
	i = 0;
	while (i < NB_MUSICS)
	{
		if (audio->musics[i])
			FMOD_Sound_Release(audio->musics[i]);
		i++;
	}
	i = 0;
	while (i < NB_EFFECTS)
	{
		if (audio->sound_effects[i])
			FMOD_Sound_Release(audio->sound_effects[i]);
		i++;
	}
	free_sound2(audio);
}
