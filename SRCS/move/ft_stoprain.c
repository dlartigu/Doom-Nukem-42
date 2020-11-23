/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoprain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:43:21 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 13:07:34 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				ft_stoprain(t_env *env, t_elem *floor)
{
	env->test = 0;
	if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][CEILING_TXT] == '0')
		floor->seerain = 1;
	else if (floor[floor->currentstair].new[(int)floor->posy]
			[(int)floor->posx][CEILING_TXT] != '0')
		floor->seerain = 0;
}
