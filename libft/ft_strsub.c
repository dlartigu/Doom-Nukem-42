/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:58:27 by dlartigu          #+#    #+#             */
/*   Updated: 2019/05/10 12:16:01 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = NULL;
	if (s)
	{
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		str = ft_strncpy(str, s + start, len);
	}
	return (str);
}
