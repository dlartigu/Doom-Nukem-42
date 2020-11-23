/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animated_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:59:06 by niboute           #+#    #+#             */
/*   Updated: 2020/10/07 14:35:40 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void					ft_lvl3texturenormal_p2(t_elem *floor)
{
	floor->animatedwalltext[18] = ft_load_texture(LVL3_NORMAL_18);
	floor->animatedwalltext[19] = ft_load_texture(LVL3_NORMAL_19);
	floor->animatedwalltext[20] = ft_load_texture(LVL3_NORMAL_20);
	floor->animatedwalltext[21] = ft_load_texture(LVL3_NORMAL_21);
	floor->animatedwalltext[22] = ft_load_texture(LVL3_NORMAL_22);
	floor->animatedwalltext[23] = ft_load_texture(LVL3_NORMAL_23);
	floor->animatedwalltext[24] = ft_load_texture(LVL3_NORMAL_24);
	floor->animatedwalltext[25] = ft_load_texture(LVL3_NORMAL_25);
	floor->animatedwalltext[26] = ft_load_texture(LVL3_NORMAL_26);
	floor->animatedwalltext[27] = ft_load_texture(LVL3_NORMAL_27);
	floor->animatedwalltext[28] = ft_load_texture(LVL3_NORMAL_28);
	floor->animatedwalltext[29] = ft_load_texture(LVL3_NORMAL_29);
}

void					ft_lvl3texturenormal(t_elem *floor)
{
	floor->animatedwalltext[0] = ft_load_texture(LVL3_NORMAL_0);
	floor->animatedwalltext[1] = ft_load_texture(LVL3_NORMAL_1);
	floor->animatedwalltext[2] = ft_load_texture(LVL3_NORMAL_2);
	floor->animatedwalltext[3] = ft_load_texture(LVL3_NORMAL_3);
	floor->animatedwalltext[4] = ft_load_texture(LVL3_NORMAL_4);
	floor->animatedwalltext[5] = ft_load_texture(LVL3_NORMAL_5);
	floor->animatedwalltext[6] = ft_load_texture(LVL3_NORMAL_6);
	floor->animatedwalltext[7] = ft_load_texture(LVL3_NORMAL_7);
	floor->animatedwalltext[8] = ft_load_texture(LVL3_NORMAL_8);
	floor->animatedwalltext[9] = ft_load_texture(LVL3_NORMAL_9);
	floor->animatedwalltext[10] = ft_load_texture(LVL3_NORMAL_10);
	floor->animatedwalltext[11] = ft_load_texture(LVL3_NORMAL_11);
	floor->animatedwalltext[12] = ft_load_texture(LVL3_NORMAL_12);
	floor->animatedwalltext[13] = ft_load_texture(LVL3_NORMAL_13);
	floor->animatedwalltext[14] = ft_load_texture(LVL3_NORMAL_14);
	floor->animatedwalltext[15] = ft_load_texture(LVL3_NORMAL_15);
	floor->animatedwalltext[16] = ft_load_texture(LVL3_NORMAL_16);
	floor->animatedwalltext[17] = ft_load_texture(LVL3_NORMAL_17);
	ft_lvl3texturenormal_p2(floor);
}

void					ft_lvl3texturehigh_p2(t_elem *floor)
{
	floor->animatedwalltext[18] = ft_load_texture(LVL3_HIGH_18);
	floor->animatedwalltext[19] = ft_load_texture(LVL3_HIGH_19);
	floor->animatedwalltext[20] = ft_load_texture(LVL3_HIGH_20);
	floor->animatedwalltext[21] = ft_load_texture(LVL3_HIGH_21);
	floor->animatedwalltext[22] = ft_load_texture(LVL3_HIGH_22);
	floor->animatedwalltext[23] = ft_load_texture(LVL3_HIGH_23);
	floor->animatedwalltext[24] = ft_load_texture(LVL3_HIGH_24);
	floor->animatedwalltext[25] = ft_load_texture(LVL3_HIGH_25);
	floor->animatedwalltext[26] = ft_load_texture(LVL3_HIGH_26);
	floor->animatedwalltext[27] = ft_load_texture(LVL3_HIGH_27);
	floor->animatedwalltext[28] = ft_load_texture(LVL3_HIGH_28);
	floor->animatedwalltext[29] = ft_load_texture(LVL3_HIGH_29);
}

void					ft_lvl3texturehigh(t_elem *floor)
{
	floor->animatedwalltext[0] = ft_load_texture(LVL3_HIGH_0);
	floor->animatedwalltext[1] = ft_load_texture(LVL3_HIGH_1);
	floor->animatedwalltext[2] = ft_load_texture(LVL3_HIGH_2);
	floor->animatedwalltext[3] = ft_load_texture(LVL3_HIGH_3);
	floor->animatedwalltext[4] = ft_load_texture(LVL3_HIGH_4);
	floor->animatedwalltext[5] = ft_load_texture(LVL3_HIGH_5);
	floor->animatedwalltext[6] = ft_load_texture(LVL3_HIGH_6);
	floor->animatedwalltext[7] = ft_load_texture(LVL3_HIGH_7);
	floor->animatedwalltext[8] = ft_load_texture(LVL3_HIGH_8);
	floor->animatedwalltext[9] = ft_load_texture(LVL3_HIGH_9);
	floor->animatedwalltext[10] = ft_load_texture(LVL3_HIGH_10);
	floor->animatedwalltext[11] = ft_load_texture(LVL3_HIGH_11);
	floor->animatedwalltext[12] = ft_load_texture(LVL3_HIGH_12);
	floor->animatedwalltext[13] = ft_load_texture(LVL3_HIGH_13);
	floor->animatedwalltext[14] = ft_load_texture(LVL3_HIGH_14);
	floor->animatedwalltext[15] = ft_load_texture(LVL3_HIGH_15);
	floor->animatedwalltext[16] = ft_load_texture(LVL3_HIGH_16);
	floor->animatedwalltext[17] = ft_load_texture(LVL3_HIGH_17);
	ft_lvl3texturehigh_p2(floor);
}
