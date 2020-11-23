/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 00:58:10 by idris             #+#    #+#             */
/*   Updated: 2020/11/05 11:31:44 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void	drop(t_env *env, t_rect rect)
{
	t_pixel	a;
	t_pixel	b;
	int		diff;
	int		r;

	a.x = rect.x;
	a.y = rect.y;
	b.y = rect.y + rect.h;
	diff = rand() % 2;
	if (rand() % 2 == 0)
		b.x = a.x + diff;
	else
		b.x = a.x - diff;
	r = rand() % 115;
	ft_bresenham(env->foresurf, a, b, ((0x7D + r) << 24) + ((0x7D
		+ r) << 16) + ((0x7D + r) << 8) + 0xff);
}

void		rain2(t_env *env)
{
	t_rect	rect;
	int		i;
	int		prop;

	i = env->surf->w / 20;
	prop = env->surf->h / 50;
	while (i > 0)
	{
		rect.x = rand() % env->surf->w;
		rect.y = rand() % env->surf->h;
		rect.h = prop + rand() % prop;
		drop(env, rect);
		i--;
	}
}

void		rain(t_env *env)
{
	t_rect	rect;
	int		i;
	int		prop;

	i = env->surf->w / 80;
	prop = env->surf->h / 35;
	while (i > 0)
	{
		rect.x = rand() % env->surf->w;
		rect.y = rand() % env->surf->h;
		rect.h = prop + rand() % prop;
		drop(env, rect);
		i--;
	}
}

uint32_t	init_rain(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	interval = 10000 - rand() % 5000;
	floor->timedrain ^= 1;
	if (floor->timedrain == 0)
		floor->rained = 1;
	if (floor->timedrain)
		play_simple(floor->audio, EFF_RAIN, CH_RAIN, 0);
	return (interval);
}

uint32_t	fog_rain(uint32_t interval, void *param)
{
	t_elem *floor;

	(void)interval;
	floor = param;
	floor->fog ^= 1;
	if (floor->fog == 1)
		return (20000);
	else
		return (30000);
}
