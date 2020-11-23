/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:45:02 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 10:57:16 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_drawrect(SDL_Surface *surf, uint32_t color, t_rect rect)
{
	int		i;
	t_pixel pixel0;
	t_pixel pixel1;

	i = 0;
	while (i < rect.h)
	{
		pixel0.x = rect.x;
		pixel0.y = rect.y + i;
		pixel1.x = pixel0.x + rect.w;
		pixel1.y = pixel0.y;
		ft_bresenham(surf, pixel0, pixel1, color);
		i++;
	}
}

void			ft_bresenham(SDL_Surface *surf, t_pixel pixel0,
	t_pixel pixel1, uint32_t color)
{
	double	tx;
	double	dx;
	double	dy;
	int		x;
	int		y;

	tx = 0;
	dx = pixel1.x - pixel0.x;
	dy = pixel1.y - pixel0.y;
	while (tx <= 1)
	{
		x = pixel0.x + (dx * tx);
		y = pixel0.y + (dy * tx);
		ft_putpixel(surf, x, y, color);
		tx += 1 / sqrt((dx * dx) + (dy * dy));
	}
}

uint32_t		ft_readpixel(SDL_Surface *surf, int x, int y)
{
	int		bpp;
	uint8_t	*p;

	bpp = surf->format->BytesPerPixel;
	p = (uint8_t *)surf->pixels + y * surf->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(uint16_t *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(uint32_t *)p);
	return (0);
}

void			ft_putpixel(SDL_Surface *surf, int x, int y, uint32_t color)
{
	uint32_t	*pixels;

	pixels = (uint32_t *)surf->pixels;
	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
		pixels[y * surf->w + x] = color;
}
