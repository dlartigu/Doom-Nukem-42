/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ttf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:35:10 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/21 17:06:37 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		load_font(t_env *env)
{
	if (env->police2)
		TTF_CloseFont(env->police2);
	env->police2 = NULL;
	if (!(env->police2 = TTF_OpenFont("./RSCS/fonts/wolfenstein.ttf", 60)))
		ft_ttf_error(NULL);
	env->red.r = 165;
	env->red.g = 25;
	env->red.b = 25;
	env->red.a = 0;
}

SDL_Rect	s_rect(double x, double y, double w, double h)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}

void		set_ttf_rect_xy(t_env *env, double x, double y)
{
	env->pos2.x = x;
	env->pos2.y = y;
}

void		set_ttf_rect_wh(t_env *env, double w, double h)
{
	env->pos2.w = w;
	env->pos2.h = h;
}
