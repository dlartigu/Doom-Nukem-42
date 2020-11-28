# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 00:40:28 by niboute           #+#    #+#              #
#    Updated: 2020/11/26 15:17:22 by dlartigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COLORS ##################

NAME = doom-nukem
LIB = libft/libft.a
SRCS_PATH = SRCS/
PWD := $(shell pwd)

SRCS_NAME = main_utils/main.c \
			main_utils/ft_exit.c \
			main_utils/ft_set_ttf.c \
			main_utils/ft_free_exit.c \
			main_utils/ft_rect_size.c \
			gnl/get_next_line.c \
			gnl/join_free.c \
			gnl/ft_helpers.c \
			setsdl/ft_set_sdl.c\
			setsdl/ft_window.c \
			setsdl/ft_render_set.c \
			setsdl/ft_setstruct.c \
			setsdl/get_max_res.c \
			setsdl/ft_init_env.c \
			parsing/ft_parse_map.c\
			parsing/ft_error.c \
			parsing/ft_fillinfos.c \
			parsing/ft_printtab.c \
			parsing/ft_checkfloor.c \
			parsing/ft_wolfcheck.c \
			parsing/ft_checkspawn.c \
			parsing/ft_new_backup.c \
			free/ft_freetab.c \
			free/ft_freestruct.c \
			free/ft_freestructall.c \
			free/ft_freestructall_p2.c \
			free/free_sound.c \
			free/ft_free_hud_struct.c \
			free/ft_remove_timers.c \
			menu/draw_cursor.c \
			menu/draw_menu_arcade.c \
			menu/draw_menu_audio.c \
			menu/draw_menu_controls.c \
			menu/draw_menu_gameplay.c \
			menu/draw_menu_play.c \
			menu/draw_menu_settings.c \
			menu/draw_menu_start.c \
			menu/draw_menu_story.c \
			menu/draw_menu_video.c \
			menu/draw_menu_video_settings.c \
			menu/arcade_event.c \
			menu/audio_event.c \
			menu/controls_event.c \
			menu/gameplay_event.c \
			menu/play_event.c \
			menu/settings_event.c \
			menu/start_menu_event.c \
			menu/story_event.c \
			menu/video_event.c \
			menu/menu_utils.c \
			raycasting/ft_initray.c \
			raycasting/ft_raycasting.c \
			raycasting/ft_rayhelper.c \
			raycasting/windowcasting.c \
			raycasting/calc_window.c \
			loadtextures/ft_walltexture.c \
			loadtextures/ft_animated_texture.c \
			loadtextures/ft_animated_texture2.c \
			loadtextures/ft_ceilingtexture.c \
			loadtextures/ft_floortexture.c \
			loadtextures/ft_textnum.c \
			loadtextures/ft_loadtextures.c \
			loadtextures/load_skybox.c \
			loadtextures/ft_weapons_textures.c \
			loadtextures/ft_weapons_textures_p2.c \
			loadtextures/ft_load_hud.c \
			loadtextures/load_sprites_textures.c \
			loadtextures/load_sprites_textures2.c \
			loadtextures/load_sprites_textures3.c \
			loadtextures/load_sprites_textures4.c \
			loadtextures/load_sprites_textures5.c \
			draw/ft_crosshair.c \
			draw/ft_minimap.c \
			draw/ft_putpixel.c \
			draw/ft_drawrenderer.c \
			draw/ft_drawcompass.c \
			draw/ft_draw_walltextured.c \
			draw/ft_drawfloorceiling.c \
			draw/draw_window.c \
			draw/draw_skybox.c \
			draw/draw_sprites.c \
			move/ft_moves.c \
			move/ft_mousemotion.c \
			move/ft_speedshift.c \
			move/ft_movements.c \
			move/ft_crouch.c \
			move/ft_walk.c \
			move/ft_fly.c \
			move/ft_jump.c \
			move/ft_flydive.c \
			move/ft_moves_wasd.c \
			move/ft_moves_wasd_noclip.c \
			move/warp/ft_warp.c \
			move/warp/ft_nextfloor.c \
			move/items/ft_items_hud.c \
			move/items/ft_items_hud_p2.c \
			move/items/ft_lightuptorch.c \
			move/medkit/ft_medkit.c \
			move/weapons/ft_weapons.c \
			move/ammo/ft_ammo.c \
			move/ft_godmode.c \
			move/ft_stoprain.c \
			play_content/init_story.c \
			play_content/init_arcade.c \
			play_content/intro/ft_intro.c \
			play_content/intro/ft_intro_content.c \
			play_content/intro/ft_introhelper.c \
			play_content/intro/ft_intro_lvl1.c \
			play_content/intro/ft_intro_lvl2.c \
			play_content/intro/ft_intro_lvl3.c \
			play_content/play_content.c \
			play_content/ft_display_game.c \
			play_content/init_game.c \
			play_content/ft_render.c \
			play_content/ft_messages.c \
			play_content/ft_printscore.c \
			play_content/level_setup/ft_setup_levels.c \
			play_content/level_setup/ft_arcade_setup.c \
			play_content/level_setup/ft_setup_helpers.c \
			editor/start_editor.c \
			editor/button_placement.c \
			editor/button_placement2.c \
			editor/button_placement3.c \
			editor/draw_block.c \
			editor/draw_block_line.c \
			editor/draw_map.c \
			editor/draw_menu.c \
			editor/draw_menu2.c \
			editor/draw_menu3.c \
			editor/edit_map.c \
			editor/events.c \
			editor/ft_printerror.c \
			editor/ft_errordel.c \
			editor/initialisation.c \
			editor/init_map.c \
			editor/load_menu.c \
			editor/load_menu_utils.c \
			editor/load_menu2.c \
			editor/loop.c \
			editor/map_events.c \
			editor/menu_block_events.c \
			editor/menu_events.c \
			editor/menu_events2.c \
			editor/menu_events3.c \
			editor/menu_events_utils.c \
			editor/menu_presets.c \
			editor/options_menu.c \
			editor/place_block.c \
			editor/prompt_event.c \
			editor/save_map.c \
			editor/save_map2.c \
			editor/textures.c \
			editor/textures2.c \
			editor/ttf_init.c \
			editor/update_cursor.c \
			editor/utils.c \
			editor/wipeout.c \
			editor/wipeout_editor.c \
			editor/wipeout_editor_p2.c \
			editor/wipeout_utils.c \
			audio/music.c \
			audio/soundeffects.c \
			audio/load_sounds.c \
			audio/load_sound_p2.c \
			ragdoll/ft_ragdoll.c \
			ragdoll/ft_ragdoll_helper.c \
			ragdoll/ft_ragdollup.c \
			hud/ft_fps.c \
			hud/ft_hud.c \
			hud/ft_print_hud.c \
			hud/ft_print_ammos.c \
			hud/ft_head_guy.c \
			hud/weapons/ft_weapons.c \
			hud/weapons/ft_weapons_rect.c \
			hud/weapons/ft_devastator_animation.c \
			hud/weapons/ft_shotgun_animation.c \
			hud/weapons/ft_pistol_animation.c \
			hud/weapons/ft_fist_animation.c \
			hud/weapons/ft_weapons_utils.c \
			hud/weapons/ft_reload_timers.c \
			hud/weapons/ft_shoot_timers.c \
			hud/weapons/ft_weapons_timers.c \
			hud/weapons/ft_fist_timers.c \
			gameover/gameover.c \
			gameover/init_gameover.c \
			effects/rain.c \
			effects/bubble.c \
			effects/bubble_render.c \
			effects/fog_wall.c \
			effects/fog_floor.c \
			effects/reflection.c \
			effects/psyeffect.c \
			effects/ft_effects.c \
			effects/bullet_impact.c \
			effects/bullet_impact2.c \
			effects/counter.c \
			free/ft_freesmallstruct.c \
			sprites/add_sprite.c \
			sprites/add_projectile.c \
			sprites/anim_sprites.c \
			sprites/anim_sprites2.c \
			sprites/anim_torch_warp.c \
			sprites/anim_dead_sprite.c \
			sprites/anim_devastator_explosion.c \
			sprites/calc_sprites.c \
			sprites/store_sprites.c \
			sprites/init_sprites.c \
			sprites/init_sprites2.c \
			sprites/init_sprites3.c \
			sprites/load_map_sprites.c \
			sprites/combat.c \
			sprites/enemy_attack.c \
			sprites/attack_enemy.c \
			sprites/ft_remove_sprites.c \
			sprites/sprites_ai.c \
			sprites/sprites_ai2.c \
			sprites/sprites_ai3.c \
			sprites/projectile.c \
			sprites/update_enemies.c \
			effects/bullet_impact3.c \
			effects/bullet_impact4.c

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ= $(SRCS:.c=.o)

