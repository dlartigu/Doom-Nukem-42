/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:08:35 by niboute           #+#    #+#             */
/*   Updated: 2020/09/14 00:18:52 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dmap(double val, double range, double min2, double max2)
{
	if (!range)
		return (0);
	return (((min2 + (max2 - min2)) * val) / range);
}
