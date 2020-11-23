/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floortexture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:29:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 16:45:46 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void			ft_floortextureepic(t_elem *floor)
{
	floor->floortext[0] = ft_load_texture(FLO_EPIC_0);
	floor->floortext[1] = ft_load_texture(FLO_EPIC_1);
	floor->floortext[2] = ft_load_texture(FLO_EPIC_2);
	floor->floortext[3] = ft_load_texture(FLO_EPIC_3);
	floor->floortext[4] = ft_load_texture(FLO_EPIC_4);
	floor->floortext[5] = ft_load_texture(FLO_EPIC_5);
}

static	void			ft_floortexturehigh(t_elem *floor)
{
	floor->floortext[0] = ft_load_texture(FLO_HIGH_0);
	floor->floortext[1] = ft_load_texture(FLO_HIGH_1);
	floor->floortext[2] = ft_load_texture(FLO_HIGH_2);
	floor->floortext[3] = ft_load_texture(FLO_HIGH_3);
	floor->floortext[4] = ft_load_texture(FLO_HIGH_4);
	floor->floortext[5] = ft_load_texture(FLO_HIGH_5);
}

static	void			ft_floortexturenormal(t_elem *floor)
{
	floor->floortext[0] = ft_load_texture(FLO_NORMAL_0);
	floor->floortext[1] = ft_load_texture(FLO_NORMAL_1);
	floor->floortext[2] = ft_load_texture(FLO_NORMAL_2);
	floor->floortext[3] = ft_load_texture(FLO_NORMAL_3);
	floor->floortext[4] = ft_load_texture(FLO_NORMAL_4);
	floor->floortext[5] = ft_load_texture(FLO_NORMAL_5);
}

void					ft_floortexture(t_elem *floor)
{
	if (floor->floortext)
		ft_free_surface_tab(&floor->floortext);
	if (!(floor->floortext = ft_memalloc(sizeof(SDL_Surface) * 6)))
		ft_fct_error("malloc failed");
	else if (floor->texture_res == 1)
		ft_floortexturenormal(floor);
	else if (floor->texture_res == 2)
		ft_floortexturehigh(floor);
	else if (floor->texture_res == 4)
		ft_floortextureepic(floor);
}
