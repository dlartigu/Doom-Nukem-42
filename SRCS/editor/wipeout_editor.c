/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipeout_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:07:11 by niboute           #+#    #+#             */
/*   Updated: 2020/11/08 19:09:31 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	delete_font(TTF_Font *font)
{
	if (font)
		TTF_CloseFont(font);
	font = NULL;
}

void	free_editor_ttf_p2(t_editor *data)
{
	int	i;

	i = 2;
	while (i > 0 && i--)
		if (data->ttf_wall_size[i])
		{
			delete_texture_tab_ttf(data->ttf_wall_size[i], 1);
			ft_memdel((void **)&data->ttf_wall_size[i]);
		}
	delete_texture_tab_ttf(data->ttf_prompt, 1);
	ft_memdel((void **)&data->ttf_prompt);
	delete_texture_tab_ttf(data->ttf_text_input, 1);
	ft_memdel((void **)&data->ttf_text_input);
}

void	free_editor_ttf(t_editor *data)
{
	int i;

	if (data->fonts)
	{
		while (data->nb_fonts > 0 && data->nb_fonts--)
			delete_font(data->fonts[data->nb_fonts]);
		free(data->fonts);
		data->fonts = NULL;
	}
	delete_sdl_text(&data->menu_textures);
	delete_ttf(&data->ttf_wall_size[0]);
	delete_ttf(&data->ttf_wall_size[1]);
	delete_ttf(&data->ttf_wave);
	delete_ttf(&data->ttf_prompt);
	i = 10;
	while (i > 0 && i--)
	{
		if (data->ttf_digits[i])
		{
			delete_texture_tab_ttf(data->ttf_digits[i], 1);
			ft_memdel((void **)&data->ttf_digits[i]);
		}
	}
}

void	free_editor_presets(t_editor *data)
{
	t_preset	*tmp;

	if (!data->preset_list)
		return ;
	while (data->preset_list)
	{
		delete_texture_tab_ttf(data->preset_list->ttf_texture, 1);
		tmp = data->preset_list->next;
		ft_memdel((void **)&data->preset_list);
		data->preset_list = tmp;
	}
	data->nb_presets = 0;
}

void	free_editor_premenu(t_editor *data)
{
	delete_texture_tab(data->premenu_textures.skybox, 3);
	delete_texture_tab(&data->premenu_textures.icon, 1);
	delete_texture_tab_ttf(data->premenu_textures.size, 1);
	ft_memdel((void**)&data->premenu_textures.size);
	delete_texture_tab_ttf(data->premenu_textures.grav, 1);
	ft_memdel((void**)&data->premenu_textures.grav);
}
