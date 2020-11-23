/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadtextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <jcharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:44:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/25 17:00:01 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

SDL_Surface			*ft_load_texture(char *file)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;

	if (!(stock = SDL_LoadBMP(file)))
		ft_sdl_error(NULL);
	if (!(surface = SDL_ConvertSurfaceFormat(stock,
		SDL_PIXELFORMAT_RGBA8888, 0)))
	{
		SDL_FreeSurface(stock);
		ft_sdl_error(NULL);
	}
	if (stock)
		SDL_FreeSurface(stock);
	return (surface);
}

SDL_Texture			*load_bmp_to_texture(SDL_Renderer *renderer, char *file)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;
	SDL_Texture		*text;

	if (!(stock = SDL_LoadBMP(file)))
		ft_sdl_error(NULL);
	if (!(surface = SDL_ConvertSurfaceFormat(stock,
		SDL_PIXELFORMAT_RGBA8888, 0)))
	{
		SDL_FreeSurface(stock);
		ft_sdl_error(NULL);
	}
	SDL_FreeSurface(stock);
	if (!(text = SDL_CreateTextureFromSurface(renderer, surface)))
		ft_sdl_error(NULL);
	SDL_FreeSurface(surface);
	return (text);
}

SDL_Texture			*load_ttf_to_texture(SDL_Renderer *renderer, char *str,
					TTF_Font *font, SDL_Color col)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;
	SDL_Texture		*text;

	if (!(stock = TTF_RenderText_Blended(font, str, col)))
		ft_sdl_error(NULL);
	if (!(surface = SDL_ConvertSurfaceFormat(stock,
		SDL_PIXELFORMAT_RGBA8888, 0)))
	{
		SDL_FreeSurface(stock);
		ft_sdl_error(NULL);
	}
	SDL_FreeSurface(stock);
	if (!(text = SDL_CreateTextureFromSurface(renderer, surface)))
		ft_sdl_error(NULL);
	SDL_FreeSurface(surface);
	return (text);
}

void				ft_init_texture(t_env *env, t_elem *floor)
{
	ft_walltexture(floor);
	ft_floortexture(floor);
	ft_ceilingtexture(floor);
	load_skyboxes(env, floor);
	ft_load_head_guy_texture(env);
	ft_load_hud_textures(env, floor);
	ft_load_weapons_textures(env);
	ft_load_intro_textures(env);
}
