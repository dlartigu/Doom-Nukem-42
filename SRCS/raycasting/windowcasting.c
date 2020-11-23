/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:31:34 by niboute           #+#    #+#             */
/*   Updated: 2020/11/07 03:01:59 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			windowcast_thread_p2(t_thread *thread, t_env *env,
				t_elem *floor, t_ray *ray)
{
	int			i;

	while (ray->x < thread->xend)
	{
		if (env->window_buffer[ray->x])
		{
			ft_setupray(env, floor, ray);
			ft_step(ray);
			i = hit_windows(floor, ray, env->window_buffer[ray->x]);
			i = ft_range(i, 0, 9);
			while (--i >= 0)
			{
				ray->perwalldist = ray->window_zbuffers[i];
				ray->side = ray->window_sidebuffer[i];
				ray->dperc = ray->window_depthbuffer[i];
				ray->wall_side = ray->wall_sidebuffer[i];
				ray->mapx = ray->wall_mapxbuffer[i];
				ray->mapy = ray->wall_mapybuffer[i];
				calc_window(env, floor, ray, i);
			}
		}
		ray->x++;
	}
}

void			*windowcast_thread(void *ptr)
{
	t_thread	*thread;
	t_ray		ray;
	t_elem		*floor;
	t_env		*env;

	thread = (t_thread*)ptr;
	floor = thread->floor;
	env = thread->env;
	ray.x = thread->x;
	ray.posx = floor->posx;
	ray.posy = floor->posy;
	windowcast_thread_p2(thread, env, floor, &ray);
	return (NULL);
}
