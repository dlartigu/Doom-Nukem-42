/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:41 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/27 17:06:36 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void		ft_intro_setup(t_env *env, int w, int h, char *str)
{
	SDL_RenderClear(env->ren);
	ft_intro_helper(env, w, h);
	if (!(env->surf =
		TTF_RenderText_Blended(env->police2, str, env->color)))
		ft_ttf_error(NULL);
	ft_intro_baba(env);
}

void			ft_intro_content_p1(t_env *env)
{
	if (env->introstep == 0)
	{
		SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
		SDL_RenderClear(env->ren);
		ft_baba(env);
		SDL_RenderPresent(env->ren);
		if (env->bmpsurf)
			SDL_FreeSurface(env->bmpsurf);
		env->bmpsurf = NULL;
		if (env->bmptex)
			SDL_DestroyTexture(env->bmptex);
		env->bmptex = NULL;
	}
	else if (env->introstep == 1)
		ft_intro_setup(env, 60, 50, "Sergei");
}

void			ft_intro_content_p2(t_env *env)
{
	if (env->introstep == 2)
		ft_intro_setup(env, 70, 50, "Sergei!");
	else if (env->introstep == 3)
		ft_intro_setup(env, 180, 50, "WAKE   UP   Sergei!");
	else if (env->introstep == 4)
		ft_intro_setup(env, 210, 50, "I  am   the  BabaYaga");
	else if (env->introstep == 5)
		ft_intro_setup(env, 360, 50, "I  summoned  you  from  the  hells");
	else if (env->introstep == 6)
		ft_intro_setup(env, 500, 50,
			"It s  time  to  accomplish  your  purpose");
	else if (env->introstep == 7)
		ft_intro_setup(env, 450, 50,
			"Kill  them  all  and  I will  set  you  free!");
	else if (env->introstep == 8)
		ft_intro_setup(env, 380, 50, "You  have  lost  your  memories");
	else if (env->introstep == 9)
		ft_intro_setup(env, 540, 50,
			"Let s  find  them  in  the  maze  of  your  soul");
	else if (env->introstep == 10)
		ft_intro_setup(env, 450, 50, "A  BabaYaga  never  breaks  a  promise");
	else if (env->introstep == 11)
		ft_intro_setup(env, 650, 50,
			"Legs  yes!  Hearts  occasionnaly  but  never  a  promise!");
}
