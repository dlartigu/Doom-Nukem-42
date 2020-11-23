/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:12:49 by niboute           #+#    #+#             */
/*   Updated: 2020/11/14 21:21:37 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "../libft/libft.h"
# include "sdl_inc.h"
# include "../INCLUDES/prog.h"
# include <fcntl.h>
# include <unistd.h>
# define MENU_CONF "./RSCS/editor/menu.conf"
# define BLOCK_SIZE 64
# define MAX_MENU_TEXTURES 14
# define NB_BUTTONS 5
# define NB_MENU_RECTANGLE 9
# define FONT_TITLE 38
# define FONT_CHOICES 28
# define NB_BUTTON_MENU_0 10
# define NB_BUTTON_MENU_1 12
# define NB_BUTTON_MENU_2 12
# define MAX_TEXT_SIZE 30
# define MAX_BUTTONS 20
# define MAX_BUTTONS_LINE 5
# define MAX_BUTTON_SKINS 20
# define NB_MENUS 3
# define DEFAULT_BUTTON_ID 0
# define CHOICE_BUTTON_ID 1
# define BLOCK_HEIGHT_0 "NORMAL +"
# define BLOCK_HEIGHT_ELSE "HIGH +"
# define MAX_RECTS 50
# define MAX_PRESETS 50
# define MAX_PRESET_NAME_SIZE 30
# define MAX_PRESET_NAME_SIZE 30
# define MAX_ENEMY_TEXTURES 5
# define MAX_ITEM_TEXTURES 15
# define MAX_WALL_TEXTURES 18
# define MAX_ROOF_TEXTURES 3
# define MAX_FLOOR_TEXTURES 6
# define MAX_SKYBOX_TEXTURES 3
# define TEXTURE_CLOW_ICON "./RSCS/editor/textures/clownicon_alpha.bmp"
# define TEXTURE_NB_0 "./RSCS/editor/textures/0moche.bmp"
# define TEXTURE_FLAG "./RSCS/editor/textures/signal_flag.bmp"
# define SKYBOX_1 "./RSCS/skybox/normal/level1.bmp"
# define SKYBOX_2 "./RSCS/skybox/normal/level3.bmp"
# define SKYBOX_3 "./RSCS/skybox/normal/level4.bmp"
# define TORCH "/RSCS/texture/torch/front/torche_front_on1.bmp"
# define ENNEMI_1 "RSCS/texture/ennemis/1/front/front1.bmp"
# define ENNEMI_2 "RSCS/texture/ennemis/2/front/0000.bmp"
# define ENNEMI_4 "RSCS/texture/ennemis/4/front/front1.bmp"
# define ENNEMI_5 "RSCS/texture/ennemis/5/front/MOMDA1.bmp"

typedef enum		e_menu_id
{
	OPTIONS_MENU,
	FEATURE_MENU,
	PRESET_MENU,
	BLOCK_EMPTY_MENU,
	BLOCK_WALL_MENU,
	WALL_ERASE_MENU,
	WALL_TEXTURE_MENU,
	FLOOR_TEXTURE_MENU,
	ROOF_TEXTURE_MENU,
	ENEMY_TEXTURE_MENU,
	ITEM_TEXTURE_MENU,
	WALL_FEATURE_MENU,
	WAVE_MENU,
	VALIDATE_MENU
}					t_menu_id;

typedef enum		e_button_skin
{
	BUTTON_CLICK,
	BUTTON_CLICK_GREEN,
	BUTTON_TITLE,
	BUTTON_SELECT_NO,
	BUTTON_SELECT_YES
}					t_button_skin;

typedef enum		e_blocktype
{
	BLOCK_EMPTY,
	BLOCK_WALL
}					t_blocktype;

typedef struct		s_events
{
	unsigned char	shift;
	unsigned char	ctrl;
	int				lb_sx;
	int				lb_sy;
	int				rb_sx;
	int				rb_sy;
	int				mb_sx;
	int				mb_sy;
	unsigned int	scale;
	unsigned int	block_y;
	unsigned int	block_x;
	int				mousex;
	int				mousey;
}					t_events;

typedef struct		s_block
{
	unsigned char	type;
	unsigned char	wall_text;
	unsigned char	feature;
	unsigned char	feature_text;
	unsigned char	height;
	unsigned char	wave;
	unsigned char	skybox;
	unsigned char	roof_text;
	unsigned char	floor_text;
	unsigned char	is_spawn;
}					t_block;

typedef struct		s_sdl_text
{
	SDL_Texture		*texture;
	SDL_Rect		rect;
}					t_sdl_text;

typedef struct		s_ttf_text
{
	SDL_Texture		*texture;
	SDL_Rect		textbox;
}					t_ttf_text;

typedef struct		s_edmap
{
	int				skybox_id;
	int				gravity;
	int				lighting;
	int				shadow;
	int				rain;
	int				fog;
	int				bubbles;
	int				psy;
	int				size;
	t_block			blocks[50][50];
}					t_edmap;

typedef struct		s_sdl_data
{
	char			*desc;
	SDL_Renderer	*renderer;
	SDL_Window		*win;
	t_sdl_text		map_texture;
	SDL_Rect		map_res;
	SDL_Rect		menu_res;
	SDL_Rect		win_res;
	SDL_Rect		zoomed_map;
	t_sdl_text		menu_textures[MAX_MENU_TEXTURES];
}					t_sdl_data;

typedef struct		s_menu
{
	int				texture_id;
	int				texture_blur_id;
	int				nb_buttons;
	char			**button_str;
	SDL_Rect		*buttons_pos;
	t_ttf_text		**ttf;
	int				*skin_id;
	int				*button_per_sec;
	int				nb_menu_sections;
}					t_menu;

typedef struct		s_targetblock
{
	int				y;
	int				x;
	t_block			*block;
}					t_targetblock;

typedef struct		s_preset
{
	t_block			block;
	t_ttf_text		*ttf_texture;
	SDL_Rect		rect;
	struct s_preset	*next;
}					t_preset;

typedef struct		s_premenu_text
{
	int				hover;
	t_sdl_text		skybox[3];
	t_ttf_text		*size;
	t_ttf_text		*grav;
	t_sdl_text		icon;
	SDL_Rect		dest[9];
}					t_premenu_text;

typedef struct		s_editor
{
	int				draw_menu_textures;
	t_sdl_data		win;
	t_sdl_text		wall_text[MAX_WALL_TEXTURES];
	t_sdl_text		item_text[MAX_ITEM_TEXTURES];
	t_sdl_text		enemy_text[MAX_ENEMY_TEXTURES];
	t_sdl_text		skybox_textures[MAX_SKYBOX_TEXTURES];
	t_sdl_text		floor_text[MAX_FLOOR_TEXTURES];
	t_sdl_text		roof_text[MAX_ROOF_TEXTURES];
	SDL_Texture		*cursor[2];
	TTF_Font		**fonts;
	t_ttf_text		*ttf_digits[10];
	t_ttf_text		*ttf_wave;
	t_ttf_text		*ttf_wall_size[2];
	t_ttf_text		*ttf_prompt;
	t_ttf_text		*ttf_text_input;
	t_preset		*preset_list;
	t_sdl_text		spawn_texture;
	int				nb_presets;
	char			text_input[30];
	SDL_Rect		scroll_rects[MAX_RECTS];
	int				nb_scroll_rects;
	t_menu			*menus;
	t_sdl_text		white_text;
	t_sdl_text		*button_skins;
	int				nb_btn_skins;
	int				nb_menus;
	t_sdl_text		*menu_textures;
	int				nb_menu_textures;
	int				nb_fonts;
	t_events		events;
	int				current_menu;
	int				last_menu;
	t_block			current_block;
	int				scroll;
	int				zoom;
	int				fit_in_win;
	int				selected_preset;
	int				selected_feature;
	t_targetblock	target;
	int				waitforinput;
	int				spawn_x;
	int				spawn_y;
	t_edmap			map;
	int				draw_mode;
	unsigned char	changed;
	unsigned char	editor_exit;
	int				button_pressed;
	t_premenu_text	premenu_textures;
	int				maxheight;
	uint8_t			draw_ceiling;
	uint8_t			draw_only;
	int				inited;
}					t_editor;

/*
** BUTTON_PLACEMENT.C
*/
void				center_menu_buttons(t_editor *data);
void				center_menu_buttons_p2(t_editor *data, int i, int j, int y);
void				center_wall_size_ttf(t_editor *data, SDL_Rect *dst);
void				center_x_ttf(t_ttf_text **text, SDL_Rect *dst, int nb);
void				fit_x_buttons(SDL_Rect *src, SDL_Rect *dst, int nb);

