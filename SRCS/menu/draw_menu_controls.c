/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:32:18 by niboute           #+#    #+#             */
/*   Updated: 2020/08/31 10:52:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	draw_menu_controls(t_env *env)
{
	if (!(env->texte = SDL_LoadBMP(
	"./RSCS/menu/settings/Gameplay/show_controls/show_controls.bmp")))
		ft_sdl_error(NULL);
	SDL_RenderClear(env->ren);
	if (!(env->fonttex =
	SDL_CreateTextureFromSurface(env->ren, env->texte)))
		ft_sdl_error("control_menu 2");
	if (env->texte)
		ft_free_surface(&env->texte);
	SDL_RenderCopy(env->ren, env->fonttex, NULL, NULL);
	if (env->fonttex)
		ft_free_texture(&env->fonttex);
}
