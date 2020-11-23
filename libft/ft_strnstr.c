/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:24:29 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/15 16:01:52 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	ptr = (char *)haystack;
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (ptr[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (needle[j] == ptr[k] && needle[j] != '\0' && k < len)
		{
			j++;
			k++;
		}
		if (needle[j] == '\0')
			return (ptr + i);
		i++;
	}
	return (NULL);
}
