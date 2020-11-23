/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:31:30 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/04 19:05:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static SDL_Renderer		*h_off_v_off(SDL_Window *win, t_env *env)
{
	SDL_Renderer	*ren;

	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE)))
		ft_putendl(SDL_GetError());
	env->vsync_op = 0;
	env->gpu_op = 0;
	return (ren);
}

static SDL_Renderer		*h_off_v_on(SDL_Window *win, t_env *env, int retry)
{
	SDL_Renderer	*ren;

	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE
	| SDL_RENDERER_PRESENTVSYNC)))
	{
		ft_putendl(SDL_GetError());
		if (retry)
		{
			ft_putendl("VSync couldn't be activated, disabling it and"
			" retrying");
			return (h_off_v_off(win, env));
		}
	}
	env->vsync_op = 1;
	env->gpu_op = 0;
	return (ren);
}

static SDL_Renderer		*h_on_v_off(SDL_Window *win, t_env *env, int retry)
{
	SDL_Renderer	*ren;

	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED)))
	{
		ft_putendl(SDL_GetError());
		if (retry)
		{
			ft_putendl("Hardware Acceleration couldn't be activated, disabling"
			" it and retrying");
			return (h_off_v_off(win, env));
		}
	}
	env->vsync_op = 0;
	env->gpu_op = 1;
	return (ren);
}

static SDL_Renderer		*h_on_v_on(SDL_Window *win, t_env *env, int retry)
{
	SDL_Renderer	*ren;

	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED
	| SDL_RENDERER_PRESENTVSYNC)))
	{
		if (retry)
		{
			ft_putendl(SDL_GetError());
			ft_putendl("Either VSync or Hardware Acceleration isn't supported "
			"on your machine, trying without VSync");
			if (!(ren = h_on_v_off(win, env, 0)))
			{
				ft_putendl("Disabling VSync didn't work, trying again with only"
				" hardware acceleration disabled");
				return (h_on_v_off(win, env, 1));
			}
			return (ren);
		}
	}
	env->vsync_op = 1;
	env->gpu_op = 1;
	return (ren);
}

SDL_Renderer			*ft_init_renderer(SDL_Window *win, t_sdl *sdl,
						t_env *env)
{
	SDL_Renderer		*ren;

	ren = NULL;
	if (sdl->hard_accel == 0 && sdl->vsync == 0)
		ren = h_off_v_off(win, env);
	else if (sdl->hard_accel == 0 && sdl->vsync == 1)
		ren = h_off_v_on(win, env, 1);
	else if (sdl->hard_accel == 1 && sdl->vsync == 0)
		ren = h_on_v_off(win, env, 1);
	else if (sdl->hard_accel == 1 && sdl->vsync == 1)
		ren = h_on_v_on(win, env, 1);
	if (ren == NULL)
		ft_error(INIT_REN);
	SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
	sdl->vsync = env->vsync_op;
	sdl->hard_accel = env->gpu_op;
	return (ren);
}
