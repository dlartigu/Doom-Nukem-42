/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_items_hud_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:28:44 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/05 15:29:28 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDES/prog.h"

void			ft_items_hud(t_elem *floor)
{
	ft_ticket(floor);
	ft_lollipop(floor);
	ft_balloon(floor);
}