/*
** BUTTON_PLACEMENT2.C
*/
int					assign_menu_rect(SDL_Rect *rect, int y, SDL_Rect *src);
void				button_to_rect(SDL_Rect *src, SDL_Rect *dst, int index,
					int nb);
void				center_rect_left(SDL_Rect *src, SDL_Rect *dst, int index,
					int nb);
void				center_rect_middle(SDL_Rect *src, SDL_Rect *dst, int index,
					int nb);
void				center_rect_right(SDL_Rect *src, SDL_Rect *dst, int index,
					int nb);

/*
** BUTTON_PLACEMENT3.C
*/
void				set_menu_textures_rects(t_editor *data, int nb_textures,
					int texture_size);
void				set_menu_textures_rects_p2(t_editor *data, int nb_textures,
					int texture_size);
/*
** DRAW_BLOCK.c
*/

void				draw_block_rect(t_editor *data, SDL_MouseButtonEvent *event,
					t_block *block);
void				draw_block(t_editor *data, int y, int x,
					t_sdl_text *texture);

/*
** DRAW_BLOCK_LINE.C
*/

int					set_linealg_values(int xy[4], int delta[4], int sign[2]);
int					draw_line(t_editor *data, int *xy, t_block *block);
void				get_draw_y(t_editor *data, SDL_MouseButtonEvent *event,
					int *y, int *ymax);
