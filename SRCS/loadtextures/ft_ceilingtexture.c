/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceilingtexture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:29:29 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:41:16 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void			ft_ceilingtextureepic(t_elem *floor)
{
	floor->ceilingtext[0] = ft_load_texture(CEL_EPIC_0);
	floor->ceilingtext[1] = ft_load_texture(CEL_EPIC_1);
}

static	void			ft_ceilingtexturehigh(t_elem *floor)
{
	floor->ceilingtext[0] = ft_load_texture(CEL_HIGH_0);
	floor->ceilingtext[1] = ft_load_texture(CEL_HIGH_1);
}

static	void			ft_ceilingtexturenormal(t_elem *floor)
{
	floor->ceilingtext[0] = ft_load_texture(CEL_NORMAL_0);
	floor->ceilingtext[1] = ft_load_texture(CEL_NORMAL_1);
}

void					ft_ceilingtexture(t_elem *floor)
{
	if (floor->ceilingtext)
		ft_free_surface_tab(&floor->ceilingtext);
	if (!(floor->ceilingtext = ft_memalloc(sizeof(SDL_Surface) * 3)))
		ft_fct_error("malloc failed");
	else if (floor->texture_res == 1)
		ft_ceilingtexturenormal(floor);
	else if (floor->texture_res == 2)
		ft_ceilingtexturehigh(floor);
	else if (floor->texture_res == 4)
		ft_ceilingtextureepic(floor);
}
