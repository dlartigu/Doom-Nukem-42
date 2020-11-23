/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:06:54 by niboute           #+#    #+#             */
/*   Updated: 2020/10/14 18:32:22 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int		add_preset(t_editor *data)
{
	t_preset	*ptr;
	t_preset	*new;
	SDL_Color	col;

	ft_memset(&col, 0x00, sizeof(SDL_Color));
	if (!(new = (t_preset*)ft_calloc(sizeof(t_preset), 1)))
		return (ft_printerror("ERROR: malloc"));
	if (!(new->ttf_texture = create_str_texture(data->win.renderer,
			data->text_input, col, data->fonts[1])))
		return (ft_errordel("ERROR: create_str_texture", (void**)&new));
	new->block = data->target.block
	? *(data->target.block) : data->current_block;
	new->next = NULL;
	ptr = data->preset_list;
	data->nb_presets++;
	if (!ptr)
	{
		data->preset_list = new;
		return (1);
	}
	while (ptr && ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (1);
}

int		reload_ttf_input(t_editor *data)
{
	SDL_Color	col;

	ft_memset(&col, 0x00, sizeof(SDL_Color));
	if (data->ttf_text_input)
	{
		if (data->ttf_text_input->texture)
			SDL_DestroyTexture(data->ttf_text_input->texture);
		data->ttf_text_input->texture = NULL;
		ft_memdel((void**)&data->ttf_text_input);
	}
	if (data->text_input[0])
		if (!(data->ttf_text_input = create_str_texture(data->win.renderer,
				data->text_input, col, data->fonts[1])))
			return (0);
	data->changed = 1;
	return (1);
}

int		stop_prompt(t_editor *data)
{
	SDL_StopTextInput();
	data->waitforinput = 0;
	ft_bzero((char*)data->text_input, 20);
	if (!(reload_ttf_input(data)))
		return (ft_printerror("reload_ttf_input"));
	data->changed = 1;
	return (1);
}

int		prompt_event(t_editor *data, SDL_KeyboardEvent *event)
{
	size_t	len;

	len = ft_strlen((char*)&data->text_input);
	if (event->keysym.sym == SDLK_BACKSPACE)
		data->text_input[len > 0 ? len - 1 : 0] = '\0';
	if (event->keysym.sym == SDLK_BACKSPACE)
		reload_ttf_input(data);
	if (event->keysym.sym == SDLK_RETURN)
	{
		if (!(add_preset(data)))
			return (ft_printerror("ERROR: add_preset"));
		data->selected_preset = data->nb_presets == 0
		? 0 : data->nb_presets - 1;
		if (data->selected_preset > 8)
			data->scroll = data->nb_presets - data->selected_preset > 7
			? data->selected_preset : data->nb_presets - 8;
	}
	if (event->keysym.sym == SDLK_ESCAPE || event->keysym.sym == SDLK_RETURN)
		stop_prompt(data);
	return (1);
}

int		read_input(t_editor *data, SDL_TextInputEvent *event)
{
	size_t		len;

	if (event->type == SDL_TEXTINPUT)
	{
		len = ft_strlen(data->text_input);
		if (len < 20)
			ft_strncat((char*)data->text_input, event->text, 20 - len);
		reload_ttf_input(data);
	}
	return (1);
}
