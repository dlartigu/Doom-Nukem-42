/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousemotion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:57:19 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/07 02:14:18 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_mousemotion(t_env *env, t_elem *floor)
{
	int	newlookupdown;

	if (env->events.type == SDL_MOUSEMOTION)
	{
		if (floor->autorunmove == 0)
		{
			floor->mousex = (double)env->events.motion.xrel
			/ ((double)floor->sensitivity_x / floor->sensitivity_setup);
			floor->angle -= floor->rotatespeed * floor->mousex;
			newlookupdown = floor->lookupdown
			+ ft_dmap(((double)env->events.motion.yrel
				* ((double)floor->sensitivity_y * floor->sensitivity_setup)),
				450, 0, env->res_hight);
		}
		SDL_WarpMouseInWindow(env->win, env->res_width / 2, env->res_hight / 2);
		if (floor->autorunmove == 0)
		{
			if (newlookupdown > floor->lookupcap)
				floor->lookupdown = floor->lookupcap;
			else if (newlookupdown < -floor->lookupcap)
				floor->lookupdown = -floor->lookupcap;
			else
				floor->lookupdown = newlookupdown;
		}
	}
}