void				get_draw_x(t_editor *data, SDL_MouseButtonEvent *event,
					int *x, int *xmax);
void				draw_block_line(t_editor *data, SDL_MouseButtonEvent *event,
					t_block *block);

/*
** DRAW_MAP.C
*/
void				draw_map(t_editor *data, uint8_t access);
void				render_map(t_editor *data, t_sdl_data *win, SDL_Rect dst);

/*
** DRAW_MENU.C
*/
void				draw_editor_menu(t_editor *data);
void				draw_menu_buttons(t_editor *data, t_menu *menu);
void				draw_menu_textures_rects(t_editor *data,
						t_sdl_text *textures, int nb);
void				render_button_blurred(t_editor *data, t_menu *menu, int i);

/*
** DRAW_MENU2.C
*/
void				draw_menu_specific_data(t_editor *data);
void				render_presets(t_editor *data, t_menu *menu);
void				render_presets_p2(t_editor *data, t_menu *menu, int i,
					t_preset *ptr);
void				draw_texture_menu(t_editor *data);
void				draw_block_height_button(t_editor *data,
					t_block *block_target);
void				draw_wave_button(t_editor *data, t_block *block_target);

/*
** EDIT_MAP.C
*/
void				set_block_feature(t_block *dst, t_block *src, int feature);
int					get_map_texture_px_x(t_editor *data, int px);
int					get_map_texture_px_y(t_editor *data, int px);
int					remove_old_spawn(t_editor *data);
int					place_spawn(t_editor *data, int px_y, int px_x);
/*
** EVENTS.C
*/
int					mousewheel_event(t_editor *data,
					SDL_MouseWheelEvent *event);
