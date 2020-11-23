/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:48:51 by idris             #+#    #+#             */
/*   Updated: 2020/11/05 16:49:47 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		print_counter(t_env *env, t_elem *floor)
{
	char	*str;
	char	*todel;

	todel = ft_itoa(floor->timechrono);
	str = ft_strjoin("                 ", todel);
	ft_memdel((void**)&todel);
	todel = str;
	str = ft_strjoin(todel, "                 ");
	ft_memdel((void**)&todel);
	if (floor->timechrono >= 0)
		ft_message_setup(env, floor, str);
	if (floor->timechrono == -1 && floor->chrono)
		SDL_RemoveTimer(floor->chrono);
	ft_memdel((void**)&str);
}

uint32_t	counter(uint32_t interval, void *param)
{
	t_elem	*floor;

	floor = param;
	floor->timechrono--;
	return (interval);
}

void		init_counter(t_elem *floor, int time)
{
	floor->timechrono = time;
	if (!floor->chrono)
		floor->chrono = SDL_AddTimer(1000, counter, floor);
}
