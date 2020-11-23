/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crosshair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:44:19 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/28 18:15:38 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_crosshair(t_env *env)
{
	SDL_SetRenderDrawColor(env->ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(env->ren, env->res_width / 2, env->res_hight / 2);
	SDL_RenderDrawLine(env->ren, env->res_width / 2 - 10,
		env->res_hight / 2, env->res_width / 2 - 5, env->res_hight / 2);
	SDL_RenderDrawLine(env->ren, env->res_width / 2 + 10,
		env->res_hight / 2, env->res_width / 2 + 5, env->res_hight / 2);
	SDL_RenderDrawLine(env->ren, env->res_width / 2,
		env->res_hight / 2 - 5, env->res_width / 2, env->res_hight / 2 - 10);
	SDL_RenderDrawLine(env->ren, env->res_width / 2,
		env->res_hight / 2 + 5, env->res_width / 2, env->res_hight / 2 + 10);
}
