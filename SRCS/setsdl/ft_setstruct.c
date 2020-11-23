/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:10:01 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 19:15:32 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		reload_sdlparams_p2(t_sdl *sdl, t_env *env)
{
	if (env->res_op == 0 && env->fs_op == 0)
	{
		sdl->res_width = 800;
		sdl->res_hight = 450;
		env->res_width = 800;
		env->res_hight = 450;
	}
	else
	{
		sdl->res_width = sdl->w_max;
		sdl->res_hight = sdl->h_max;
		env->res_width = sdl->w_max;
		env->res_hight = sdl->h_max;
	}
}

void			reload_sdlparams(t_sdl *sdl, t_env *env)
{
	if (env->fs_op == 0 && env->res_op == 0)
		sdl->windowed = 1;
	else if (env->fs_op == 1)
		sdl->fullscreen = 1;
	else if (env->res_op == 1)
		sdl->fullscreen_maxres = 1;
	sdl->hard_accel = env->gpu_op;
	sdl->vsync = env->vsync_op;
	reload_sdlparams_p2(sdl, env);
}

void			set_events_struct(t_env *env)
{
	env->startmenu = 1;
	env->intro = 1;
	env->sens_value = 1;
	env->music_op = 1;
	env->effect_op = 1;
	env->int_volume_value = 1;
}
