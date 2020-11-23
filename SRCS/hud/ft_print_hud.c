/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <jcharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:45:55 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/25 17:23:20 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_print_hud(t_env *env, t_elem *floor)
{
	SDL_RenderCopy(env->ren, floor->ticket == 0 ? env->hud.tex_ticket_off :
		env->hud.tex_ticket_on, NULL, &env->hud.rect_ticket);
	SDL_RenderCopy(env->ren, floor->balloon == 0 ? env->hud.tex_balloon_off :
		env->hud.tex_balloon_on, NULL, &env->hud.rect_balloon);
	SDL_RenderCopy(env->ren, floor->lollipop == 0 ? env->hud.tex_candy_off :
		env->hud.tex_candy_on, NULL, &env->hud.rect_candy);
	SDL_RenderCopy(env->ren, floor->pistol == 0 ? env->hud.tex_pistol_off :
		env->hud.tex_pistol_on, NULL, &env->hud.rect_pistol);
	SDL_RenderCopy(env->ren, floor->shotgun == 0 ? env->hud.tex_shotgun_off :
		env->hud.tex_shotgun_on, NULL, &env->hud.rect_shotgun);
	SDL_RenderCopy(env->ren, floor->devastator == 0 ? env->hud.tex_devast_off :
		env->hud.tex_devast_on, NULL, &env->hud.rect_devastator);
}

void			ft_print_fire_stat(t_env *env, int stat)
{
	SDL_RenderCopy(env->ren, stat > 0 ? env->hud.tex_fire_on :
		env->hud.tex_fire_off, NULL, &env->hud.rect_fire1);
	SDL_RenderCopy(env->ren, stat > 1 ? env->hud.tex_fire_on :
		env->hud.tex_fire_off, NULL, &env->hud.rect_fire2);
	SDL_RenderCopy(env->ren, stat > 2 ? env->hud.tex_fire_on :
		env->hud.tex_fire_off, NULL, &env->hud.rect_fire3);
	SDL_RenderCopy(env->ren, stat > 3 ? env->hud.tex_fire_on :
		env->hud.tex_fire_off, NULL, &env->hud.rect_fire4);
	SDL_RenderCopy(env->ren, stat > 4 ? env->hud.tex_fire_on :
		env->hud.tex_fire_off, NULL, &env->hud.rect_fire5);
}

void			ft_print_life(t_env *env, t_elem *floor)
{
	SDL_Color lifecolor;

	if (floor->life < 50)
	{
		lifecolor.r = 165;
		lifecolor.g = 25;
		lifecolor.b = 25;
	}
	else
	{
		lifecolor.r = 25;
		lifecolor.g = 165;
		lifecolor.b = 25;
	}
	if (floor->str_life)
		ft_strdel(&floor->str_life);
	floor->str_life = ft_itoa(floor->life);
	if (env->hud.tex_life)
		SDL_DestroyTexture(env->hud.tex_life);
	env->hud.tex_life = load_ttf_to_texture(env->ren, floor->str_life,
		floor->fpsfont, lifecolor);
	if (SDL_RenderCopy(env->ren, env->hud.tex_life, NULL, &env->hud.rect_life))
		ft_sdl_error(NULL);
}

void			ft_print_skull(t_env *env, t_elem *floor)
{
	if (floor->pistol_selected == 1)
	{
		SDL_RenderCopy(env->ren, env->hud.tex_skull, NULL,
		&env->hud.rect_pis_equiped);
	}
	else if (floor->shotgun_selected == 1)
	{
		SDL_RenderCopy(env->ren, env->hud.tex_skull, NULL,
		&env->hud.rect_sho_equiped);
	}
	else if (floor->devastator_selected == 1)
	{
		SDL_RenderCopy(env->ren, env->hud.tex_skull, NULL,
		&env->hud.rect_dev_equiped);
	}
}
