/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:34:57 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/08 02:20:07 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			video_event(t_env *env, int x, int y)
{
	if (env->events.type == SDL_KEYDOWN && env->events.key.keysym.scancode
	== SDL_SCANCODE_S)
		env->video_choice = (env->video_choice + 1) % 8;
	else if (env->events.type == SDL_KEYDOWN
	&& env->events.key.keysym.scancode == SDL_SCANCODE_W)
		env->video_choice = (env->video_choice + 7) % 8;
	else if (env->events.type == SDL_MOUSEMOTION && x > 205 && x < 593)
	{
		if (y >= 90 && y < 135)
			env->video_choice = 0;
		else if (y >= 135 && y < 171)
			env->video_choice = 1;
		else if (y >= 171 && y < 207)
			env->video_choice = 2;
		else if (y >= 207 && y < 243)
			env->video_choice = 3;
		else if (y >= 243 && y < 279)
			env->video_choice = 4;
		else if (y >= 279 && y < 315)
			env->video_choice = 5;
		else if (y >= 315 && y < 351)
			env->video_choice = 6;
		else if (y >= 351 && y < 387)
			env->video_choice = 7;
	}
}

static void		apply_video_settings_p2(t_env *env, t_elem *floor)
{
	if (env->text_q_op == 0)
		floor->texture_res = 1;
	else if (env->text_q_op == 1)
		floor->texture_res = 2;
	else if (env->text_q_op == 2)
		floor->texture_res = 4;
}

void			apply_video_settings(t_sdl *sdl, t_env *env, t_elem *floor)
{
	env->apply_video_op = 0;
	SDL_SetWindowGrab(env->win, SDL_FALSE);
	SDL_DestroyRenderer(env->ren);
	env->ren = NULL;
	SDL_DestroyWindow(env->win);
	env->win = NULL;
	reload_sdlparams(sdl, env);
	if (env->aliasing_op == 1)
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	else
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	if (!(env->win = ft_create_window(sdl)))
		ft_sdl_error(NULL);
	SDL_GetWindowBrightness(env->win);
	SDL_SetWindowGrab(env->win, SDL_TRUE);
	SDL_ShowCursor(SDL_DISABLE);
	env->ren = ft_init_renderer(env->win, sdl, env);
	if (env->cursors[0])
		ft_free_texture(&env->cursors[0]);
	if (env->cursors[1])
		ft_free_texture(&env->cursors[1]);
	if (env->ren == NULL)
		ft_video_op_error(sdl, env);
	apply_video_settings_p2(env, floor);
}

void			apply_video(t_env *env, t_elem *floor, SDL_Event *event)
{
	if ((event->type == SDL_MOUSEBUTTONUP || (event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)) && env->video_choice != 7)
	{
		if (env->video_choice == 0)
			env->res_op ^= 1;
		else if (env->video_choice == 1)
			env->vsync_op ^= 1;
		else if (env->video_choice == 2)
			env->fs_op ^= 1;
		else if (env->video_choice == 3)
			env->gpu_op ^= 1;
		else if (env->video_choice == 4)
			env->aliasing_op ^= 1;
		else if (env->video_choice == 5)
			env->text_q_op = (env->text_q_op + 1) % 3;
		else if (env->video_choice == 6)
			env->apply_video_op = 1;
	}
	else if (test_return(env->video_choice == 7, event))
	{
		env->text_q_op = floor->texture_res / 2;
		env->settings_menu = 1;
		env->vid_menu = 0;
	}
}
