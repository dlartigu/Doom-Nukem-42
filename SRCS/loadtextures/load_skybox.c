/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:06:32 by niboute           #+#    #+#             */
/*   Updated: 2020/10/17 21:40:51 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static t_skybox		*load_skybox(SDL_Renderer *ren, char *file)
{
	t_skybox	*ptr;

	if (!(ptr = (t_skybox*)ft_memalloc(sizeof(t_skybox))))
		ft_fct_error("malloc");
	if (!(ptr->texture = load_bmp_to_texture(ren, file)))
		ft_fct_error("load_bmp");
	SDL_QueryTexture(ptr->texture, NULL, NULL, &ptr->w, &ptr->h);
	return (ptr);
}

static	void		ft_skylevel1(t_env *env, t_elem *floor)
{
	if (floor->texture_res == 1)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/normal/level1.bmp");
	else if (floor->texture_res == 2)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/high/level1.bmp");
	else if (floor->texture_res == 4)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/epic/level1.bmp");
}

static	void		ft_skylevel3(t_env *env, t_elem *floor)
{
	if (floor->texture_res == 1)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/normal/level3.bmp");
	else if (floor->texture_res == 2)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/high/level3.bmp");
	else if (floor->texture_res == 4)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/epic/level3.bmp");
}

static	void		ft_skyboss(t_env *env, t_elem *floor)
{
	if (floor->texture_res == 1)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/normal/level4.bmp");
	else if (floor->texture_res == 2)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/high/level4.bmp");
	else if (floor->texture_res == 4)
		floor->skyboxes[0] = load_skybox(env->ren,
			"./RSCS/skybox/epic/level4.bmp");
}

void				load_skyboxes(t_env *env, t_elem *floor)
{
	if (floor->skyboxes[0])
	{
		if (floor->skyboxes[0]->texture)
			ft_free_texture(&floor->skyboxes[0]->texture);
		ft_memdel((void**)&floor->skyboxes[0]);
	}
	if ((floor->currentstair == 0 || floor->currentstair == 4)
		|| (floor->currentstair == 7 && floor[7].custom_skybox == 0))
		ft_skylevel1(env, floor);
	if ((floor->currentstair == 2 || floor->currentstair == 6)
		|| (floor->currentstair == 7 && floor[7].custom_skybox == 1))
		ft_skylevel3(env, floor);
	if ((floor->currentstair == 3)
		|| (floor->currentstair == 7 && floor[7].custom_skybox == 2))
		ft_skyboss(env, floor);
	if (floor->skyboxes[0])
	{
		floor->skyboxes[0]->speed = 2;
		floor->skyboxes[0]->h_scale = 1;
	}
}
