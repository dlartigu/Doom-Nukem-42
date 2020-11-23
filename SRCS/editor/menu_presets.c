/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_presets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:06:47 by niboute           #+#    #+#             */
/*   Updated: 2020/08/20 14:00:48 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

t_block			*preset_select(t_editor *data)
{
	int			i;
	t_preset	*curr;

	i = 0;
	curr = data->preset_list;
	while (curr && i != data->selected_preset && i < data->nb_presets)
	{
		curr = curr->next;
		i++;
	}
	if (curr)
		return (&curr->block);
	return (NULL);
}

void			delete_preset(t_preset *preset)
{
	if (!preset)
		return ;
	if (preset->ttf_texture)
	{
		if (preset->ttf_texture->texture)
			SDL_DestroyTexture(preset->ttf_texture->texture);
		preset->ttf_texture->texture = NULL;
		ft_memdel((void**)&preset->ttf_texture);
	}
	free(preset);
}

int				delete_current_preset(t_editor *data)
{
	t_preset	*ptr;
	t_preset	*tmp;
	int			i;

	if (!data->nb_presets || !data->preset_list)
		return (0);
	if (data->selected_preset == 0)
	{
		ptr = data->preset_list->next;
		delete_preset(data->preset_list);
		data->preset_list = ptr;
		return (1);
	}
	i = 0;
	ptr = data->preset_list;
	while (ptr->next && i + 1 < data->selected_preset)
	{
		ptr = ptr->next;
		i++;
	}
	tmp = ptr->next;
	ptr->next = !tmp ? NULL : tmp->next;
	delete_preset(tmp);
	return (1);
}

void			change_selected_preset(t_editor *data,
				SDL_MouseButtonEvent *event)
{
	int			i;
	t_preset	*ptr;

	i = 0;
	ptr = data->preset_list;
	while (i < data->scroll && ptr && ptr->next)
	{
		ptr = ptr->next;
		i++;
	}
	while (i - data->scroll < 8 && data->scroll < data->nb_presets && ptr)
	{
		if (ptr->rect.x <= event->x && ptr->rect.x + ptr->rect.w > event->x
			&& ptr->rect.y <= event->y
			&& ptr->rect.y + ptr->rect.h > event->y)
		{
			data->selected_preset = i + data->scroll;
			data->changed = 1;
		}
		ptr = ptr->next;
		i++;
	}
}

int				preset_menu_event(t_editor *data, SDL_MouseButtonEvent *event,
				int button)
{
	if (button == 0)
		change_menu(data, FEATURE_MENU, data->current_menu);
	else if (button == 1)
	{
		change_menu(data, data->current_block.type + BLOCK_EMPTY_MENU,
			data->current_menu);
	}
	else if (button == 2)
	{
		if (delete_current_preset(data))
		{
			data->selected_preset = 0;
			data->nb_presets--;
		}
	}
	else if (button == 3)
		change_menu(data, VALIDATE_MENU, data->current_menu);
	else if (button == -1)
		change_selected_preset(data, event);
	return (1);
}
