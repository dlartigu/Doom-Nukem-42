/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:04:16 by niboute           #+#    #+#             */
/*   Updated: 2020/11/06 17:24:18 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

void	draw_wave_button(t_editor *data, t_block *block_target)
{
	t_ttf_text	*ttf_target;
	SDL_Rect	pos;

	ttf_target = data->ttf_wave;
	pos = ttf_target->textbox;
	if (data->current_menu == WAVE_MENU)
		pos.y = data->menus[data->current_menu].ttf[1]->textbox.y;
	SDL_RenderCopy(data->win.renderer, ttf_target->texture, NULL,
	&pos);
	ttf_target = data->ttf_digits[block_target->wave];
	pos = ttf_target->textbox;
	if (data->current_menu == WAVE_MENU)
		pos.y = data->menus[data->current_menu].ttf[1]->textbox.y;
	SDL_RenderCopy(data->win.renderer, ttf_target->texture, NULL,
	&pos);
}

void	draw_block_height_button(t_editor *data, t_block *block_target)
{
	t_ttf_text	*ttf_target;
	SDL_Rect	pos;

	ttf_target = data->ttf_wall_size[block_target->height == 0 ? 0 : 1];
	pos = ttf_target->textbox;
	if (data->current_menu == WALL_FEATURE_MENU)
		pos.y = data->menus[data->current_menu].ttf[1]->textbox.y;
	SDL_RenderCopy(data->win.renderer, ttf_target->texture, NULL,
	&pos);
	ttf_target = data->ttf_digits[block_target->height];
	pos = ttf_target->textbox;
	if (data->current_menu == WALL_FEATURE_MENU)
		pos.y = data->menus[data->current_menu].ttf[1]->textbox.y;
	SDL_RenderCopy(data->win.renderer, ttf_target->texture, NULL,
	&pos);
}

void	draw_menu_specific_data(t_editor *data)
{
	t_block		*block_target;

	block_target = data->target.block ? data->target.block
	: &data->current_block;
	if (data->current_menu == PRESET_MENU)
		render_presets(data, &data->menus[data->current_menu]);
	else if (data->current_menu == BLOCK_WALL_MENU
		|| data->current_menu == WALL_FEATURE_MENU)
		draw_block_height_button(data, block_target);
	else if (data->current_menu == WAVE_MENU)
		draw_wave_button(data, block_target);
	else if (data->current_menu >= WALL_TEXTURE_MENU
	&& data->current_menu <= ITEM_TEXTURE_MENU)
		draw_texture_menu(data);
}

void	render_presets_p2(t_editor *data, t_menu *menu, int i, t_preset *ptr)
{
	SDL_Rect	rect;
	int			j;

	rect.x = data->win.menu_res.x;
	rect.w = data->win.menu_res.w;
	rect.y = menu->buttons_pos[2].y + menu->buttons_pos[2].h;
	rect.h = (data->win.win_res.h - rect.y - menu->buttons_pos[3].h) / 8;
	j = -1;
	while (ptr && i < data->nb_presets && ++j < 8)
	{
		SDL_RenderCopy(data->win.renderer,
		data->button_skins[(data->selected_preset == i + data->scroll
		? BUTTON_SELECT_YES : BUTTON_SELECT_NO)].texture, NULL, &rect);
		if (ptr->ttf_texture && ptr->ttf_texture->texture)
			center_rect_middle(&ptr->ttf_texture->textbox, &rect, 1, 1);
		if (ptr->ttf_texture && ptr->ttf_texture->texture)
			SDL_RenderCopy(data->win.renderer, ptr->ttf_texture->texture, NULL,
							&ptr->ttf_texture->textbox);
		ptr->rect = rect;
		rect.y += rect.h;
		ptr = ptr->next;
		i++;
	}
}

void	render_presets(t_editor *data, t_menu *menu)
{
	int			i;
	t_preset	*ptr;

	i = 0;
	ptr = data->preset_list;
	while (ptr && ptr->next && i < data->scroll)
	{
		ptr = ptr->next;
		i++;
	}
	render_presets_p2(data, menu, i, ptr);
}
