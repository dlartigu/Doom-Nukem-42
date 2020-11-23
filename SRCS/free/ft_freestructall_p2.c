/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestructall_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:35:01 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:43:36 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void				ft_free_env_1_p2(t_env *env)
{
	if (env->ren != NULL)
		SDL_DestroyRenderer(env->ren);
	env->ren = NULL;
	if (env->win != NULL)
		SDL_DestroyWindow(env->win);
	env->win = NULL;
	ft_free_texture(&env->bmptex);
	ft_free_texture(&env->fonttex);
	ft_free_texture(&env->streamingtex);
}

void						ft_free_env_1(t_env *env)
{
	ft_free_texture(&env->cursors[0]);
	ft_free_texture(&env->cursors[1]);
	ft_free_texture(&env->fpstext);
	ft_free_texture(&env->text);
	ft_free_texture(&env->text2);
	ft_free_surface(&env->surf);
	ft_free_surface(&env->surf2);
	ft_free_surface_tab(&env->wall_texture);
	ft_free_surface(&env->floor_texture);
	ft_free_surface(&env->ceiling_texture);
	ft_free_surface(&env->icon);
	ft_free_surface_tab(&env->weapon);
	ft_free_env_1_p2(env);
}

static	void				ft_free_floor_p3(t_elem **floor)
{
	if ((*floor)->timetext)
		SDL_RemoveTimer((*floor)->timetext);
	ft_free_sprite_data(*floor);
	ft_lstdelsprite(&(*floor)->enemies);
	ft_lstdelsprite(&(*floor)->items);
	ft_lstdelsprite(&(*floor)->projectiles);
	ft_free_surface_tab(&(*floor)->sprites);
	ft_free_surface_tab(&(*floor)->animatedwalltext);
	if ((*floor)->max_floor > 7)
		ft_freebigtab(&(*floor)[7].map);
	ft_free_tab_telem(floor);
}

static	void				ft_free_floor_p2(t_elem **floor)
{
	if ((*floor)->timer_bubble)
		SDL_RemoveTimer((*floor)->timer_bubble);
	if ((*floor)->timer_bubble_progress)
		SDL_RemoveTimer((*floor)->timer_bubble_progress);
	ft_free_texture_tab(&(*floor)->bubble);
	ft_lstdelm(&((*floor)->lst));
	ft_free_twall(&(*floor)->tab[0]);
	ft_free_twall(&(*floor)->tab[1]);
	ft_free_surface(&(*floor)->bullet);
	ft_lstdelm(&((*floor)->lst));
	ft_free_surface(&(*floor)->minimapsurf);
	ft_strdel(&(*floor)->str_life);
	ft_strdel(&(*floor)->fps);
	ft_free_skyboxes(*floor);
	ft_free_floor_p3(floor);
}

void						ft_free_floor(t_elem **floor)
{
	if (!floor || !*floor)
		return ;
	if ((*floor)->fpsfont != NULL)
		TTF_CloseFont((*floor)->fpsfont);
	(*floor)->fpsfont = NULL;
	ft_free_surface(&(*floor)->fpssurf);
	ft_free_texture(&(*floor)->fpstext);
	ft_free_surface(&(*floor)->surf);
	ft_free_texture(&(*floor)->text);
	ft_free_surface_tab(&(*floor)->walltext);
	ft_free_surface_tab(&(*floor)->floortext);
	ft_free_texture(&(*floor)->skybox);
	ft_free_surface_tab(&(*floor)->ceilingtext);
	ft_free_surface(&(*floor)->icon);
	ft_free_surface_tab(&(*floor)->weapon);
	ft_free_floor_p2(floor);
}
