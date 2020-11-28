/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:33:01 by niboute           #+#    #+#             */
/*   Updated: 2020/11/25 17:35:25 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t		mix_argb(uint32_t colora, uint32_t colorb)
{
	uint8_t		alpha;
	double		perc;

	perc = ft_dmap((colora & 0xFF), 0xFF, 0, 100);
	alpha = (colora & 0xFF) + ((colorb & 0xFF)
		* (0xFF - (colora & 0xFF))) / 0xFF;
	return (color_grad(colorb >> 8, colora >> 8, (int)perc) + alpha);
}

static void		calc_sprite_p4(t_env *env, t_elem *floor, t_spritecast *spr)
{
	if (spr->dstx < 0)
		spr->dstx = 0;
	spr->dendx = spr->wid / 2 + spr->winx;
	if (spr->dendx >= env->res_width)
		spr->dendx = env->res_width - 1;
	if (floor->fog == 1)
	{
		if (spr->sprite->dist > (double)3)
			spr->fog_perc = 100;
		else
			spr->fog_perc = ft_dmap(spr->sprite->dist, (double)3, 0, 100);
	}
	else
	{
		if (spr->sprite->dist > (double)6)
			spr->fog_perc = 100;
		else
			spr->fog_perc = ft_dmap(spr->sprite->dist, (double)6, 0, 100);
	}
}

static void		calc_sprite_p3(t_env *env, t_elem *floor, t_spritecast *spr)
{
	spr->vmove = ft_dmap((spr->data->grounded
		* (floor->sprites[spr->texnum]->h
			* ((double)floor->sprites[spr->texnum]->h / 128.0f)))
				/ spr->transformy, 450, 0, env->res_hight)
					+ floor->deltafix + spr->sprite->posz;
	spr->hei = fabs(env->res_hight / spr->transformy) * spr->data->hscale
		* ((double)floor->sprites[spr->texnum]->h / 128.0f);
	spr->dsty = (-spr->hei / 2) + env->res_hight / 2
		+ spr->vmove;
	if (spr->dsty < floor->lookupdown)
		spr->dsty = floor->lookupdown;
	spr->dendy = (spr->hei / 2) + env->res_hight / 2
		+ spr->vmove;
	if (spr->dendy >= env->res_hight + floor->lookupdown)
		spr->dendy = env->res_hight + floor->lookupdown - 1;
	spr->wid = fabs(env->res_hight / spr->transformy) * spr->data->wscale
		* (floor->sprites[spr->texnum]->w / 128.0f);
	spr->dstx = -spr->wid / 2 + spr->winx;
	calc_sprite_p4(env, floor, spr);
}

static void		calc_sprite_p2(t_env *env, t_elem *floor, t_spritecast *spr)
{
	spr->texnum = spr->data->texid[spr->dir][spr->animation];
	spr->spritex = spr->sprite->posx - floor->posx;
	spr->spritey = spr->sprite->posy - floor->posy;
	spr->planex = cos(floor->angle - 1.5708);
	spr->planey = sin(floor->angle - 1.5708);
	spr->invdet = 1.0 / (spr->planex * sin(floor->angle) - cos(floor->angle)
		* spr->planey);
	spr->transformx = spr->invdet * (sin(floor->angle) * spr->spritex
		- cos(floor->angle) * spr->spritey);
	spr->transformy = spr->invdet * (-spr->planey * spr->spritex + spr->planex
		* spr->spritey);
	spr->winx = ((env->res_width / 2) * (1 + spr->transformx
		/ spr->transformy));
	floor->deltafix = (env->res_hight / (8 * floor->crouchsensi)
		- env->res_hight / (8 * floor->flysensi));
	calc_sprite_p3(env, floor, spr);
}

void			calc_sprite(t_env *env, t_elem *floor, t_spritecast *spr)
{
	spr->angle = floor->angle;
	spr->angle = atan2(floor->posy - spr->sprite->posy, floor->posx
		- spr->sprite->posx);
	spr->objdir = (((int)(((atan2(spr->sprite->diry, spr->sprite->dirx) + M_PI)
		/ (M_PI * 2)) * spr->data->max_dir + spr->data->max_dir)
		% spr->data->max_dir));
	if (spr->sprite->type == DEVASTATOR_PROJECTILE)
		spr->objdir++;
	spr->dir = (int)(((int)((spr->angle * 180) / M_PI) + 360
		+ (spr->sprite->type < ENEMY_1) * 225) % 360) / (360
		/ spr->data->max_dir);
	spr->dir = (spr->dir - spr->objdir + spr->data->max_dir / 2)
		% spr->data->max_dir;
	if (spr->dir < 0)
		spr->dir += spr->data->max_dir;
	spr->animation = spr->sprite->animation % spr->data->max_anims;
	if (spr->sprite->type == TORCH && spr->sprite->state == 1)
		spr->animation = (spr->sprite->animation + 1)
		% (spr->data->max_anims - 1) + 1;
	calc_sprite_p2(env, floor, spr);
}
