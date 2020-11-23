/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:06:55 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 18:59:45 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		draw_skybox_p3(t_env *env, t_skybox *skybox,
			int nextwid)
{
	if (nextwid)
	{
		skybox->dst.x = skybox->dst.w;
		skybox->dst.w = env->res_width - skybox->dst.w;
		skybox->src.x = 0;
		skybox->src.w = nextwid;
		SDL_RenderCopy(env->ren, skybox->texture, &skybox->src, &skybox->dst);
	}
}

void		draw_skybox_p2(t_env *env, t_elem *elem, t_skybox *skybox,
			int nextwid)
{
	if (skybox->h_scale <= 1)
	{
		skybox->src.h = ft_dmap(env->res_hight, env->res_hight
		+ elem->lookupcap, 0, skybox->h);
		skybox->src.y = skybox->h - skybox->src.h - ft_dmap(-elem->lookupdown,
		elem->lookupcap, 0, skybox->h - skybox->src.h);
	}
	else
	{
		skybox->src.h = skybox->h;
		skybox->src.y = 0;
	}
	skybox->dst.x = 0;
	skybox->dst.y = env->res_hight - env->res_hight / skybox->h_scale;
	skybox->dst.h = env->res_hight / skybox->h_scale;
	skybox->src.y = 0;
	skybox->src.h = skybox->h;
	skybox->dst.h = env->res_hight / (skybox->speed / 2) + elem->lookupcap;
	skybox->dst.y = -elem->lookupcap - elem->lookupdown;
	skybox->dst.w = ft_dmap(skybox->src.w, skybox->w / skybox->speed,
	0, env->res_width);
	SDL_RenderCopy(env->ren, skybox->texture, &skybox->src, &skybox->dst);
	draw_skybox_p3(env, skybox, nextwid);
}

void		draw_skybox(t_env *env, t_elem *elem, t_skybox *skybox)
{
	double		angle;
	int			nextwid;

	nextwid = 0;
	angle = (elem->angle * 180) / M_PI;
	angle -= 360.0f / (skybox->speed * 2.0f);
	while (angle >= 360.0f)
		angle -= 360.0f;
	while (angle < 0.0f)
		angle += 360.0f;
	angle = 360.0f - angle;
	skybox->src.x = (int)ft_dmap(angle, 360, 0, skybox->w);
	skybox->src.w = (int)ft_dmap(360.0f / skybox->speed, 360, 0, skybox->w);
	if (skybox->src.x + skybox->src.w > skybox->w)
	{
		nextwid = (skybox->src.x + skybox->src.w) % skybox->w;
		skybox->src.w = (skybox->w / skybox->speed) - nextwid;
		skybox->src.x = skybox->w - skybox->src.w;
	}
	draw_skybox_p2(env, elem, skybox, nextwid);
}
