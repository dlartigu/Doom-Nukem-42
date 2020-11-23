/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:38:30 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/10 03:38:48 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	get_max_res(t_sdl *sdl)
{
	SDL_DisplayMode		current;
	int					display;

	display = SDL_GetCurrentDisplayMode(0, &current);
	sdl->w_max = current.w;
	sdl->h_max = current.h;
}
