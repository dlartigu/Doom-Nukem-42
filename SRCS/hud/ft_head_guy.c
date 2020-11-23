/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_guy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:44:43 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/17 20:13:43 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_head_guy_2(t_env *env, t_elem *floor)
{
	if (floor->life < 60 && floor->life >= 40)
	{
		if (env->hud.hg_step == 1)
			SDL_RenderCopy(env->ren, env->hud.hg_text[7], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 2)
			SDL_RenderCopy(env->ren, env->hud.hg_text[8], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 3)
			SDL_RenderCopy(env->ren, env->hud.hg_text[9], NULL, &env->hud.rhg);
	}
	else if (floor->life < 40 && floor->life >= 20)
	{
		if (env->hud.hg_step == 1)
			SDL_RenderCopy(env->ren, env->hud.hg_text[10], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 2)
			SDL_RenderCopy(env->ren, env->hud.hg_text[11], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 3)
			SDL_RenderCopy(env->ren, env->hud.hg_text[12], NULL, &env->hud.rhg);
	}
}

static void		ft_head_guy_1(t_env *env, t_elem *floor)
{
	if (!env->hud.head_guy_timer)
		env->hud.head_guy_timer = SDL_AddTimer(1500, ft_head_guy_timer,
			&env->hud);
	if (floor->life <= 100 && floor->life >= 80)
	{
		if (env->hud.hg_step == 1)
			SDL_RenderCopy(env->ren, env->hud.hg_text[1], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 2)
			SDL_RenderCopy(env->ren, env->hud.hg_text[2], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 3)
			SDL_RenderCopy(env->ren, env->hud.hg_text[3], NULL, &env->hud.rhg);
	}
	else if (floor->life < 80 && floor->life >= 60)
	{
		if (env->hud.hg_step == 1)
			SDL_RenderCopy(env->ren, env->hud.hg_text[4], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 2)
			SDL_RenderCopy(env->ren, env->hud.hg_text[5], NULL, &env->hud.rhg);
		else if (env->hud.hg_step == 3)
			SDL_RenderCopy(env->ren, env->hud.hg_text[6], NULL, &env->hud.rhg);
	}
	else
		ft_head_guy_2(env, floor);
}

uint32_t		ft_head_guy_timer(uint32_t interval, void *param)
{
	t_hud	*hud;

	hud = param;
	if (hud->hg_step == 1)
	{
		hud->hg_step = 2;
		hud->hg_prev_step = 1;
	}
	else if (hud->hg_step == 2 && hud->hg_prev_step == 1)
	{
		hud->hg_step = 3;
		hud->hg_prev_step = 2;
	}
	else if (hud->hg_step == 3)
	{
		hud->hg_step = 2;
		hud->hg_prev_step = 3;
	}
	else if (hud->hg_step == 2 && hud->hg_prev_step == 3)
	{
		hud->hg_step = 1;
		hud->hg_prev_step = 2;
	}
	return (interval);
}

void			ft_head_guy(t_env *env, t_elem *floor)
{
	if (floor->godmode)
		SDL_RenderCopy(env->ren, env->hud.hg_text[0], NULL, &env->hud.rhg);
	else
	{
		ft_head_guy_1(env, floor);
		if (floor->life < 20 && floor->life >= 10)
		{
			if (env->hud.hg_step == 1)
				SDL_RenderCopy(env->ren, env->hud.hg_text[13],
					NULL, &env->hud.rhg);
			if (env->hud.hg_step == 2)
				SDL_RenderCopy(env->ren, env->hud.hg_text[14],
					NULL, &env->hud.rhg);
			if (env->hud.hg_step == 3)
				SDL_RenderCopy(env->ren, env->hud.hg_text[15],
					NULL, &env->hud.rhg);
		}
		if (floor->life < 10)
			SDL_RenderCopy(env->ren, env->hud.hg_text[16], NULL, &env->hud.rhg);
	}
}

void			ft_load_head_guy_texture(t_env *env)
{
	if (env->hud.hg_text)
		ft_free_texture_tab(&env->hud.hg_text);
	if (!(env->hud.hg_text = (SDL_Texture**)ft_memalloc(
	sizeof(SDL_Texture*) * 18)))
		ft_fct_error("malloc failed");
	env->hud.hg_text[0] = load_bmp_to_texture(env->ren, HG_GOD);
	env->hud.hg_text[1] = load_bmp_to_texture(env->ren, HG_100_P1);
	env->hud.hg_text[2] = load_bmp_to_texture(env->ren, HG_100_P2);
	env->hud.hg_text[3] = load_bmp_to_texture(env->ren, HG_100_P3);
	env->hud.hg_text[4] = load_bmp_to_texture(env->ren, HG_80_P1);
	env->hud.hg_text[5] = load_bmp_to_texture(env->ren, HG_80_P2);
	env->hud.hg_text[6] = load_bmp_to_texture(env->ren, HG_80_P3);
	env->hud.hg_text[7] = load_bmp_to_texture(env->ren, HG_60_P1);
	env->hud.hg_text[8] = load_bmp_to_texture(env->ren, HG_60_P2);
	env->hud.hg_text[9] = load_bmp_to_texture(env->ren, HG_60_P3);
	env->hud.hg_text[10] = load_bmp_to_texture(env->ren, HG_40_P1);
	env->hud.hg_text[11] = load_bmp_to_texture(env->ren, HG_40_P2);
	env->hud.hg_text[12] = load_bmp_to_texture(env->ren, HG_40_P3);
	env->hud.hg_text[13] = load_bmp_to_texture(env->ren, HG_20_P1);
	env->hud.hg_text[14] = load_bmp_to_texture(env->ren, HG_20_P2);
	env->hud.hg_text[15] = load_bmp_to_texture(env->ren, HG_20_P3);
	env->hud.hg_text[16] = load_bmp_to_texture(env->ren, HG_10);
	env->hud.hg_step = 1;
}
