/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:59:49 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 22:15:35 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/editor.h"

int	load_counters_ttf(t_editor *data, TTF_Font *font)
{
	SDL_Color	col;

	ft_memset(&col, 0x00, sizeof(SDL_Color));
	col.r = 255;
	if (!(data->ttf_wall_size[0] = create_str_texture(data->win.renderer,
	BLOCK_HEIGHT_0, col, font)))
		return (ft_printerror("ERROR: create_str_texture"));
	if (!(data->ttf_wall_size[1] = create_str_texture(data->win.renderer,
	BLOCK_HEIGHT_ELSE, col, font)))
		return (ft_printerror("ERROR: create_str_texture"));
	return (load_counters_ttf_p2(data, font));
}

int	load_bmp(SDL_Renderer *renderer, char *name, t_sdl_text *ptr, int isalpha)
{
	SDL_Surface *tmp;

	if (!(tmp = SDL_LoadBMP(name)))
		return (ft_printerror("ERROR: SDL_LoadBMP."));
	ptr->texture = SDL_CreateTextureFromSurface(renderer, tmp);
	if (!isalpha)
		SDL_SetTextureBlendMode(ptr->texture, SDL_BLENDMODE_NONE);
	ptr->rect.w = tmp->w;
	ptr->rect.h = tmp->h;
	ptr->rect.y = 0;
	ptr->rect.x = 0;
	SDL_FreeSurface(tmp);
	if (!ptr->texture)
		return (ft_printerror("ERROR: SDL_CreateTextureFromSurface."));
	return (1);
}

int	load_textures(t_editor *data)
{
	if (!load_floors(data))
		return (ft_printerror("ERROR : couldn't load floor textures."));
	if (!load_roofs(data))
		return (ft_printerror("ERROR : couldn't load roof textures."));
	if (!load_walls(data))
		return (ft_printerror("ERROR : couldn't load wall textures."));
	if (!load_sprites(data))
		return (ft_printerror("ERROR : couldn't load sprite textures."));
	if (!load_items(data))
		return (ft_printerror("ERROR : couldn't load item textures."));
	if (!load_skyboxs(data))
		return (ft_printerror("ERROR : couldn't load skybox textures."));
	if (!load_bmp(data->win.renderer, TEXTURE_FLAG, &data->spawn_texture, 0))
		return (ft_printerror("ERROR : couldn't load spawn texture."));
	return (1);
}

int	init_menu(t_editor *data)
{
	SDL_Color	col;
	int			*ptr;
	int			tmp;

	ft_memset(&col, 0x00, sizeof(SDL_Color));
	col.b = 255;
	if (!(load_menu(data)))
		return (ft_printerror("ERROR: load_menu"));
	if (!(data->ttf_prompt = create_str_texture(data->win.renderer,
		"ENTER PRESET NAME", col, data->fonts[1])))
		return (ft_printerror("ERROR: create_str_texture"));
	if (!(data->white_text.texture = SDL_CreateTexture(data->win.renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 1, 1)))
		return (ft_printerror("ERROR: SDL_CreateTexture"));
	SDL_LockTexture(data->white_text.texture, NULL, (void**)&ptr, &tmp);
	*ptr = 0x00FFFFFF;
	SDL_UnlockTexture(data->white_text.texture);
	center_menu_buttons(data);
	change_options_textures(data, NULL);
	set_optmenu_textures_rects(data);
	return (1);
}

int	init_editor(t_editor *data)
{
	if (!load_bmp(data->win.renderer, TEXTURE_CLOW_ICON,
	&data->premenu_textures.icon, 1))
		return (ft_printerror("ERROR : couldn't load clown texture."));
	data->premenu_textures.icon.rect.w = 20;
	data->premenu_textures.icon.rect.h = 30;
	if (!load_bmp(data->win.renderer, SKYBOX_1,
	&data->premenu_textures.skybox[0], 0))
		return (ft_printerror("ERROR: load_bmp(1)"));
	if (!load_bmp(data->win.renderer, SKYBOX_2,
	&data->premenu_textures.skybox[1], 0))
		return (ft_printerror("ERROR: load_bmp(2)"));
	if (!load_bmp(data->win.renderer, SKYBOX_3,
	&data->premenu_textures.skybox[2], 0))
		return (ft_printerror("ERROR: load_bmp(3)"));
	if (!init_menu(data))
		return (ft_printerror("ERROR: init_menu"));
	return (1);
}
