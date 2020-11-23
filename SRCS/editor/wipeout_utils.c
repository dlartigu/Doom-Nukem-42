/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipeout_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:07:16 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:19:14 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	delete_texture(SDL_Texture *texture)
{
	if (texture)
		SDL_DestroyTexture(texture);
	texture = NULL;
}

void	delete_texture_tab_ttf(t_ttf_text *tab, size_t i)
{
	if (tab)
		while (i > 0 && i--)
			delete_texture(tab[i].texture);
}

void	delete_sdl_text(t_sdl_text **tab)
{
	if (*tab)
	{
		ft_free_texture(&(*tab)->texture);
		ft_memdel((void**)tab);
	}
}

void	delete_ttf(t_ttf_text **tab)
{
	if (*tab)
	{
		ft_free_texture(&(*tab)->texture);
		ft_memdel((void**)tab);
	}
}

void	delete_texture_tab(t_sdl_text *tab, size_t i)
{
	if (tab)
		while (i > 0 && i--)
			delete_texture(tab[i].texture);
}
