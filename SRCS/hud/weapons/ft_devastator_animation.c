/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devastator_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:57:14 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/05 16:36:11 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void			ft_event_dev(t_env *env, t_elem *floor)
{
	if (env->events.type == SDL_MOUSEBUTTONDOWN && env->events.button.button
		== SDL_BUTTON_LEFT && floor->usable_ammo_legendary > 0)
	{
		if (!env->hud.weapon_timer)
		{
			add_projectile(env, floor, 0, NULL);
			env->switchlock = 1;
			env->hud.dev_flag = 1;
			env->hud.weapon_timer = SDL_AddTimer(0, ft_weapons_timer,
				env);
			if (!floor->shoot_delay)
				floor->shoot_delay =
					SDL_AddTimer(0, ft_spend_ammo_timer, floor);
		}
	}
}

void			ft_draw_dev(t_env *env, t_elem *floor)
{
	if (floor->devastator_selected == 1)
	{
		if (env->hud.dev_flag == 1)
		{
			SDL_RenderCopy(env->ren, env->hud.dev_text[env->hud.weapon_step],
				NULL, &env->hud.rect_dev_pos1);
		}
		else
			SDL_RenderCopy(env->ren, env->hud.dev_text[0], NULL,
				&env->hud.rect_dev_pos1);
	}
}
