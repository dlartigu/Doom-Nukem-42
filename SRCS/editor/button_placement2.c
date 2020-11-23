/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_placement2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:04:01 by niboute           #+#    #+#             */
/*   Updated: 2020/10/18 08:56:24 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		assign_menu_rect(SDL_Rect *rect, int y, SDL_Rect *src)
{
	rect->x = src->x;
	rect->y = y;
	rect->w = src->w;
	if (y == 0)
		rect->h = src->h * 3 / 21;
	else
		rect->h = src->h * 2 / 21;
	return (rect->h);
}

void	button_to_rect(SDL_Rect *src, SDL_Rect *dst, int index, int nb)
{
	src->w = dst->w / nb;
	src->x = (index * dst->w) / nb + dst->x;
	src->h = dst->h;
	src->y = dst->y;
}

void	center_rect_middle(SDL_Rect *src, SDL_Rect *dst, int index, int nb)
{
	if (src->w < dst->w / nb - 10)
		src->x = (((index * 2) - 1) * dst->w) / (2 * nb) - src->w / 2 + dst->x;
	else
	{
		src->w = dst->w / nb - 10;
		src->x = dst->x + ((index - 1) * dst->w) / nb + 5;
	}
	if (src->h < dst->h)
		src->y = dst->h / 2 - src->h / 2 + dst->y;
	else
	{
		src->y = dst->y + 5;
		src->h = dst->h - 10;
	}
}

void	center_rect_left(SDL_Rect *src, SDL_Rect *dst, int index, int nb)
{
	if (src->w < dst->w - 10)
		src->x = 10 + (index * dst->w) / nb + dst->x;
	else
	{
		src->w = dst->w / nb;
		src->x = (index * dst->w) / nb + dst->x;
	}
	if (src->h < dst->h)
		src->y = dst->h / 2 - src->h / 2 + dst->y;
	else
	{
		src->y = dst->y;
		src->h = dst->h;
	}
}

void	center_rect_right(SDL_Rect *src, SDL_Rect *dst, int index, int nb)
{
	if (src->w < dst->w - 10)
		src->x = (index * dst->w) / nb - (src->w + 10) + dst->x;
	else
	{
		src->w = dst->w / nb;
		src->x = (index * dst->w) / nb + dst->x;
	}
	if (src->h < dst->h)
		src->y = dst->h / 2 - src->h / 2 + dst->y;
	else
	{
		src->y = dst->y;
		src->h = dst->h;
	}
}
