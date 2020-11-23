/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:10:40 by dlartigu          #+#    #+#             */
/*   Updated: 2020/09/30 12:41:37 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	uc;
	unsigned long	ul;
	unsigned long	*lptr;

	lptr = (unsigned long*)b;
	uc = (unsigned char)c;
	ul = uc;
	ul = (ul << 56) + (ul << 48) + (ul << 40) + (ul << 32) + (ul << 24)
		+ (ul << 16) + (ul << 8) + ul;
	while (len >= sizeof(long))
	{
		*(lptr++) = ul;
		len -= sizeof(long);
	}
	ptr = (unsigned char*)lptr;
	while (len)
	{
		*(ptr++) = uc;
		len--;
	}
	return (b);
}
