/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro_lvl2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:11:54 by jcharrou          #+#    #+#             */
/*   Updated: 2020/10/07 14:35:44 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_intro_content_lvl2(t_env *env)
{
	if (env->introstep == 0)
	{
		SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 2.76, env->res_hight / 15);
		ft_render_story(env, STORYLINE_2_1, env->text_intro[6], env->pos2);
	}
	else if (env->introstep == 1)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 2.5, env->res_hight / 15);
		ft_render_story(env, STORYLINE_2_2, env->text_intro[6], env->pos2);
	}
	else if (env->introstep == 2)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 8, env->res_hight / 15);
		ft_render_story(env, STORYLINE_2_3, env->text_intro[6], env->pos2);
	}
	else if (env->introstep == 3)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 2.22, env->res_hight / 15);
		ft_render_story(env, STORYLINE_2_4, env->text_intro[6], env->pos2);
	}
}

void			ft_intro_lvl2(t_env *env, t_elem *floor)
{
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_INTRO],
	&env->audio.channels[CH_MUSIC], env->music_op);
	ft_init_intro(env);
	while (env->introstep != 4)
	{
		if (env->events.key.keysym.sym == SDLK_RETURN
			&& env->events.type == SDL_KEYDOWN)
			env->introstep++;
		ft_intro_content_lvl2(env);
		SDL_WaitEvent(&env->events);
	}
	floor->currentstair = 2;
	floor->autorunswitch = 0;
}
