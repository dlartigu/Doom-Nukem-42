/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 01:08:06 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/10 03:37:54 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_free_surface(SDL_Surface **surface)
{
	if (!surface)
		return ;
	if (*surface)
		SDL_FreeSurface(*surface);
	*surface = NULL;
}

void	ft_free_texture(SDL_Texture **texture)
{
	if (!texture)
		return ;
	if (*texture)
		SDL_DestroyTexture(*texture);
	*texture = NULL;
}
