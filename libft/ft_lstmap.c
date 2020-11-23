/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:54:43 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/23 17:35:06 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_list;

	if (!lst || !f)
		return (NULL);
	if (!(n_list = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	n_list->next = ft_lstmap(lst->next, f);
	return (n_list);
}
