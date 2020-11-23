/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:07:00 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:52:14 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"
#include "../../INCLUDES/editor.h"

int			load_floors(t_editor *data)
{
	if (!load_bmp(data->win.renderer, FLO_NORMAL_0, &data->floor_text[0],
	0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, FLO_NORMAL_1, &data->floor_text[1],
	0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, FLO_NORMAL_2, &data->floor_text[2],
	0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, FLO_NORMAL_3, &data->floor_text[3],
	0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, FLO_NORMAL_5, &data->floor_text[4],
	0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, LVL3_NORMAL_5, &data->floor_text[5],
	0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	return (1);
}

int			load_roofs(t_editor *data)
{
	if (!load_bmp(data->win.renderer, CEL_NORMAL_0, &data->roof_text[0], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, CEL_NORMAL_1, &data->roof_text[1], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, LVL3_NORMAL_5, &data->roof_text[2], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	return (1);
}

static int	load_walls_p2(t_editor *data)
{
	if (!load_bmp(data->win.renderer, LVL3_NORMAL_5, &data->wall_text[10], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_10, &data->wall_text[11], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_11, &data->wall_text[12], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_12, &data->wall_text[13], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_13, &data->wall_text[14], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_14, &data->wall_text[15], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_15, &data->wall_text[16], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_16, &data->wall_text[17], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	return (1);
}

int			load_walls(t_editor *data)
{
	if (!load_bmp(data->win.renderer, WAL_NORMAL_0, &data->wall_text[0], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_1, &data->wall_text[1], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_2, &data->wall_text[2], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_3, &data->wall_text[3], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_4, &data->wall_text[4], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_5, &data->wall_text[5], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_6, &data->wall_text[6], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_7, &data->wall_text[7], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_8, &data->wall_text[8], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	if (!load_bmp(data->win.renderer, WAL_NORMAL_9, &data->wall_text[9], 0))
		return (ft_printerror("ERROR: couldn't load bmp."));
	return (load_walls_p2(data));
}

int			load_skyboxs(t_editor *data)
{
	if (!load_bmp(data->win.renderer, SKYBOX_1, &data->skybox_textures[0], 0))
		return (ft_printerror("ERROR: couldn't load bmpA."));
	if (!load_bmp(data->win.renderer, SKYBOX_2, &data->skybox_textures[1], 0))
		return (ft_printerror("ERROR: couldn't load bmpB."));
	if (!load_bmp(data->win.renderer, SKYBOX_3, &data->skybox_textures[2], 0))
		return (ft_printerror("ERROR: couldn't load bmpC."));
	return (1);
}
