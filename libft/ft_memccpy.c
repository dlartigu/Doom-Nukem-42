/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:25:05 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/17 12:22:36 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (i < n && ptr == NULL)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
			ptr = dst + i + 1;
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (ptr);
}
