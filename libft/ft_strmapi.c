/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:24:36 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/17 14:26:54 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*cp;
	char		*res;

	i = 0;
	if (!s || !f || !(cp = ft_strdup(s))
		|| !(res = ft_strnew(ft_strlen(cp))))
		return (NULL);
	while (i < ft_strlen(cp))
	{
		res[i] = f(i, cp[i]);
		++i;
	}
	return (res);
}
