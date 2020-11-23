/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipeout_editor_p2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 03:28:51 by niboute           #+#    #+#             */
/*   Updated: 2020/10/15 23:52:22 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	del_t_menu(t_editor *data)
{
	int	tmp;

	while (data->nb_menus > 0 && data->nb_menus--)
	{
		ft_tabdel((void ***)&data->menus[data->nb_menus].button_str,
							data->menus[data->nb_menus].nb_buttons);
		tmp = data->menus[data->nb_menus].nb_buttons;
		while (tmp > 0 && tmp--)
		{
			delete_texture_tab_ttf((void *)data->menus[data->
			nb_menus].ttf[tmp], 1);
			ft_memdel((void **)&data->menus[data->nb_menus].ttf[tmp]);
		}
		ft_memdel((void**)&data->menus[data->nb_menus].buttons_pos);
		ft_memdel((void **)&data->menus[data->nb_menus].ttf);
		ft_memdel((void **)&data->menus[data->nb_menus].skin_id);
		ft_memdel((void **)&data->menus[data->nb_menus].button_per_sec);
	}
	ft_memdel((void **)&data->menus);
}

void	free_editor_menu(t_editor *data)
{
	delete_texture_tab((void *)data->button_skins, data->nb_btn_skins);
	ft_memdel((void **)&data->button_skins);
	if (data->menus)
		del_t_menu(data);
	delete_texture_tab((void *)data->menu_textures, data->nb_menu_textures);
	ft_memdel((void **)&data->target.block);
}

void	free_editor_textures(t_editor *data)
{
	delete_texture_tab((void *)data->wall_text, MAX_WALL_TEXTURES);
	delete_texture_tab((void *)data->item_text, MAX_ITEM_TEXTURES);
	delete_texture_tab((void *)data->enemy_text, MAX_ENEMY_TEXTURES);
	delete_texture_tab((void *)data->skybox_textures, MAX_SKYBOX_TEXTURES);
	delete_texture_tab((void *)data->floor_text, MAX_FLOOR_TEXTURES);
	delete_texture_tab((void *)data->roof_text, MAX_ROOF_TEXTURES);
}
