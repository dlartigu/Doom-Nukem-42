/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesmallstruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:44:09 by idris             #+#    #+#             */
/*   Updated: 2020/11/05 16:39:33 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_free_twall(t_tab_wall *tab)
{
	int i;

	i = 0;
	while (i < tab->number_wall)
	{
		tab->wall_impact[i].blockheight = -1;
		tab->wall_impact[i].mapx = -1;
		tab->wall_impact[i].mapy = -1;
		tab->wall_impact[i].side = -1;
		ft_free_surface(&(tab->wall_impact)[i].tex);
		i++;
	}
	tab->number_wall = 0;
	tab->oldest_wall = 0;
}

void		ft_free_skyboxes(t_elem *floor)
{
	if (floor->skyboxes[0])
	{
		if (floor->skyboxes[0]->texture)
			ft_free_texture(&floor->skyboxes[0]->texture);
		ft_memdel((void**)&floor->skyboxes[0]);
	}
	if (floor->skyboxes[1])
	{
		if (floor->skyboxes[1]->texture)
			ft_free_texture(&floor->skyboxes[1]->texture);
		ft_memdel((void**)&floor->skyboxes[1]);
	}
	ft_memdel((void**)&floor->skyboxes);
}

void		ft_free_sprite_data(t_elem *floor)
{
	int i;
	int j;

	i = 0;
	while (i < NB_SPRITE_TYPES)
	{
		j = 0;
		while (j < floor->sprites_data[i].max_dir)
		{
			ft_memdel((void**)&floor->sprites_data[i].texid[j]);
			j++;
		}
		ft_memdel((void**)&floor->sprites_data[i].texid);
		i++;
	}
}
