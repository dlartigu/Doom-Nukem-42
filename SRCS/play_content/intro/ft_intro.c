/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:25 by jcharrou          #+#    #+#             */
/*   Updated: 2020/10/07 00:57:40 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void		ft_init_intro(t_env *env)
{
	env->rect_intro.x = env->res_width / 8;
	env->rect_intro.y = env->res_hight / 1.2;
	env->color.r = 255;
	env->color.g = 255;
	env->color.b = 255;
	env->color.a = 0;
	if (env->police2)
		TTF_CloseFont(env->police2);
	env->police2 = NULL;
	if (!(env->police2 = TTF_OpenFont("./RSCS/fonts/StraightToHellBB.ttf", 60)))
		ft_ttf_error(NULL);
	SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
	SDL_RenderClear(env->ren);
	SDL_RenderPresent(env->ren);
	env->introstep = 0;
}

void		ft_intro(t_env *env, t_elem *floor)
{
	change_sound_in_channel(&env->audio, env->audio.musics[MUS_INTRO],
	&env->audio.channels[CH_MUSIC], env->music_op);
	ft_init_intro(env);
	if (env->surf)
		SDL_FreeSurface(env->surf);
	env->surf = NULL;
	while (env->introstep != 12)
	{
		if (env->events.key.keysym.sym == SDLK_RETURN
			&& env->events.type == SDL_KEYDOWN)
			env->introstep++;
		ft_intro_content_p1(env);
		ft_intro_content_p2(env);
		SDL_WaitEvent(&env->events);
	}
	floor->currentstair = 0;
	floor->autorunswitch = 0;
}

uint32_t	ft_speak(uint32_t interval, void *param)
{
	t_env *env;

	env = param;
	env->introstep++;
	return (interval);
}

void		ft_render_intro(t_env *env)
{
	SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
	SDL_RenderCopy(env->ren, env->text, NULL, &env->rect_intro);
	if (env->surf)
		SDL_FreeSurface(env->surf);
	env->surf = NULL;
	if (env->text)
		SDL_DestroyTexture(env->text);
	env->text = NULL;
	SDL_RenderPresent(env->ren);
}

void		ft_baba(t_env *env)
{
	env->rect_baba.x = 0;
	env->rect_baba.y = 0;
	env->rect_baba.w = env->res_width;
	env->rect_baba.h = env->res_hight;
	if (env->bmpsurf)
	{
		SDL_FreeSurface(env->bmpsurf);
		env->bmpsurf = NULL;
	}
	ft_baba_image(env);
	if (env->bmptex)
	{
		SDL_DestroyTexture(env->bmptex);
		env->bmptex = NULL;
	}
	if (!(env->bmptex = SDL_CreateTextureFromSurface(env->ren, env->bmpsurf)))
		ft_sdl_error(NULL);
	SDL_RenderCopy(env->ren, env->bmptex, NULL, &env->rect_baba);
}
