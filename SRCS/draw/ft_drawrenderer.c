/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:44:28 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/17 17:21:21 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_render_sky(t_env *env, t_elem *floor)
{
	if ((floor->currentstair != 1 && floor->currentstair != 5)
	&& floor->skyboxes[0])
		draw_skybox(env, floor, floor->skyboxes[0]);
}

void			draw_free(SDL_Renderer *ren, SDL_Surface **surf, SDL_Rect *dst)
{
	SDL_Texture *texture;

	if (!(texture = SDL_CreateTextureFromSurface(ren, *surf)))
		ft_ttf_error(NULL);
	ft_free_surface(surf);
	if (SDL_RenderCopy(ren, texture, NULL, dst))
		ft_sdl_error(NULL);
	SDL_DestroyTexture(texture);
}

static	void	ft_drawrenderer_p2(t_env *env, t_elem *floor)
{
	SDL_SetTextureBlendMode(env->text, SDL_BLENDMODE_BLEND);
	SDL_RenderClear(env->ren);
	ft_render_sky(env, floor);
	draw_free(env->ren, &env->surf, NULL);
	draw_free(env->ren, &env->foresurf, NULL);
	ft_free_texture(&env->text);
	ft_printragdoll(env, floor);
	draw_free(env->ren, &floor->radarsurf, NULL);
	if (floor->m)
		draw_free(env->ren, &floor->minimapsurf, NULL);
}

void			ft_drawrenderer(t_env *env, t_elem *floor, t_thread *threads)
{
	if (floor->timedrain && floor->seerain)
		rain2(env);
	start_threads(threads, env, floor, raycast_thread);
	draw_sprites(env, floor);
	start_threads(threads, env, floor, windowcast_thread);
	if (floor->impact == 2)
	{
		if (floor->taketxtnum == 17)
			bullet_impact(floor, floor->tab, 1);
		else
			bullet_impact(floor, floor->tab, 0);
		floor->impact = 0;
	}
	if (floor->timedrain && floor->seerain)
		rain(env);
	if (floor->m == 1)
		ft_minimap(env, floor);
	ft_radar(env, floor);
	ft_free_texture(&env->text);
	if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		ft_ttf_error(NULL);
	ft_drawrenderer_p2(env, floor);
}
