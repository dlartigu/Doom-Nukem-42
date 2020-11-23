/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:09:38 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/31 16:50:30 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		render_cursor(SDL_Renderer *ren, SDL_Texture *cursor, int x,
				int y)
{
	SDL_Rect	rect;

	rect.x = x - 12;
	rect.y = y - 2;
	rect.w = 16;
	rect.h = 16;
	SDL_RenderCopy(ren, cursor, NULL, &rect);
}

void		draw_cursor(t_env *env, SDL_Event *event)
{
	if (!env->cursors[1] && !(env->cursors[1] = load_bmp_to_texture(env->ren,
		"RSCS/gameicons/cursor/cursor_wolf1.bmp")))
		ft_sdl_error("draw_cursor_up");
	if (!env->cursors[0] && !(env->cursors[0] = load_bmp_to_texture(env->ren,
		"RSCS/gameicons/cursor/cursor_keydown.bmp")))
		ft_sdl_error("draw_cursor_down");
	SDL_GetMouseState(&env->cursx, &env->cursy);
	env->cx = ft_dmap(env->cursx, env->res_width, 0, 800);
	env->cy = ft_dmap(env->cursy, env->res_hight, 0, 450);
	if (event->type == SDL_MOUSEBUTTONDOWN)
		render_cursor(env->ren, env->cursors[0], env->cursx, env->cursy);
	else
		render_cursor(env->ren, env->cursors[1], env->cursx, env->cursy);
}
