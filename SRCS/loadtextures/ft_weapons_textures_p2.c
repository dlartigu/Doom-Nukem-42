/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons_textures_p2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:37:12 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/18 17:47:44 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_load_shotgun_textures_p3(t_env *env)
{
	env->hud.shotgun_text[17] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S10);
	env->hud.shotgun_text[18] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S11);
	env->hud.shotgun_text[19] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S12);
	env->hud.shotgun_text[20] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S13);
	env->hud.shotgun_text[21] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S14);
	env->hud.shotgun_text[22] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S15);
	env->hud.shotgun_text[23] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S16);
	env->hud.shotgun_text[24] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S17);
}

static void		ft_load_shotgun_textures_p2(t_env *env)
{
	env->hud.shotgun_text[8] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S1);
	env->hud.shotgun_text[9] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S2);
	env->hud.shotgun_text[10] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S3);
	env->hud.shotgun_text[11] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S4);
	env->hud.shotgun_text[12] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S5);
	env->hud.shotgun_text[13] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S6);
	env->hud.shotgun_text[14] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S7);
	env->hud.shotgun_text[15] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S8);
	env->hud.shotgun_text[16] = load_bmp_to_texture(env->ren, SHOTGUN_RL_S9);
	ft_load_shotgun_textures_p3(env);
}

void			ft_load_shotgun_textures(t_env *env)
{
	if (env->hud.shotgun_text)
		ft_free_texture_tab(&env->hud.shotgun_text);
	if (!(env->hud.shotgun_text = (SDL_Texture**)ft_memalloc(
	sizeof(SDL_Texture*) * 26)))
		ft_fct_error("malloc failed");
	env->hud.shotgun_text[0] = load_bmp_to_texture(env->ren, SHOTGUN_1);
	env->hud.shotgun_text[1] = load_bmp_to_texture(env->ren, SHOTGUN_F_S1);
	env->hud.shotgun_text[2] = load_bmp_to_texture(env->ren, SHOTGUN_F_S2);
	env->hud.shotgun_text[3] = load_bmp_to_texture(env->ren, SHOTGUN_L_S1);
	env->hud.shotgun_text[4] = load_bmp_to_texture(env->ren, SHOTGUN_L_S2);
	env->hud.shotgun_text[5] = load_bmp_to_texture(env->ren, SHOTGUN_L_S3);
	env->hud.shotgun_text[6] = load_bmp_to_texture(env->ren, SHOTGUN_L_S4);
	env->hud.shotgun_text[7] = load_bmp_to_texture(env->ren, SHOTGUN_L_S5);
	ft_load_shotgun_textures_p2(env);
}
