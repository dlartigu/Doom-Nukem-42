/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestructall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 01:02:41 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 17:22:02 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void						ft_free_env_2(t_env *env)
{
	ft_memdel((void**)&env->window_buffer);
	ft_memdel((void**)&env->zbuffer);
	ft_memdel((void**)&env->sprite_zbuffer);
	ft_free_texture(&env->fonttex2);
	ft_free_texture(&env->gameover1);
	ft_free_texture(&env->gameover2);
	ft_free_surface(&env->bmpsurf);
	ft_free_surface(&env->texte);
	if (env->police != NULL)
		TTF_CloseFont(env->police);
	env->police = NULL;
	if (env->police2 != NULL)
		TTF_CloseFont(env->police2);
	env->police2 = NULL;
	ft_memdel((void**)&env->sensitivity_value);
	ft_memdel((void**)&env->char_volume_value);
	ft_free_texture_tab(&env->text_intro);
}

void						ft_free_map_struct(t_map *map)
{
	map->floor = NULL;
	ft_memdel((void**)&(map->line));
	ft_memdel((void**)&(map->tmp));
}

void						ft_free_structs(t_env *env, t_map *map,
							t_elem *floor, int exit)
{
	ft_remove_timers(env, floor);
	ft_free_env_1(env);
	ft_free_env_2(env);
	ft_free_floor(&floor);
	if (exit)
	{
		ft_free_map_struct(map);
		ft_exit_sdl(env);
	}
}

static void					ft_free_between_p2(t_elem **floor)
{
	ft_free_texture(&(*floor)->skybox);
	ft_free_surface_tab(&(*floor)->ceilingtext);
	ft_free_surface(&(*floor)->icon);
	ft_free_surface_tab(&(*floor)->weapon);
	if ((*floor)->timer_bubble)
		SDL_RemoveTimer((*floor)->timer_bubble);
	if ((*floor)->timer_bubble_progress)
		SDL_RemoveTimer((*floor)->timer_bubble_progress);
	ft_free_texture_tab(&(*floor)->bubble);
	ft_lstdelm(&((*floor)->lst));
	ft_free_twall(&(*floor)->tab[0]);
	ft_free_twall(&(*floor)->tab[1]);
	ft_free_surface(&(*floor)->bullet);
	ft_free_surface(&(*floor)->minimapsurf);
	ft_strdel(&(*floor)->str_life);
	ft_free_skyboxes(*floor);
}

void						ft_free_between(t_env **env, t_elem **floor)
{
	if (!env || !*env)
		return ;
	ft_memdel((void**)&(*env)->window_buffer);
	ft_memdel((void**)&(*env)->zbuffer);
	ft_memdel((void**)&(*env)->sprite_zbuffer);
	if (!floor || !*floor)
		return ;
	if ((*floor)->fpsfont != NULL)
		TTF_CloseFont((*floor)->fpsfont);
	(*floor)->fpsfont = NULL;
	ft_free_surface(&(*floor)->fpssurf);
	ft_free_texture(&(*floor)->fpstext);
	ft_free_surface(&(*floor)->surf);
	ft_free_texture(&(*floor)->text);
	ft_free_surface_tab(&(*floor)->floortext);
	ft_free_between_p2(floor);
}
