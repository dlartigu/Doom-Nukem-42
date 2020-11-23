/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_impact4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 02:49:04 by user42            #+#    #+#             */
/*   Updated: 2020/11/15 03:28:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	fill_poswall(t_elem *floor, t_ray *ray, t_wall *mywall)
{
	mywall->mapx = ray->mapx;
	mywall->mapy = ray->mapy;
	mywall->side = ft_side(ray->side, ray->rdirx, ray->rdiry);
	mywall->blockheight = (((int)ray->texpos - TEXT_H
	* floor->texture_res)) / (TEXT_H * floor->texture_res);
}
