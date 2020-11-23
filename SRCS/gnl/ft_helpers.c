/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:45:49 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/10 03:37:33 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int			ft_ctoi(const char *str)
{
	return (((int)str[0] - '0'));
}

double		ft_floor(double nb)
{
	return (floor((nb)));
}

char		*ftoa(double n, char *res)
{
	int		intpart;

	intpart = (int)n;
	res = ft_itoa(n);
	return (res);
}
