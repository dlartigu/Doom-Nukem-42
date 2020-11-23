/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:39:37 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/17 16:07:17 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *found;
	char *ptr;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	while ((ptr = ft_strchr(s, c)) != NULL)
	{
		found = ptr;
		s = ptr + 1;
	}
	return ((char *)found);
}
