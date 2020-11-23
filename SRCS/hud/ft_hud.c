/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:51:02 by jcharrou          #+#    #+#             */
/*   Updated: 2020/10/06 22:31:06 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_set_hud_right(t_env *env)
{
	env->hud.rect_pis_equiped = s_rect(rsx(env, 9), rsy(env, 6),
		rsw(env, 20), rsh(env, 20));
	env->hud.rect_sho_equiped = s_rect(rsx(env, 6), rsy(env, 4),
		rsw(env, 20), rsh(env, 20));
	env->hud.rect_dev_equiped = s_rect(rsx(env, 5), rsy(env, 3),
		rsw(env, 20), rsh(env, 20));
	env->hud.rect_pistol = s_rect(rsx(env, 15), rsy(env, 6.5),
		rsw(env, 20), rsh(env, 20));
	env->hud.rect_shotgun = s_rect(rsx(env, 8.7), rsy(env, 3.5),
		rsw(env, 10), rsh(env, 10));
	env->hud.rect_devastator = s_rect(rsx(env, 6.5), rsy(env, 2.5),
		rsw(env, 7), rsh(env, 7));
}

static	void	ft_set_hud_left(t_env *env)
{
	int w;

	env->hud.rect_ticket = s_rect(rsx(env, -20), rsy(env, 7.5),
		rsw(env, 15), rsh(env, 20));
	env->hud.rect_candy = s_rect(rsx(env, -20), rsy(env, 4.25),
		rsw(env, 15), rsh(env, 20));
	env->hud.rect_balloon = s_rect(rsx(env, -20), rsy(env, 3),
		rsw(env, 15), rsh(env, 20));
	w = rsw(env, 15);
	env->hud.rhg = s_rect(rsx(env, -20),
		rsy(env, 2) - w / 2, w, rsh(env, 20));
	env->hud.rect_life = s_rect(rsx(env, -20), rsy(env, 2.1),
		rsw(env, 15), rsh(env, 30));
}

void			ft_set_hud_rect(t_env *env)
{
	env->hud.rect_fire1 = s_rect(rsx(env, 2.8), rsy(env, 1.02),
		rsw(env, 15), rsh(env, 15));
	env->hud.rect_fire2 = s_rect(rsx(env, 3), rsy(env, 1.02),
		rsw(env, 15), rsh(env, 15));
	env->hud.rect_fire3 = s_rect(rsx(env, 3.25), rsy(env, 1.02),
		rsw(env, 15), rsh(env, 15));
	env->hud.rect_fire4 = s_rect(rsx(env, 3.50), rsy(env, 1.02),
		rsw(env, 15), rsh(env, 15));
	env->hud.rect_fire5 = s_rect(rsx(env, 3.80), rsy(env, 1.02),
		rsw(env, 15), rsh(env, 15));
	env->hud.rect_used_ammo = s_rect(rsx(env, 4.22), rsy(env, 12),
		rsw(env, 40), rsh(env, 32));
	env->hud.rect_split_ammo = s_rect(rsx(env, 5.15), rsy(env, 12),
		rsw(env, 35), rsh(env, 35));
	env->hud.rect_max_ammo = s_rect(rsx(env, 6.55), rsy(env, 12),
		rsw(env, 40), rsh(env, 32));
	env->hud.rect_no_ammo = s_rect(rsx(env, 1.22), rsy(env, 1.15),
		rsw(env, 8), rsh(env, 12));
}

void			ft_init_hud(t_env *env)
{
	ft_set_hud_right(env);
	ft_set_hud_left(env);
	ft_set_hud_rect(env);
	ft_set_weapons_rect(env);
	ft_set_weapon_struct(env);
}