HEADER=	prog.h \
		editor.h \
		editor_textures.h \
		get_next_line.h

INC= ./INCLUDES/

HEADERS= $(addprefix $(INC), $(HEADER))

SDL2= SDL2/

SDL2_TTF= SDL2_TTF/

LIBSDL2_TTF= SDL2_TTF/lib/libSDL2_ttf.a

INC_LIBFT= -I libft

LD_LIBFT= -L ./libft -lft

INC_FMOD= -I ./fmod_inc

LD_FMOD = -lfmod -lfmodL

UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		SDL_DEPENDENCIES = $(shell  ./SDL2/bin/sdl2-config --libs) \
			-L ./SDL2_TTF/lib -lSDL2_ttf
		SDL_DEPENDENCIES += -lfreetype
		INC_SDL2= -I SDL2/include/SDL2/
		INC_SDL2_TTF= -I SDL2_TTF/include/SDL2/
		MAKE_DEPLOY = deploy_linux
		FREETYPE_INSTALLED=$(shell dpkg -l | grep libfreetype6-dev)
		FREEGLUT_INSTALLED=$(shell dpkg -l | grep freeglut3-dev)
    endif
    ifeq ($(UNAME_S),Darwin)
		SDL_DEPENDENCIES = $(shell sdl2-config --libs) \
			-lSDL2_ttf
		SDL_DEPENDENCIES += -lfreetype
		INC_SDL2 = -I /usr/include/SDL2
		MAKE_DEPLOY = deploy_mac
		FREETYPE_INSTALLED=$(shell brew list | grep -w freetype)
		SDL2_INSTALLED=$(shell brew list | grep -w sdl2)
		SDL2_TTF_INSTALLED=$(shell brew list | grep -w sdl2_ttf)
	endif

