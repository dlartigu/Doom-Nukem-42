/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:39:11 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 18:11:34 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

static void			ft_setup_level_helper_p2(t_env *env, t_elem *floor)
{
	floor->jump = 1;
	floor->walking = 0;
	floor->ticket = 0;
	floor->balloon = 0;
	floor->lollipop = 0;
	floor->negative = 0;
	floor->torchtoogle = 0;
	floor->game_msg = 0;
	floor->drawceiling = 1;
	floor->posx = floor[floor->currentstair].spawn_x;
	floor->posy = floor[floor->currentstair].spawn_y;
	floor->difficulty = 3 - env->story_difficulty;
	floor->fire_stat = 0;
	floor->score = 0;
	floor->pistol_selected = 0;
	floor->shotgun_selected = 0;
	floor->devastator_selected = 0;
	remove_sprites(floor);
	load_map_sprites(env, floor);
	if (floor->swim)
		change_channel_state(env, env->audio.channels[CH_WATER_BREATHING], 2);
}

void				ft_setup_level_helper(t_env *env, t_elem *floor)
{
	pause_soundeffects(floor->audio);
	floor->timechrono = -1;
	floor->arcade_retry = 0;
	floor->gravity = 1;
	floor->autorunmove = 0;
	floor->crouchsensi = 1;
	floor->flysensi = 1;
	floor->life = 100;
	floor->speedragdoll = 0.00;
	floor->prevlife = 100;
	floor->speedweapon = 1;
	floor->speed = 0.001;
	floor->speedshift = 0.5;
	floor->lookupdown = 0;
	floor->printscore = 0;
	ft_setup_level_helper_p2(env, floor);
	if (floor->godmode)
		ft_godmode_toggle_off(floor);
}
