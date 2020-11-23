/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:24:46 by ibouabda          #+#    #+#             */
/*   Updated: 2020/08/31 00:09:37 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *m;

	if (*alst == NULL)
		*alst = new;
	else
	{
		m = *alst;
		while (m->next)
			m = m->next;
		m->next = new;
	}
}
