/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:38:03 by niboute           #+#    #+#             */
/*   Updated: 2020/11/18 22:21:05 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_range(double val, double min, double max)
{
	if (val < min)
		val = min;
	else if (val > max)
		val = max;
	return (val);
}
