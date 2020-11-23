/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rect_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:29:23 by dlartigu          #+#    #+#             */
/*   Updated: 2020/10/06 15:39:34 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int		rsx(t_env *env, double x)
{
	int		res;

	if (x < 0)
	{
		x = -x;
		x = env->res_width / x / 2;
		return (res = (int)x);
	}
	else
		x = env->res_width - (env->res_width / x);
	return (res = (int)x);
}

int		rsy(t_env *env, double y)
{
	int		res;

	if (y < 0)
	{
		y = -y;
		y = env->res_width / y / 2;
		return (res = (int)y);
	}
	else
		y = env->res_hight - (env->res_hight / y);
	return (res = (int)y);
}

int		rsw(t_env *env, double w)
{
	int		res;

	w = env->res_width / w;
	return (res = (int)w);
}

int		rsh(t_env *env, double h)
{
	int		res;

	h = env->res_width / h;
	return (res = (int)h);
}
