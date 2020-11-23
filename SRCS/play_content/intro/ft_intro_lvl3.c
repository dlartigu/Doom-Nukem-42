/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro_lvl3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:11:58 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/17 16:38:09 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_intro_content_lvl3(t_env *env)
{
	if (env->introstep == 0)
	{
		SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 1.81, env->res_hight / 15);
		ft_render_story(env, STORYLINE_3_1, env->text_intro[7], env->pos2);
	}
	else if (env->introstep == 1)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 1.81, env->res_hight / 15);
		ft_render_story(env, STORYLINE_3_2, env->text_intro[7], env->pos2);
	}
	else if (env->introstep == 2)
	{
		set_ttf_rect_xy(env, env->res_width / 16, env->res_hight / 1.29);
		set_ttf_rect_wh(env, env->res_width / 8, env->res_hight / 15);
		ft_render_story(env, STORYLINE_3_3, env->text_intro[7], env->pos2);
	}
}

uint32_t		timer_endgame(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	floor->endgame = 1;
	SDL_RemoveTimer(floor->endgame_timer);
	interval = 0;
	return (interval);
}

void			ft_credits(t_env *env, t_elem *floor)
{
	SDL_RenderClear(env->ren);
	SDL_RenderCopy(env->ren, env->text_intro[8], NULL, NULL);
	SDL_RenderPresent(env->ren);
	while (SDL_WaitEvent(&env->events))
	{
		if (env->events.key.keysym.sym == SDLK_RETURN
				&& env->events.type == SDL_KEYDOWN)
		{
			floor->endgame = 0;
			return ;
		}
	}
}

void			ft_render_story(t_env *env, char *str, SDL_Texture *texture,
				SDL_Rect rect)
{
	SDL_RenderClear(env->ren);
	SDL_RenderCopy(env->ren, texture, NULL, NULL);
	env->text = load_ttf_to_texture(env->ren, str, env->police2, env->color);
	SDL_RenderCopy(env->ren, env->text, NULL, &rect);
	SDL_RenderPresent(env->ren);
}

void			ft_intro_lvl3(t_env *env, t_elem *floor)
{
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_INTRO],
	&env->audio.channels[CH_MUSIC], env->music_op);
	ft_init_intro(env);
	while (env->introstep != 3)
	{
		if (env->events.key.keysym.sym == SDLK_RETURN
			&& env->events.type == SDL_KEYDOWN)
			env->introstep++;
		ft_intro_content_lvl3(env);
		SDL_WaitEvent(&env->events);
	}
	floor->currentstair = 3;
	floor->autorunswitch = 0;
}
