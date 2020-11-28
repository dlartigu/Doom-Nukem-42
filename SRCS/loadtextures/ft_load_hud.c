/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:00:04 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/25 18:10:05 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_load_hud_textures_p2(t_env *env, t_elem *floor)
{
	if (!env->hud.tex_pistol_off)
		env->hud.tex_pistol_off = load_bmp_to_texture(env->ren, PISTOL_OFF);
	if (!env->hud.tex_shotgun_on)
		env->hud.tex_shotgun_on = load_bmp_to_texture(env->ren, SHOTGUN_ON);
	if (!env->hud.tex_shotgun_off)
		env->hud.tex_shotgun_off = load_bmp_to_texture(env->ren, SHOTGUN_OFF);
	if (!env->hud.tex_devast_on)
		env->hud.tex_devast_on = load_bmp_to_texture(env->ren, LEGEND_ON);
	if (!env->hud.tex_devast_off)
		env->hud.tex_devast_off = load_bmp_to_texture(env->ren, LEGEND_OFF);
	if (!env->hud.tex_no_ammo)
		env->hud.tex_no_ammo = load_ttf_to_texture(env->ren, "00",
			floor->fpsfont, floor->fpscolor);
	if (!env->hud.tex_ammo)
		env->hud.tex_ammo = load_ttf_to_texture(env->ren, "00",
		floor->fpsfont, floor->fpscolor);
	if (!env->hud.tex_split_ammo)
		env->hud.tex_split_ammo = load_ttf_to_texture(env->ren, "/",
		floor->fpsfont, floor->fpscolor);
	if (!env->hud.tex_skull)
		env->hud.tex_skull = load_bmp_to_texture(env->ren, SKULL);
}

void			ft_load_hud_textures(t_env *env, t_elem *floor)
{
	if (!env->hud.tex_ticket_on)
		env->hud.tex_ticket_on = load_bmp_to_texture(env->ren, TICKET_ON);
	if (!env->hud.tex_ticket_off)
		env->hud.tex_ticket_off = load_bmp_to_texture(env->ren, TICKET_OFF);
	if (!env->hud.tex_balloon_on)
		env->hud.tex_balloon_on = load_bmp_to_texture(env->ren, BALLON_ON);
	if (!env->hud.tex_balloon_off)
		env->hud.tex_balloon_off = load_bmp_to_texture(env->ren, BALLON_OFF);
	if (!env->hud.tex_candy_on)
		env->hud.tex_candy_on = load_bmp_to_texture(env->ren, LOLLIPOP_ON);
	if (!env->hud.tex_candy_off)
		env->hud.tex_candy_off = load_bmp_to_texture(env->ren, LOLLIPOP_OFF);
	if (!env->hud.tex_fire_on)
		env->hud.tex_fire_on = load_bmp_to_texture(env->ren, FIRE_ON);
	if (!env->hud.tex_fire_off)
		env->hud.tex_fire_off = load_bmp_to_texture(env->ren, FIRE_OFF);
	if (!env->hud.tex_pistol_on)
		env->hud.tex_pistol_on = load_bmp_to_texture(env->ren, PISTOL_ON);
	ft_load_hud_textures_p2(env, floor);
}

void			ft_load_intro_textures(t_env *env)
{
	if (env->text_intro)
		ft_free_texture_tab(&env->text_intro);
	if (!(env->text_intro = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture*)
	* 10)))
		ft_fct_error("malloc failed");
	env->text_intro[0] = load_bmp_to_texture(env->ren, STORY_LVL1_1);
	env->text_intro[1] = load_bmp_to_texture(env->ren, STORY_LVL1_2);
	env->text_intro[2] = load_bmp_to_texture(env->ren, STORY_LVL1_3);
	env->text_intro[3] = load_bmp_to_texture(env->ren, STORY_LVL1_4);
	env->text_intro[4] = load_bmp_to_texture(env->ren, STORY_LVL1_5);
	env->text_intro[5] = load_bmp_to_texture(env->ren, STORY_LVL1_6);
	env->text_intro[6] = load_bmp_to_texture(env->ren, STORY_LVL2);
	env->text_intro[7] = load_bmp_to_texture(env->ren, STORY_LVL3);
	env->text_intro[8] = load_bmp_to_texture(env->ren, CREDITS);
}
