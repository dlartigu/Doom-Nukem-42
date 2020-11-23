/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:03 by jcharrou          #+#    #+#             */
/*   Updated: 2020/10/26 19:30:59 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		ft_fpsrenderhelper(t_env *env, t_elem *floor)
{
	if (!(floor->fpssurf =
		TTF_RenderText_Solid(floor->fpsfont, floor->fps, floor->fpscolor)))
		ft_ttf_error(NULL);
	if (env->fpstext)
	{
		SDL_DestroyTexture(env->fpstext);
		env->fpstext = NULL;
	}
}

void				ft_fpsrender(t_env *env, t_elem *floor)
{
	ft_countfps(floor);
	ft_fpsrenderhelper(env, floor);
	if (!(env->fpstext =
		SDL_CreateTextureFromSurface(env->ren, floor->fpssurf)))
		ft_ttf_error(NULL);
	if (floor->fpssurf)
	{
		SDL_FreeSurface(floor->fpssurf);
		floor->fpssurf = NULL;
	}
	if (SDL_RenderCopy(env->ren, env->fpstext, NULL, &env->rectfps))
		ft_sdl_error(NULL);
}

void				ft_initfps(t_elem *floor, t_env *env)
{
	env->rectfps = s_rect(rsx(env, 8), rsy(env, 1.04), rsw(env, 20),
		rsh(env, 20));
	if (!(floor->fpsfont = TTF_OpenFont(
		"./RSCS/fonts/StraightToHellBB.ttf", 60)))
		ft_ttf_error(NULL);
	floor->fpscolor.r = 165;
	floor->fpscolor.g = 25;
	floor->fpscolor.b = 25;
	floor->fpscolor.a = 0;
}

void				ft_countfps(t_elem *floor)
{
	floor->oldtime = floor->time;
	floor->time = SDL_GetTicks();
	floor->frametime = (floor->time - floor->oldtime) / 1000.0;
}

uint32_t			ft_printfps(uint32_t interval, void *parametre)
{
	t_elem *floor;

	floor = parametre;
	interval = 500;
	if (floor->fps)
		ft_strdel(&floor->fps);
	if (!(floor->fps = ftoa(1.0 / floor->frametime, floor->fps)))
		ft_fct_error("ftoa");
	return (interval);
}
