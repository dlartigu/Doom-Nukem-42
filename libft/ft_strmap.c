/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:56:53 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/18 16:22:50 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		res[i] = f(cp[i]);
		++i;
	}
	return (res);
}
