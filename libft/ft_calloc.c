/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:27:43 by marvin            #+#    #+#             */
/*   Updated: 2020/06/23 21:35:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_calloc(size_t type_size, size_t num)
{
	void	*ptr;

	if (!type_size || !num)
		return (NULL);
	ptr = malloc(type_size * num);
	if (ptr)
		ft_bzero(ptr, type_size * num);
	return (ptr);
}
