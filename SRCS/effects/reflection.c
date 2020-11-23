/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:43:29 by idris             #+#    #+#             */
/*   Updated: 2020/10/09 23:36:11 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t	mix_colors(t_env *env, t_ray *ray, uint32_t color, int y)
{
	uint32_t	c;
	int			percent;

	if (y > ray->yreflend)
		return (color);
	c = ft_readpixel(env->surf, ray->x, y);
	if (!(c & 0xFF))
		return (color);
	percent = 100 - ft_dmap(y - ray->dend, ray->yreflend - ray->dend, 0, 100);
	c = color_grad(c >> 8, 0, percent);
	return ((color_grad(color >> 8, c >> 8, percent)
		& 0xFFFFFF00) | (color & 0xFF));
}
