/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:19:39 by idris             #+#    #+#             */
/*   Updated: 2020/11/18 19:02:37 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

uint32_t	ft_create_bubble(uint32_t interval, void *param)
{
	t_elem *floor;

	floor = param;
	if (rand() % 2)
		ft_lstaddend(&(floor->lst), ft_lstnewd(ft_rect((floor->res_width
		/ 5.33) - rand() % (int)(floor->res_width / 6), floor->res_hight,
		0, 0), sizeof(SDL_Rect*)));
	else
		ft_lstaddend(&(floor->lst), ft_lstnewd(ft_rect((floor->res_width
		- floor->res_width / 5.33) + rand() % (int)(floor->res_width / 6),
		floor->res_hight, 0, 0), sizeof(SDL_Rect*)));
	return (interval);
}

int			ft_draw_bubble(t_elem *floor, SDL_Rect *rect)
{
	double h;
	double prop;

	rect->y -= floor->v;
	if (rect->y < 0)
		return (1);
	h = (floor->res_hight - (double)rect->y) / floor->res_hight;
	prop = floor->res_hight / 450.0;
	rect->w = 100.0 * h * prop;
	rect->h = 100.0 * h * prop;
	return (0);
}

void		ft_lstdelcurrent(t_elem *floor, t_list **list)
{
	t_list *ptr;

	ptr = floor->lst;
	while (ptr && ptr->next != *list)
		ptr = ptr->next;
	if (ptr)
	{
		ptr->next = (*list)->next;
		if ((*list)->content)
			ft_memdel(&(*list)->content);
		if (*list)
			ft_memdel((void**)list);
	}
}

uint32_t	ft_bubble_progress(uint32_t interval, void *param)
{
	t_list *ptr;
	t_elem *floor;

	floor = param;
	ptr = floor->lst;
	while (ptr)
	{
		if (ft_draw_bubble(floor, ptr->content) == 1)
			ft_lstdelcurrent(floor, &ptr);
		if (ptr)
			ptr = ptr->next;
	}
	return (interval);
}

void		init_bubble(t_env *env, t_elem *floor)
{
	ft_free_texture_tab(&floor->bubble);
	if (!(floor->bubble = ft_memalloc(sizeof(SDL_Texture*) * 8)))
		ft_fct_error("malloc failed");
	floor->bubble[0] = load_bmp_to_texture(env->ren, BUBBLE_0);
	floor->bubble[1] = load_bmp_to_texture(env->ren, BUBBLE_1);
	floor->bubble[2] = load_bmp_to_texture(env->ren, BUBBLE_2);
	floor->bubble[3] = load_bmp_to_texture(env->ren, BUBBLE_3);
	floor->bubble[4] = load_bmp_to_texture(env->ren, BUBBLE_4);
	floor->bubble[5] = load_bmp_to_texture(env->ren, BUBBLE_5);
	floor->bubble[6] = load_bmp_to_texture(env->ren, BUBBLE_6);
	floor->bubble[7] = NULL;
	floor->res_hight = env->res_hight;
	floor->res_width = env->res_width;
	floor->v = floor->res_hight / 450.0;
	floor->vh = floor->res_width / 800.0;
	if (rand() % 2)
		floor->lst = ft_lstnewd(ft_rect((env->res_width / 5.33)
		- rand() % (int)(env->res_width / 16), env->res_hight,
		0, 0), sizeof(SDL_Rect*));
	else
		floor->lst = ft_lstnewd(ft_rect((env->res_width - env->res_width / 5.33)
		+ rand() % (int)(env->res_width / 16),
		env->res_hight, 0, 0), sizeof(SDL_Rect*));
}
