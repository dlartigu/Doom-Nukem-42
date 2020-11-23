/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:15:01 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/28 11:22:23 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	long	*lptr;

	lptr = (long*)s;
	while (n >= sizeof(long))
	{
		*(lptr++) = 0;
		n -= sizeof(long);
	}
	ptr = (char*)lptr;
	while (n)
	{
		*(ptr++) = 0;
		n--;
	}
}