CC= clang
CFLAGS += -Wall -Wextra -Werror -O2
CFLAGS += -I $(INC)
CFLAGS += $(INC_SDL2)
CFLAGS += $(INC_SDL2_TTF)
CFLAGS += $(INC_LIBFT)
CFLAGS += $(INC_FMOD)
LDFLAGS += $(SDL_DEPENDENCIES)
LDFLAGS += $(LD_LIBFT)
LDFLAGS += $(LD_FMOD)
all: buildft check_deploy $(NAME)

buildft:
	@make --no-print-directory -C libft/

check_deploy:
        ifeq ($(UNAME_S),Linux)
			@cp ./.linux/sdl_inc.h INCLUDES/sdl_inc.h
			@(test -s ./SDL2 -a FREETYPE_INSTALLED) ||  make $(MAKE_DEPLOY)
        endif
        ifeq ($(UNAME_S),Darwin)
			@cp ./.macos/sdl_inc.h INCLUDES/sdl_inc.h
			@(test FREETYPE_INSTALLED -a SDL2_INSTALLED -a SDL2_TTF_INSTALLED) || make $(MAKE_DEPLOY)
        endif

$(NAME): $(LIB) $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
			@echo "\\n[OK] Compilation de $(NAME)"

%.o: %.c $(HEADERS) $(LIB) Makefile
	@$(CC) $(CFLAGS) -c -o $@ $< && printf "[OK] Generation de %-50s\r" "$@" || \
		(echo "[ERREUR] Une est erreur est survenue sur $<, $(NAME) non compilé(e)\n" && exit 1)

