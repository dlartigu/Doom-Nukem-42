/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sdl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:16:01 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/14 08:46:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		menu_events_list_3(t_env *env)
{
	if (env->audio_menu == 1)
	{
		audio_menu_event(env, env->cx, env->cy);
		apply_menu_audio(env, &env->events);
	}
	else if (env->controls_menu == 1)
	{
		controls_event(env, env->cx, env->cy);
		apply_controls(env, &env->events);
	}
}

static void		menu_events_list_2(t_env *env, t_elem *floor)
{
	if (env->gameplay_menu == 1)
	{
		gameplay_event(env, env->cx, env->cy);
		apply_gameplay(env, floor, &env->events);
	}
	else if (env->play_menu == 1)
	{
		play_event(env, env->cx, env->cy);
		apply_play(env, &env->events);
	}
	else if (env->story_menu == 1)
	{
		story_event(env, env->cx, env->cy);
		apply_story(env, &env->events);
	}
	else if (env->arcade_menu == 1)
	{
		arcade_event(env, env->cx, env->cy, floor[7].new == NULL ? 3 : 4);
		apply_arcade(env, &env->events, env->cy);
	}
	else
		menu_events_list_3(env);
}

static int		check_input(SDL_Event *event)
{
	if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONUP
		|| (event->type == SDL_KEYDOWN && !event->key.repeat
		&& (event->key.keysym.scancode == SDL_SCANCODE_W
		|| event->key.keysym.scancode == SDL_SCANCODE_S
		|| event->key.keysym.scancode == SDL_SCANCODE_A
		|| event->key.keysym.scancode == SDL_SCANCODE_D
		|| event->key.keysym.sym == SDLK_RETURN
		|| event->key.keysym.sym == SDLK_ESCAPE)))
		return (1);
	return (0);
}

int				menu_events_list(t_env *env, t_sdl *sdl, t_elem *floor)
{
	if (!check_input(&env->events))
		return (1);
	if (env->startmenu == 1)
	{
		start_menu_event(env, env->cx, env->cy);
		if (!apply_menu(env, sdl, floor, &env->events))
			return (0);
	}
	else if (env->settings_menu == 1)
	{
		settings_event(env, env->cx, env->cy);
		apply_settings(env, &env->events);
	}
	else if (env->vid_menu == 1)
	{
		video_event(env, env->cx, env->cy);
		apply_video(env, floor, &env->events);
	}
	else
		menu_events_list_2(env, floor);
	return (1);
}

int				ft_set_sdl(t_sdl *sdl, t_env *env, t_elem *floor)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
		ft_sdl_error(NULL);
	SDL_ShowCursor(SDL_DISABLE);
	env->win = ft_create_window(sdl);
	if (env->win == NULL)
		ft_error(INIT_WIN);
	SDL_GetWindowBrightness(env->win);
	env->ren = ft_init_renderer(env->win, sdl, env);
	TTF_Init();
	get_max_res(sdl);
	if (!(env->surf = SDL_CreateRGBSurfaceWithFormat(0, env->res_width,
		env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
		ft_sdl_error(NULL);
	env->icon = ft_load_texture("./RSCS/gameicons/icon/wolf_icon.bmp");
	SDL_SetWindowIcon(env->win, env->icon);
	if (!init_fmod(&env->audio, env->music_op))
	{
		ft_putendl("Couldn't init fmod");
		return (0);
	}
	return (ft_init_events(env, sdl, floor));
}
