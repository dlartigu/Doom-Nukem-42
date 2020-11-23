/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:12:20 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/14 22:55:34 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	free_sprite(t_list *sprite)
{
	if (((t_sprite*)sprite->content)->timer)
		SDL_RemoveTimer(((t_sprite*)sprite->content)->timer);
	if (((t_sprite*)sprite->content)->timer_idle)
		SDL_RemoveTimer(((t_sprite*)sprite->content)->timer_idle);
	free(sprite->content);
	free(sprite);
}

void	ft_lstdelsprite(t_list **alst)
{
	t_list *m;
	t_list *erase;

	m = *alst;
	while (m != NULL)
	{
		erase = m;
		m = m->next;
		free_sprite(erase);
	}
	*alst = NULL;
}

void	remove_item(t_list **list, int x, int y)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!*list)
		return ;
	if (((int)((t_sprite*)(*list)->content)->posx) == x
		&& ((int)((t_sprite*)(*list)->content)->posy) == y)
	{
		ptr = *list;
		*list = ptr->next;
		free_sprite(ptr);
		return ;
	}
	ptr = *list;
	while (ptr->next && (((int)((t_sprite*)ptr->next->content)->posx) != x
		|| ((int)((t_sprite*)ptr->next->content)->posy) != y))
		ptr = ptr->next;
	if (ptr->next)
	{
		tmp = ptr->next;
		ptr->next = tmp->next;
		free_sprite(tmp);
	}
}

void	remove_sprite(t_list **list, t_sprite *sprite)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!*list)
		return ;
	if ((t_sprite*)(*list)->content == sprite)
	{
		ptr = *list;
		*list = ptr->next;
		free_sprite(ptr);
		return ;
	}
	ptr = *list;
	while (ptr->next && (t_sprite*)(ptr->next->content) != sprite)
		ptr = ptr->next;
	if (ptr->next && ptr->next->content == sprite)
	{
		tmp = ptr->next;
		ptr->next = tmp->next;
		free_sprite(tmp);
	}
}

void	remove_sprites(t_elem *floor)
{
	ft_lstdelsprite(&floor->items);
	ft_lstdelsprite(&floor->enemies);
	ft_lstdelsprite(&floor->projectiles);
}
