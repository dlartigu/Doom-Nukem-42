/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:46:09 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 19:46:24 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	update_enemies(t_elem *floor)
{
	t_list		*ptr;
	t_sprite	*spr;

	ptr = floor->enemies;
	while (ptr)
	{
		spr = (t_sprite*)ptr->content;
		if (spr->wave <= floor->fire_stat)
		{
			floor[floor->currentstair].new[(int)spr->posy]
			[(int)spr->posx][SPRITE] = '6';
		}
		ptr = ptr->next;
	}
}
