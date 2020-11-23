/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:41:47 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/17 17:14:46 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	ptr = (char *)haystack;
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (ptr[i] != '\0')
	{
		j = 0;
		k = i;
		while (needle[j] == ptr[k] && needle[j] != '\0')
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
