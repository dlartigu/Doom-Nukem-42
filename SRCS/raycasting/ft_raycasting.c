/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 17:37:51 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		raycast_solidwalls_p2(t_ray *ray, t_env *env, t_elem *floor,
				int i)
{
	int			psyeffect;

	ray->deltafly = ray->deltaline <= 0 ? 0 : ray->deltaline;
	floor->deltafly = ray->deltafly;
	if (ray->blocksize > 1)
		ray->blocksize = (ray->blocksize - 1) * ray->linehight;
	psyeffect = floor->psy == 0 ? 0 : env->res_width / 8;
	ray->dst = (-ray->linehight / (2 * floor->flysensi)
	+ env->res_hight / 2
	- floor->lookupdown - ray->blocksize) + ray->deltacrouch;
	ray->dend = (ray->linehight / (2 * floor->crouchsensi)
	+ env->res_hight / 2
	- floor->lookupdown - psyeffect) + ray->deltafly;
	ray->dend =
		ray->dend >= env->res_hight ? (env->res_hight - 1) : ray->dend;
	ray->yrefl = ray->dend - ((ray->dst - psyeffect) - ray->dend);
	ray->dst = ray->dst < 0 ? 0 : ray->dst;
	ray->y = ray->dst - psyeffect;
	ray->y = ft_range(ray->y, 0, env->res_hight - 1);
	ray->yrefl = ft_range(ray->yrefl, 0, env->res_hight - 1);
	ray->yreflend = ray->yrefl;
	ft_wall_textnum(floor, ray);
	ft_draw_walltextured(env, floor, ray, i);
	ft_drawfloorceiling(env, floor, ray, i);
}

void			raycast_solidwalls(t_env *env, t_elem *floor, t_ray *ray, int i)
{
	ft_hit(env, floor, ray, i);
	if (ray->blocksize <= ray->maxheight)
		return ;
	ray->maxheight = ray->blocksize;
	ray->linehight = abs((int)(env->res_hight / ray->perwalldist));
	ray->crouchde = ray->linehight / (2 * floor->crouchsensi);
	ray->crouchds = ray->linehight / (2 * floor->flysensi);
	ray->deltaline = ray->crouchde - ray->crouchds;
	floor->deltaline = 2 * floor->crouchsensi - 2 * floor->flysensi;
	ray->deltacrouch = ray->deltaline >= 0 ? 0 : ray->deltaline;
	floor->deltacrouch = ray->deltacrouch;
	raycast_solidwalls_p2(ray, env, floor, i);
}

void			*raycast_thread(void *ptr)
{
	t_thread	*thread;
	t_ray		ray;
	t_env		*env;
	t_elem		*floor;
	int			i;

	thread = (t_thread*)ptr;
	floor = thread->floor;
	env = thread->env;
	ray.x = thread->x;
	ray.posx = floor->posx;
	ray.posy = floor->posy;
	while (ray.x < thread->xend)
	{
		ft_setupray(env, floor, &ray);
		ft_step(&ray);
		i = 0;
		while (ray.mapx > 0 && ray.mapy > 0 && ray.mapx
		< floor[floor->currentstair].width - 1 && ray.mapy
		< floor[floor->currentstair].hight - 1 && ray.old_dst > 0)
			raycast_solidwalls(env, floor, &ray, i++);
		ray.x++;
	}
	return (NULL);
}

void			start_threads(t_thread *threads, t_env *env, t_elem *floor,
				void *(fct(void*)))
{
	int			i;

	i = 0;
	while (i < floor->nb_threads)
	{
		threads[i].x = (i * env->res_width) / floor->nb_threads;
		threads[i].xend = ((i + 1) * env->res_width) / floor->nb_threads;
		if (pthread_create(&threads[i].thread, NULL, fct,
			(void*)&threads[i]))
			ft_fct_error("start_threads");
		i++;
	}
	i = 0;
	while (i < floor->nb_threads)
	{
		pthread_join(threads[i].thread, NULL);
		i++;
	}
}
