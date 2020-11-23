/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:15:50 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:38 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				ft_render_weapons(t_env *env, t_elem *floor)
{
	if (floor->devastator_selected == 1)
		ft_draw_dev(env, floor);
	else if (floor->pistol_selected == 1)
		ft_draw_pistol(env, floor);
	else if (floor->shotgun_selected == 1)
		ft_draw_shotgun(env, floor);
	else
		ft_draw_fist(env);
}

void				ft_draw_hud(t_env *env, t_elem *floor)
{
	ft_crosshair(env);
	ft_fpsrender(env, floor);
	ft_print_life(env, floor);
	ft_print_hud(env, floor);
	ft_print_fire_stat(env, floor->fire_stat);
	ft_print_ammos(env, floor);
	ft_print_skull(env, floor);
	ft_render_weapons(env, floor);
	ft_head_guy(env, floor);
	ft_messages(env, floor);
	ft_game_msg(env, floor);
	ft_printscore(env, floor, 0);
}

static	void		ft_render_p2(t_env *env, t_elem *floor, t_thread *threads)
{
	ft_drawrenderer(env, floor, threads);
	ft_draw_hud(env, floor);
	if (floor->underwater)
		ft_bubble(env, floor);
	if (floor->negative || floor->player_hit)
		renderer_aftereffect(env, floor);
	if (floor->timechrono >= 0)
		print_counter(env, floor);
	SDL_RenderPresent(env->ren);
}

void				ft_render(t_env *env, t_elem *floor, t_thread *threads)
{
	ft_free_surface(&env->surf);
	ft_free_surface(&env->foresurf);
	if (!env->surf && !(env->surf = SDL_CreateRGBSurfaceWithFormat(0,
	env->res_width, env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
		ft_sdl_error(NULL);
	if (!env->foresurf && !(env->foresurf = SDL_CreateRGBSurfaceWithFormat(0,
	env->res_width, env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
		ft_sdl_error(NULL);
	if (!floor->radarsurf
	&& !(floor->radarsurf = SDL_CreateRGBSurfaceWithFormat(0, env->res_width,
		env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
		ft_sdl_error(NULL);
	if (!floor->minimapsurf
	&& !(floor->minimapsurf = SDL_CreateRGBSurfaceWithFormat(0, env->res_width,
		env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
		ft_sdl_error(NULL);
	ft_bzero(env->window_buffer, env->res_width * sizeof(uint8_t));
	ft_bzero(env->sprite_zbuffer, env->res_width * env->res_hight
		* sizeof(double));
	ft_render_p2(env, floor, threads);
}
