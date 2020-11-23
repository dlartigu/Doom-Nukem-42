/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_backup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:23:41 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 16:57:30 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_restore_backup(t_elem *floor)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < floor->max_floor)
	{
		j = 0;
		while (floor[i].new_backup[j])
		{
			k = 0;
			while (floor[i].new_backup[j][k])
			{
				if (ft_strcmp(floor[i].new[j][k],
				floor[i].new_backup[j][k]) != 0)
				{
					ft_bzero(floor[i].new[j][k], 10);
					ft_strcpy(floor[i].new[j][k], floor[i].new_backup[j][k]);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
