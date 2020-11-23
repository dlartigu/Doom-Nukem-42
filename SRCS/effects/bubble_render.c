/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 23:41:39 by idris             #+#    #+#             */
/*   Updated: 2020/11/06 17:20:26 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		select_texture(t_env *env, t_elem *floor, SDL_Rect *rect)
{
	int			part;
	SDL_Rect	coord;

	part = (int)floor->res_hight / 7;
	coord.x = rect->x - rect->w / 2;
	coord.y = rect->y;
	coord.h = rect->h;
	coord.w = rect->w;
	if (coord.y > part)
		SDL_RenderCopy(env->ren, floor->bubble[0], NULL, &coord);
	else if (coord.y > part / 2)
		SDL_RenderCopy(env->ren, floor->bubble[1], NULL, &coord);
	else if (coord.y > part / 3)
		SDL_RenderCopy(env->ren, floor->bubble[2], NULL, &coord);
	else if (coord.y > part / 4)
		SDL_RenderCopy(env->ren, floor->bubble[3], NULL, &coord);
	else if (coord.y > part / 5)
		SDL_RenderCopy(env->ren, floor->bubble[4], NULL, &coord);
	else if (coord.y > part / 6)
		SDL_RenderCopy(env->ren, floor->bubble[5], NULL, &coord);
	else
		SDL_RenderCopy(env->ren, floor->bubble[6], NULL, &coord);
}

void		ft_bubble(t_env *env, t_elem *floor)
{
	t_list *ptr;

	ptr = floor->lst;
	while (ptr)
	{
		select_texture(env, floor, ptr->content);
		ptr = ptr->next;
	}
}

SDL_Rect	*ft_rect(int x, int y, int w, int h)
{
	SDL_Rect *rect;

	if (!(rect = (SDL_Rect*)ft_memalloc(sizeof(SDL_Rect))))
		ft_fct_error("malloc failed");
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	return (rect);
}

void		start_bubbles(t_env *env, t_elem *floor)
{
	if (!floor->bubble)
		init_bubble(env, floor);
	if (!floor->timer_bubble)
		floor->timer_bubble = SDL_AddTimer(600, ft_create_bubble, floor);
	if (!floor->timer_bubble_progress)
		floor->timer_bubble_progress = SDL_AddTimer(10, ft_bubble_progress,
			floor);
}
