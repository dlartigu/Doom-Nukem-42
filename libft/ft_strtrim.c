/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:27:06 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/19 15:00:28 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_blank_before(const char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	ft_blank_after(const char *s)
{
	int i;
	int len;

	i = ft_strlen(s) - 1;
	len = i;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (len - i);
}

static int	ft_full_blank(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != ' ') && (s[i] != '\n') && (s[i] != '\t'))
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	size_t	len_t;
	int		start;
	int		end;
	char	*s2;

	s2 = NULL;
	if (!s)
		return (NULL);
	if (ft_full_blank(s) == 1)
		return (s2 = ft_strnew(0));
	len = ft_strlen(s);
	start = ft_blank_before(s);
	end = ft_blank_after(s);
	len_t = len - start - end;
	s2 = ft_strnew(len_t);
	s2 = ft_strsub(s, start, len_t);
	return (s2);
}
