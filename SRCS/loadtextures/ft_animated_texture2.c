/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animated_texture2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:58:40 by niboute           #+#    #+#             */
/*   Updated: 2020/10/07 14:01:19 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void					ft_lvl3textureepic_p2(t_elem *floor)
{
	floor->animatedwalltext[18] = ft_load_texture(LVL3_EPIC_18);
	floor->animatedwalltext[19] = ft_load_texture(LVL3_EPIC_19);
	floor->animatedwalltext[20] = ft_load_texture(LVL3_EPIC_20);
	floor->animatedwalltext[21] = ft_load_texture(LVL3_EPIC_21);
	floor->animatedwalltext[22] = ft_load_texture(LVL3_EPIC_22);
	floor->animatedwalltext[23] = ft_load_texture(LVL3_EPIC_23);
	floor->animatedwalltext[24] = ft_load_texture(LVL3_EPIC_24);
	floor->animatedwalltext[25] = ft_load_texture(LVL3_EPIC_25);
	floor->animatedwalltext[26] = ft_load_texture(LVL3_EPIC_26);
	floor->animatedwalltext[27] = ft_load_texture(LVL3_EPIC_27);
	floor->animatedwalltext[28] = ft_load_texture(LVL3_EPIC_28);
	floor->animatedwalltext[29] = ft_load_texture(LVL3_EPIC_29);
}

void					ft_lvl3textureepic(t_elem *floor)
{
	floor->animatedwalltext[0] = ft_load_texture(LVL3_EPIC_0);
	floor->animatedwalltext[1] = ft_load_texture(LVL3_EPIC_1);
	floor->animatedwalltext[2] = ft_load_texture(LVL3_EPIC_2);
	floor->animatedwalltext[3] = ft_load_texture(LVL3_EPIC_3);
	floor->animatedwalltext[4] = ft_load_texture(LVL3_EPIC_4);
	floor->animatedwalltext[5] = ft_load_texture(LVL3_EPIC_5);
	floor->animatedwalltext[6] = ft_load_texture(LVL3_EPIC_6);
	floor->animatedwalltext[7] = ft_load_texture(LVL3_EPIC_7);
	floor->animatedwalltext[8] = ft_load_texture(LVL3_EPIC_8);
	floor->animatedwalltext[9] = ft_load_texture(LVL3_EPIC_9);
	floor->animatedwalltext[10] = ft_load_texture(LVL3_EPIC_10);
	floor->animatedwalltext[11] = ft_load_texture(LVL3_EPIC_11);
	floor->animatedwalltext[12] = ft_load_texture(LVL3_EPIC_12);
	floor->animatedwalltext[13] = ft_load_texture(LVL3_EPIC_13);
	floor->animatedwalltext[14] = ft_load_texture(LVL3_EPIC_14);
	floor->animatedwalltext[15] = ft_load_texture(LVL3_EPIC_15);
	floor->animatedwalltext[16] = ft_load_texture(LVL3_EPIC_16);
	floor->animatedwalltext[17] = ft_load_texture(LVL3_EPIC_17);
	ft_lvl3textureepic_p2(floor);
}
