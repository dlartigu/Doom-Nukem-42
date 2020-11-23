/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:35:05 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:10:35 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

static void	save_block_sprite_p2(t_block *block, char *str)
{
	if (block->feature_text <= 13)
	{
		str[2] = '2';
		str[3] = block->feature_text - 5 + '1';
	}
	else
	{
		str[2] = '7';
		str[3] = '0';
	}
}

void		save_block_sprite(t_block *block, char *str)
{
	if (block->feature == 1)
	{
		str[2] = '6';
		str[3] = block->feature_text + '1';
	}
	else if (block->feature == 2)
	{
		if (block->feature_text <= 1)
		{
			str[2] = '1';
			if (block->feature_text == 1)
				str[3] = '1';
			else
				str[3] = '0';
		}
		else if (block->feature_text <= 4)
		{
			str[2] = block->feature_text + '1';
			str[3] = '0';
		}
		else
			save_block_sprite_p2(block, str);
	}
}
