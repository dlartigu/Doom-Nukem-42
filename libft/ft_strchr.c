/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:34:39 by thallot           #+#    #+#             */
/*   Updated: 2019/04/03 13:25:49 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	*ptr;
	size_t	len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(str);
	ptr = NULL;
	while (i < len + 1 && ptr == NULL)
	{
		if (str[i] == (char)c)
			ptr = (char *)s + i;
		i++;
	}
	return (ptr);
}