void				mousemotion_event(t_editor *data,
					SDL_MouseMotionEvent *event);
int					handle_events(t_editor *data, SDL_Event *event);
int					keyboard_event(t_editor *data, SDL_KeyboardEvent *event);
void				update_cursor(SDL_Event *event, t_editor *data);

/*
** INIT_SDL.C
*/
int					create_window(t_sdl_data *win, t_editor *data);
int					init_sdl(t_sdl_data *win, t_editor *data);

/*
** INITIALISATION.C
*/
int					init_menu(t_editor *data);
int					load_bmp(SDL_Renderer *renderer, char *name,
					t_sdl_text *ptr, int isalpha);
int					load_textures(t_editor *data);
int					init_editor(t_editor *data);

/*
** INIT_MAP.C
*/
int					init_map(t_editor *data);

/*
** LOAD_MENU.C
*/

int					load_counters_ttf_p2(t_editor *data, TTF_Font *font);
int					load_counters_ttf(t_editor *data, TTF_Font *font);
int					load_menu(t_editor *data);
int					load_wall_size_numbers(t_editor *data, TTF_Font *font);
int					parse_button_skins(t_editor *data, int fd);
int					parse_menu_textures(t_editor *data, int fd);
int					read_button_data(t_menu *menu, int fd, t_editor *data,
					char *str);

/*
** LOAD_MENU_UTILS.C
*/
char				*skip_info(char *str);
int					skip_to_number(char *str);
int					read_btn_pos(int *tab, int nb, char *str, int max);
int					parse_menu_fonts(t_editor *data, int fd);
int					parse_menu_fonts_p2(t_editor *data, int fd,
					char **fonts_path, int nb_fonts_path);
/*
** LOAD_MENU2.C
*/
int					load_fonts(t_editor *data, int fd, char **fonts_path,
					int nb_fonts_path);
int					init_menu_tabs(t_menu *menu);
int					parse_menu_p2(t_menu *menu, int fd, t_editor *data);
int					parse_menu(t_menu *menu, int fd, t_editor *data);

/*
** LOOP.C
*/
int					loop(t_editor *data);
void				draw_prompt(t_editor *data);

/*
** MAP_EVENTS.C
*/
int					identify_block(t_editor *data, SDL_MouseButtonEvent *event);
void				map_event(t_editor *data, SDL_MouseButtonEvent *event);
int					mousebutton_event(t_editor *data,
					SDL_MouseButtonEvent *event);
int					mousebutton_mapevent(t_editor *data,
					SDL_MouseButtonEvent *event);
void				save_button(t_editor *data, SDL_MouseButtonEvent *event);

/*
** MENU_BLOCK_EVENTS.C
*/
int					block_menu_defaultbuttons_event(t_editor *data, int button);
int					block_menu_empty_event(t_editor *data, int button);
void				block_menu_wall_event(t_editor *data, int button,
					SDL_MouseButtonEvent *event);

/*
** MENU_EVENTS.C
*/
void				mousebutton_menuevent(t_editor *data,
					SDL_MouseButtonEvent *event);
void				texture_menu_event(t_editor *data,
					SDL_MouseButtonEvent *event);
int					feature_menu_event(t_editor *data, int button);
int					wall_feature_event(t_editor *data,
					SDL_MouseButtonEvent *event, int button);
void				validate_menu_event(t_editor *data, int button);

/*
** MENU_EVENTS_2.C
*/
int					options_menu_event(t_editor *data,
					SDL_MouseButtonEvent *event);
int					change_options_textures(t_editor *data, t_edmap *oldmap);
int					wave_menu_event(t_editor *data,
					SDL_MouseButtonEvent *event, int button);
int					wall_feature_event(t_editor *data,
					SDL_MouseButtonEvent *event, int button);
