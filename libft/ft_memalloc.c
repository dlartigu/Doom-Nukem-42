/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:03:11 by dlartigu          #+#    #+#             */
/*   Updated: 2019/06/03 13:14:42 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;

	if (!(ptr = (char *)malloc(sizeof(*ptr) * size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
