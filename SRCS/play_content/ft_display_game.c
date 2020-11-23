/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:17:26 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 19:11:32 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void	ft_display_game_p3(t_env *env, t_elem *floor,
				t_thread *threads)
{
	change_walk_audio(env, floor);
	ft_sound_events(env, floor);
	ft_inputs(env, floor);
	ft_godmode(floor);
	if (floor->wall_toclean == 1 && floor->tab->number_wall > 0)
	{
		ft_free_twall(&floor->tab[1]);
		floor->wall_toclean = 0;
	}
	handle_enemies(env, floor);
	ft_render(env, floor, threads);
}

static int	ft_display_game_p2(t_env *env, t_elem *floor,
			t_thread *threads)
{
	while (1)
	{
		if (floor->life <= 0
		|| (env->play_choice == 1 && floor->timechrono <= 0))
		{
			if (!gameover(env, threads, floor))
				ft_sdl_error("gameover");
			return (1);
		}
		while (SDL_PollEvent(&env->events))
		{
			ft_weapons_events(env, floor);
			ft_godmode_toggle(env, floor);
			if (game_events(env, floor, threads))
				return (1);
		}
		ft_display_game_p3(env, floor, threads);
	}
}

int			ft_display_game(t_env *env, t_elem *floor)
{
	t_thread		*threads;

	if (floor->inited == 1)
		ft_free_between(&env, &floor);
	init_game(env, floor, &threads);
	bullet_impact_init(floor);
	SDL_SetWindowGrab(env->win, SDL_TRUE);
	SDL_WarpMouseInWindow(env->win, env->res_hight / 2, env->res_width / 2);
	floor->autorunswitch = 0;
	ft_effects(env, floor);
	floor->inited = 1;
	ft_display_game_p2(env, floor, threads);
	return (1);
}
