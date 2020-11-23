/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:37:30 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/22 15:54:15 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_freetab(char ***tab)
{
	int		i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		ft_memdel((void **)&((*tab)[i]));
		i++;
	}
	ft_memdel((void **)tab);
}

void		ft_freebigtab(char ****tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		ft_freetab(&(*tab)[i]);
		i++;
	}
	ft_memdel((void **)tab);
}
