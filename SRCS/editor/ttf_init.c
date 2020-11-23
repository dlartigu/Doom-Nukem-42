/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 23:06:00 by niboute           #+#    #+#             */
/*   Updated: 2020/08/20 14:00:48 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

t_ttf_text	*create_str_texture(SDL_Renderer *renderer, char *str,
								SDL_Color col, TTF_Font *police)
{
	SDL_Surface	*txt_surf;
	t_ttf_text	*new;

	if (!(new = (t_ttf_text*)ft_calloc(sizeof(t_ttf_text), 1)))
		return (NULL);
	if (!(txt_surf = TTF_RenderText_Blended(police, str, col)))
	{
		free(new);
		return (NULL);
	}
	if (!(new->texture = SDL_CreateTextureFromSurface(renderer, txt_surf)))
	{
		ft_putendl(TTF_GetError());
		free(new);
		SDL_FreeSurface(txt_surf);
		return (NULL);
	}
	SDL_QueryTexture(new->texture, NULL, NULL, &new->textbox.w,
					&new->textbox.h);
	SDL_FreeSurface(txt_surf);
	return (new);
}
