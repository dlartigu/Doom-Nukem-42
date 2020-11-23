/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextfloor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:15:16 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:28:04 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void		ft_warptonextfloor2(t_env *env, t_elem *floor)
{
	ft_effects(env, floor);
	ft_free_twall(&floor->tab[0]);
	ft_free_twall(&floor->tab[1]);
}

void		ft_warptonextfloor(t_env *env, t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] != '8')
		floor->message = 0;
	else if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '8' && floor->currentstair < 4
		&& floor->ticket == 0)
		floor->message = 1;
	else if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '8' && floor->currentstair < 4
		&& floor->ticket == 1)
	{
		pause_soundeffects(&env->audio);
		if (floor->currentstair == 0)
			ft_setup_level2(env, floor);
		else if (floor->currentstair == 1)
			ft_setup_level3(env, floor);
		else if (floor->currentstair == 2)
			ft_setup_level4(env, floor);
		ft_warptonextfloor2(env, floor);
	}
}

void		ft_warp(t_env *env, t_elem *floor)
{
	ft_warptonextfloor(env, floor);
	ft_warptowarp(floor);
}
