/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 07:14:08 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 18:36:23 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"
#include "../../INCLUDES/editor.h"

static void	escape(t_env *env, int retry, t_elem *floor)
{
	if (retry)
	{
		if (env->play_choice == 0)
			floor->retry = 1;
		if (env->play_choice == 1)
			floor->arcade_retry = 1;
	}
	else
	{
		ft_set_weapon_struct(env);
		env->startmenu_choice = 0;
		env->startmenu = 1;
		env->play_ready = 0;
	}
	if (env->timer)
		SDL_RemoveTimer(env->timer);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_MENU],
	&env->audio.channels[CH_MUSIC], env->music_op);
}

static void	gameover_mousemotionevent(SDL_Event *event, t_env *env,
		int *hover, t_elem *floor)
{
	int		y;

	y = ft_dmap(event->motion.y, env->res_hight, 0, 450);
	if (y > 200 && y < 250 && *hover)
		*hover = 0;
	else if (y >= 250 && y < 300 && !(*hover))
		*hover = 1;
	if (*hover)
		SDL_RenderCopy(env->ren, env->gameover1, NULL, NULL);
	else
		SDL_RenderCopy(env->ren, env->gameover2, NULL, NULL);
	ft_printscore(env, floor, 1);
	draw_cursor(env, event);
	SDL_RenderPresent(env->ren);
}

static int	gameover_mousebuttonevent(SDL_MouseButtonEvent *event, t_env *env,
			t_elem *floor)
{
	int		y;

	y = ft_dmap(event->y, env->res_hight, 0, 450);
	if (y > 200 && y < 250)
	{
		escape(env, 1, floor);
		return (1);
	}
	else if (y >= 250 && y < 300)
	{
		escape(env, 0, floor);
		return (1);
	}
	return (0);
}

static int	gameover_keyboardevent(SDL_KeyboardEvent *event, t_env *env,
			int *hover, t_elem *floor)
{
	if (event->keysym.sym == SDLK_ESCAPE || event->keysym.sym == SDLK_RETURN)
	{
		escape(env, (event->keysym.sym == SDLK_RETURN && *hover == 0)
			? 1 : 0, floor);
		return (1);
	}
	else if ((event->keysym.sym == SDLK_UP || event->keysym.sym == SDLK_w)
		&& *hover)
	{
		SDL_RenderCopy(env->ren, env->gameover2, NULL, NULL);
		ft_printscore(env, floor, 1);
		SDL_RenderPresent(env->ren);
		*hover = 0;
	}
	else if ((event->keysym.sym == SDLK_DOWN || event->keysym.sym == SDLK_s)
		&& !(*hover))
	{
		SDL_RenderCopy(env->ren, env->gameover1, NULL, NULL);
		ft_printscore(env, floor, 1);
		SDL_RenderPresent(env->ren);
		*hover = 1;
	}
	return (0);
}

int			gameover(t_env *env, t_thread *threads, t_elem *floor)
{
	SDL_Event	event;
	int			hover;
	int			ret;

	ft_memdel((void**)&threads);
	pause_soundeffects(&env->audio);
	if (!init_gameover(env, &hover, &ret, floor))
		return (0);
	while (!ret)
		while (!ret && SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
				gameover_mousemotionevent(&event, env, &hover, floor);
			else if (event.type == SDL_MOUSEBUTTONDOWN
			&& event.button.state == SDL_PRESSED)
				ret = gameover_mousebuttonevent(&event.button, env, floor);
			else if (event.type == SDL_KEYDOWN)
				ret = gameover_keyboardevent(&event.key, env, &hover, floor);
		}
	ft_free_texture(&env->gameover1);
	ft_free_texture(&env->gameover2);
	return (1);
}
