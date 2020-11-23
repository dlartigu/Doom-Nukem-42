/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <jcharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 02:17:04 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/25 16:44:59 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			draw_menus(t_env *env, t_sdl *sdl)
{
	if (env->startmenu == 1)
		draw_menu_start(env);
	else if (env->settings_menu == 1)
		draw_menu_settings(env);
	else if (env->vid_menu == 1)
		draw_menu_video(sdl, env);
	else if (env->gameplay_menu == 1)
		draw_menu_gameplay(sdl, env);
	else if (env->play_menu == 1)
		draw_menu_play(env);
	else if (env->story_menu == 1)
		draw_menu_story(env);
	else if (env->arcade_menu == 1)
		draw_menu_arcade(env);
	else if (env->audio_menu == 1)
		draw_menu_audio(sdl, env);
	else if (env->controls_menu == 1)
		draw_menu_controls(env);
}

int				ft_init_events(t_env *env, t_sdl *sdl, t_elem *floor)
{
	while (1)
	{
		while (SDL_PollEvent(&env->events))
			if (!(menu_events_list(env, sdl, floor)))
				return (0);
		if (env->events.type == SDL_WINDOWEVENT_CLOSE || env->escape)
			return (1);
		draw_menus(env, sdl);
		draw_cursor(env, &env->events);
		SDL_RenderPresent(env->ren);
		if (env->apply_audio_op == 1)
			menu_apply_audio_params(env);
		else if (env->apply_video_op == 1)
			apply_video_settings(sdl, env, floor);
		else if (env->next_stage == 1)
			ft_play_intros(env, floor);
		else if (env->play_ready == 1)
			ft_display_game(env, floor);
	}
	return (1);
}