int					feature_menu_event(t_editor *data, int button);

/*
** MENU_EVENTS_UTILS.C
*/
int					change_menu(t_editor *data, int next_menu, int curr_menu);
int					choice_button_row(t_editor *data, int button, int start,
					int end);
int					is_in_rect(SDL_Rect *rect, int y, int x);
int					which_button(t_editor *data, int y, int x);
void				set_highlight_buttons(t_editor *data, int next_menu,
					t_block *target);

/*
** MENU_PRESETS.C
*/
int					delete_current_preset(t_editor *data);
void				delete_preset(t_preset *preset);
int					preset_menu_event(t_editor *data,
					SDL_MouseButtonEvent *event, int button);
t_block				*preset_select(t_editor *data);
void				change_selected_preset(t_editor *data,
					SDL_MouseButtonEvent *event);

/*
** OPTIONS_MENU.C
*/
void				draw_editor_optmenu(t_editor *data);
void				set_optmenu_textures_rects(t_editor *data);

/*
** PLACE_BLOCK.C
*/

int					try_block(t_editor *data, t_block *block, int y, int x);
void				place_block(t_editor *data, t_block *block, int y, int x);
int					place_block_px(t_editor *data, t_block *block, int y,
					int x);
int					place_block_pos(t_editor *data, t_block *block, int y,
					int x);

/*
** PROMPT_EVENTS.C
*/
int					add_preset(t_editor *data);
int					prompt_event(t_editor *data, SDL_KeyboardEvent *event);
int					read_input(t_editor *data, SDL_TextInputEvent *event);
int					reload_ttf_input(t_editor *data);
int					stop_prompt(t_editor *data);

/*
** SAVE_MAP.C
*/
int					save_map(t_editor *data, t_elem *elem);
void				save_block_sprite(t_block *block, char *str);

/*
** TEXTURES.C
*/
int					load_floors(t_editor *data);
int					load_roofs(t_editor *data);
int					load_walls(t_editor *data);
int					load_sprites(t_editor *data);
int					load_skyboxs(t_editor *data);

/*
** TEXTURES2.C
*/
int					load_items(t_editor *data);

/*
** TTF_INIT.C
*/
t_ttf_text			*create_str_texture(SDL_Renderer *renderer, char *str,
					SDL_Color col, TTF_Font *police);

/*
** UTILS.C
*/

void				change_zoom(t_editor *data, int dir, int y, int x);
void				change_zoom_p2(t_editor *data, int y, int x);

/*
** WIPEOUT.C
*/
void				free_editor(t_editor *data);
void				free_sdl(t_sdl_data *win);
void				wipeout(t_editor *data, int ret);

/*
** WIPEOUT_EDITOR.C
*/
void				free_editor_presets(t_editor *data);
void				free_editor_ttf(t_editor *data);
void				free_editor_ttf_p2(t_editor *data);

/*
** WIPEOUT_EDITOR_P2.C
*/
void				free_editor_textures(t_editor *data);
void				free_editor_menu(t_editor *data);
void				free_editor_premenu(t_editor *data);
void				del_t_menu(t_editor *data);

/*
** WIPEOUT_UTILS.C
*/
void				delete_font(TTF_Font *font);
void				delete_texture_tab(t_sdl_text *tab, size_t i);
void				delete_texture_tab_ttf(t_ttf_text *tab, size_t i);
void				delete_texture(SDL_Texture *texture);
void				delete_sdl_text(t_sdl_text **tab);
void				delete_ttf(t_ttf_text **tab);

/*
** MAIN.C
*/
void				render_presets(t_editor *data, t_menu *menu);
int					ft_printerror(char *str);
int					ft_errordel(char *str, void **ptr);

/*
** DOOM
*/
void				render_cursor(SDL_Renderer *ren, SDL_Texture *cursor, int x,
					int y);
#endif
