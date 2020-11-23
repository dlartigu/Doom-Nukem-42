/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 01:54:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 00:48:03 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"
#include "../../INCLUDES/editor.h"

int			init_gameover(t_env *env, int *hover, int *ret, t_elem *floor)
{
	*ret = 0;
	*hover = 0;
	SDL_SetRelativeMouseMode(SDL_FALSE);
	play_simple(&env->audio, EFF_GAMEOVER, CH_GAMEOVER, 1);
	env->gameover1 = load_bmp_to_texture(env->ren, GAMEOVER_RETURN);
	env->gameover2 = load_bmp_to_texture(env->ren, GAMEOVER_RETRY);
	SDL_RenderCopy(env->ren, env->gameover1, NULL, NULL);
	ft_printscore(env, floor, 1);
	SDL_RenderPresent(env->ren);
	return (1);
}
