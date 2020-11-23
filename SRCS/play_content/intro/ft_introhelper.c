/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_introhelper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:29:56 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/30 16:28:40 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void			ft_sdlputerror(void)
{
	ft_putendl("SDL_load image failed");
	SDL_GetError();
}

static	void	ft_baba_image2(t_env *env)
{
	if (env->introstep == 3)
	{
		if ((env->bmpsurf = SDL_LoadBMP(BABA3)) < 0)
			ft_sdlputerror();
	}
	else if (env->introstep == 4)
	{
		if ((env->bmpsurf = SDL_LoadBMP(BABA4)) < 0)
			ft_sdlputerror();
	}
	else if (env->introstep >= 5)
	{
		if ((env->bmpsurf = SDL_LoadBMP(BABA5)) < 0)
			ft_sdlputerror();
	}
}

void			ft_baba_image(t_env *env)
{
	if (env->introstep == 0)
	{
		if ((env->bmpsurf = SDL_LoadBMP(BABA0)) < 0)
			ft_sdlputerror();
	}
	else if (env->introstep == 1)
	{
		if ((env->bmpsurf = SDL_LoadBMP(BABA1)) < 0)
			ft_sdlputerror();
	}
	else if (env->introstep == 2)
	{
		if ((env->bmpsurf = SDL_LoadBMP(BABA2)) < 0)
			ft_sdlputerror();
	}
	ft_baba_image2(env);
}

void			ft_intro_baba(t_env *env)
{
	if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		ft_sdl_error(NULL);
	ft_baba(env);
	ft_render_intro(env);
}

void			ft_intro_helper(t_env *env, int rectw, int recth)
{
	env->rect_intro.w = rectw;
	env->rect_intro.h = recth;
}
