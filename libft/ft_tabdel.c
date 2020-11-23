/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:30:19 by niboute           #+#    #+#             */
/*   Updated: 2018/12/20 13:56:57 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_tabdel(void ***tab, size_t size)
{
	size_t	i;

	if (!tab)
		return ;
	if (!*tab)
		return ;
	i = 0;
	while (i < size)
	{
		if ((*tab)[i])
			free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}
