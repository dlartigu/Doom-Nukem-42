/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:49:40 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 07:42:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	n;

	n = ft_strlen(s1);
	if (!(dup = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	return (ft_strcpy(dup, s1));
}
