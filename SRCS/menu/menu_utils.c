/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 08:14:36 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 18:17:33 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int	test_return(int check, SDL_Event *event)
{
	if ((check && ((event->type == SDL_KEYDOWN
	&& event->key.keysym.sym == SDLK_RETURN)
	|| event->type == SDL_MOUSEBUTTONUP))
	|| (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE))
		return (1);
	return (0);
}
