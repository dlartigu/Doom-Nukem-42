/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapons_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:38:37 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/19 15:58:17 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void			ft_load_fist_textures(t_env *env)
{
	if (env->hud.fist_text)
		ft_free_texture_tab(&env->hud.fist_text);
	if (!(env->hud.fist_text = (SDL_Texture**)ft_memalloc(
	sizeof(SDL_Texture*) * 10)))
		ft_fct_error("malloc failed");
	env->hud.fist_text[0] = load_bmp_to_texture(env->ren, FIST_1);
	env->hud.fist_text[1] = load_bmp_to_texture(env->ren, LEFT_PUNCH_S1);
	env->hud.fist_text[2] = load_bmp_to_texture(env->ren, LEFT_PUNCH_S2);
	env->hud.fist_text[3] = load_bmp_to_texture(env->ren, LEFT_PUNCH_S3);
	env->hud.fist_text[4] = load_bmp_to_texture(env->ren, RIGHT_PUNCH_S1);
	env->hud.fist_text[5] = load_bmp_to_texture(env->ren, RIGHT_PUNCH_S2);
	env->hud.fist_text[6] = load_bmp_to_texture(env->ren, RIGHT_PUNCH_S3);
	env->hud.fist_text[7] = load_bmp_to_texture(env->ren, KICK_STAT1);
	env->hud.fist_text[8] = load_bmp_to_texture(env->ren, KICK_STAT2);
}

static void			ft_load_pistol_textures_p2(t_env *env)
{
	env->hud.pistol_text[10] = load_bmp_to_texture(env->ren, PISTOL_RL_S5);
	env->hud.pistol_text[11] = load_bmp_to_texture(env->ren, PISTOL_RL_S6);
	env->hud.pistol_text[12] = load_bmp_to_texture(env->ren, PISTOL_RL_S7);
	env->hud.pistol_text[13] = load_bmp_to_texture(env->ren, PISTOL_RL_S8);
	env->hud.pistol_text[14] = load_bmp_to_texture(env->ren, PISTOL_RL_S9);
	env->hud.pistol_text[15] = load_bmp_to_texture(env->ren, PISTOL_RL_S10);
	env->hud.pistol_text[16] = load_bmp_to_texture(env->ren, PISTOL_RL_S11);
	env->hud.pistol_text[17] = load_bmp_to_texture(env->ren, PISTOL_RL_S12);
}

static void			ft_load_pistol_textures(t_env *env)
{
	if (env->hud.pistol_text)
		ft_free_texture_tab(&env->hud.pistol_text);
	if (!(env->hud.pistol_text = (SDL_Texture**)ft_memalloc(
	sizeof(SDL_Texture*) * 19)))
		ft_fct_error("malloc failed");
	env->hud.pistol_text[0] = load_bmp_to_texture(env->ren, PISTOL_1);
	env->hud.pistol_text[1] = load_bmp_to_texture(env->ren, PISTOL_F_S1);
	env->hud.pistol_text[2] = load_bmp_to_texture(env->ren, PISTOL_F_S2);
	env->hud.pistol_text[3] = load_bmp_to_texture(env->ren, PISTOL_F_S3);
	env->hud.pistol_text[4] = load_bmp_to_texture(env->ren, PISTOL_F_S4);
	env->hud.pistol_text[5] = load_bmp_to_texture(env->ren, PISTOL_F_S5);
	env->hud.pistol_text[6] = load_bmp_to_texture(env->ren, PISTOL_RL_S1);
	env->hud.pistol_text[7] = load_bmp_to_texture(env->ren, PISTOL_RL_S2);
	env->hud.pistol_text[8] = load_bmp_to_texture(env->ren, PISTOL_RL_S3);
	env->hud.pistol_text[9] = load_bmp_to_texture(env->ren, PISTOL_RL_S4);
	ft_load_pistol_textures_p2(env);
}

static void			ft_load_dev_textures(t_env *env)
{
	if (env->hud.dev_text)
		ft_free_texture_tab(&env->hud.dev_text);
	if (!(env->hud.dev_text = (SDL_Texture**)ft_memalloc(
	sizeof(SDL_Texture*) * 19)))
		ft_fct_error("malloc failed");
	env->hud.dev_text[0] = load_bmp_to_texture(env->ren, DEV_1);
	env->hud.dev_text[1] = load_bmp_to_texture(env->ren, DEV_RELOAD1);
	env->hud.dev_text[2] = load_bmp_to_texture(env->ren, DEV_SHOT1);
	env->hud.dev_text[3] = load_bmp_to_texture(env->ren, DEV_1);
	env->hud.dev_text[4] = load_bmp_to_texture(env->ren, DEV_RELOAD1);
	env->hud.dev_text[5] = load_bmp_to_texture(env->ren, DEV_SHOT1);
	env->hud.dev_text[6] = load_bmp_to_texture(env->ren, DEV_SHOT2);
	env->hud.dev_text[7] = load_bmp_to_texture(env->ren, DEV_SHOT3);
	env->hud.dev_text[8] = load_bmp_to_texture(env->ren, DEV_SHOT4);
	env->hud.dev_text[9] = load_bmp_to_texture(env->ren, DEV_SHOT5);
	env->hud.dev_text[10] = load_bmp_to_texture(env->ren, DEV_SHOT6);
	env->hud.dev_text[11] = load_bmp_to_texture(env->ren, DEV_RELOAD1);
	env->hud.dev_text[12] = load_bmp_to_texture(env->ren, DEV_RELOAD2);
	env->hud.dev_text[13] = load_bmp_to_texture(env->ren, DEV_FIRE_STAT1);
	env->hud.dev_text[14] = load_bmp_to_texture(env->ren, DEV_FIRE_STAT2);
	env->hud.dev_text[15] = load_bmp_to_texture(env->ren, DEV_FIRE_STAT3);
	env->hud.dev_text[16] = load_bmp_to_texture(env->ren, DEV_FIRE_STAT4);
	env->hud.dev_text[17] = load_bmp_to_texture(env->ren, DEV_FIRE_STAT5);
}

void				ft_load_weapons_textures(t_env *env)
{
	ft_load_dev_textures(env);
	ft_load_pistol_textures(env);
	ft_load_shotgun_textures(env);
	ft_load_fist_textures(env);
}
