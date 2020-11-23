/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightuptorch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:31:01 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:30:04 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void	search_items(t_elem *floor, int num, int activate)
{
	t_list *m;

	m = floor->items;
	while (m)
	{
		if (((t_sprite*)(m->content))->type == num)
			((t_sprite*)(m->content))->state = activate;
		m = m->next;
	}
}

void	ft_torch_toogle(t_env *env, t_elem *floor)
{
	if (floor->torchtoogle == 1)
	{
		if (floor->shadow)
		{
			if (env->events.key.keysym.sym == SDLK_e
				&& env->events.type == SDL_KEYDOWN)
			{
				floor->shadow = 0;
				floor->lightop = 1;
				search_items(floor, TORCH, 1);
			}
		}
		else if (!floor->shadow)
		{
			if (env->events.key.keysym.sym == SDLK_e
				&& env->events.type == SDL_KEYDOWN)
			{
				floor->shadow = 1;
				floor->lightop = 0;
				search_items(floor, TORCH, 0);
			}
		}
	}
}

void	ft_sprite_torch(t_elem *floor)
{
	if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] == '1')
	{
		floor->torchtoogle = 1;
		if (floor->shadow)
			floor->message = 2;
		else if (!floor->shadow)
			floor->message = 3;
	}
	else if (floor[floor->currentstair].new[(int)floor->posy]
		[(int)floor->posx][SPRITE] != '1')
		floor->torchtoogle = 0;
}
