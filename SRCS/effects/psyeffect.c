/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psyeffect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:24:07 by idris             #+#    #+#             */
/*   Updated: 2020/11/17 10:20:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t	ft_negatifflash_timer(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	floor->negative ^= 1;
	return (interval);
}

uint32_t	ft_negatifflash_meta(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->timer_flashtoflash == 1)
	{
		floor->timer_flashtoflash = 0;
		interval = 10000;
	}
	else
	{
		floor->timer_flashtoflash = 1;
		interval = 3000;
	}
	if (floor->timer_flashtoflash == 1)
	{
		floor->negatifflashtimer = SDL_AddTimer(5, ft_negatifflash_timer,
			floor);
	}
	else if (floor->timer_flashtoflash == 0 && floor->negatifflashtimer)
	{
		SDL_RemoveTimer(floor->negatifflashtimer);
		floor->negative = 0;
	}
	return (interval);
}

void		flashnegatif(t_elem *floor)
{
	if (floor->negatifflash == 1)
	{
		if (!floor->timer_flash)
			floor->timer_flash = SDL_AddTimer(0, ft_negatifflash_meta, floor);
		else
			SDL_RemoveTimer(floor->timer_flash);
	}
	else if (floor->negatifflash == 0 && floor->negatifflashtimer)
	{
		SDL_RemoveTimer(floor->timer_flash);
		floor->negative = 0;
		if (floor->negatifflashtimer)
			SDL_RemoveTimer(floor->negatifflashtimer);
		floor->timer_flashtoflash = 0;
	}
}

void		init_negativ(t_env *env)
{
	env->width = env->res_width;
	env->height = env->res_hight;
	env->streamingtex = SDL_CreateTexture(env->ren, SDL_PIXELFORMAT_RGBA8888,
	SDL_TEXTUREACCESS_STREAMING, env->width, env->height);
}

void		renderer_aftereffect(t_env *env, t_elem *floor)
{
	int		max;
	int		i;
	Uint32	*ren_tab;
	int		pitch;

	i = 0;
	max = env->width * env->height;
	SDL_LockTexture(env->streamingtex, NULL, (void**)&ren_tab, &pitch);
	SDL_RenderReadPixels(env->ren, NULL, SDL_PIXELFORMAT_RGBA8888, ren_tab,
	pitch);
	while (i < max)
	{
		if (floor->negative)
		{
			ren_tab[i] = (0xFFFFFF00 - (ren_tab[i]) & 0xFFFFFF00)
			+ (ren_tab[i] & 0xFF);
		}
		if (floor->player_hit)
			ren_tab[i] = color_grad(ren_tab[i] >> 8, 0xFF0000, 50);
		i++;
	}
	SDL_UnlockTexture(env->streamingtex);
	SDL_RenderCopy(env->ren, env->streamingtex, NULL, NULL);
}
