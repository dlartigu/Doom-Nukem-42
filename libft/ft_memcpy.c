/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:26:15 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/03 18:51:54 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	if (!src && !dst)
		return (NULL);
	psrc = (const char*)src;
	pdst = (char*)dst;
	if ((psrc > pdst && psrc - psrc < (long)n)
			|| (pdst > psrc && pdst - psrc < (long)n))
		ft_memmove(dst, src, n);
	while (n)
	{
		*pdst++ = *psrc++;
		n--;
	}
	return (dst);
}
