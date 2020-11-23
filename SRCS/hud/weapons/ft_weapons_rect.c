/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <jcharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:36:15 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/23 19:01:52 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void			ft_set_weapons_rect(t_env *env)
{
	int		w;
	int		h;

	w = rsx(env, 1.5);
	h = rsy(env, 1.5);
	env->hud.rect_dev_pos1 = s_rect(rsx(env, 2.01) - w / 2,
		env->res_hight - h, w, h);
	w = rsx(env, 2);
	h = rsy(env, 2);
	env->hud.rect_dev_fb_1 = s_rect(rsx(env, 2) - w / 2,
		env->res_hight - h, w, h);
	w = rsx(env, 1.5);
	h = rsy(env, 1.5);
	env->hud.rect_pis_p1 = s_rect(rsx(env, 2.6) - w / 2,
		env->res_hight - h, w, h);
	w = rsx(env, 1.5);
	h = rsy(env, 1.5);
	env->hud.rect_sho_p1 = s_rect(rsx(env, 2.05) - w / 2,
		env->res_hight - h, w, h);
	w = rsx(env, 2);
	h = rsy(env, 3);
	env->hud.rect_fist_p1 = s_rect(rsx(env, 2) - w / 2,
		env->res_hight - h, w, h);
}
