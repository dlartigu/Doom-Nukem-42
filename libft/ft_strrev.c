/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:40:25 by dlartigu          #+#    #+#             */
/*   Updated: 2019/04/18 16:07:44 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int			i;
	int			j;
	char		temp;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	while (i < (j - 1))
	{
		temp = str[i];
		str[i] = str[j - 1];
		str[j - 1] = temp;
		i++;
		j--;
	}
	return (str);
}
