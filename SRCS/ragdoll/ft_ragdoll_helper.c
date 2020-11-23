/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ragdoll_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:33:17 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/22 20:38:02 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_ragdoll_timerdown(t_elem *floor, double speedragdoll, int ragdoll,
		double ragdollsensi)
{
	floor->speedragdoll = speedragdoll;
	floor->ragdoll = ragdoll;
	floor->ragdollsensi = ragdollsensi;
	if (floor->timerragdolldown)
		SDL_RemoveTimer(floor->timerragdolldown);
	if (!(floor->timerragdolldown = SDL_AddTimer(20
		* floor->gravity, ft_ragdoll_base_down, floor)))
		ft_sdl_error(NULL);
}

void	ft_ragdoll_timerup(t_elem *floor, double speedragdoll, int ragdoll,
		double ragdollsensi)
{
	floor->speedragdoll = speedragdoll;
	floor->ragdoll = ragdoll;
	floor->ragdollsensi = ragdollsensi;
	if (floor->timerragdollup)
		SDL_RemoveTimer(floor->timerragdollup);
	if (!(floor->timerragdollup = SDL_AddTimer(20
		* floor->gravity, ft_ragdoll_base_up, floor)))
		ft_sdl_error(NULL);
}

void	ft_printragdoll(t_env *env, t_elem *floor)
{
	if (floor->life < 50 && floor->life >= 0)
	{
		floor->ragsurf = NULL;
		floor->ragtext = NULL;
		if (floor->life < 50 && floor->life >= 40)
			floor->ragsurf = ft_load_texture(RAG50);
		if (floor->life < 40 && floor->life >= 20)
			floor->ragsurf = ft_load_texture(RAG40);
		if (floor->life < 20 && floor->life >= 10)
			floor->ragsurf = ft_load_texture(RAG20);
		if (floor->life < 10 && floor->life >= 0)
			floor->ragsurf = ft_load_texture(RAG10);
		floor->ragtext = SDL_CreateTextureFromSurface(env->ren, floor->ragsurf);
		SDL_FreeSurface(floor->ragsurf);
		SDL_RenderCopy(env->ren, floor->ragtext, NULL, NULL);
		SDL_DestroyTexture(floor->ragtext);
	}
}

void	ft_ragdoll_above50(t_elem *floor)
{
	if (floor->life >= 90)
		floor->speedragdoll = 0.00;
	else if (floor->life < 90 && floor->life >= 80)
		floor->speedragdoll = 0.004;
	else if (floor->life < 80 && floor->life >= 60)
		floor->speedragdoll = 0.006;
	else if (floor->life < 60 && floor->life > 50)
		floor->speedragdoll = 0.008;
}
