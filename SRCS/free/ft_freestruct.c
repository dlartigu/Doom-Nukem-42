/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:45:33 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 09:50:53 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				ft_free_tab_telem(t_elem **floor)
{
	int		i;

	i = 0;
	while (i < (*floor)->max_floor + 1)
	{
		ft_memdel((void**)&(*floor)[i].warp);
		ft_freetab(&(*floor)[i].box);
		ft_freebigtab(&(*floor)[i].map);
		ft_freebigtab(&(*floor)[i].new);
		ft_freebigtab(&(*floor)[i].new_backup);
		i++;
	}
	ft_memdel((void **)floor);
}

void				ft_free_surface_tab(SDL_Surface ***surfaces)
{
	int		i;

	i = 0;
	if (surfaces == NULL || *surfaces == NULL)
		return ;
	while ((*surfaces)[i])
	{
		ft_free_surface(&((*surfaces)[i]));
		i++;
	}
	ft_memdel((void**)surfaces);
}

void				ft_free_texture_tab(SDL_Texture ***texture)
{
	int		i;

	i = 0;
	if (texture == NULL || *texture == NULL)
		return ;
	while ((*texture)[i])
	{
		ft_free_texture(&((*texture)[i]));
		i++;
	}
	ft_memdel((void**)texture);
}
