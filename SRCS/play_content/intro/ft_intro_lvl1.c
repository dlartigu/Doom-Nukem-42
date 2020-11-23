/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro_lvl1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:11:51 by jcharrou          #+#    #+#             */
/*   Updated: 2020/10/07 02:15:14 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_intro_content_lvl1_p2(t_env *env)
{
	if (env->introstep == 3)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 1.95, env->res_hight / 15);
		ft_render_story(env, STORYLINE_1_4, env->text_intro[3], env->pos2);
	}
	else if (env->introstep == 4)
	{
		SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 2.96, env->res_hight / 15);
		ft_render_story(env, STORYLINE_1_5, env->text_intro[4], env->pos2);
	}
	else if (env->introstep == 5)
	{
		SDL_RenderClear(env->ren);
		SDL_RenderCopy(env->ren, env->text_intro[5], NULL, NULL);
		SDL_RenderPresent(env->ren);
	}
}

static void		ft_intro_content_lvl1_p1(t_env *env)
{
	if (env->introstep == 0)
	{
		SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 2.5, env->res_hight / 15);
		ft_render_story(env, STORYLINE_1_1, env->text_intro[0], env->pos2);
	}
	else if (env->introstep == 1)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 3.1, env->res_hight / 15);
		ft_render_story(env, STORYLINE_1_2, env->text_intro[1], env->pos2);
	}
	else if (env->introstep == 2)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 2.29, env->res_hight / 15);
		ft_render_story(env, STORYLINE_1_3, env->text_intro[2], env->pos2);
	}
	else
		ft_intro_content_lvl1_p2(env);
}

void			ft_intro_lvl1(t_env *env, t_elem *floor)
{
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_INTRO],
	&env->audio.channels[CH_MUSIC], env->music_op);
	ft_init_intro(env);
	while (env->introstep != 6)
	{
		if (env->events.key.keysym.sym == SDLK_RETURN
			&& env->events.type == SDL_KEYDOWN)
			env->introstep++;
		ft_intro_content_lvl1_p1(env);
		SDL_WaitEvent(&env->events);
	}
	floor->currentstair = 1;
	floor->autorunswitch = 1;
}
