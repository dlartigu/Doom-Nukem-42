/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ammos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:51:59 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/19 16:36:09 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static char		*ft_check_ammos(int ammo, char *str)
{
	str[0] = ammo / 10 + '0';
	str[1] = ammo % 10 + '0';
	str[2] = '\0';
	return (str);
}

static void		ft_convert_ammos(t_elem *floor)
{
	if (floor->devastator_selected == 1)
	{
		ft_check_ammos(floor->max_ammo_legendary,
			floor->str_max_ammo_legendary);
		ft_check_ammos(floor->usable_ammo_legendary,
			floor->str_usable_ammo_legendary);
	}
	else if (floor->pistol_selected == 1)
	{
		ft_check_ammos(floor->max_ammo_pistol,
			floor->str_max_ammo_pistol);
		ft_check_ammos(floor->usable_ammo_pistol,
			floor->str_usable_ammo_pistol);
	}
	else if (floor->shotgun_selected == 1)
	{
		ft_check_ammos(floor->max_ammo_shotgun,
			floor->str_max_ammo_shotgun);
		ft_check_ammos(floor->usable_ammo_shotgun,
			floor->str_usable_ammo_shotgun);
	}
}

static void		ft_max_ammos(t_env *env, t_elem *floor, char *max, int current)
{
	ft_free_texture(&env->hud.tex_ammo);
	if (!(env->hud.tex_ammo = load_ttf_to_texture(env->ren, max, floor->fpsfont,
		floor->fpscolor)))
		ft_sdl_error("Invalid texture max ammos");
	if (SDL_RenderCopy(env->ren, env->hud.tex_ammo, NULL,
		&env->hud.rect_max_ammo))
		ft_sdl_error("texture max ammo");
	floor->previous_max_ammo = current;
}

static void		ft_used_ammos(t_env *env, t_elem *floor, char *used,
	int current)
{
	ft_free_texture(&env->hud.tex_no_ammo);
	if (!(env->hud.tex_no_ammo = load_ttf_to_texture(env->ren, used,
		floor->fpsfont, floor->fpscolor)))
		ft_sdl_error("Invalid texture used ammos");
	if (SDL_RenderCopy(env->ren, env->hud.tex_no_ammo, NULL,
		&env->hud.rect_used_ammo))
		ft_sdl_error("texture used ammo");
	if (SDL_RenderCopy(env->ren, env->hud.tex_split_ammo, NULL,
		&env->hud.rect_split_ammo))
		ft_sdl_error("texture split ammo");
	floor->previous_used_ammo = current;
}

void			ft_print_ammos(t_env *env, t_elem *floor)
{
	ft_convert_ammos(floor);
	if (floor->pistol_selected == 1)
	{
		ft_used_ammos(env, floor, floor->str_usable_ammo_pistol,
			floor->usable_ammo_pistol);
		ft_max_ammos(env, floor, floor->str_max_ammo_pistol,
			floor->max_ammo_pistol);
	}
	else if (floor->shotgun_selected == 1)
	{
		ft_used_ammos(env, floor, floor->str_usable_ammo_shotgun,
			floor->usable_ammo_shotgun);
		ft_max_ammos(env, floor, floor->str_max_ammo_shotgun,
			floor->max_ammo_shotgun);
	}
	else if (floor->devastator_selected == 1)
	{
		ft_used_ammos(env, floor, floor->str_usable_ammo_legendary,
			floor->usable_ammo_legendary);
		ft_max_ammos(env, floor, floor->str_max_ammo_legendary,
			floor->max_ammo_legendary);
	}
}
