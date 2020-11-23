/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:27:42 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/15 00:10:40 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		init_threads(t_thread *threads, t_env *env, t_elem *floor)
{
	int				i;

	i = 0;
	while (i < floor->nb_threads)
	{
		threads[i].env = env;
		threads[i].floor = floor;
		i++;
	}
}

static void	init_game_p3(t_env *env, t_elem *floor)
{
	if (env->play_choice == 0)
		init_story(env, floor);
	else if (env->play_choice == 1)
		init_arcade(env, floor);
	ft_countfps(floor);
	if (!env->timer)
		env->timer = SDL_AddTimer(0, ft_printfps, floor);
	if (floor->inited == 0)
	{
		floor->ntext = 0;
		if (!floor->timetext)
			floor->timetext = SDL_AddTimer(80, ft_ntext, floor);
	}
}

static void	init_game_p2(t_env *env, t_elem *floor)
{
	floor->audio = &env->audio;
	floor->audio->effect_op = env->effect_op;
	floor->res_hight = env->res_hight;
	floor->res_width = env->res_width;
	floor->lookupcap = ft_dmap(600, 900, 0, env->res_hight * 2);
	floor->timer_arcade = 120;
	ft_initraycasting(floor);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	ft_initcolors(floor);
	ft_initfps(floor, env);
	ft_init_texture(env, floor);
	ft_init_hud(env);
	init_negativ(env);
	init_game_p3(env, floor);
}

void		init_game(t_env *env, t_elem *floor, t_thread **threads)
{
	floor->fist_selected = 1;
	if (!(*threads = (t_thread*)malloc(sizeof(t_thread) * floor->nb_threads)))
		ft_fct_error("init game(1)");
	if (!(env->window_buffer = (uint8_t*)ft_memalloc(sizeof(uint8_t)
	* env->res_width)))
		ft_fct_error("init game(2)");
	if (!(env->zbuffer = (double*)ft_memalloc(sizeof(double) * env->res_width)))
		ft_fct_error("init game(3)");
	if (!(env->sprite_zbuffer = (double*)ft_memalloc(sizeof(double)
	* env->res_width * env->res_hight)))
		ft_fct_error("init game(4)");
	init_threads(*threads, env, floor);
	init_game_p2(env, floor);
}