clean:
		@rm -f $(OBJ)
		@make -C libft clean
		@echo "[OK] Supression de tous les objets"
fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean
		@echo "[OK] Supression de tous les fichiers"

clean_sdl:
        ifeq ($(UNAME_S),Linux)
			rm -rf ./SDL2
			rm -rf ./SDL2-2.0.12
			rm -rf ./SDL2-2.0.12.tar.gz
			rm -rf ./SDL2_TTF
			rm -rf ./SDL2_ttf-2.0.15
			rm -rf ./SDL2_ttf-2.0.15.tar.gz
        endif

deploy:
		make $(MAKE_DEPLOY)

deploy_linux:
		@$(ROOT) cp fmod_lib/libfmod.so /usr/lib/
		@$(ROOT) cp fmod_lib/libfmod.so.12 /usr/lib/
		@$(ROOT) cp fmod_lib/libfmod.so.12.0 /usr/lib/
		@$(ROOT) cp fmod_lib/libfmodL.so /usr/lib/
		@$(ROOT) cp fmod_lib/libfmodL.so.12 /usr/lib/
		@$(ROOT) cp fmod_lib/libfmodL.so.12.0 /usr/lib/
        ifeq ($(strip $(FREETYPE_INSTALLED)), )
			sudo apt-get install libfreetype6-dev
        endif
        ifeq ($(strip $(FREEGLUT_INSTALLED)), )
			sudo apt-get install freeglut3-dev
        endif
		$(MAKE) clean_sdl
		wget https://www.libsdl.org/release/SDL2-2.0.12.tar.gz -O SDL2-2.0.12.tar.gz \
		&& tar -xf SDL2-2.0.12.tar.gz \
		&& (cd SDL2-2.0.12 \
		&& ./configure --prefix=$(shell pwd)/SDL2 --enable-static --disable-shared \
		&& make \
		&& make install)
		@wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz -O SDL2_ttf-2.0.15.tar.gz \
		&& tar -xf SDL2_ttf-2.0.15.tar.gz \
		&& (cd SDL2_ttf-2.0.15 \
		&& ./configure --prefix=$(shell pwd)/SDL2_TTF \
		--with-sdl-prefix=$(shell pwd)/SDL2 \
		--with-sdl-exec-prefix=$(shell pwd)/SDL2 --disable-shared \
		--enable-static \
		&& make \
		&& make install)
		@rm -rf ./SDL2-2.0.12
		@rm -rf ./SDL2-2.0.12.tar.gz
		@rm -rf ./SDL2_ttf-2.0.15
		@rm -rf ./SDL2_ttf-2.0.15.tar.gz

deploy_mac:
		@cp ./.macos/sdl.h INCLUDES/sdl.h
		@$(ROOT) cp fmod_lib/libfmod.dylib /usr/local/lib
		@$(ROOT) cp fmod_lib/libfmodL.dylib /usr/local/lib
		/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
		@echo $(strip $(FREETYPE_INSTALLED))
        ifeq ($(strip $(FREETYPE_INSTALLED)),)
			brew install freetype
			brew link freetype
        else
			@echo "[Freetype] is already installed" 
        endif
        ifeq ($(strip $(SDL2_INSTALLED)),)
			brew install sdl2
			brew link sdl2
        else
			@echo "[SDL] is already installed"
        endif
        ifeq ($(strip $(SDL2_TTF_INSTALLED)),)
			brew install sdl2_ttf
			brew link sdl2_ttf
        else
			@echo "[SDL_TTF] is already installed" 
        endif

re: fclean all

redeploy: clean_sdl deploy

.PHONY: all clean fclean re buildft clean_sdl deploy redeploy check_deploy
