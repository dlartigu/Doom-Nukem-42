/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_hud_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:02:13 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/17 19:54:04 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_free_hud2(t_hud *hud)
{
	if (hud->tex_fire_off)
		ft_free_texture(&hud->tex_fire_off);
	if (hud->tex_pistol_on)
		ft_free_texture(&hud->tex_pistol_on);
	if (hud->tex_pistol_off)
		ft_free_texture(&hud->tex_pistol_off);
	if (hud->tex_shotgun_on)
		ft_free_texture(&hud->tex_shotgun_on);
	if (hud->tex_shotgun_off)
		ft_free_texture(&hud->tex_shotgun_off);
	if (hud->tex_devast_on)
		ft_free_texture(&hud->tex_devast_on);
	if (hud->tex_devast_off)
		ft_free_texture(&hud->tex_devast_off);
	if (hud->tex_ammo)
		ft_free_texture(&hud->tex_ammo);
	if (hud->tex_no_ammo)
		ft_free_texture(&hud->tex_no_ammo);
	if (hud->tex_split_ammo)
		ft_free_texture(&hud->tex_split_ammo);
}

static void		ft_free_hud1(t_hud *hud)
{
	if (hud->tex_skull)
		ft_free_texture(&hud->tex_skull);
	if (hud->tex_life)
		ft_free_texture(&hud->tex_life);
	if (hud->tex_ticket_on)
		ft_free_texture(&hud->tex_ticket_on);
	if (hud->tex_ticket_off)
		ft_free_texture(&hud->tex_ticket_off);
	if (hud->tex_balloon_on)
		ft_free_texture(&hud->tex_balloon_on);
	if (hud->tex_balloon_off)
		ft_free_texture(&hud->tex_balloon_off);
	if (hud->tex_candy_on)
		ft_free_texture(&hud->tex_candy_on);
	if (hud->tex_candy_off)
		ft_free_texture(&hud->tex_candy_off);
	if (hud->tex_fire_on)
		ft_free_texture(&hud->tex_fire_on);
	ft_free_hud2(hud);
}

void			ft_free_hud(t_hud *hud)
{
	if (hud)
		ft_free_hud1(hud);
	if (hud->hg_text)
		ft_free_texture_tab(&hud->hg_text);
	if (hud->dev_text)
		ft_free_texture_tab(&hud->dev_text);
	if (hud->pistol_text)
		ft_free_texture_tab(&hud->pistol_text);
	if (hud->head_guy_timer)
		SDL_RemoveTimer(hud->head_guy_timer);
	if (hud->shotgun_text)
		ft_free_texture_tab(&hud->shotgun_text);
	if (hud->fist_text)
		ft_free_texture_tab(&hud->fist_text);
	if (hud->tex_ammo)
		ft_free_texture(&hud->tex_ammo);
	if (hud->tex_no_ammo)
		ft_free_texture(&hud->tex_no_ammo);
	if (hud->tex_split_ammo)
		ft_free_texture(&hud->tex_split_ammo);
}
