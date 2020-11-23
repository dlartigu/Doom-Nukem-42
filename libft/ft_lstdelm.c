/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:30:52 by ibouabda          #+#    #+#             */
/*   Updated: 2020/09/03 15:57:19 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

void	ft_lstdelm(t_list **alst)
{
	t_list *m;
	t_list *erase;

	m = *alst;
	while (m != NULL)
	{
		erase = m;
		m = m->next;
		if (erase->content)
			free(erase->content);
		free(erase);
	}
	*alst = NULL;
}
