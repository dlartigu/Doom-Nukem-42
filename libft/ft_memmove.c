/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:09 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/03 18:52:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*pdst;
	const char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdst = (char*)dst;
	psrc = (const char*)src;
	i = (dst > src) ? len : 0;
	if (dst > src)
	{
		while (i)
		{
			i--;
			pdst[i] = psrc[i];
		}
	}
	else
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	return (dst);
}
