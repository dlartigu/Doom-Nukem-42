/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:59:37 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/19 11:23:49 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	ldst;
	size_t	lsrc;

	len = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size < ldst)
		return (size + lsrc);
	while ((ldst + len) < (size - 1) && src[len] != '\0')
	{
		dst[ldst + len] = src[len];
		len++;
	}
	dst[ldst + len] = '\0';
	return (ldst + lsrc);
}
