/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:52:59 by niboute           #+#    #+#             */
/*   Updated: 2020/11/17 09:49:18 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			get_sprite_color(t_env *env, t_elem *floor, t_spritecast *spr,
				int y)
{
	spr->color = ft_readpixel(spr->surf, spr->texx, spr->texy);
	if ((spr->color & 0xFF) && spr->dstx == env->res_width / 2
	&& y - floor->lookupdown == env->res_hight / 2 && spr->sprite->type
	>= ENEMY_1 && spr->sprite->type < ENEMY_DEAD_1)
		floor->enemy_target = spr->sprite;
	if (spr->sprite->hit)
		spr->color = color_grad(spr->color >> 8, 0xFFFFFF, 30)
		+ (spr->color & 0xFF);
	if (spr->color & 0xFF)
		spr->color = mix_argb(spr->color, ft_readpixel(env->foresurf,
			spr->dstx, y - floor->lookupdown));
}

void			draw_sprite_p2(t_env *env, t_elem *floor, t_spritecast *spr)
{
	int		y;

	y = spr->dsty - 1;
	while (++y < spr->dendy)
	{
		if (y - floor->lookupdown >= 0
			&& y - floor->lookupdown < env->res_hight)
		{
			spr->texy = (((y - spr->vmove) - env->res_hight / 2 + spr->hei
			/ 2) * (spr->surf->h) / spr->hei);
			if (spr->texy >= 0 && spr->texy < spr->surf->h)
			{
				get_sprite_color(env, floor, spr, y);
				if (spr->color & 0xFF)
				{
					spr->color = wall_fog(floor, spr->fog_perc, spr->color);
					env->sprite_zbuffer[(y - floor->lookupdown)
						* (int)env->res_width + spr->dstx] = spr->transformy;
					ft_putpixel(env->foresurf, spr->dstx, y - floor->lookupdown,
					spr->color);
				}
			}
		}
	}
}

void			draw_sprite(t_env *env, t_elem *floor, t_sprite *sprite)
{
	t_spritecast	spr;

	spr.data = &floor->sprites_data[sprite->type];
	spr.sprite = sprite;
	calc_sprite(env, floor, &spr);
	spr.surf = floor->sprites[spr.texnum];
	spr.dstx = spr.dstx;
	while (spr.dstx < spr.dendx)
	{
		spr.texx = (spr.dstx - (-spr.wid / 2 + spr.winx)) * spr.surf->w
		/ spr.wid;
		if (spr.transformy > 0 && spr.transformy < env->zbuffer[spr.dstx]
		&& spr.texx >= 0 && spr.texx < spr.surf->w)
			draw_sprite_p2(env, floor, &spr);
		spr.dstx++;
	}
}

static void		ft_swap(void *var1, void *var2, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	tmp;
	size_t			i;

	i = 0;
	p1 = var1;
	p2 = var2;
	while (i < len)
	{
		tmp = p1[i];
		p1[i] = p2[i];
		p2[i] = tmp;
		i++;
	}
}

void			draw_sprites(t_env *env, t_elem *floor)
{
	int		i;
	int		j;

	store_sprites(env, floor);
	floor->enemy_target = NULL;
	i = 0;
	while (++i < floor->nb_sprites)
	{
		j = i;
		while (j > 0 && env->spritedistance[j - 1] < env->spritedistance[j])
		{
			ft_swap(env->spritedistance + j, env->spritedistance + j - 1,
			sizeof(double));
			ft_swap(env->spriteorder + j, env->spriteorder + j - 1,
			sizeof(t_sprite*));
			j--;
		}
	}
	i = -1;
	while (++i < floor->nb_sprites)
		draw_sprite(env, floor, env->spriteorder[i]);
}
