/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:01:15 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/26 14:52:32 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROG_H
# define PROG_H

# include "../fmod_inc/fmod.h"
# include "../libft/libft.h"
# include "sdl_inc.h"
# include <sys/types.h>
# include <sys/sysctl.h>
# include <pthread.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <inttypes.h>
# include "get_next_line.h"
# define IMG_HOME "../RSCS/menu/home_menu.bmp"
# define HOME "./RSCS/menu/home/home2.bmp"
# define PLAY "./RSCS/menu/home/PLAY.bmp"
# define MAPEDIT "./RSCS/menu/home/mapedit.bmp"
# define SET_HOME "./RSCS/menu/home/SETTINGS_home.bmp"
# define EXIT "./RSCS/menu/home/EXIT.bmp"
# define SET_BACK "./RSCS/menu/settings/back_to_main_menu.bmp"
# define SET_VIDEO "./RSCS/menu/settings/video.bmp"
# define SET_AUDIO "./RSCS/menu/settings/audio.bmp"
# define SET_GAMEPLAY "./RSCS/menu/settings/gameplay.bmp"
# define VID_RES "./RSCS/menu/settings/video/Resolution.bmp"
# define VID_VSYNC "./RSCS/menu/settings/video/VSYNC.bmp"
# define VID_FS "./RSCS/menu/settings/video/Fullscreen.bmp"
# define VID_GPU "./RSCS/menu/settings/video/GPUACCELL.bmp"
# define VID_ALIAS "./RSCS/menu/settings/video/anti-aliasing.bmp"
# define VID_TEXTURE "./RSCS/menu/settings/video/texture_quality.bmp"
# define VID_RET "./RSCS/menu/settings/video/RETURN.bmp"
# define VID_APPLY "./RSCS/menu/settings/video/APPLY.bmp"
# define GAME_DIF "./RSCS/menu/settings/Gameplay/difficulty.bmp"
# define GAME_SENS "./RSCS/menu/settings/Gameplay/sensitivity.bmp"
# define GAME_CONTROL "./RSCS/menu/settings/Gameplay/controls.bmp"
# define GAME_APPLY "./RSCS/menu/settings/Gameplay/apply.bmp"
# define GAME_RETURN "./RSCS/menu/settings/Gameplay/return.bmp"
# define TEXT_VOL "./RSCS/menu/settings/audio/volume.bmp"
# define TEXT_MUS "./RSCS/menu/settings/audio/music.bmp"
# define TEXT_EFFECT "./RSCS/menu/settings/audio/effect.bmp"
# define TEXT_APL "./RSCS/menu/settings/audio/apply.bmp"
# define TEXT_RET "./RSCS/menu/settings/audio/return.bmp"
# define PLAY_STORY "./RSCS/menu/play/story.bmp"
# define PLAY_ARCADE "./RSCS/menu/play/arcade.bmp"
# define PLAY_MULTI "./RSCS/menu/play/multi.bmp"
# define PLAY_RETURN "./RSCS/menu/play/HOME_MENU.bmp"
# define STORY_NORMAL "./RSCS/menu/play/story/normal.bmp"
# define STORY_HARD "./RSCS/menu/play/story/hard.bmp"
# define STORY_HELL "./RSCS/menu/play/story/hell.bmp"
# define STORY_RETURN "./RSCS/menu/play/story/story_home_menu.bmp"
# define ARCADE_CIRCUS_0 "./RSCS/menu/play/arcade/1circus_play.bmp"
# define ARCADE_CIRCUS_1 "./RSCS/menu/play/arcade/1circus_return.bmp"
# define ARCADE_MINE_0 "./RSCS/menu/play/arcade/2mine_play.bmp"
# define ARCADE_MINE_1 "./RSCS/menu/play/arcade/2mine_return.bmp"
# define ARCADE_MAGMA_0 "./RSCS/menu/play/arcade/3magma_play.bmp"
# define ARCADE_MAGMA_1 "./RSCS/menu/play/arcade/3magma_return.bmp"
# define ARCADE_CUSTOM_0 "./RSCS/menu/play/arcade/4custommap_play.bmp"
# define ARCADE_CUSTOM_1 "./RSCS/menu/play/arcade/4custommap_return.bmp"
# define CEL_EPIC_0 "./RSCS/texture/ceiling/epic/0.bmp"
# define CEL_EPIC_1 "./RSCS/texture/ceiling/epic/1.bmp"
# define CEL_HIGH_0 "./RSCS/texture/ceiling/high/0.bmp"
# define CEL_HIGH_1 "./RSCS/texture/ceiling/high/1.bmp"
# define CEL_NORMAL_0 "./RSCS/texture/ceiling/normal/0.bmp"
# define CEL_NORMAL_1 "./RSCS/texture/ceiling/normal/1.bmp"
# define FLO_EPIC_0 "./RSCS/texture/floor/epic/0.bmp"
# define FLO_EPIC_1 "./RSCS/texture/floor/epic/1.bmp"
# define FLO_EPIC_2 "./RSCS/texture/floor/epic/2.bmp"
# define FLO_EPIC_3 "./RSCS/texture/floor/epic/3.bmp"
# define FLO_EPIC_4 "./RSCS/texture/floor/epic/4.bmp"
# define FLO_EPIC_5 "./RSCS/texture/floor/epic/5.bmp"
# define FLO_HIGH_0 "./RSCS/texture/floor/high/0.bmp"
# define FLO_HIGH_1 "./RSCS/texture/floor/high/1.bmp"
# define FLO_HIGH_2 "./RSCS/texture/floor/high/2.bmp"
# define FLO_HIGH_3 "./RSCS/texture/floor/high/3.bmp"
# define FLO_HIGH_4 "./RSCS/texture/floor/high/4.bmp"
# define FLO_HIGH_5 "./RSCS/texture/floor/high/5.bmp"
# define FLO_NORMAL_0 "./RSCS/texture/floor/normal/0.bmp"
# define FLO_NORMAL_1 "./RSCS/texture/floor/normal/1.bmp"
# define FLO_NORMAL_2 "./RSCS/texture/floor/normal/2.bmp"
# define FLO_NORMAL_3 "./RSCS/texture/floor/normal/3.bmp"
# define FLO_NORMAL_4 "./RSCS/texture/floor/normal/4.bmp"
# define FLO_NORMAL_5 "./RSCS/texture/floor/normal/5.bmp"
# define WAL_EPIC_0 "./RSCS/texture/wall/epic/0.bmp"
# define WAL_EPIC_1 "./RSCS/texture/wall/epic/1.bmp"
# define WAL_EPIC_2 "./RSCS/texture/wall/epic/2.bmp"
# define WAL_EPIC_3 "./RSCS/texture/wall/epic/3.bmp"
# define WAL_EPIC_4 "./RSCS/texture/wall/epic/4.bmp"
# define WAL_EPIC_5 "./RSCS/texture/wall/epic/5.bmp"
# define WAL_EPIC_6 "./RSCS/texture/wall/epic/6.bmp"
# define WAL_EPIC_7 "./RSCS/texture/wall/epic/7.bmp"
# define WAL_EPIC_8 "./RSCS/texture/wall/epic/8.bmp"
# define WAL_EPIC_9 "./RSCS/texture/wall/epic/9.bmp"
# define WAL_EPIC_10 "./RSCS/texture/wall/epic/B.bmp"
# define WAL_EPIC_11 "./RSCS/texture/wall/epic/C.bmp"
# define WAL_EPIC_12 "./RSCS/texture/wall/epic/D.bmp"
# define WAL_EPIC_13 "./RSCS/texture/wall/epic/E.bmp"
# define WAL_EPIC_14 "./RSCS/texture/wall/epic/F.bmp"
# define WAL_EPIC_15 "./RSCS/texture/wall/epic/G.bmp"
# define WAL_EPIC_16 "./RSCS/texture/wall/epic/H.bmp"
# define WAL_HIGH_0 "./RSCS/texture/wall/high/0.bmp"
# define WAL_HIGH_1 "./RSCS/texture/wall/high/1.bmp"
# define WAL_HIGH_2 "./RSCS/texture/wall/high/2.bmp"
# define WAL_HIGH_3 "./RSCS/texture/wall/high/3.bmp"
# define WAL_HIGH_4 "./RSCS/texture/wall/high/4.bmp"
# define WAL_HIGH_5 "./RSCS/texture/wall/high/5.bmp"
# define WAL_HIGH_6 "./RSCS/texture/wall/high/6.bmp"
# define WAL_HIGH_7 "./RSCS/texture/wall/high/7.bmp"
# define WAL_HIGH_8 "./RSCS/texture/wall/high/8.bmp"
# define WAL_HIGH_9 "./RSCS/texture/wall/high/9.bmp"
# define WAL_HIGH_10 "./RSCS/texture/wall/high/B.bmp"
# define WAL_HIGH_11 "./RSCS/texture/wall/high/C.bmp"
# define WAL_HIGH_12 "./RSCS/texture/wall/high/D.bmp"
# define WAL_HIGH_13 "./RSCS/texture/wall/high/E.bmp"
# define WAL_HIGH_14 "./RSCS/texture/wall/high/F.bmp"
# define WAL_HIGH_15 "./RSCS/texture/wall/high/G.bmp"
# define WAL_HIGH_16 "./RSCS/texture/wall/high/H.bmp"
# define WAL_NORMAL_0  "./RSCS/texture/wall/normal/0.bmp"
# define WAL_NORMAL_1 "./RSCS/texture/wall/normal/1.bmp"
# define WAL_NORMAL_2 "./RSCS/texture/wall/normal/2.bmp"
# define WAL_NORMAL_3 "./RSCS/texture/wall/normal/3.bmp"
# define WAL_NORMAL_4 "./RSCS/texture/wall/normal/4.bmp"
# define WAL_NORMAL_5 "./RSCS/texture/wall/normal/5.bmp"
# define WAL_NORMAL_6 "./RSCS/texture/wall/normal/6.bmp"
# define WAL_NORMAL_7 "./RSCS/texture/wall/normal/7.bmp"
# define WAL_NORMAL_8 "./RSCS/texture/wall/normal/8.bmp"
# define WAL_NORMAL_9 "./RSCS/texture/wall/normal/9.bmp"
# define WAL_NORMAL_10 "./RSCS/texture/wall/normal/B.bmp"
# define WAL_NORMAL_11 "./RSCS/texture/wall/normal/C.bmp"
# define WAL_NORMAL_12 "./RSCS/texture/wall/normal/D.bmp"
# define WAL_NORMAL_13 "./RSCS/texture/wall/normal/E.bmp"
# define WAL_NORMAL_14 "./RSCS/texture/wall/normal/F.bmp"
# define WAL_NORMAL_15 "./RSCS/texture/wall/normal/G.bmp"
# define WAL_NORMAL_16 "./RSCS/texture/wall/normal/H.bmp"

# define LVL3_NORMAL_0 "RSCS/texture/wall/normal/wall_level3/frame_00.bmp"
# define LVL3_NORMAL_1 "RSCS/texture/wall/normal/wall_level3/frame_01.bmp"
# define LVL3_NORMAL_2 "RSCS/texture/wall/normal/wall_level3/frame_02.bmp"
# define LVL3_NORMAL_3 "RSCS/texture/wall/normal/wall_level3/frame_03.bmp"
# define LVL3_NORMAL_4 "RSCS/texture/wall/normal/wall_level3/frame_04.bmp"
# define LVL3_NORMAL_5 "RSCS/texture/wall/normal/wall_level3/frame_05.bmp"
# define LVL3_NORMAL_6 "RSCS/texture/wall/normal/wall_level3/frame_06.bmp"
# define LVL3_NORMAL_7 "RSCS/texture/wall/normal/wall_level3/frame_07.bmp"
# define LVL3_NORMAL_8 "RSCS/texture/wall/normal/wall_level3/frame_08.bmp"
# define LVL3_NORMAL_9 "RSCS/texture/wall/normal/wall_level3/frame_09.bmp"
# define LVL3_NORMAL_10 "RSCS/texture/wall/normal/wall_level3/frame_10.bmp"
# define LVL3_NORMAL_11 "RSCS/texture/wall/normal/wall_level3/frame_11.bmp"
# define LVL3_NORMAL_12 "RSCS/texture/wall/normal/wall_level3/frame_12.bmp"
# define LVL3_NORMAL_13 "RSCS/texture/wall/normal/wall_level3/frame_13.bmp"
# define LVL3_NORMAL_14 "RSCS/texture/wall/normal/wall_level3/frame_14.bmp"
# define LVL3_NORMAL_15 "RSCS/texture/wall/normal/wall_level3/frame_15.bmp"
# define LVL3_NORMAL_16 "RSCS/texture/wall/normal/wall_level3/frame_16.bmp"
# define LVL3_NORMAL_17 "RSCS/texture/wall/normal/wall_level3/frame_17.bmp"
# define LVL3_NORMAL_18 "RSCS/texture/wall/normal/wall_level3/frame_18.bmp"
# define LVL3_NORMAL_19 "RSCS/texture/wall/normal/wall_level3/frame_19.bmp"
# define LVL3_NORMAL_20 "RSCS/texture/wall/normal/wall_level3/frame_20.bmp"
# define LVL3_NORMAL_21 "RSCS/texture/wall/normal/wall_level3/frame_21.bmp"
# define LVL3_NORMAL_22 "RSCS/texture/wall/normal/wall_level3/frame_22.bmp"
# define LVL3_NORMAL_23 "RSCS/texture/wall/normal/wall_level3/frame_23.bmp"
# define LVL3_NORMAL_24 "RSCS/texture/wall/normal/wall_level3/frame_24.bmp"
# define LVL3_NORMAL_25 "RSCS/texture/wall/normal/wall_level3/frame_25.bmp"
# define LVL3_NORMAL_26 "RSCS/texture/wall/normal/wall_level3/frame_26.bmp"
# define LVL3_NORMAL_27 "RSCS/texture/wall/normal/wall_level3/frame_27.bmp"
# define LVL3_NORMAL_28 "RSCS/texture/wall/normal/wall_level3/frame_28.bmp"
# define LVL3_NORMAL_29 "RSCS/texture/wall/normal/wall_level3/frame_29.bmp"
# define LVL3_HIGH_0 "RSCS/texture/wall/high/wall_level3/frame_00.bmp"
# define LVL3_HIGH_1 "RSCS/texture/wall/high/wall_level3/frame_01.bmp"
# define LVL3_HIGH_2 "RSCS/texture/wall/high/wall_level3/frame_02.bmp"
# define LVL3_HIGH_3 "RSCS/texture/wall/high/wall_level3/frame_03.bmp"
# define LVL3_HIGH_4 "RSCS/texture/wall/high/wall_level3/frame_04.bmp"
# define LVL3_HIGH_5 "RSCS/texture/wall/high/wall_level3/frame_05.bmp"
# define LVL3_HIGH_6 "RSCS/texture/wall/high/wall_level3/frame_06.bmp"
# define LVL3_HIGH_7 "RSCS/texture/wall/high/wall_level3/frame_07.bmp"
# define LVL3_HIGH_8 "RSCS/texture/wall/high/wall_level3/frame_08.bmp"
# define LVL3_HIGH_9 "RSCS/texture/wall/high/wall_level3/frame_09.bmp"
# define LVL3_HIGH_10 "RSCS/texture/wall/high/wall_level3/frame_10.bmp"
# define LVL3_HIGH_11 "RSCS/texture/wall/high/wall_level3/frame_11.bmp"
# define LVL3_HIGH_12 "RSCS/texture/wall/high/wall_level3/frame_12.bmp"
# define LVL3_HIGH_13 "RSCS/texture/wall/high/wall_level3/frame_13.bmp"
# define LVL3_HIGH_14 "RSCS/texture/wall/high/wall_level3/frame_14.bmp"
# define LVL3_HIGH_15 "RSCS/texture/wall/high/wall_level3/frame_15.bmp"
# define LVL3_HIGH_16 "RSCS/texture/wall/high/wall_level3/frame_16.bmp"
# define LVL3_HIGH_17 "RSCS/texture/wall/high/wall_level3/frame_17.bmp"
# define LVL3_HIGH_18 "RSCS/texture/wall/high/wall_level3/frame_18.bmp"
# define LVL3_HIGH_19 "RSCS/texture/wall/high/wall_level3/frame_19.bmp"
# define LVL3_HIGH_20 "RSCS/texture/wall/high/wall_level3/frame_20.bmp"
# define LVL3_HIGH_21 "RSCS/texture/wall/high/wall_level3/frame_21.bmp"
# define LVL3_HIGH_22 "RSCS/texture/wall/high/wall_level3/frame_22.bmp"
# define LVL3_HIGH_23 "RSCS/texture/wall/high/wall_level3/frame_23.bmp"
# define LVL3_HIGH_24 "RSCS/texture/wall/high/wall_level3/frame_24.bmp"
# define LVL3_HIGH_25 "RSCS/texture/wall/high/wall_level3/frame_25.bmp"
# define LVL3_HIGH_26 "RSCS/texture/wall/high/wall_level3/frame_26.bmp"
# define LVL3_HIGH_27 "RSCS/texture/wall/high/wall_level3/frame_27.bmp"
# define LVL3_HIGH_28 "RSCS/texture/wall/high/wall_level3/frame_28.bmp"
# define LVL3_HIGH_29 "RSCS/texture/wall/high/wall_level3/frame_29.bmp"
# define LVL3_EPIC_0 "RSCS/texture/wall/epic/wall_level3/frame_00.bmp"
# define LVL3_EPIC_1 "RSCS/texture/wall/epic/wall_level3/frame_01.bmp"
# define LVL3_EPIC_2 "RSCS/texture/wall/epic/wall_level3/frame_02.bmp"
# define LVL3_EPIC_3 "RSCS/texture/wall/epic/wall_level3/frame_03.bmp"
# define LVL3_EPIC_4 "RSCS/texture/wall/epic/wall_level3/frame_04.bmp"
# define LVL3_EPIC_5 "RSCS/texture/wall/epic/wall_level3/frame_05.bmp"
# define LVL3_EPIC_6 "RSCS/texture/wall/epic/wall_level3/frame_06.bmp"
# define LVL3_EPIC_7 "RSCS/texture/wall/epic/wall_level3/frame_07.bmp"
# define LVL3_EPIC_8 "RSCS/texture/wall/epic/wall_level3/frame_08.bmp"
# define LVL3_EPIC_9 "RSCS/texture/wall/epic/wall_level3/frame_09.bmp"
# define LVL3_EPIC_10 "RSCS/texture/wall/epic/wall_level3/frame_10.bmp"
# define LVL3_EPIC_11 "RSCS/texture/wall/epic/wall_level3/frame_11.bmp"
# define LVL3_EPIC_12 "RSCS/texture/wall/epic/wall_level3/frame_12.bmp"
# define LVL3_EPIC_13 "RSCS/texture/wall/epic/wall_level3/frame_13.bmp"
# define LVL3_EPIC_14 "RSCS/texture/wall/epic/wall_level3/frame_14.bmp"
# define LVL3_EPIC_15 "RSCS/texture/wall/epic/wall_level3/frame_15.bmp"
# define LVL3_EPIC_16 "RSCS/texture/wall/epic/wall_level3/frame_16.bmp"
# define LVL3_EPIC_17 "RSCS/texture/wall/epic/wall_level3/frame_17.bmp"
# define LVL3_EPIC_18 "RSCS/texture/wall/epic/wall_level3/frame_18.bmp"
# define LVL3_EPIC_19 "RSCS/texture/wall/epic/wall_level3/frame_19.bmp"
# define LVL3_EPIC_20 "RSCS/texture/wall/epic/wall_level3/frame_20.bmp"
# define LVL3_EPIC_21 "RSCS/texture/wall/epic/wall_level3/frame_21.bmp"
# define LVL3_EPIC_22 "RSCS/texture/wall/epic/wall_level3/frame_22.bmp"
# define LVL3_EPIC_23 "RSCS/texture/wall/epic/wall_level3/frame_23.bmp"
# define LVL3_EPIC_24 "RSCS/texture/wall/epic/wall_level3/frame_24.bmp"
# define LVL3_EPIC_25 "RSCS/texture/wall/epic/wall_level3/frame_25.bmp"
# define LVL3_EPIC_26 "RSCS/texture/wall/epic/wall_level3/frame_26.bmp"
# define LVL3_EPIC_27 "RSCS/texture/wall/epic/wall_level3/frame_27.bmp"
# define LVL3_EPIC_28 "RSCS/texture/wall/epic/wall_level3/frame_28.bmp"
# define LVL3_EPIC_29 "RSCS/texture/wall/epic/wall_level3/frame_29.bmp"
# define BUBBLE_0 "./RSCS/texture/bubble/bubble01.bmp"
# define BUBBLE_1 "./RSCS/texture/bubble/bubble02.bmp"
# define BUBBLE_2 "./RSCS/texture/bubble/bubble03.bmp"
# define BUBBLE_3 "./RSCS/texture/bubble/bubble04.bmp"
# define BUBBLE_4 "./RSCS/texture/bubble/bubble05.bmp"
# define BUBBLE_5 "./RSCS/texture/bubble/bubble06.bmp"
# define BUBBLE_6 "./RSCS/texture/bubble/bubble07.bmp"
# define BABA0 "./RSCS/story/intro/baba_00.bmp"
# define BABA1 "./RSCS/story/intro/baba_01.bmp"
# define BABA2 "./RSCS/story/intro/baba_02.bmp"
# define BABA3 "./RSCS/story/intro/baba_03.bmp"
# define BABA4 "./RSCS/story/intro/baba_04.bmp"
# define BABA5 "./RSCS/story/intro/baba_05.bmp"
# define RAG10 "./RSCS/texture/ragdoll/10.bmp"
# define RAG20 "./RSCS/texture/ragdoll/20.bmp"
# define RAG40 "./RSCS/texture/ragdoll/40.bmp"
# define RAG50 "./RSCS/texture/ragdoll/50.bmp"
# define MENU_MUSIC_PATH "./RSCS/sounds/menu.mp3"
# define INTRO_MUSIC_PATH "./RSCS/sounds/intro.mp3"
# define LEVEL1_MUSIC_PATH "./RSCS/sounds/Level1.mp3"
# define LEVEL2_MUSIC_PATH "./RSCS/sounds/Level2.mp3"
# define LEVEL3_MUSIC_PATH "./RSCS/sounds/Level3.mp3"
# define BOSS_MUSIC_PATH "./RSCS/sounds/final_boss.mp3"
# define TRAIN_MUSIC_PATH "./RSCS/sounds/train.mp3"
# define ARCADE_MUSIC_PATH "./RSCS/sounds/arcade_multi.mp3"
# define HEARTBEAT_EFFECT_PATH "./RSCS/sounds/heartbeat.mp3"
# define WALKING_EFFECT_PATH "./RSCS/sounds/walk.mp3"
# define RUNNING_EFFECT_PATH "./RSCS/sounds/run.mp3"
# define RAIN_EFFECT_PATH "./RSCS/sounds/rain.mp3"
# define FIRE_EFFECT_PATH "./RSCS/sounds/fire.mp3"
# define LOL_EFFECT_PATH "./RSCS/sounds/lol.mp3"
# define WATER_BREATHING_EFFECT_PATH "./RSCS/sounds/underwater_breathing.mp3"
# define GAMEOVER_EFFECT_PATH "./RSCS/sounds/gameover.mp3"
# define JUMP_EFFECT_PATH "./RSCS/sounds/jump.mp3"
# define PUNCH_EFFECT_PATH "./RSCS/sounds/punch.mp3"
# define DEVASTATOR_EFFECT_PATH "./RSCS/sounds/Devastator.mp3"
# define DEVASTATOR_RELOAD_EFFECT_PATH "./RSCS/sounds/Devastator_reload.mp3"
# define PISTOL_EFFECT_PATH "./RSCS/sounds/pistol.mp3"
# define PISTOL_RELOAD_EFFECT_PATH "./RSCS/sounds/pistol_reload.mp3"
# define PISTOL_EMPTY_EFFECT_PATH "./RSCS/sounds/pistol_empty.wav"
# define SHOTGUN_EFFECT_PATH "./RSCS/sounds/shotgun.wav"
# define SHOTGUN_LOAD_EFFECT_PATH "./RSCS/sounds/shotgun_load_one.mp3"
# define SHOTGUN_RELOAD_EFFECT_PATH "./RSCS/sounds/shotgun_reload_mag.mp3"
# define EXPLOSION_EFFECT_PATH "./RSCS/sounds/explosion.mp3"
# define ENEMY_1_EFFECT_PATH "./RSCS/sounds/enemy1_roar.mp3"
# define ENEMY_2_EFFECT_PATH "./RSCS/sounds/enemy2_roar.mp3"
# define ENEMY_3_EFFECT_PATH "./RSCS/sounds/enemy3_roar.mp3"
# define ENEMY_4_EFFECT_PATH "./RSCS/sounds/enemy4_roar.mp3"
# define ENEMY_BOSS_EFFECT_PATH "./RSCS/sounds/enemyboss_roar.mp3"
# define GAMEOVER_RETRY "./RSCS/gameover/tryagain.bmp"
# define GAMEOVER_RETURN "./RSCS/gameover/gofuckyourself.bmp"
# define BALLON_ON "./RSCS/hud/items_on/ballon.bmp"
# define BALLON_OFF "./RSCS/hud/items_off/ballon.bmp"
# define FIRE_ON "./RSCS/hud/items_on/fire.bmp"
# define FIRE_OFF "./RSCS/hud/items_off/fire.bmp"
# define LEGEND_ON "./RSCS/hud/items_on/legendary.bmp"
# define LEGEND_OFF "./RSCS/hud/items_off/legendary.bmp"
# define PISTOL_ON "./RSCS/hud/items_on/pistol.bmp"
# define PISTOL_OFF "./RSCS/hud/items_off/pistol.bmp"
# define SHOTGUN_ON "./RSCS/hud/items_on/shotgun.bmp"
# define SHOTGUN_OFF "./RSCS/hud/items_off/shotgun.bmp"
# define LOLLIPOP_ON "./RSCS/hud/items_on/lollipop.bmp"
# define LOLLIPOP_OFF "./RSCS/hud/items_off/lollipop.bmp"
# define TICKET_ON "./RSCS/hud/items_on/ticket.bmp"
# define TICKET_OFF "./RSCS/hud/items_off/ticket.bmp"
# define HG_GOD "./RSCS/hud/head_guy/godmode/stfgod0.bmp"
# define HG_100_P1 "./RSCS/hud/head_guy/100to80/stfst00.bmp"
# define HG_100_P2 "./RSCS/hud/head_guy/100to80/stfst01.bmp"
# define HG_100_P3 "./RSCS/hud/head_guy/100to80/stfst02.bmp"
# define HG_80_P1 "./RSCS/hud/head_guy/80to60/stfst10.bmp"
# define HG_80_P2 "./RSCS/hud/head_guy/80to60/stfst11.bmp"
# define HG_80_P3 "./RSCS/hud/head_guy/80to60/stfst12.bmp"
# define HG_60_P1 "./RSCS/hud/head_guy/60to40/stfst20.bmp"
# define HG_60_P2 "./RSCS/hud/head_guy/60to40/stfst21.bmp"
# define HG_60_P3 "./RSCS/hud/head_guy/60to40/stfst22.bmp"
# define HG_40_P1 "./RSCS/hud/head_guy/40to20/stfst30.bmp"
# define HG_40_P2 "./RSCS/hud/head_guy/40to20/stfst31.bmp"
# define HG_40_P3 "./RSCS/hud/head_guy/40to20/stfst32.bmp"
# define HG_20_P1 "./RSCS/hud/head_guy/20to10/stfst40.bmp"
# define HG_20_P2 "./RSCS/hud/head_guy/20to10/stfst41.bmp"
# define HG_20_P3 "./RSCS/hud/head_guy/20to10/stfst42.bmp"
# define HG_10 "./RSCS/hud/head_guy/10to00/stfdead0.bmp"
# define SKULL "./RSCS/hud/current_weapon.bmp"
# define DEV_1 "./RSCS/texture/weapons/devastator/devastator1.bmp"
# define DEV_RELOAD1 "./RSCS/texture/weapons/devastator/devastator2.bmp"
# define DEV_RELOAD2 "./RSCS/texture/weapons/devastator/devastator3.bmp"
# define DEV_SHOT1 "./RSCS/texture/weapons/devastator/devastator4.bmp"
# define DEV_SHOT2 "./RSCS/texture/weapons/devastator/devastator5.bmp"
# define DEV_SHOT3 "./RSCS/texture/weapons/devastator/devastator6.bmp"
# define DEV_SHOT4 "./RSCS/texture/weapons/devastator/devastator7.bmp"
# define DEV_SHOT5 "./RSCS/texture/weapons/devastator/devastator8.bmp"
# define DEV_SHOT6 "./RSCS/texture/weapons/devastator/devastator9.bmp"
# define DEV_FIRE_STAT1 "./RSCS/texture/weapons/devastator/fire5.bmp"
# define DEV_FIRE_STAT2 "./RSCS/texture/weapons/devastator/fire4.bmp"
# define DEV_FIRE_STAT3 "./RSCS/texture/weapons/devastator/fire3.bmp"
# define DEV_FIRE_STAT4 "./RSCS/texture/weapons/devastator/fire2.bmp"
# define DEV_FIRE_STAT5 "./RSCS/texture/weapons/devastator/fire1.bmp"
# define PISTOL_1 "./RSCS/texture/weapons/pistol/fire/fire1.bmp"
# define PISTOL_F_S1 "./RSCS/texture/weapons/pistol/fire/fire2.bmp"
# define PISTOL_F_S2 "./RSCS/texture/weapons/pistol/fire/fire3.bmp"
# define PISTOL_F_S3 "./RSCS/texture/weapons/pistol/fire/fire4.bmp"
# define PISTOL_F_S4 "./RSCS/texture/weapons/pistol/fire/fire5.bmp"
# define PISTOL_F_S5 "./RSCS/texture/weapons/pistol/fire/fire6.bmp"
# define PISTOL_RL_S1 "./RSCS/texture/weapons/pistol/reload/reload1.bmp"
# define PISTOL_RL_S2 "./RSCS/texture/weapons/pistol/reload/reload2.bmp"
# define PISTOL_RL_S3 "./RSCS/texture/weapons/pistol/reload/reload3.bmp"
# define PISTOL_RL_S4 "./RSCS/texture/weapons/pistol/reload/reload4.bmp"
# define PISTOL_RL_S5 "./RSCS/texture/weapons/pistol/reload/reload5.bmp"
# define PISTOL_RL_S6 "./RSCS/texture/weapons/pistol/reload/reload6.bmp"
# define PISTOL_RL_S7 "./RSCS/texture/weapons/pistol/reload/reload7.bmp"
# define PISTOL_RL_S8 "./RSCS/texture/weapons/pistol/reload/reload8.bmp"
# define PISTOL_RL_S9 "./RSCS/texture/weapons/pistol/reload/reload9.bmp"
# define PISTOL_RL_S10 "./RSCS/texture/weapons/pistol/reload/reload10.bmp"
# define PISTOL_RL_S11 "./RSCS/texture/weapons/pistol/reload/reload11.bmp"
# define PISTOL_RL_S12 "./RSCS/texture/weapons/pistol/reload/reload12.bmp"
# define SHOTGUN_1 "./RSCS/texture/weapons/shotgun/fire/fire1.bmp"
# define SHOTGUN_F_S1 "./RSCS/texture/weapons/shotgun/fire/fire2.bmp"
# define SHOTGUN_F_S2 "./RSCS/texture/weapons/shotgun/fire/fire3.bmp"
# define SHOTGUN_L_S1 "./RSCS/texture/weapons/shotgun/load/load1.bmp"
# define SHOTGUN_L_S2 "./RSCS/texture/weapons/shotgun/load/load2.bmp"
# define SHOTGUN_L_S3 "./RSCS/texture/weapons/shotgun/load/load3.bmp"
# define SHOTGUN_L_S4 "./RSCS/texture/weapons/shotgun/load/load4.bmp"
# define SHOTGUN_L_S5 "./RSCS/texture/weapons/shotgun/load/load5.bmp"
# define SHOTGUN_RL_S1 "./RSCS/texture/weapons/shotgun/reload/reload1.bmp"
# define SHOTGUN_RL_S2 "./RSCS/texture/weapons/shotgun/reload/reload2.bmp"
# define SHOTGUN_RL_S3 "./RSCS/texture/weapons/shotgun/reload/reload3.bmp"
# define SHOTGUN_RL_S4 "./RSCS/texture/weapons/shotgun/reload/reload4.bmp"
# define SHOTGUN_RL_S5 "./RSCS/texture/weapons/shotgun/reload/reload5.bmp"
# define SHOTGUN_RL_S6 "./RSCS/texture/weapons/shotgun/reload/reload6.bmp"
# define SHOTGUN_RL_S7 "./RSCS/texture/weapons/shotgun/reload/reload7.bmp"
# define SHOTGUN_RL_S8 "./RSCS/texture/weapons/shotgun/reload/reload8.bmp"
# define SHOTGUN_RL_S9 "./RSCS/texture/weapons/shotgun/reload/reload9.bmp"
# define SHOTGUN_RL_S10 "./RSCS/texture/weapons/shotgun/reload/reload10.bmp"
# define SHOTGUN_RL_S11 "./RSCS/texture/weapons/shotgun/reload/reload11.bmp"
# define SHOTGUN_RL_S12 "./RSCS/texture/weapons/shotgun/reload/reload12.bmp"
# define SHOTGUN_RL_S13 "./RSCS/texture/weapons/shotgun/reload/reload13.bmp"
# define SHOTGUN_RL_S14 "./RSCS/texture/weapons/shotgun/reload/reload14.bmp"
# define SHOTGUN_RL_S15 "./RSCS/texture/weapons/shotgun/reload/reload15.bmp"
# define SHOTGUN_RL_S16 "./RSCS/texture/weapons/shotgun/reload/reload16.bmp"
# define SHOTGUN_RL_S17 "./RSCS/texture/weapons/shotgun/reload/reload17.bmp"
# define FIST_1 "./RSCS/texture/weapons/punch/idle/idle.bmp"
# define LEFT_PUNCH_S1 "./RSCS/texture/weapons/punch/left_punch/left1.bmp"
# define LEFT_PUNCH_S2 "./RSCS/texture/weapons/punch/left_punch/left2.bmp"
# define LEFT_PUNCH_S3 "./RSCS/texture/weapons/punch/left_punch/left3.bmp"
# define RIGHT_PUNCH_S1 "./RSCS/texture/weapons/punch/right_punch/right1.bmp"
# define RIGHT_PUNCH_S2 "./RSCS/texture/weapons/punch/right_punch/right2.bmp"
# define RIGHT_PUNCH_S3 "./RSCS/texture/weapons/punch/right_punch/right3.bmp"
# define KICK_STAT1 "./RSCS/texture/weapons/punch/kick/kick1.bmp"
# define KICK_STAT2 "./RSCS/texture/weapons/punch/kick/kick2.bmp"
# define STORY_LVL1_1 "./RSCS/story/level1/1.bmp"
# define STORY_LVL1_2 "./RSCS/story/level1/2.bmp"
# define STORY_LVL1_3 "./RSCS/story/level1/3.bmp"
# define STORY_LVL1_4 "./RSCS/story/level1/4.bmp"
# define STORY_LVL1_5 "./RSCS/story/level1/5.bmp"
# define STORY_LVL1_6 "./RSCS/story/level1/6.bmp"
# define STORY_LVL2 "./RSCS/story/level2/level2.bmp"
# define STORY_LVL3 "./RSCS/story/level3/level3.bmp"
# define CREDITS "./RSCS/story/credits/credits.bmp"
# define STORYLINE_1_1 "You are disappointing me Sergei"
# define STORYLINE_1_2 "You didn't kill them all!"
# define STORYLINE_1_3 "I can give you back what you want!"
# define STORYLINE_1_4 "If you follow the path to your inner soul"
# define STORYLINE_1_5 "And find a way to end this"
# define STORYLINE_2_1 "You missed something again..."
# define STORYLINE_2_2 "Are you fighting my hold on you ?"
# define STORYLINE_2_3 "hahahahaha"
# define STORYLINE_2_4 "Face the biggest fears of your mind!"
# define STORYLINE_3_1 "I can see that you are trying to fight me."
# define STORYLINE_3_2 "The Angel of Death will kill you anyway..."
# define STORYLINE_3_3 "hahahahahah"
# define DOOR_CLOSE "RSCS/texture/doors/normal/doors_close.bmp"
# define DOOR_OPEN "RSCS/texture/doors/normal/doors_open.bmp"

# define WARP_NXT_FLOOR_1 "RSCS/texture/warp/nextlevel/frame_01.bmp"
# define WARP_NXT_FLOOR_2 "RSCS/texture/warp/nextlevel/frame_02.bmp"
# define WARP_NXT_FLOOR_3 "RSCS/texture/warp/nextlevel/frame_03.bmp"
# define WARP_NXT_FLOOR_4 "RSCS/texture/warp/nextlevel/frame_04.bmp"
# define WARP_NXT_FLOOR_5 "RSCS/texture/warp/nextlevel/frame_05.bmp"
# define WARP_NXT_FLOOR_6 "RSCS/texture/warp/nextlevel/frame_06.bmp"
# define WARP_NXT_FLOOR_7 "RSCS/texture/warp/nextlevel/frame_07.bmp"
# define WARP_NXT_FLOOR_8 "RSCS/texture/warp/nextlevel/frame_08.bmp"
# define WARP_NXT_FLOOR_9 "RSCS/texture/warp/nextlevel/frame_09.bmp"
# define WARP_NXT_FLOOR_10 "RSCS/texture/warp/nextlevel/frame_10.bmp"
# define WARP_NXT_FLOOR_11 "RSCS/texture/warp/nextlevel/frame_11.bmp"
# define WARP_NXT_FLOOR_12 "RSCS/texture/warp/nextlevel/frame_12.bmp"
# define WARP_NXT_FLOOR_13 "RSCS/texture/warp/nextlevel/frame_13.bmp"
# define WARP_NXT_FLOOR_14 "RSCS/texture/warp/nextlevel/frame_14.bmp"
# define WARP_NXT_FLOOR_15 "RSCS/texture/warp/nextlevel/frame_15.bmp"
# define WARP_NXT_FLOOR_16 "RSCS/texture/warp/nextlevel/frame_16.bmp"
# define WARP_NXT_FLOOR_17 "RSCS/texture/warp/nextlevel/frame_17.bmp"
# define WARP_NXT_FLOOR_18 "RSCS/texture/warp/nextlevel/frame_18.bmp"
# define WARP_NXT_FLOOR_19 "RSCS/texture/warp/nextlevel/frame_19.bmp"
# define WARP_NXT_FLOOR_20 "RSCS/texture/warp/nextlevel/frame_20.bmp"
# define WARP_NXT_FLOOR_21 "RSCS/texture/warp/nextlevel/frame_21.bmp"
# define WARP_NXT_FLOOR_22 "RSCS/texture/warp/nextlevel/frame_22.bmp"
# define WARP_NXT_FLOOR_23 "RSCS/texture/warp/nextlevel/frame_23.bmp"

# define WARP_TO_WARP_1 "RSCS/texture/warp/randomwarp/randomwarp_1.bmp"
# define WARP_TO_WARP_2 "RSCS/texture/warp/randomwarp/randomwarp_2.bmp"
# define WARP_TO_WARP_3 "RSCS/texture/warp/randomwarp/randomwarp_3.bmp"
# define WARP_TO_WARP_4 "RSCS/texture/warp/randomwarp/randomwarp_4.bmp"
# define WARP_TO_WARP_5 "RSCS/texture/warp/randomwarp/randomwarp_5.bmp"
# define WARP_TO_WARP_6 "RSCS/texture/warp/randomwarp/randomwarp_6.bmp"
# define WARP_TO_WARP_7 "RSCS/texture/warp/randomwarp/randomwarp_7.bmp"
# define WARP_TO_WARP_8 "RSCS/texture/warp/randomwarp/randomwarp_8.bmp"
# define WARP_TO_WARP_9 "RSCS/texture/warp/randomwarp/randomwarp_9.bmp"
# define WARP_TO_WARP_10 "RSCS/texture/warp/randomwarp/randomwarp_10.bmp"
# define WARP_TO_WARP_11 "RSCS/texture/warp/randomwarp/randomwarp_11.bmp"
# define WARP_TO_WARP_12 "RSCS/texture/warp/randomwarp/randomwarp_12.bmp"

# define SPR_BALLOON "./RSCS/texture/balloon/balloon.bmp"
# define SPR_LOLLIPOP "./RSCS/texture/lollipop/lollipop.bmp"
# define SPR_TICKET "./RSCS/texture/ticket/ticket.bmp"

# define SPR_MEDKIT_10_1 "./RSCS/texture/medkit/medkit10/medkit10_1.bmp"
# define SPR_MEDKIT_10_2 "./RSCS/texture/medkit/medkit10/medkit10_2.bmp"
# define SPR_MEDKIT_10_3 "./RSCS/texture/medkit/medkit10/medkit10_3.bmp"
# define SPR_MEDKIT_10_4 "./RSCS/texture/medkit/medkit10/medkit10_4.bmp"
# define SPR_MEDKIT_20_1 "./RSCS/texture/medkit/medkit20/medkit20_left.bmp"
# define SPR_MEDKIT_20_2 "./RSCS/texture/medkit/medkit20/medkit20_right.bmp"
# define SPR_MEDKIT_50_1 "./RSCS/texture/medkit/medkit50/medkit50_close.bmp"
# define SPR_MEDKIT_50_2 "./RSCS/texture/medkit/medkit50/medkit50_open.bmp"

# define SPR_TORCH_F_OFF "./RSCS/texture/torch/front/torch_front_off.bmp"
# define SPR_TORCH_F_ON1 "./RSCS/texture/torch/front/torch_front_on1.bmp"
# define SPR_TORCH_F_ON2 "./RSCS/texture/torch/front/torch_front_on2.bmp"
# define SPR_TORCH_F_ON3 "./RSCS/texture/torch/front/torch_front_on3.bmp"
# define SPR_TORCH_F_ON4 "./RSCS/texture/torch/front/torch_front_on4.bmp"
# define SPR_TORCH_F_ON5 "./RSCS/texture/torch/front/torch_front_on5.bmp"
# define SPR_TORCH_F_ON6 "./RSCS/texture/torch/front/torch_front_on6.bmp"
# define SPR_TORCH_L_OFF "./RSCS/texture/torch/left/torch_left_off.bmp"
# define SPR_TORCH_L_ON1 "./RSCS/texture/torch/left/torch_left_on1.bmp"
# define SPR_TORCH_L_ON2 "./RSCS/texture/torch/left/torch_left_on2.bmp"
# define SPR_TORCH_L_ON3 "./RSCS/texture/torch/left/torch_left_on3.bmp"
# define SPR_TORCH_L_ON4 "./RSCS/texture/torch/left/torch_left_on4.bmp"
# define SPR_TORCH_L_ON5 "./RSCS/texture/torch/left/torch_left_on5.bmp"
# define SPR_TORCH_L_ON6 "./RSCS/texture/torch/left/torch_left_on6.bmp"
# define SPR_TORCH_R_OFF "./RSCS/texture/torch/right/torch_right_off.bmp"
# define SPR_TORCH_R_ON1 "./RSCS/texture/torch/right/torch_right_on1.bmp"
# define SPR_TORCH_R_ON2 "./RSCS/texture/torch/right/torch_right_on2.bmp"
# define SPR_TORCH_R_ON3 "./RSCS/texture/torch/right/torch_right_on3.bmp"
# define SPR_TORCH_R_ON4 "./RSCS/texture/torch/right/torch_right_on4.bmp"
# define SPR_TORCH_R_ON5 "./RSCS/texture/torch/right/torch_right_on5.bmp"
# define SPR_TORCH_R_ON6 "./RSCS/texture/torch/right/torch_right_on6.bmp"

# define SPR_PISTOL	"./RSCS/texture/weapons/pistol_sprite.bmp"
# define SPR_SHOTGUN	"./RSCS/texture/weapons/shotgun_sprite.bmp"
# define SPR_DEVASTATOR	"./RSCS/texture/weapons/devastator_sprite.bmp"
# define SPR_AMMO_PISTOL "./RSCS/texture/ammo/pistol/ammo_pistol.bmp"
# define SPR_AMMO_SHOTGUN "./RSCS/texture/ammo/shotgun/ammo_shotgun.bmp"
# define SPR_AMMO_DEVAST "./RSCS/texture/ammo/devastator/ammo_devastator.bmp"

# define SPR_PROJ_DEVAST_F "./RSCS/texture/projectile/proj_devastator_1.bmp"
# define SPR_PROJ_DEVAST_F_L "./RSCS/texture/projectile/proj_devastator_2.bmp"
# define SPR_PROJ_DEVAST_L "./RSCS/texture/projectile/proj_devastator_3.bmp"
# define SPR_PROJ_DEVAST_B_L "./RSCS/texture/projectile/proj_devastator_4.bmp"
# define SPR_PROJ_DEVAST_B "./RSCS/texture/projectile/proj_devastator_5.bmp"
# define SPR_PROJ_DEVAST_B_R "./RSCS/texture/projectile/proj_devastator_6.bmp"
# define SPR_PROJ_DEVAST_R "./RSCS/texture/projectile/proj_devastator_7.bmp"
# define SPR_PROJ_DEVAST_F_R "./RSCS/texture/projectile/proj_devastator_8.bmp"

# define SPR_PROJ_ENEMY_3 "./RSCS/texture/projectile/red_energy_ball.bmp"
# define SPR_PROJ_ENEMY_4 "./RSCS/texture/projectile/purple_energy_ball.bmp"
# define SPR_PROJ_ENEMY_BOSS "./RSCS/texture/projectile/green_energy_ball.bmp"

# define SPR_ENMY1_F_1	"./RSCS/texture/enemies/1/front/front1.bmp"
# define SPR_ENMY1_F_2	"./RSCS/texture/enemies/1/front/front2.bmp"
# define SPR_ENMY1_F_3	"./RSCS/texture/enemies/1/front/front3.bmp"
# define SPR_ENMY1_F_4	"./RSCS/texture/enemies/1/front/front4.bmp"
# define SPR_ENMY1_F_5	"./RSCS/texture/enemies/1/front/front5.bmp"
# define SPR_ENMY1_F_L_1 "./RSCS/texture/enemies/1/front_left/front_left1.bmp"
# define SPR_ENMY1_F_L_2 "./RSCS/texture/enemies/1/front_left/front_left2.bmp"
# define SPR_ENMY1_F_L_3 "./RSCS/texture/enemies/1/front_left/front_left3.bmp"
# define SPR_ENMY1_F_L_4 "./RSCS/texture/enemies/1/front_left/front_left4.bmp"
# define SPR_ENMY1_F_L_5 "./RSCS/texture/enemies/1/front_left/front_left5.bmp"
# define SPR_ENMY1_L_1 "./RSCS/texture/enemies/1/left/left1.bmp"
# define SPR_ENMY1_L_2 "./RSCS/texture/enemies/1/left/left2.bmp"
# define SPR_ENMY1_L_3 "./RSCS/texture/enemies/1/left/left3.bmp"
# define SPR_ENMY1_L_4 "./RSCS/texture/enemies/1/left/left4.bmp"
# define SPR_ENMY1_L_5 "./RSCS/texture/enemies/1/left/left5.bmp"
# define SPR_ENMY1_B_L_1 "./RSCS/texture/enemies/1/back_left/back_left1.bmp"
# define SPR_ENMY1_B_L_2 "./RSCS/texture/enemies/1/back_left/back_left2.bmp"
# define SPR_ENMY1_B_L_3 "./RSCS/texture/enemies/1/back_left/back_left3.bmp"
# define SPR_ENMY1_B_L_4 "./RSCS/texture/enemies/1/back_left/back_left4.bmp"
# define SPR_ENMY1_B_L_5 "./RSCS/texture/enemies/1/back_left/back_left5.bmp"
# define SPR_ENMY1_B_1 "./RSCS/texture/enemies/1/back/back1.bmp"
# define SPR_ENMY1_B_2 "./RSCS/texture/enemies/1/back/back2.bmp"
# define SPR_ENMY1_B_3 "./RSCS/texture/enemies/1/back/back3.bmp"
# define SPR_ENMY1_B_4 "./RSCS/texture/enemies/1/back/back4.bmp"
# define SPR_ENMY1_B_5 "./RSCS/texture/enemies/1/back/back5.bmp"
# define SPR_ENMY1_B_R_1 "./RSCS/texture/enemies/1/back_right/back_right1.bmp"
# define SPR_ENMY1_B_R_2 "./RSCS/texture/enemies/1/back_right/back_right2.bmp"
# define SPR_ENMY1_B_R_3 "./RSCS/texture/enemies/1/back_right/back_right3.bmp"
# define SPR_ENMY1_B_R_4 "./RSCS/texture/enemies/1/back_right/back_right4.bmp"
# define SPR_ENMY1_B_R_5 "./RSCS/texture/enemies/1/back_right/back_right5.bmp"
# define SPR_ENMY1_R_1 "./RSCS/texture/enemies/1/right/right1.bmp"
# define SPR_ENMY1_R_2 "./RSCS/texture/enemies/1/right/right2.bmp"
# define SPR_ENMY1_R_3 "./RSCS/texture/enemies/1/right/right3.bmp"
# define SPR_ENMY1_R_4 "./RSCS/texture/enemies/1/right/right4.bmp"
# define SPR_ENMY1_R_5 "./RSCS/texture/enemies/1/right/right5.bmp"
# define SPR_ENMY1_F_R_1 "./RSCS/texture/enemies/1/front_right/front_right1.bmp"
# define SPR_ENMY1_F_R_2 "./RSCS/texture/enemies/1/front_right/front_right2.bmp"
# define SPR_ENMY1_F_R_3 "./RSCS/texture/enemies/1/front_right/front_right3.bmp"
# define SPR_ENMY1_F_R_4 "./RSCS/texture/enemies/1/front_right/front_right4.bmp"
# define SPR_ENMY1_F_R_5 "./RSCS/texture/enemies/1/front_right/front_right5.bmp"

# define SPR_ENMY1_DEAD_1 "./RSCS/texture/enemies/1/death/death1.bmp"
# define SPR_ENMY1_DEAD_2 "./RSCS/texture/enemies/1/death/death2.bmp"
# define SPR_ENMY1_DEAD_3 "./RSCS/texture/enemies/1/death/death3.bmp"
# define SPR_ENMY1_DEAD_4 "./RSCS/texture/enemies/1/death/death4.bmp"
# define SPR_ENMY1_DEAD_5 "./RSCS/texture/enemies/1/death/death5.bmp"
# define SPR_ENMY1_DEAD_6 "./RSCS/texture/enemies/1/death/death6.bmp"
# define SPR_ENMY1_DEAD_7 "./RSCS/texture/enemies/1/death/death7.bmp"

# define SPR_ENMY_2_F_1 "./RSCS/texture/enemies/2/Front/0000.bmp"
# define SPR_ENMY_2_F_2 "./RSCS/texture/enemies/2/Front/0020.bmp"
# define SPR_ENMY_2_F_3 "./RSCS/texture/enemies/2/Front/0022.bmp"
# define SPR_ENMY_2_F_4 "./RSCS/texture/enemies/2/Front/0024.bmp"
# define SPR_ENMY_2_F_5 "./RSCS/texture/enemies/2/Front/0026.bmp"
# define SPR_ENMY_2_F_6 "./RSCS/texture/enemies/2/Front/0028.bmp"
# define SPR_ENMY_2_F_7 "./RSCS/texture/enemies/2/Front/0030.bmp"
# define SPR_ENMY_2_F_8 "./RSCS/texture/enemies/2/Front/0032.bmp"
# define SPR_ENMY_2_F_9 "./RSCS/texture/enemies/2/Front/0034.bmp"
# define SPR_ENMY_2_F_10 "./RSCS/texture/enemies/2/Front/0036.bmp"
# define SPR_ENMY_2_F_11 "./RSCS/texture/enemies/2/Front/0038.bmp"
# define SPR_ENMY_2_F_12 "./RSCS/texture/enemies/2/Front/0040.bmp"
# define SPR_ENMY_2_F_13 "./RSCS/texture/enemies/2/Front/0104.bmp"
# define SPR_ENMY_2_F_14 "./RSCS/texture/enemies/2/Front/0108.bmp"
# define SPR_ENMY_2_F_15 "./RSCS/texture/enemies/2/Front/0106.bmp"
# define SPR_ENMY_2_F_16 "./RSCS/texture/enemies/2/Front/0110.bmp"
# define SPR_ENMY_2_F_17 "./RSCS/texture/enemies/2/Front/0112.bmp"
# define SPR_ENMY_2_F_18 "./RSCS/texture/enemies/2/Front/0114.bmp"
# define SPR_ENMY_2_F_19 "./RSCS/texture/enemies/2/Front/0116.bmp"
# define SPR_ENMY_2_F_20 "./RSCS/texture/enemies/2/Front/0118.bmp"

# define SPR_ENMY_2_F_L_1 "./RSCS/texture/enemies/2/FrontLeft/0000.bmp"
# define SPR_ENMY_2_F_L_2 "./RSCS/texture/enemies/2/FrontLeft/0020.bmp"
# define SPR_ENMY_2_F_L_3 "./RSCS/texture/enemies/2/FrontLeft/0022.bmp"
# define SPR_ENMY_2_F_L_4 "./RSCS/texture/enemies/2/FrontLeft/0024.bmp"
# define SPR_ENMY_2_F_L_5 "./RSCS/texture/enemies/2/FrontLeft/0026.bmp"
# define SPR_ENMY_2_F_L_6 "./RSCS/texture/enemies/2/FrontLeft/0028.bmp"
# define SPR_ENMY_2_F_L_7 "./RSCS/texture/enemies/2/FrontLeft/0030.bmp"
# define SPR_ENMY_2_F_L_8 "./RSCS/texture/enemies/2/FrontLeft/0032.bmp"
# define SPR_ENMY_2_F_L_9 "./RSCS/texture/enemies/2/FrontLeft/0034.bmp"
# define SPR_ENMY_2_F_L_10 "./RSCS/texture/enemies/2/FrontLeft/0036.bmp"
# define SPR_ENMY_2_F_L_11 "./RSCS/texture/enemies/2/FrontLeft/0038.bmp"
# define SPR_ENMY_2_F_L_12 "./RSCS/texture/enemies/2/FrontLeft/0040.bmp"
# define SPR_ENMY_2_F_L_13 "./RSCS/texture/enemies/2/FrontLeft/0104.bmp"
# define SPR_ENMY_2_F_L_14 "./RSCS/texture/enemies/2/FrontLeft/0108.bmp"
# define SPR_ENMY_2_F_L_15 "./RSCS/texture/enemies/2/FrontLeft/0106.bmp"
# define SPR_ENMY_2_F_L_16 "./RSCS/texture/enemies/2/FrontLeft/0110.bmp"
# define SPR_ENMY_2_F_L_17 "./RSCS/texture/enemies/2/FrontLeft/0112.bmp"
# define SPR_ENMY_2_F_L_18 "./RSCS/texture/enemies/2/FrontLeft/0114.bmp"
# define SPR_ENMY_2_F_L_19 "./RSCS/texture/enemies/2/FrontLeft/0116.bmp"
# define SPR_ENMY_2_F_L_20 "./RSCS/texture/enemies/2/FrontLeft/0118.bmp"

# define SPR_ENMY_2_L_1 "./RSCS/texture/enemies/2/Left/0000.bmp"
# define SPR_ENMY_2_L_2 "./RSCS/texture/enemies/2/Left/0020.bmp"
# define SPR_ENMY_2_L_3 "./RSCS/texture/enemies/2/Left/0022.bmp"
# define SPR_ENMY_2_L_4 "./RSCS/texture/enemies/2/Left/0024.bmp"
# define SPR_ENMY_2_L_5 "./RSCS/texture/enemies/2/Left/0026.bmp"
# define SPR_ENMY_2_L_6 "./RSCS/texture/enemies/2/Left/0028.bmp"
# define SPR_ENMY_2_L_7 "./RSCS/texture/enemies/2/Left/0030.bmp"
# define SPR_ENMY_2_L_8 "./RSCS/texture/enemies/2/Left/0032.bmp"
# define SPR_ENMY_2_L_9 "./RSCS/texture/enemies/2/Left/0034.bmp"
# define SPR_ENMY_2_L_10 "./RSCS/texture/enemies/2/Left/0036.bmp"
# define SPR_ENMY_2_L_11 "./RSCS/texture/enemies/2/Left/0038.bmp"
# define SPR_ENMY_2_L_12 "./RSCS/texture/enemies/2/Left/0040.bmp"
# define SPR_ENMY_2_L_13 "./RSCS/texture/enemies/2/Left/0104.bmp"
# define SPR_ENMY_2_L_14 "./RSCS/texture/enemies/2/Left/0108.bmp"
# define SPR_ENMY_2_L_15 "./RSCS/texture/enemies/2/Left/0106.bmp"
# define SPR_ENMY_2_L_16 "./RSCS/texture/enemies/2/Left/0110.bmp"
# define SPR_ENMY_2_L_17 "./RSCS/texture/enemies/2/Left/0112.bmp"
# define SPR_ENMY_2_L_18 "./RSCS/texture/enemies/2/Left/0114.bmp"
# define SPR_ENMY_2_L_19 "./RSCS/texture/enemies/2/Left/0116.bmp"
# define SPR_ENMY_2_L_20 "./RSCS/texture/enemies/2/Left/0118.bmp"

# define SPR_ENMY_2_B_L_1 "./RSCS/texture/enemies/2/BackLeft/0000.bmp"
# define SPR_ENMY_2_B_L_2 "./RSCS/texture/enemies/2/BackLeft/0020.bmp"
# define SPR_ENMY_2_B_L_3 "./RSCS/texture/enemies/2/BackLeft/0022.bmp"
# define SPR_ENMY_2_B_L_4 "./RSCS/texture/enemies/2/BackLeft/0024.bmp"
# define SPR_ENMY_2_B_L_5 "./RSCS/texture/enemies/2/BackLeft/0026.bmp"
# define SPR_ENMY_2_B_L_6 "./RSCS/texture/enemies/2/BackLeft/0028.bmp"
# define SPR_ENMY_2_B_L_7 "./RSCS/texture/enemies/2/BackLeft/0030.bmp"
# define SPR_ENMY_2_B_L_8 "./RSCS/texture/enemies/2/BackLeft/0032.bmp"
# define SPR_ENMY_2_B_L_9 "./RSCS/texture/enemies/2/BackLeft/0034.bmp"
# define SPR_ENMY_2_B_L_10 "./RSCS/texture/enemies/2/BackLeft/0036.bmp"
# define SPR_ENMY_2_B_L_11 "./RSCS/texture/enemies/2/BackLeft/0038.bmp"
# define SPR_ENMY_2_B_L_12 "./RSCS/texture/enemies/2/BackLeft/0040.bmp"
# define SPR_ENMY_2_B_L_13 "./RSCS/texture/enemies/2/BackLeft/0104.bmp"
# define SPR_ENMY_2_B_L_14 "./RSCS/texture/enemies/2/BackLeft/0108.bmp"
# define SPR_ENMY_2_B_L_15 "./RSCS/texture/enemies/2/BackLeft/0106.bmp"
# define SPR_ENMY_2_B_L_16 "./RSCS/texture/enemies/2/BackLeft/0110.bmp"
# define SPR_ENMY_2_B_L_17 "./RSCS/texture/enemies/2/BackLeft/0112.bmp"
# define SPR_ENMY_2_B_L_18 "./RSCS/texture/enemies/2/BackLeft/0114.bmp"
# define SPR_ENMY_2_B_L_19 "./RSCS/texture/enemies/2/BackLeft/0116.bmp"
# define SPR_ENMY_2_B_L_20 "./RSCS/texture/enemies/2/BackLeft/0118.bmp"

# define SPR_ENMY_2_B_1 "./RSCS/texture/enemies/2/Back/0000.bmp"
# define SPR_ENMY_2_B_2 "./RSCS/texture/enemies/2/Back/0020.bmp"
# define SPR_ENMY_2_B_3 "./RSCS/texture/enemies/2/Back/0022.bmp"
# define SPR_ENMY_2_B_4 "./RSCS/texture/enemies/2/Back/0024.bmp"
# define SPR_ENMY_2_B_5 "./RSCS/texture/enemies/2/Back/0026.bmp"
# define SPR_ENMY_2_B_6 "./RSCS/texture/enemies/2/Back/0028.bmp"
# define SPR_ENMY_2_B_7 "./RSCS/texture/enemies/2/Back/0030.bmp"
# define SPR_ENMY_2_B_8 "./RSCS/texture/enemies/2/Back/0032.bmp"
# define SPR_ENMY_2_B_9 "./RSCS/texture/enemies/2/Back/0034.bmp"
# define SPR_ENMY_2_B_10 "./RSCS/texture/enemies/2/Back/0036.bmp"
# define SPR_ENMY_2_B_11 "./RSCS/texture/enemies/2/Back/0038.bmp"
# define SPR_ENMY_2_B_12 "./RSCS/texture/enemies/2/Back/0040.bmp"
# define SPR_ENMY_2_B_13 "./RSCS/texture/enemies/2/Back/0104.bmp"
# define SPR_ENMY_2_B_14 "./RSCS/texture/enemies/2/Back/0108.bmp"
# define SPR_ENMY_2_B_15 "./RSCS/texture/enemies/2/Back/0106.bmp"
# define SPR_ENMY_2_B_16 "./RSCS/texture/enemies/2/Back/0110.bmp"
# define SPR_ENMY_2_B_17 "./RSCS/texture/enemies/2/Back/0112.bmp"
# define SPR_ENMY_2_B_18 "./RSCS/texture/enemies/2/Back/0114.bmp"
# define SPR_ENMY_2_B_19 "./RSCS/texture/enemies/2/Back/0116.bmp"
# define SPR_ENMY_2_B_20 "./RSCS/texture/enemies/2/Back/0118.bmp"

# define SPR_ENMY_2_B_R_1 "./RSCS/texture/enemies/2/BackRight/0000.bmp"
# define SPR_ENMY_2_B_R_2 "./RSCS/texture/enemies/2/BackRight/0020.bmp"
# define SPR_ENMY_2_B_R_3 "./RSCS/texture/enemies/2/BackRight/0022.bmp"
# define SPR_ENMY_2_B_R_4 "./RSCS/texture/enemies/2/BackRight/0024.bmp"
# define SPR_ENMY_2_B_R_5 "./RSCS/texture/enemies/2/BackRight/0026.bmp"
# define SPR_ENMY_2_B_R_6 "./RSCS/texture/enemies/2/BackRight/0028.bmp"
# define SPR_ENMY_2_B_R_7 "./RSCS/texture/enemies/2/BackRight/0030.bmp"
# define SPR_ENMY_2_B_R_8 "./RSCS/texture/enemies/2/BackRight/0032.bmp"
# define SPR_ENMY_2_B_R_9 "./RSCS/texture/enemies/2/BackRight/0034.bmp"
# define SPR_ENMY_2_B_R_10 "./RSCS/texture/enemies/2/BackRight/0036.bmp"
# define SPR_ENMY_2_B_R_11 "./RSCS/texture/enemies/2/BackRight/0038.bmp"
# define SPR_ENMY_2_B_R_12 "./RSCS/texture/enemies/2/BackRight/0040.bmp"
# define SPR_ENMY_2_B_R_13 "./RSCS/texture/enemies/2/BackRight/0104.bmp"
# define SPR_ENMY_2_B_R_14 "./RSCS/texture/enemies/2/BackRight/0108.bmp"
# define SPR_ENMY_2_B_R_15 "./RSCS/texture/enemies/2/BackRight/0106.bmp"
# define SPR_ENMY_2_B_R_16 "./RSCS/texture/enemies/2/BackRight/0110.bmp"
# define SPR_ENMY_2_B_R_17 "./RSCS/texture/enemies/2/BackRight/0112.bmp"
# define SPR_ENMY_2_B_R_18 "./RSCS/texture/enemies/2/BackRight/0114.bmp"
# define SPR_ENMY_2_B_R_19 "./RSCS/texture/enemies/2/BackRight/0116.bmp"
# define SPR_ENMY_2_B_R_20 "./RSCS/texture/enemies/2/BackRight/0118.bmp"

# define SPR_ENMY_2_R_1 "./RSCS/texture/enemies/2/Right/0000.bmp"
# define SPR_ENMY_2_R_2 "./RSCS/texture/enemies/2/Right/0020.bmp"
# define SPR_ENMY_2_R_3 "./RSCS/texture/enemies/2/Right/0022.bmp"
# define SPR_ENMY_2_R_4 "./RSCS/texture/enemies/2/Right/0024.bmp"
# define SPR_ENMY_2_R_5 "./RSCS/texture/enemies/2/Right/0026.bmp"
# define SPR_ENMY_2_R_6 "./RSCS/texture/enemies/2/Right/0028.bmp"
# define SPR_ENMY_2_R_7 "./RSCS/texture/enemies/2/Right/0030.bmp"
# define SPR_ENMY_2_R_8 "./RSCS/texture/enemies/2/Right/0032.bmp"
# define SPR_ENMY_2_R_9 "./RSCS/texture/enemies/2/Right/0034.bmp"
# define SPR_ENMY_2_R_10 "./RSCS/texture/enemies/2/Right/0036.bmp"
# define SPR_ENMY_2_R_11 "./RSCS/texture/enemies/2/Right/0038.bmp"
# define SPR_ENMY_2_R_12 "./RSCS/texture/enemies/2/Right/0040.bmp"
# define SPR_ENMY_2_R_13 "./RSCS/texture/enemies/2/Right/0104.bmp"
# define SPR_ENMY_2_R_14 "./RSCS/texture/enemies/2/Right/0108.bmp"
# define SPR_ENMY_2_R_15 "./RSCS/texture/enemies/2/Right/0106.bmp"
# define SPR_ENMY_2_R_16 "./RSCS/texture/enemies/2/Right/0110.bmp"
# define SPR_ENMY_2_R_17 "./RSCS/texture/enemies/2/Right/0112.bmp"
# define SPR_ENMY_2_R_18 "./RSCS/texture/enemies/2/Right/0114.bmp"
# define SPR_ENMY_2_R_19 "./RSCS/texture/enemies/2/Right/0116.bmp"
# define SPR_ENMY_2_R_20 "./RSCS/texture/enemies/2/Right/0118.bmp"

# define SPR_ENMY_2_F_R_1 "./RSCS/texture/enemies/2/FrontRight/0000.bmp"
# define SPR_ENMY_2_F_R_2 "./RSCS/texture/enemies/2/FrontRight/0020.bmp"
# define SPR_ENMY_2_F_R_3 "./RSCS/texture/enemies/2/FrontRight/0022.bmp"
# define SPR_ENMY_2_F_R_4 "./RSCS/texture/enemies/2/FrontRight/0024.bmp"
# define SPR_ENMY_2_F_R_5 "./RSCS/texture/enemies/2/FrontRight/0026.bmp"
# define SPR_ENMY_2_F_R_6 "./RSCS/texture/enemies/2/FrontRight/0028.bmp"
# define SPR_ENMY_2_F_R_7 "./RSCS/texture/enemies/2/FrontRight/0030.bmp"
# define SPR_ENMY_2_F_R_8 "./RSCS/texture/enemies/2/FrontRight/0032.bmp"
# define SPR_ENMY_2_F_R_9 "./RSCS/texture/enemies/2/FrontRight/0034.bmp"
# define SPR_ENMY_2_F_R_10 "./RSCS/texture/enemies/2/FrontRight/0036.bmp"
# define SPR_ENMY_2_F_R_11 "./RSCS/texture/enemies/2/FrontRight/0038.bmp"
# define SPR_ENMY_2_F_R_12 "./RSCS/texture/enemies/2/FrontRight/0040.bmp"
# define SPR_ENMY_2_F_R_13 "./RSCS/texture/enemies/2/FrontRight/0104.bmp"
# define SPR_ENMY_2_F_R_14 "./RSCS/texture/enemies/2/FrontRight/0108.bmp"
# define SPR_ENMY_2_F_R_15 "./RSCS/texture/enemies/2/FrontRight/0106.bmp"
# define SPR_ENMY_2_F_R_16 "./RSCS/texture/enemies/2/FrontRight/0110.bmp"
# define SPR_ENMY_2_F_R_17 "./RSCS/texture/enemies/2/FrontRight/0112.bmp"
# define SPR_ENMY_2_F_R_18 "./RSCS/texture/enemies/2/FrontRight/0114.bmp"
# define SPR_ENMY_2_F_R_19 "./RSCS/texture/enemies/2/FrontRight/0116.bmp"
# define SPR_ENMY_2_F_R_20 "./RSCS/texture/enemies/2/FrontRight/0118.bmp"

# define SPR_ENMY_2_DEAD_F_1 "./RSCS/texture/enemies/2/Front/0200.bmp"
# define SPR_ENMY_2_DEAD_F_2 "./RSCS/texture/enemies/2/Front/0202.bmp"
# define SPR_ENMY_2_DEAD_F_3 "./RSCS/texture/enemies/2/Front/0204.bmp"
# define SPR_ENMY_2_DEAD_F_4 "./RSCS/texture/enemies/2/Front/0206.bmp"
# define SPR_ENMY_2_DEAD_F_5 "./RSCS/texture/enemies/2/Front/0208.bmp"
# define SPR_ENMY_2_DEAD_F_6 "./RSCS/texture/enemies/2/Front/0210.bmp"
# define SPR_ENMY_2_DEAD_F_7 "./RSCS/texture/enemies/2/Front/0212.bmp"
# define SPR_ENMY_2_DEAD_F_8 "./RSCS/texture/enemies/2/Front/0214.bmp"
# define SPR_ENMY_2_DEAD_F_9 "./RSCS/texture/enemies/2/Front/0215.bmp"

# define SPR_ENMY_2_DEAD_F_L_1 "./RSCS/texture/enemies/2/FrontLeft/0200.bmp"
# define SPR_ENMY_2_DEAD_F_L_2 "./RSCS/texture/enemies/2/FrontLeft/0202.bmp"
# define SPR_ENMY_2_DEAD_F_L_3 "./RSCS/texture/enemies/2/FrontLeft/0204.bmp"
# define SPR_ENMY_2_DEAD_F_L_4 "./RSCS/texture/enemies/2/FrontLeft/0206.bmp"
# define SPR_ENMY_2_DEAD_F_L_5 "./RSCS/texture/enemies/2/FrontLeft/0208.bmp"
# define SPR_ENMY_2_DEAD_F_L_6 "./RSCS/texture/enemies/2/FrontLeft/0210.bmp"
# define SPR_ENMY_2_DEAD_F_L_7 "./RSCS/texture/enemies/2/FrontLeft/0212.bmp"
# define SPR_ENMY_2_DEAD_F_L_8 "./RSCS/texture/enemies/2/FrontLeft/0214.bmp"
# define SPR_ENMY_2_DEAD_F_L_9 "./RSCS/texture/enemies/2/FrontLeft/0215.bmp"

# define SPR_ENMY_2_DEAD_L_1 "./RSCS/texture/enemies/2/Left/0200.bmp"
# define SPR_ENMY_2_DEAD_L_2 "./RSCS/texture/enemies/2/Left/0202.bmp"
# define SPR_ENMY_2_DEAD_L_3 "./RSCS/texture/enemies/2/Left/0204.bmp"
# define SPR_ENMY_2_DEAD_L_4 "./RSCS/texture/enemies/2/Left/0206.bmp"
# define SPR_ENMY_2_DEAD_L_5 "./RSCS/texture/enemies/2/Left/0208.bmp"
# define SPR_ENMY_2_DEAD_L_6 "./RSCS/texture/enemies/2/Left/0210.bmp"
# define SPR_ENMY_2_DEAD_L_7 "./RSCS/texture/enemies/2/Left/0212.bmp"
# define SPR_ENMY_2_DEAD_L_8 "./RSCS/texture/enemies/2/Left/0214.bmp"
# define SPR_ENMY_2_DEAD_L_9 "./RSCS/texture/enemies/2/Left/0215.bmp"

# define SPR_ENMY_2_DEAD_B_L_1 "./RSCS/texture/enemies/2/BackLeft/0200.bmp"
# define SPR_ENMY_2_DEAD_B_L_2 "./RSCS/texture/enemies/2/BackLeft/0202.bmp"
# define SPR_ENMY_2_DEAD_B_L_3 "./RSCS/texture/enemies/2/BackLeft/0204.bmp"
# define SPR_ENMY_2_DEAD_B_L_4 "./RSCS/texture/enemies/2/BackLeft/0206.bmp"
# define SPR_ENMY_2_DEAD_B_L_5 "./RSCS/texture/enemies/2/BackLeft/0208.bmp"
# define SPR_ENMY_2_DEAD_B_L_6 "./RSCS/texture/enemies/2/BackLeft/0210.bmp"
# define SPR_ENMY_2_DEAD_B_L_7 "./RSCS/texture/enemies/2/BackLeft/0212.bmp"
# define SPR_ENMY_2_DEAD_B_L_8 "./RSCS/texture/enemies/2/BackLeft/0214.bmp"
# define SPR_ENMY_2_DEAD_B_L_9 "./RSCS/texture/enemies/2/BackLeft/0215.bmp"

# define SPR_ENMY_2_DEAD_B_1 "./RSCS/texture/enemies/2/Back/0200.bmp"
# define SPR_ENMY_2_DEAD_B_2 "./RSCS/texture/enemies/2/Back/0202.bmp"
# define SPR_ENMY_2_DEAD_B_3 "./RSCS/texture/enemies/2/Back/0204.bmp"
# define SPR_ENMY_2_DEAD_B_4 "./RSCS/texture/enemies/2/Back/0206.bmp"
# define SPR_ENMY_2_DEAD_B_5 "./RSCS/texture/enemies/2/Back/0208.bmp"
# define SPR_ENMY_2_DEAD_B_6 "./RSCS/texture/enemies/2/Back/0210.bmp"
# define SPR_ENMY_2_DEAD_B_7 "./RSCS/texture/enemies/2/Back/0212.bmp"
# define SPR_ENMY_2_DEAD_B_8 "./RSCS/texture/enemies/2/Back/0214.bmp"
# define SPR_ENMY_2_DEAD_B_9 "./RSCS/texture/enemies/2/Back/0215.bmp"

# define SPR_ENMY_2_DEAD_B_R_1 "./RSCS/texture/enemies/2/BackRight/0200.bmp"
# define SPR_ENMY_2_DEAD_B_R_2 "./RSCS/texture/enemies/2/BackRight/0202.bmp"
# define SPR_ENMY_2_DEAD_B_R_3 "./RSCS/texture/enemies/2/BackRight/0204.bmp"
# define SPR_ENMY_2_DEAD_B_R_4 "./RSCS/texture/enemies/2/BackRight/0206.bmp"
# define SPR_ENMY_2_DEAD_B_R_5 "./RSCS/texture/enemies/2/BackRight/0208.bmp"
# define SPR_ENMY_2_DEAD_B_R_6 "./RSCS/texture/enemies/2/BackRight/0210.bmp"
# define SPR_ENMY_2_DEAD_B_R_7 "./RSCS/texture/enemies/2/BackRight/0212.bmp"
# define SPR_ENMY_2_DEAD_B_R_8 "./RSCS/texture/enemies/2/BackRight/0214.bmp"
# define SPR_ENMY_2_DEAD_B_R_9 "./RSCS/texture/enemies/2/BackRight/0215.bmp"

# define SPR_ENMY_2_DEAD_R_1 "./RSCS/texture/enemies/2/Right/0200.bmp"
# define SPR_ENMY_2_DEAD_R_2 "./RSCS/texture/enemies/2/Right/0202.bmp"
# define SPR_ENMY_2_DEAD_R_3 "./RSCS/texture/enemies/2/Right/0204.bmp"
# define SPR_ENMY_2_DEAD_R_4 "./RSCS/texture/enemies/2/Right/0206.bmp"
# define SPR_ENMY_2_DEAD_R_5 "./RSCS/texture/enemies/2/Right/0208.bmp"
# define SPR_ENMY_2_DEAD_R_6 "./RSCS/texture/enemies/2/Right/0210.bmp"
# define SPR_ENMY_2_DEAD_R_7 "./RSCS/texture/enemies/2/Right/0212.bmp"
# define SPR_ENMY_2_DEAD_R_8 "./RSCS/texture/enemies/2/Right/0214.bmp"
# define SPR_ENMY_2_DEAD_R_9 "./RSCS/texture/enemies/2/Right/0215.bmp"

# define SPR_ENMY_2_DEAD_F_R_1 "./RSCS/texture/enemies/2/FrontRight/0200.bmp"
# define SPR_ENMY_2_DEAD_F_R_2 "./RSCS/texture/enemies/2/FrontRight/0202.bmp"
# define SPR_ENMY_2_DEAD_F_R_3 "./RSCS/texture/enemies/2/FrontRight/0204.bmp"
# define SPR_ENMY_2_DEAD_F_R_4 "./RSCS/texture/enemies/2/FrontRight/0206.bmp"
# define SPR_ENMY_2_DEAD_F_R_5 "./RSCS/texture/enemies/2/FrontRight/0208.bmp"
# define SPR_ENMY_2_DEAD_F_R_6 "./RSCS/texture/enemies/2/FrontRight/0210.bmp"
# define SPR_ENMY_2_DEAD_F_R_7 "./RSCS/texture/enemies/2/FrontRight/0212.bmp"
# define SPR_ENMY_2_DEAD_F_R_8 "./RSCS/texture/enemies/2/FrontRight/0214.bmp"
# define SPR_ENMY_2_DEAD_F_R_9 "./RSCS/texture/enemies/2/FrontRight/0215.bmp"

# define SPR_ENMY_3_F_1 "./RSCS/texture/enemies/3/front/front1.bmp"
# define SPR_ENMY_3_F_2 "./RSCS/texture/enemies/3/front/front2.bmp"
# define SPR_ENMY_3_F_3 "./RSCS/texture/enemies/3/front/front3.bmp"
# define SPR_ENMY_3_F_4 "./RSCS/texture/enemies/3/front/front4.bmp"
# define SPR_ENMY_3_F_5 "./RSCS/texture/enemies/3/front/front5.bmp"
# define SPR_ENMY_3_F_6 "./RSCS/texture/enemies/3/front/front6.bmp"
# define SPR_ENMY_3_F_7 "./RSCS/texture/enemies/3/front/front7.bmp"

# define SPR_ENMY_3_F_L_1 "./RSCS/texture/enemies/3/frontleft/front_left1.bmp"
# define SPR_ENMY_3_F_L_2 "./RSCS/texture/enemies/3/frontleft/front_left2.bmp"
# define SPR_ENMY_3_F_L_3 "./RSCS/texture/enemies/3/frontleft/front_left3.bmp"
# define SPR_ENMY_3_F_L_4 "./RSCS/texture/enemies/3/frontleft/front_left4.bmp"
# define SPR_ENMY_3_F_L_5 "./RSCS/texture/enemies/3/frontleft/front_left5.bmp"
# define SPR_ENMY_3_F_L_6 "./RSCS/texture/enemies/3/frontleft/front_left6.bmp"
# define SPR_ENMY_3_F_L_7 "./RSCS/texture/enemies/3/frontleft/front_left7.bmp"

# define SPR_ENMY_3_L_1 "./RSCS/texture/enemies/3/left/left1.bmp"
# define SPR_ENMY_3_L_2 "./RSCS/texture/enemies/3/left/left2.bmp"
# define SPR_ENMY_3_L_3 "./RSCS/texture/enemies/3/left/left3.bmp"
# define SPR_ENMY_3_L_4 "./RSCS/texture/enemies/3/left/left4.bmp"
# define SPR_ENMY_3_L_5 "./RSCS/texture/enemies/3/left/left5.bmp"
# define SPR_ENMY_3_L_6 "./RSCS/texture/enemies/3/left/left6.bmp"
# define SPR_ENMY_3_L_7 "./RSCS/texture/enemies/3/left/left7.bmp"

# define SPR_ENMY_3_B_L_1 "./RSCS/texture/enemies/3/backleft/back_left1.bmp"
# define SPR_ENMY_3_B_L_2 "./RSCS/texture/enemies/3/backleft/back_left2.bmp"
# define SPR_ENMY_3_B_L_3 "./RSCS/texture/enemies/3/backleft/back_left3.bmp"
# define SPR_ENMY_3_B_L_4 "./RSCS/texture/enemies/3/backleft/back_left4.bmp"
# define SPR_ENMY_3_B_L_5 "./RSCS/texture/enemies/3/backleft/back_left5.bmp"
# define SPR_ENMY_3_B_L_6 "./RSCS/texture/enemies/3/backleft/back_left6.bmp"
# define SPR_ENMY_3_B_L_7 "./RSCS/texture/enemies/3/backleft/back_left7.bmp"

# define SPR_ENMY_3_B_1 "./RSCS/texture/enemies/3/back/back1.bmp"
# define SPR_ENMY_3_B_2 "./RSCS/texture/enemies/3/back/back2.bmp"
# define SPR_ENMY_3_B_3 "./RSCS/texture/enemies/3/back/back3.bmp"
# define SPR_ENMY_3_B_4 "./RSCS/texture/enemies/3/back/back4.bmp"
# define SPR_ENMY_3_B_5 "./RSCS/texture/enemies/3/back/back5.bmp"
# define SPR_ENMY_3_B_6 "./RSCS/texture/enemies/3/back/back6.bmp"
# define SPR_ENMY_3_B_7 "./RSCS/texture/enemies/3/back/back7.bmp"

# define SPR_ENMY_3_B_R_1 "./RSCS/texture/enemies/3/backright/back_right1.bmp"
# define SPR_ENMY_3_B_R_2 "./RSCS/texture/enemies/3/backright/back_right2.bmp"
# define SPR_ENMY_3_B_R_3 "./RSCS/texture/enemies/3/backright/back_right3.bmp"
# define SPR_ENMY_3_B_R_4 "./RSCS/texture/enemies/3/backright/back_right4.bmp"
# define SPR_ENMY_3_B_R_5 "./RSCS/texture/enemies/3/backright/back_right5.bmp"
# define SPR_ENMY_3_B_R_6 "./RSCS/texture/enemies/3/backright/back_right6.bmp"
# define SPR_ENMY_3_B_R_7 "./RSCS/texture/enemies/3/backright/back_right7.bmp"

# define SPR_ENMY_3_R_1 "./RSCS/texture/enemies/3/right/right1.bmp"
# define SPR_ENMY_3_R_2 "./RSCS/texture/enemies/3/right/right2.bmp"
# define SPR_ENMY_3_R_3 "./RSCS/texture/enemies/3/right/right3.bmp"
# define SPR_ENMY_3_R_4 "./RSCS/texture/enemies/3/right/right4.bmp"
# define SPR_ENMY_3_R_5 "./RSCS/texture/enemies/3/right/right5.bmp"
# define SPR_ENMY_3_R_6 "./RSCS/texture/enemies/3/right/right6.bmp"
# define SPR_ENMY_3_R_7 "./RSCS/texture/enemies/3/right/right7.bmp"

# define SPR_ENMY_3_F_R_1 "./RSCS/texture/enemies/3/frontright/front_right1.bmp"
# define SPR_ENMY_3_F_R_2 "./RSCS/texture/enemies/3/frontright/front_right2.bmp"
# define SPR_ENMY_3_F_R_3 "./RSCS/texture/enemies/3/frontright/front_right3.bmp"
# define SPR_ENMY_3_F_R_4 "./RSCS/texture/enemies/3/frontright/front_right4.bmp"
# define SPR_ENMY_3_F_R_5 "./RSCS/texture/enemies/3/frontright/front_right5.bmp"
# define SPR_ENMY_3_F_R_6 "./RSCS/texture/enemies/3/frontright/front_right6.bmp"
# define SPR_ENMY_3_F_R_7 "./RSCS/texture/enemies/3/frontright/front_right7.bmp"

# define SPR_ENMY_3_DEAD_1 "./RSCS/texture/enemies/3/death/death1.bmp"
# define SPR_ENMY_3_DEAD_2 "./RSCS/texture/enemies/3/death/death2.bmp"
# define SPR_ENMY_3_DEAD_3 "./RSCS/texture/enemies/3/death/death3.bmp"
# define SPR_ENMY_3_DEAD_4 "./RSCS/texture/enemies/3/death/death4.bmp"
# define SPR_ENMY_3_DEAD_5 "./RSCS/texture/enemies/3/death/death5.bmp"
# define SPR_ENMY_3_DEAD_6 "./RSCS/texture/enemies/3/death/death6.bmp"
# define SPR_ENMY_3_DEAD_7 "./RSCS/texture/enemies/3/death/death7.bmp"
# define SPR_ENMY_3_DEAD_8 "./RSCS/texture/enemies/3/death/death8.bmp"
# define SPR_ENMY_3_DEAD_9 "./RSCS/texture/enemies/3/death/death9.bmp"

# define SPR_ENMY_4_F_1 "./RSCS/texture/enemies/4/Front/MOMDC1.bmp"
# define SPR_ENMY_4_F_2 "./RSCS/texture/enemies/4/Front/MOMDE1.bmp"
# define SPR_ENMY_4_F_3 "./RSCS/texture/enemies/4/Front/MOMDF1.bmp"
# define SPR_ENMY_4_F_4 "./RSCS/texture/enemies/4/Front/MOMDG1.bmp"
# define SPR_ENMY_4_F_5 "./RSCS/texture/enemies/4/Front/MOMDH1.bmp"
# define SPR_ENMY_4_F_6 "./RSCS/texture/enemies/4/Front/MOMDI1.bmp"
# define SPR_ENMY_4_F_7 "./RSCS/texture/enemies/4/Front/MOMDJ1.bmp"

# define SPR_ENMY_4_F_L_1 "./RSCS/texture/enemies/4/FrontLeft/MOMDA2A8.bmp"
# define SPR_ENMY_4_F_L_2 "./RSCS/texture/enemies/4/FrontLeft/MOMDE2E8.bmp"
# define SPR_ENMY_4_F_L_3 "./RSCS/texture/enemies/4/FrontLeft/MOMDF2F8.bmp"
# define SPR_ENMY_4_F_L_4 "./RSCS/texture/enemies/4/FrontLeft/MOMDG2G8.bmp"
# define SPR_ENMY_4_F_L_5 "./RSCS/texture/enemies/4/FrontLeft/MOMDH2H8.bmp"
# define SPR_ENMY_4_F_L_6 "./RSCS/texture/enemies/4/FrontLeft/MOMDI2I8.bmp"
# define SPR_ENMY_4_F_L_7 "./RSCS/texture/enemies/4/FrontLeft/MOMDJ2J8.bmp"

# define SPR_ENMY_4_F_R_1 "./RSCS/texture/enemies/4/FrontRight/MOMDA2A8.bmp"
# define SPR_ENMY_4_F_R_2 "./RSCS/texture/enemies/4/FrontRight/MOMDE2E8.bmp"
# define SPR_ENMY_4_F_R_3 "./RSCS/texture/enemies/4/FrontRight/MOMDF2F8.bmp"
# define SPR_ENMY_4_F_R_4 "./RSCS/texture/enemies/4/FrontRight/MOMDG2G8.bmp"
# define SPR_ENMY_4_F_R_5 "./RSCS/texture/enemies/4/FrontRight/MOMDH2H8.bmp"
# define SPR_ENMY_4_F_R_6 "./RSCS/texture/enemies/4/FrontRight/MOMDI2I8.bmp"
# define SPR_ENMY_4_F_R_7 "./RSCS/texture/enemies/4/FrontRight/MOMDJ2J8.bmp"

# define SPR_ENMY_4_L_1 "./RSCS/texture/enemies/4/Left/MOMDA3A7.bmp"
# define SPR_ENMY_4_L_2 "./RSCS/texture/enemies/4/Left/MOMDE3E7.bmp"
# define SPR_ENMY_4_L_3 "./RSCS/texture/enemies/4/Left/MOMDF3F7.bmp"
# define SPR_ENMY_4_L_4 "./RSCS/texture/enemies/4/Left/MOMDG3G7.bmp"
# define SPR_ENMY_4_L_5 "./RSCS/texture/enemies/4/Left/MOMDH3H7.bmp"
# define SPR_ENMY_4_L_6 "./RSCS/texture/enemies/4/Left/MOMDI3I7.bmp"
# define SPR_ENMY_4_L_7 "./RSCS/texture/enemies/4/Left/MOMDJ3J7.bmp"

# define SPR_ENMY_4_R_1 "./RSCS/texture/enemies/4/Right/MOMDA3A7.bmp"
# define SPR_ENMY_4_R_2 "./RSCS/texture/enemies/4/Right/MOMDE3E7.bmp"
# define SPR_ENMY_4_R_3 "./RSCS/texture/enemies/4/Right/MOMDF3F7.bmp"
# define SPR_ENMY_4_R_4 "./RSCS/texture/enemies/4/Right/MOMDG3G7.bmp"
# define SPR_ENMY_4_R_5 "./RSCS/texture/enemies/4/Right/MOMDH3H7.bmp"
# define SPR_ENMY_4_R_6 "./RSCS/texture/enemies/4/Right/MOMDI3I7.bmp"
# define SPR_ENMY_4_R_7 "./RSCS/texture/enemies/4/Right/MOMDJ3J7.bmp"

# define SPR_ENMY_4_B_1 "./RSCS/texture/enemies/4/Back/MOMDC5.bmp"
# define SPR_ENMY_4_B_2 "./RSCS/texture/enemies/4/Back/MOMDE5.bmp"
# define SPR_ENMY_4_B_3 "./RSCS/texture/enemies/4/Back/MOMDF5.bmp"
# define SPR_ENMY_4_B_4 "./RSCS/texture/enemies/4/Back/MOMDG5.bmp"
# define SPR_ENMY_4_B_5 "./RSCS/texture/enemies/4/Back/MOMDH5.bmp"
# define SPR_ENMY_4_B_6 "./RSCS/texture/enemies/4/Back/MOMDI5.bmp"
# define SPR_ENMY_4_B_7 "./RSCS/texture/enemies/4/Back/MOMDJ5.bmp"

# define SPR_ENMY_4_B_L_1 "./RSCS/texture/enemies/4/BackLeft/MOMDC4C6.bmp"
# define SPR_ENMY_4_B_L_2 "./RSCS/texture/enemies/4/BackLeft/MOMDE4E6.bmp"
# define SPR_ENMY_4_B_L_3 "./RSCS/texture/enemies/4/BackLeft/MOMDF4F6.bmp"
# define SPR_ENMY_4_B_L_4 "./RSCS/texture/enemies/4/BackLeft/MOMDG4G6.bmp"
# define SPR_ENMY_4_B_L_5 "./RSCS/texture/enemies/4/BackLeft/MOMDH4H6.bmp"
# define SPR_ENMY_4_B_L_6 "./RSCS/texture/enemies/4/BackLeft/MOMDI4I6.bmp"
# define SPR_ENMY_4_B_L_7 "./RSCS/texture/enemies/4/BackLeft/MOMDJ4J6.bmp"

# define SPR_ENMY_4_B_R_1 "./RSCS/texture/enemies/4/BackRight/MOMDC4C6.bmp"
# define SPR_ENMY_4_B_R_2 "./RSCS/texture/enemies/4/BackRight/MOMDE4E6.bmp"
# define SPR_ENMY_4_B_R_3 "./RSCS/texture/enemies/4/BackRight/MOMDF4F6.bmp"
# define SPR_ENMY_4_B_R_4 "./RSCS/texture/enemies/4/BackRight/MOMDG4G6.bmp"
# define SPR_ENMY_4_B_R_5 "./RSCS/texture/enemies/4/BackRight/MOMDH4H6.bmp"
# define SPR_ENMY_4_B_R_6 "./RSCS/texture/enemies/4/BackRight/MOMDI4I6.bmp"
# define SPR_ENMY_4_B_R_7 "./RSCS/texture/enemies/4/BackRight/MOMDJ4J6.bmp"

# define SPR_ENMY_4_DEAD_1 "./RSCS/texture/enemies/4/Death/MOMDL0.bmp"
# define SPR_ENMY_4_DEAD_2 "./RSCS/texture/enemies/4/Death/MOMDM0.bmp"
# define SPR_ENMY_4_DEAD_3 "./RSCS/texture/enemies/4/Death/MOMDN0.bmp"
# define SPR_ENMY_4_DEAD_4 "./RSCS/texture/enemies/4/Death/MOMDO0.bmp"
# define SPR_ENMY_4_DEAD_5 "./RSCS/texture/enemies/4/Death/MOMDP0.bmp"
# define SPR_ENMY_4_DEAD_6 "./RSCS/texture/enemies/4/Death/MOMDR0.bmp"
# define SPR_ENMY_4_DEAD_7 "./RSCS/texture/enemies/4/Death/MOMDQ0.bmp"
# define SPR_ENMY_4_DEAD_8 "./RSCS/texture/enemies/4/Death/MOMDS0.bmp"
# define SPR_ENMY_4_DEAD_9 "./RSCS/texture/enemies/4/Death/MOMDT0.bmp"

# define SPR_BOSS_1 "./RSCS/texture/enemies/boss/ANGLA0.bmp"
# define SPR_BOSS_2 "./RSCS/texture/enemies/boss/ANGLB0.bmp"
# define SPR_BOSS_3 "./RSCS/texture/enemies/boss/ANGLC0.bmp"
# define SPR_BOSS_4 "./RSCS/texture/enemies/boss/ANGLD0.bmp"
# define SPR_BOSS_5 "./RSCS/texture/enemies/boss/ANGLE0.bmp"
# define SPR_BOSS_6 "./RSCS/texture/enemies/boss/ANGLF0.bmp"
# define SPR_BOSS_7 "./RSCS/texture/enemies/boss/ANGLG0.bmp"
# define SPR_BOSS_8 "./RSCS/texture/enemies/boss/ANGLH0.bmp"

# define SPR_BOSS_DEAD_1 "./RSCS/texture/enemies/boss/ANGLI0.bmp"
# define SPR_BOSS_DEAD_2 "./RSCS/texture/enemies/boss/ANGLJ0.bmp"
# define SPR_BOSS_DEAD_3 "./RSCS/texture/enemies/boss/ANGLK0.bmp"
# define SPR_BOSS_DEAD_4 "./RSCS/texture/enemies/boss/ANGLL0.bmp"
# define SPR_BOSS_DEAD_5 "./RSCS/texture/enemies/boss/ANGLM0.bmp"
# define SPR_BOSS_DEAD_6 "./RSCS/texture/enemies/boss/ANGLN0.bmp"
# define SPR_BOSS_DEAD_7 "./RSCS/texture/enemies/boss/ANGLO0.bmp"
# define SPR_BOSS_DEAD_8 "./RSCS/texture/enemies/boss/ANGLP0.bmp"

# define ON "ON"
# define OFF "OFF"
# define PROG_H
# define INIT_SDL		0
# define INIT_WIN		1
# define INIT_REN		2
# define BAD_ARG 		3
# define BAD_FILE		4
# define BAD_FILENAME	5
# define BAD_MAP		6
# define BAD_SPAWN		7
# define BAD_BLOCK		8
# define TEXT_W			64
# define TEXT_H			64
# define WALL			0
# define WALL_TEXT		1
# define SPRITE			2
# define SPRITE_TEXT	3
# define BLOCK_H		4
# define CEILING		5
# define CEILING_TXT	6
# define FLOOR_TXT		7
# define MAX_B			8
# define STEP			10

# define WALLIMPSIZE	10

typedef enum			e_sprite_type
{
	BALLOON,
	LOLLIPOP,
	TICKET,
	MEDKIT_10,
	MEDKIT_20,
	MEDKIT_50,
	TORCH,
	PISTOL,
	SHOTGUN,
	DEVASTATOR,
	PISTOL_AMMO,
	SHOTGUN_AMMO,
	DEVASTATOR_AMMO,
	WARP_NXT_FLOOR,
	WARP_TO_WARP,
	DEVASTATOR_PROJECTILE,
	ENEMY_3_PROJECTILE,
	ENEMY_4_PROJECTILE,
	ENEMY_BOSS_PROJECTILE,
	EXPLOSION,
	ENEMY_1,
	ENEMY_2,
	ENEMY_3,
	ENEMY_4,
	ENEMY_BOSS,
	ENEMY_DEAD_1,
	ENEMY_DEAD_2,
	ENEMY_DEAD_3,
	ENEMY_DEAD_4,
	ENEMY_DEAD_BOSS,
	NB_SPRITE_TYPES
}						t_sprite_type;

/*
** Structures sprites
*/

typedef struct			s_sprite_data
{
	int					max_dir;
	double				wscale;
	double				hscale;
	int					max_hp;
	int					hpad;
	float				grounded;
	int					max_anims;
	double				sight;
	double				range;
	double				speed;
	int					**texid;
}						t_sprite_data;

typedef struct			s_sprite
{
	double				posx;
	double				posy;
	double				posz;
	double				dirx;
	double				diry;
	double				dirz;
	double				dist;
	int					hp;
	uint8_t				type;
	uint8_t				state;
	uint8_t				wave;
	uint8_t				animation;
	SDL_TimerID			timer;
	int					hit;
	int					idle;
	SDL_TimerID			timer_idle;
	int					asleep;
	void				*env;
	void				*floor;
	char				mapbuffer[3];
}						t_sprite;

typedef struct			s_spritecast
{
	double				planex;
	double				planey;
	double				spritex;
	double				spritey;
	double				transformx;
	double				transformy;
	double				invdet;
	int					dir;
	int					objdir;
	int					winx;
	int					hei;
	int					wid;
	int					dstx;
	int					dendx;
	int					dsty;
	int					dendy;
	int					i;
	int					texx;
	int					d;
	int					texy;
	int					j;
	double				vmove;
	double				fog_perc;
	int					texnum;
	double				angle;
	int					animation;
	t_sprite			*sprite;
	t_sprite_data		*data;
	SDL_Surface			*surf;
	uint32_t			color;
}						t_spritecast;

typedef struct			s_spritedraw
{
	int					y;
	int					x;
	int					dendx;
	int					texx;
	int					texy;
	uint32_t			color;
}						t_spritedraw;

/*
**	Structure HUD
*/

typedef struct			s_hud
{
	SDL_TimerID			weapon_timer;
	SDL_TimerID			head_guy_timer;
	SDL_TimerID			shoot_dev_timer;
	SDL_TimerID			reload_dev_timer;
	SDL_TimerID			shoot_pistol_timer;
	SDL_TimerID			reload_pistol_timer;
	SDL_TimerID			shoot_shotgun_timer;
	SDL_TimerID			reload_shotgun_timer;
	SDL_TimerID			left_fist_timer;
	SDL_TimerID			right_fist_timer;
	SDL_TimerID			kick_timer;
	int					max_ammo_shotgun;
	int					usable_ammo_shotgun;
	int					pistol_selected;
	int					shotgun_selected;
	int					devastator_selected;
	int					fist_selected;
	int					weapon_step;
	int					hg_step;
	int					hg_prev_step;
	int					weapon_choosen;
	int					fire_step;
	int					reload_dev_step;
	int					shoot_pistol_step;
	int					reload_pistol_step;
	int					shoot_shotgun_step;
	int					reload_shotgun_step;
	int					left_fist_step;
	int					right_fist_step;
	int					kick_step;
	SDL_Rect			rect_life;
	SDL_Rect			rect_ticket;
	SDL_Rect			rect_balloon;
	SDL_Rect			rect_candy;
	SDL_Rect			rect_fire1;
	SDL_Rect			rect_fire2;
	SDL_Rect			rect_fire3;
	SDL_Rect			rect_fire4;
	SDL_Rect			rect_fire5;
	SDL_Rect			rect_ammo;
	SDL_Rect			rect_pistol;
	SDL_Rect			rect_shotgun;
	SDL_Rect			rect_devastator;
	SDL_Rect			rect_used_ammo;
	SDL_Rect			rect_max_ammo;
	SDL_Rect			rect_no_ammo;
	SDL_Rect			rect_split_ammo;
	SDL_Rect			rhg;
	SDL_Rect			rect_pis_equiped;
	SDL_Rect			rect_sho_equiped;
	SDL_Rect			rect_dev_equiped;
	SDL_Rect			rect_dev_pos1;
	SDL_Rect			rect_dev_fb_1;
	SDL_Rect			rect_pis_p1;
	SDL_Rect			rect_sho_p1;
	SDL_Rect			rect_fist_p1;
	SDL_Texture			*tex_skull;
	SDL_Texture			*tex_life;
	SDL_Texture			*tex_ticket_on;
	SDL_Texture			*tex_ticket_off;
	SDL_Texture			*tex_balloon_on;
	SDL_Texture			*tex_balloon_off;
	SDL_Texture			*tex_candy_on;
	SDL_Texture			*tex_candy_off;
	SDL_Texture			*tex_fire_on;
	SDL_Texture			*tex_fire_off;
	SDL_Texture			*tex_pistol_on;
	SDL_Texture			*tex_pistol_off;
	SDL_Texture			*tex_shotgun_on;
	SDL_Texture			*tex_shotgun_off;
	SDL_Texture			*tex_devast_on;
	SDL_Texture			*tex_devast_off;
	SDL_Texture			*tex_ammo;
	SDL_Texture			*tex_no_ammo;
	SDL_Texture			*tex_split_ammo;
	SDL_Texture			**hg_text;
	SDL_Texture			**dev_text;
	SDL_Texture			**pistol_text;
	SDL_Texture			**shotgun_text;
	SDL_Texture			**fist_text;
	int					weapon_animed;
	int					dev_flag;
	int					pistol_flag;
	int					shotgun_flag;
	int					fist_flag;
	int					amount;
	SDL_Texture			*test;
	SDL_Texture			*stxt;
	SDL_Rect			rect_stxt;
	SDL_Texture			*mtxt;
	SDL_Rect			rect_mtxt;
	SDL_Texture			*pscore;
	SDL_Rect			rect_pscore;
}						t_hud;

/*
** Structure audio
*/

typedef enum			e_music_ids
{
	MUS_MENU,
	MUS_ARCADE,
	MUS_INTRO,
	MUS_LVL1,
	MUS_LVL2,
	MUS_LVL3,
	MUS_BOSS,
	NB_MUSICS
}						t_music_ids;

typedef enum			e_loopeffects_ids
{
	L_EFF_WALK,
	L_EFF_RUN,
	L_EFF_TRAIN,
	L_EFF_WATER_BREATHING,
	L_EFF_HEARTBEAT,
	L_EFF_FIRE,
	NB_LOOP_EFFECTS
}						t_loopeffect_ids;

typedef enum			e_soundeffects_ids
{
	EFF_GAMEOVER,
	EFF_RAIN,
	EFF_TRAIN,
	EFF_JUMP,
	EFF_PUNCH,
	EFF_PISTOL,
	EFF_PISTOL_RELOAD,
	EFF_PISTOL_EMPTY,
	EFF_SHOTGUN,
	EFF_SHOTGUN_RELOAD,
	EFF_SHOTGUN_LOAD,
	EFF_DEVASTATOR,
	EFF_DEVASTATOR_RELOAD,
	EFF_EXPLOSION,
	EFF_LOL,
	EFF_ENEMY_1_ATTACK,
	EFF_ENEMY_2_ATTACK,
	EFF_ENEMY_3_ATTACK,
	EFF_ENEMY_4_ATTACK,
	EFF_ENEMY_BOSS_ATTACK,
	NB_EFFECTS
}						t_soundeffects_ids;

typedef enum			e_channels
{
	CH_MUSIC,
	CH_RAIN,
	CH_BUBBLES,
	CH_WALK,
	CH_GAMEOVER,
	CH_TRAIN,
	CH_JUMP,
	CH_PUNCH,
	CH_PISTOL,
	CH_PISTOL_RELOAD,
	CH_SHOTGUN,
	CH_SHOTGUN_RELOAD,
	CH_SHOTGUN_LOAD,
	CH_DEVASTATOR,
	CH_DEVASTATOR_RELOAD,
	CH_EXPLOSION,
	CH_WATER_BREATHING,
	CH_HEARTBEAT,
	CH_LOL,
	CH_FIRE,
	CH_ENEMY_1_ATTACK,
	CH_ENEMY_2_ATTACK,
	CH_ENEMY_3_ATTACK,
	CH_ENEMY_4_ATTACK,
	CH_ENEMY_BOSS_ATTACK,
	NB_CHANNELS
}						t_channels;

typedef struct			s_audio
{
	FMOD_SYSTEM			*system;
	FMOD_SOUND			*musics[NB_MUSICS];
	FMOD_SOUND			*loop_effects[NB_LOOP_EFFECTS];
	FMOD_CHANNEL		*channels[NB_CHANNELS];
	FMOD_SOUND			*sound_effects[NB_EFFECTS];
	int					effect_op;
	float				volume;
}						t_audio;

/*
** Structure pixel
*/
typedef struct			s_pixel
{
	int					x;
	int					y;
	Uint8				r;
	Uint8				g;
	Uint8				b;
	Uint8				a;
	int					w_width;
	int					w_hight;
}						t_pixel;

/*
** Structure skybox
*/
typedef struct			s_skybox
{
	SDL_Texture			*texture;
	int					w;
	int					h;
	double				speed;
	double				h_scale;
	SDL_Rect			src;
	SDL_Rect			dst;
}						t_skybox;

/*
** Structure rect
*/
typedef struct			s_warp
{
	double				x;
	double				y;
}						t_warp;

/*
** Structure rect
*/
typedef struct			s_rect
{
	int					x;
	int					y;
	int					w;
	int					h;
}						t_rect;

/*
** Structure WALL
*/

typedef struct			s_wall
{
	int					mapx;
	int					mapy;
	int					side;
	int					blockheight;
	SDL_Surface			*tex;
}						t_wall;

typedef struct			s_tab_wall
{
	t_wall				wall_impact[WALLIMPSIZE + 1];
	int					number_wall;
	int					oldest_wall;
}						t_tab_wall;

/*
** Structure raycast
*/

typedef struct			s_ray
{
	int					x;
	int					y;
	int					mapx;
	int					mapy;
	double				posx;
	double				posy;
	double				rdirx;
	double				rdiry;
	double				deltadistx;
	double				deltadisty;
	double				sidedistx;
	double				sidedisty;
	int					dst;
	int					dend;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	double				perwalldist;
	int					linehight;
	double				oldplanex;
	int					crouchds;
	int					crouchde;
	int					deltaline;
	int					deltafly;
	int					deltacrouch;
	double				floorwallx;
	double				floorwally;
	double				playerdist;
	double				disttowall;
	double				dist;
	double				weight;
	double				floorx;
	double				floory;
	int					ftx;
	int					fty;
	int					texx;
	int					texy;
	int					txtnum;
	int					floor_txtnum;
	int					ceiling_txtnum;
	double				wallx;
	double				step;
	double				texpos;
	int					blocksize;
	int					yrefl;
	int					yreflend;
	int					dperc;
	SDL_Surface			*usethiswall;
	short				mapw;
	short				maph;
	int					maxheight;
	int					old_dst;
	int					old_dend;
	double				invdet;
	int					screen_x;
	double				planex;
	double				planey;
	double				window_zbuffers[10];
	char				*window_strbuffer[10];
	unsigned char		window_sidebuffer[10];
	char				window_depthbuffer[10];
	int					wall_mapxbuffer[10];
	int					wall_mapybuffer[10];
	int					wall_sidebuffer[10];
	int					wall_side;
	int					blockheight;
	int					deltafix;
	int					windows_hit;
}						t_ray;

/*
** Structure map
*/
typedef struct			s_elem
{
	int					inited;
	t_audio				*audio;
	double				res_width;
	double				res_hight;
	int					nb_threads;
	SDL_TimerID			timercrouchdown;
	SDL_TimerID			timercrouchup;
	SDL_TimerID			timerjump;
	SDL_TimerID			timerwalk;
	SDL_TimerID			timerflyup;
	SDL_TimerID			timerflydown;
	SDL_TimerID			timer3;
	SDL_TimerID			timer_rain;
	SDL_TimerID			time_rain_fog;
	SDL_Rect			rectfps;
	TTF_Font			*fpsfont;
	SDL_Color			fpscolor;
	SDL_Color			msg;
	SDL_Surface			*fpssurf;
	SDL_Texture			*fpstext;
	SDL_Texture			**bubble;
	t_list				*lst;
	SDL_TimerID			timer_bubble;
	SDL_TimerID			timer_bubble_progress;
	SDL_Texture			*texchrono;
	SDL_TimerID			chrono;
	int					timechrono;
	int					reflections;
	int					dstuncapped;
	int					v;
	int					vh;
	const Uint8			*keystat;
	char				**box;
	char				***map;
	char				***new;
	char				***new_backup;
	int					fog;
	int					shadow;
	int					lava_glow;
	int					underwater;
	double				spawn_x;
	double				spawn_y;
	double				tmpx;
	double				tmpy;
	int					spawn_floor;
	int					width;
	int					hight;
	int					nh;
	int					nw;
	int					max_floor;
	int					map_floor;
	int					min;
	int					max;
	int					j;
	int					k;
	int					spawn;
	t_rect				rect;
	t_rect				playerrect;
	SDL_Surface			*bullet;
	SDL_Surface			*surf;
	SDL_Texture			*text;
	SDL_Surface			**walltext;
	SDL_Surface			**animatedwalltext;
	SDL_Surface			**savewalltext;
	SDL_Surface			**floortext;
	SDL_Texture			*skybox;
	SDL_Surface			**ceilingtext;
	SDL_Surface			*icon;
	SDL_Surface			**weapon;
	SDL_Surface			*minimapsurf;
	SDL_Surface			*radarsurf;
	SDL_Rect			minimaprect;
	SDL_Rect			radarrect;
	uint32_t			time;
	uint32_t			oldtime;
	double				frametime;
	double				speed;
	double				speedweapon;
	double				speedshift;
	double				angle;
	double				rotatespeed;
	int					m;
	int					currentstair;
	int					crosshair;
	double				posx;
	double				posy;
	char				*fps;
	double				mousex;
	int					mousey;
	int					lookupdown;
	double				crouchsensi;
	double				flysensi;
	int					walk;
	int					walkswitch;
	uint32_t			red;
	uint32_t			green;
	uint32_t			blue;
	uint32_t			grey;
	uint32_t			black;
	uint32_t			white;
	uint32_t			color;
	t_rect				minimap;
	t_rect				radar;
	int					sensitivity_x;
	int					sensitivity_y;
	double				sensitivity_setup;
	int					psy;
	int					negative;
	SDL_TimerID			negatifflashtimer;
	int					texture_res;
	int					crouch;
	int					fly;
	int					stepup;
	int					swim;
	int					jump;
	int					gravity;
	int					test;
	int					life;
	int					prevlife;
	SDL_Color			life_color;
	char				*str_life;
	double				speedragdoll;
	int					ragdoll;
	SDL_TimerID			timerragdolldown;
	SDL_TimerID			timerragdollup;
	double				ragdollsensi;
	SDL_Surface			*ragsurf;
	SDL_Texture			*ragtext;
	int					rain;
	int					timedrain;
	int					rained;
	int					seerain;
	int					ticket;
	int					balloon;
	int					lollipop;
	int					pistol;
	int					shotgun;
	int					devastator;
	int					pistol_selected;
	int					shotgun_selected;
	int					devastator_selected;
	int					fist_selected;
	int					usable_ammo_pistol;
	int					usable_ammo_shotgun;
	int					usable_ammo_legendary;
	int					max_ammo_pistol;
	int					max_ammo_shotgun;
	int					max_ammo_legendary;
	int					pistol_ammo_limit;
	int					shotgun_ammo_limit;
	int					dev_ammo_limit;
	int					previous_used_ammo;
	int					previous_max_ammo;
	int					walking;
	int					weapon_hand;
	int					lookupcap;
	t_skybox			*skyboxes[2];
	int					debug_wall;
	int					debug_floor;
	int					debug_roof;
	int					max_mag_pistol;
	int					max_mag_shotgun;
	int					max_mag_devastator;
	char				str_usable_ammo_pistol[3];
	char				str_usable_ammo_shotgun[3];
	char				str_usable_ammo_legendary[3];
	char				str_max_ammo_pistol[3];
	char				str_max_ammo_shotgun[3];
	char				str_max_ammo_legendary[3];
	int					fire_stat;
	int					timer_arcade;
	int					time_s;
	t_warp				*warp;
	int					max_warp;
	int					warp_enable;
	SDL_TimerID			timerwarp;
	SDL_TimerID			timerballoon;
	SDL_TimerID			timerlollipop;
	int					impact;
	int					wall_toclean;
	t_wall				lastwall;
	t_tab_wall			tab[2];
	int					taketexx;
	int					taketexy;
	int					taketxtnum;
	char				str_ammo[3];
	SDL_TimerID			test_shot;
	int					message;
	double				framespeed;
	int					autorun;
	int					autorunswitch;
	int					autorunmove;
	SDL_TimerID			shoot_delay;
	SDL_TimerID			timetext;
	int					ntext;
	int					saved_floor;
	int					retry;
	int					rainswitch;
	int					negatifflash;
	int					noclip;
	int					torchtoogle;
	int					godmode;
	int					game_msg;
	int					prev_fire_stat;
	int					lightop;
	int					max_blockheight;
	int					arcade_retry;
	int					drawceiling;
	int					custom_lighting;
	int					custom_shadow;
	int					custom_rain;
	int					custom_fog;
	int					custom_bubbles;
	int					custom_psy;
	int					custom_gravity;
	int					custom_skybox;
	int					last_rain_state;
	SDL_Surface			**sprites;
	t_sprite_data		sprites_data[NB_SPRITE_TYPES];
	t_list				*enemies;
	t_list				*items;
	t_list				*projectiles;
	int					nb_enemies;
	int					nb_items;
	int					nb_projectiles;
	int					nb_sprites;
	int					deltafix;
	SDL_TimerID			timer_flash;
	int					timer_flashtoflash;
	int					deltafly;
	int					deltacrouch;
	int					deltaline;
	int					s_dev;
	int					s_shot;
	int					s_pistol;
	int					s_dev_use_ammo;
	int					s_shot_use_ammo;
	int					s_pistol_use_ammo;
	int					s_dev_ammo;
	int					s_shot_ammo;
	int					s_pistol_ammo;
	t_sprite			*enemy_target;
	size_t				score;
	uint8_t				player_hit;
	int					difficulty;
	int					endgame;
	SDL_TimerID			endgame_timer;
	int					printscore;
}						t_elem;

/*
** Structure Programme
*/
typedef struct			s_map
{
	t_elem				*floor;
	char				*file;
	char				*line;
	char				*tmp;
	int					fd;
	int					i;
	int					hight;
	int					width;
	int					error;
	int					max_floor;
}						t_map;

/*
** Structure SDL Variables
*/

typedef struct			s_env
{
	SDL_Texture			*cursors[2];
	SDL_Rect			rectcursor;
	int					cursx;
	int					cursy;
	int					cx;
	int					cy;
	SDL_TimerID			timer;
	SDL_TimerID			timer2;
	SDL_Rect			rectfps;
	SDL_Rect			rect_intro;
	SDL_Rect			rect_baba;
	SDL_Texture			*fpstext;
	SDL_Rect			*rect;
	SDL_Texture			*text;
	SDL_Texture			*text2;
	SDL_Surface			*surf;
	SDL_Surface			*surf2;
	SDL_Surface			*foresurf;
	SDL_Surface			**wall_texture;
	SDL_Surface			*floor_texture;
	SDL_Surface			*ceiling_texture;
	SDL_Surface			*icon;
	SDL_Surface			**weapon;
	int					test;
	SDL_Renderer		*ren;
	SDL_Window			*win;
	SDL_Event			events;
	SDL_Texture			*bmptex;
	SDL_Texture			*fonttex;
	SDL_Texture			*fonttex2;
	SDL_Surface			*bmpsurf;
	SDL_Surface			*texte;
	TTF_Font			*police;
	TTF_Font			*police2;
	SDL_Color			color;
	SDL_Color			red;
	SDL_Rect			pos;
	SDL_Rect			pos2;
	SDL_Texture			*streamingtex;
	int					width;
	int					height;
	int					error_vid;
	int					introstep;
	int					intro;
	int					option;
	int					escape;
	int					play_ready;
	int					startmenu;
	int					startmenu_choice;
	int					vid_menu;
	int					video_choice;
	int					settings_menu;
	int					settings_choice;
	int					gameplay_menu;
	int					game_choice;
	int					controls_menu;
	int					controls_choice;
	int					dif_op;
	int					sensitivity_op;
	int					sens_value;
	char				*sensitivity_value;
	int					audio_menu;
	int					audio_choice;
	int					apply_audio_op;
	int					effect_op;
	int					music_op;
	int					int_volume_value;
	char				*char_volume_value;
	int					play_menu;
	int					play_choice;
	int					story_menu;
	int					story_difficulty;
	int					arcade_menu;
	int					arcade_choice;
	int					arcade_map;
	int					res_op;
	int					vsync_op;
	int					fs_op;
	int					gpu_op;
	int					aliasing_op;
	int					text_q_op;
	int					apply_video_op;
	int					p;
	double				res_width;
	double				res_hight;
	SDL_Rect			rect_life;
	SDL_Texture			**text_intro;
	int					next_stage;
	int					last_intro;
	t_audio				audio;
	t_hud				hud;
	int					switchlock;
	SDL_Texture			*gameover1;
	SDL_Texture			*gameover2;
	t_sprite			*spriteorder[4096];
	double				spritedistance[4096];
	uint8_t				*window_buffer;
	double				*zbuffer;
	double				*sprite_zbuffer;
	uint16_t			*dst_buffer;
	uint16_t			*dend_buffer;
	SDL_TimerID			torch_timer;
}						t_env;

/*
** Structure SDL FLAGS
*/

typedef struct			s_sdl
{
	double				res_width;
	double				res_hight;
	int					windowed;
	int					windowed_resize_full;
	int					fullscreen;
	int					fullscreen_maxres;
	int					hard_accel;
	int					vsync;
	int					w_max;
	int					h_max;
	int					test;
	double				pro_hight;
	double				pro_width;
}						t_sdl;

/*
** Structure THREADS
*/

typedef struct			s_thread
{
	pthread_t			thread;
	int					x;
	int					xend;
	t_elem				*floor;
	t_env				*env;
}						t_thread;

double					ft_floor(double nb);
char					*ftoa(double n, char *res);
int						ft_ctoi(const char *str);

/*
** Related SDL INIT / RENDER Functions
*/
int						ft_set_sdl(t_sdl *sdl, t_env *env, t_elem *floor);
int						ft_init_events(t_env *env, t_sdl *sdl, t_elem *floor);
void					ft_initgame(t_env *env, t_elem *floor);
int						ft_error(int error);
int						ft_exit_sdl(t_env *env);
int						ft_set_ttf(t_sdl *sdl, SDL_Surface *bmpsurf);
void					ft_sdlputerror(void);
void					load_font(t_env *env);

/*
** Related SDL RENDER Functions
*/
SDL_Renderer			*ft_init_renderer(SDL_Window *win, t_sdl *sdl,
						t_env *env);

/*
** Window events setup
*/
SDL_Window				*ft_create_window(t_sdl *sdl);
void					get_max_res(t_sdl *sdl);

/*
** Setup struct
*/
void					reload_sdlparams(t_sdl *sdl, t_env *env);

/*
** Set Menu
*/
int						start_editor(t_env *env, t_sdl *sdl, t_elem *elem);
void					set_events_struct(t_env *env);
void					open_options(t_env *env);
int						exit_from_menu(t_env *env);
void					videos_menu(t_env *env, t_sdl *sdl);
void					start_menu_event(t_env *env, int x, int y);
void					settings_event(t_env *env, int x, int y);
int						apply_menu(t_env *env, t_sdl *sdl, t_elem *floor,
						SDL_Event *event);
void					option_event(t_env *env, int x, int y);
void					apply_option(t_env *env, SDL_Event *event);
void					apply_video(t_env *env, t_elem *floor,
						SDL_Event *event);
void					video_event(t_env *env, int x, int y);
void					back_to_option(t_env *env);
void					apply_video_settings(t_sdl *sdl, t_env *env,
						t_elem *floor);
void					play_settings(t_env *env);
int						menu_events_list(t_env *env, t_sdl *sdl,
						t_elem *floor);
SDL_Rect				s_rect(double x, double y, double w, double h);
int						rsx(t_env *env, double x);
int						rsy(t_env *env, double y);
int						rsw(t_env *env, double w);
int						rsh(t_env *env, double h);
void					set_ttf_rect_xy(t_env *env, double x, double y);
void					set_ttf_rect_wh(t_env *env, double w, double h);
void					error_option(t_sdl *sdl, t_env *env);
void					gameplay_event(t_env *env, int x, int y);
void					apply_gameplay(t_env *env, t_elem *floor,
						SDL_Event *event);
void					audio_event(t_env *env);
void					play_event(t_env *env, int x, int y);
void					apply_play(t_env *env, SDL_Event *event);
void					story_event(t_env *env, int x, int y);
void					apply_story(t_env *env, SDL_Event *event);
void					arcade_event(t_env *env, int x, int y, int max);
void					apply_arcade(t_env *env, SDL_Event *event, int y);
void					control_event(t_env *env);
void					draw_cursor(t_env *env, SDL_Event *event);
void					audio_event(t_env *env);
void					draw_audio_menu(t_sdl *sdl, t_env *env);
void					exit_from_audio(t_env *env);
void					apply_audio_op(t_env *env);
void					menu_apply_audio(t_env *env);
int						test_return(int check, SDL_Event *event);
void					audio_menu_event(t_env *env, int x, int y);
void					apply_menu_audio(t_env *env, SDL_Event *event);
void					controls_event(t_env *env, int x, int y);
void					apply_controls(t_env *env, SDL_Event *event);
void					draw_difficulty(t_sdl *sdl, t_env *env);
void					draw_sensitivity(t_sdl *sdl, t_env *env);
void					draw_menus(t_env *env, t_sdl *sdl);
void					draw_menu_start(t_env *env);
void					draw_menu_gameplay(t_sdl *sdl, t_env *env);
void					draw_menu_audio(t_sdl *sdl, t_env *env);
void					draw_menu_video(t_sdl *sdl, t_env *env);
void					draw_menu_interface(t_env *env);
void					draw_menu_settings(t_env *env);
void					draw_menu_play(t_env *env);
void					draw_menu_story(t_env *env);
void					draw_menu_arcade(t_env *env);
void					draw_menu_controls(t_env *env);
void					draw_vsync_text(t_sdl *sdl, t_env *env);
void					draw_res_text(t_sdl *sdl, t_env *env);
void					draw_gpu_text(t_sdl *sdl, t_env *env);
void					draw_fullscreen_text(t_sdl *sdl, t_env *env);
void					apply_settings(t_env *env, SDL_Event *event);
void					menu_apply_audio_params(t_env *env);

/*
**Setup map
*/
int						ft_checkfilename(char *file);
int						ft_parse_map_param(t_map *map);
int						ft_parsemapret(t_elem *floor);
int						get_next_line(const int fd, char **line);
int						ft_filwidth(t_elem *floor);
int						ft_checkspawn(t_elem *floor, int i, int j);
void					ft_checkspawneditor(t_elem *floor);
int						ft_checkfloors(t_elem *floor);
char					*join_free(char *s1, char *s2);
void					ft_printmap(t_elem *floor);
void					ft_newmap(t_elem *floor);
void					ft_filmap(t_elem *floor);
int						ft_wolfcheck(t_elem *floor);
int						ft_checkvalue(t_elem *floor);
void					ft_restore_backup(t_elem *floor);

/*
**Display Game
*/
void					init_story(t_env *env, t_elem *floor);
void					init_arcade(t_env *env, t_elem *floor);
int						ft_display_game(t_env *env, t_elem *floor);
void					init_game(t_env *env, t_elem *floor,
						t_thread **threads);
void					ft_escape(t_env *env, t_elem *floor, t_thread *threads);
int						game_events(t_env *env, t_elem *floor,
						t_thread *threads);
void					init_threads(t_thread *threads, t_env *env,
						t_elem *floor);
void					ft_set_pixels(t_env *env, t_elem *floor);
void					ft_crosshair(t_env *env);
void					ft_minimap(t_env *env, t_elem *floor);
void					ft_radar(t_env *env, t_elem *floor);
void					ft_drawcompass(int x, int y, t_env *env, t_elem *floor);
char					*ftoa(double n, char *res);
void					ft_intro(t_env *env, t_elem *floor);
void					ft_init_intro(t_env *env);
uint32_t				ft_speak(uint32_t interval, void *param);
void					ft_render_intro(t_env *env);
void					ft_baba(t_env *env);
void					ft_intro_content_p1(t_env *env);
void					ft_intro_content_p2(t_env *env);
void					ft_intro_helper(t_env *env, int rectw, int recth);
void					ft_intro_baba(t_env *env);
void					ft_baba_image(t_env *env);
void					ft_render(t_env *env, t_elem *floor, t_thread *threads);
void					ft_intro_lvl1(t_env *env, t_elem *floor);
void					ft_intro_lvl2(t_env *env, t_elem *floor);
void					ft_intro_lvl3(t_env *env, t_elem *floor);
void					ft_render_story(t_env *env, char *str,
						SDL_Texture *texture, SDL_Rect rect);
void					ft_credits(t_env *env, t_elem *floor);
uint32_t				timer_endgame(uint32_t interval, void *param);
void					ft_play_intros(t_env *env, t_elem *floor);

/*
** PIXELS
*/
void					ft_putpixel(SDL_Surface *surf, int x, int y,
						uint32_t color);
uint32_t				ft_readpixel(SDL_Surface *surf, int x, int y);
void					ft_bresenham(SDL_Surface *surf, t_pixel pixel0,
						t_pixel pixel1, uint32_t color);
void					ft_drawrect(SDL_Surface *surf,
						uint32_t color, t_rect rect);

/*
** RENDERER
*/
void					ft_initcolors(t_elem *floor);
void					ft_initraycasting(t_elem *floor);
void					ft_rayhelper(t_env *env, t_elem *floor, t_ray *ray);
void					ft_raycasting(t_env *env, t_elem *floor);
void					ft_drawrenderer(t_env *env, t_elem *floor,
						t_thread *threads);
void					ft_video_op_error(t_sdl *sdl, t_env *env);
void					ft_hit(t_env *env, t_elem *floor, t_ray *ray,
						int iteration);
void					ft_step(t_ray *ray);
void					ft_setupray(t_env *env, t_elem *floor, t_ray *ray);
void					calc_window(t_env *env, t_elem *floor, t_ray *ray,
						int i);
int						hit_windows(t_elem *floor, t_ray *ray, int max);

/*
** TEXTURE
*/
SDL_Texture				*load_bmp_to_texture(SDL_Renderer *renderer,
						char *file);
SDL_Texture				*load_ttf_to_texture(SDL_Renderer *renderer, char *str,
						TTF_Font *font, SDL_Color col);
SDL_Surface				*ft_load_texture(char *file);
void					ft_init_texture(t_env *env, t_elem *floor);
void					ft_texnum(t_elem *floor, t_ray *ray);
void					ft_walltexture(t_elem *floor);
void					ft_ceilingtexture(t_elem *floor);
void					ft_floortexture(t_elem *floor);
void					ft_lvl3textureepic(t_elem *floor);
void					ft_lvl3texturehigh(t_elem *floor);
void					ft_lvl3texturenormal(t_elem *floor);
void					ft_draw_walltextured(t_env *env, t_elem *floor,
						t_ray *ray, int i);
void					setup_wall(t_env *env, t_elem *floor, t_ray *ray,
						int *dend);
void					ft_drawfloorceiling(t_env *env, t_elem *floor,
						t_ray *ray, int draw);
void					load_skyboxes(t_env *env, t_elem *floor);
void					draw_skybox(t_env *env, t_elem *elem, t_skybox *skybox);
void					ft_load_intro_textures(t_env *env);
void					ft_ceiling_textnum(t_elem *floor, t_ray *ray,
						uint32_t *color);
void					ft_floor_textnum(t_elem *floor, t_ray *ray,
						uint32_t *color);
void					ft_wall_textnum(t_elem *floor, t_ray *ray);
uint32_t				ft_ntext(uint32_t interval, void *param);
void					draw_window(t_env *env, t_elem *floor, t_ray *ray,
						int i);
void					draw_sprites(t_env *env, t_elem *floor);
void					draw_window(t_env *env, t_elem *floor, t_ray *ray,
						int i);

void					load_sprites_textures(t_elem *floor);
void					load_sprites_textures_p2(t_elem *floor, int i);
void					load_sprites_textures_p3(t_elem *floor, int i);
void					load_sprites_textures_p4(t_elem *floor, int i);
void					load_sprites_textures_p5(t_elem *floor, int i);
void					load_sprites_textures_p6(t_elem *floor, int i);
void					load_sprites_textures_p7(t_elem *floor, int i);
void					load_sprites_textures_p8(t_elem *floor, int i);
void					load_sprites_textures_p9(t_elem *floor, int i);
void					load_sprites_textures_p10(t_elem *floor, int i);
void					load_sprites_textures_p11(t_elem *floor, int i);
void					load_sprites_textures_p12(t_elem *floor, int i);
void					load_sprites_textures_p13(t_elem *floor, int i);
void					load_sprites_textures_p14(t_elem *floor, int i);
void					load_sprites_textures_p15(t_elem *floor, int i);
void					load_sprites_textures_p16(t_elem *floor, int i);
void					load_sprites_textures_p17(t_elem *floor, int i);
void					load_sprites_textures_p18(t_elem *floor, int i);
void					load_sprites_textures_p19(t_elem *floor, int i);
void					load_sprites_textures_p20(t_elem *floor, int i);
void					load_sprites_textures_p21(t_elem *floor, int i);
void					load_sprites_textures_p22(t_elem *floor, int i);
void					load_sprites_textures_p23(t_elem *floor, int i);
void					search_items(t_elem *floor, int num, int activate);

/*
** MOVES
*/
void					ft_inputs(t_env *env, t_elem *floor);
void					ft_mousemotion(t_env *env, t_elem *floor);
void					ft_dispminimap(t_env *env, t_elem *floor);
void					ft_speedshift(t_env *env, t_elem *floor);
void					ft_movements(t_env *env, t_elem *floor);
void					ft_walk(t_elem *floor);
void					ft_dive(t_elem *floor);
void					ft_crouch(t_env *env, t_elem *floor);
void					ft_jump(t_env *env, t_elem *floor);
void					ft_fly(t_env *env, t_elem *floor);
uint32_t				ft_flyup(uint32_t interval, void *param);
uint32_t				ft_flydown(uint32_t interval, void *param);
void					ft_warptonextfloor(t_env *env, t_elem *floor);
void					ft_warptowarp(t_elem *floor);
void					ft_warp(t_env *env, t_elem *floor);
int						ft_rand_range(int min, int max, int except);
void					ft_moves_wasd(t_elem *floor);
void					ft_moves_wasd_noclip(t_elem *floor);
void					ft_move_front_back(t_elem *floor, int nb,
						double framespeed);
void					ft_messages(t_env *env, t_elem *floor);
void					ft_game_msg(t_env *env, t_elem *floor);
void					ft_printscore(t_env *env, t_elem *floor, int alive);
void					ft_godmode(t_elem *floor);
void					ft_godmode_toggle(t_env *env, t_elem *floor);
void					ft_godmode_toggle_on(t_elem *floor);
void					ft_godmode_toggle_off(t_elem *floor);

/*
** ITEMS
*/
void					ft_balloon(t_elem *floor);
void					ft_ticket(t_elem *floor);
void					ft_lollipop(t_elem *floor);
void					ft_items_hud(t_elem *floor);
void					ft_medkit(t_elem *floor);
void					ft_weapons(t_elem *floor);
void					ft_ammos(t_elem *floor);
void					ft_sprite_torch(t_elem *floor);
void					ft_torch_toogle(t_env *env, t_elem *floor);

/*
** RAGDOLL
*/
void					ft_ragdoll(t_elem *floor);
void					ft_ragdoll_up(t_elem *floor);
void					ft_ragdoll_above50(t_elem *floor);
void					ft_printragdoll(t_env *env, t_elem *floor);
uint32_t				ft_ragdoll_base_down(uint32_t interval, void *param);
uint32_t				ft_ragdoll_base_up(uint32_t interval, void *param);
void					ft_ragdoll_timerdown(t_elem *floor, double speedragdoll,
						int ragdoll, double ragdollsensi);
void					ft_ragdoll_timerup(t_elem *floor, double speedragdoll,
						int ragdoll, double ragdollsensi);

/*
** HUD
*/
void					ft_draw_hud(t_env *env, t_elem *floor);
uint32_t				ft_printfps(uint32_t interval, void *param);
void					ft_countfps(t_elem *floor);
void					ft_initfps(t_elem *floor, t_env *env);
void					ft_fpsrender(t_env *env, t_elem *floor);
void					ft_print_life(t_env *env, t_elem *floor);
void					ft_print_hud(t_env *env, t_elem *floor);
void					ft_print_fire_stat(t_env *env, int stat);
void					ft_print_ammos(t_env *env, t_elem *floor);
void					ft_set_hud_rect(t_env *env);
void					ft_load_hud_textures(t_env *env, t_elem *floor);
void					ft_load_head_guy_texture(t_env *env);
void					ft_head_guy(t_env *env, t_elem *floor);
uint32_t				ft_head_guy_timer(uint32_t interval, void *param);
void					ft_print_skull(t_env *env, t_elem *floor);
void					ft_init_hud(t_env *env);

/*
** Free Structs
*/
void					ft_free_tab_telem(t_elem **floor);
void					ft_freetab(char ***tab);
void					ft_freebigtab(char ****tab);
void					ft_free_surface(SDL_Surface **surface);
void					ft_free_texture(SDL_Texture **texture);
void					ft_free_structs(t_env *env, t_map *map, t_elem *floor,
						int exit);
void					ft_sdl_error(char *str);
void					ft_ttf_error(char *str);
void					ft_fct_error(char *str);
void					ft_free_surface_tab(SDL_Surface ***surfaces);
void					free_sound(t_audio *audio);
void					ft_free_hud(t_hud *hud);
void					ft_free_skyboxes(t_elem *floor);
void					ft_free_twall(t_tab_wall *tab);
void					ft_remove_timers(t_env *env, t_elem *floor);
void					ft_free_sprite_data(t_elem *floor);
void					ft_lstdelsprite(t_list **alst);
void					ft_free_between(t_env **env, t_elem **floor);
void					ft_free_floor(t_elem **floor);
void					ft_free_env_1(t_env *env);
void					ft_free_env_2(t_env *env);
void					ft_free_map_struct(t_map *map);

/*
** AUDIO
*/
void					load_sounds(t_audio *audio);
void					load_sounds_p5(t_audio *audio);
int						init_fmod(t_audio *audio, int music_op);
int						change_sound_in_channel(t_audio *audio,
						FMOD_SOUND *sound, FMOD_CHANNEL **channel, int paused);
void					change_walk_audio(t_env *env, t_elem *elem);
void					change_channel_state(t_env *env, FMOD_CHANNEL *channel,
						int flags);
int						gameover(t_env *env, t_thread *threads, t_elem *floor);
int						init_gameover(t_env *env, int *hover,
						int *ret, t_elem *floor);
void					pause_soundeffects(t_audio *audio);
void					play_simple(t_audio *audio, t_soundeffects_ids enum1,
						t_channels enum2, int force);
void					ft_sound_events(t_env *env, t_elem *floor);

/*
** RESET
*/
void					ft_restart(t_env *env, t_elem *floor);
void					ft_reset(t_env *env, t_elem *elem);
void					ft_setup_level4(t_env *env, t_elem *floor);
void					ft_setup_level3(t_env *env, t_elem *floor);
void					ft_setup_level2(t_env *env, t_elem *floor);
void					ft_setup_level1(t_env *env, t_elem *floor);
void					ft_setup_level_helper(t_env *env, t_elem *floor);
void					ft_arcade_circus(t_env *env, t_elem *floor);
void					ft_arcade_mine(t_env *env, t_elem *floor);
void					ft_arcade_magma(t_env *env, t_elem *floor);
void					ft_arcade_custom(t_env *env, t_elem *floor);

/*
** EFFECTS
*/
uint32_t				init_rain(uint32_t interval, void *param);
uint32_t				fog_rain(uint32_t interval, void *param);
void					rain(t_env *env);
void					init_bubble(t_env *e, t_elem *floor);
void					ft_free_texture_tab(SDL_Texture ***texture);
void					ft_bubble(t_env *e, t_elem *floor);
uint32_t				ft_bubble_progress(uint32_t interval, void *param);
uint32_t				ft_create_bubble(uint32_t interval, void *param);
void					start_bubbles(t_env *env, t_elem *floor);
SDL_Rect				*ft_rect(int x, int y, int w, int h);
void					manage_fog(t_env *env, t_elem *floor);
uint32_t				wall_fog(t_elem *floor, int percent, uint32_t col);
uint32_t				floor_fog(t_elem *floor, t_ray *ray, uint32_t col);
uint32_t				color_grad(unsigned int cola, unsigned int colb,
						int percent);
void					found_dist(t_ray *ray);
void					found_distfloor(t_elem *floor);
void					ft_reflections(t_env *env, t_elem *floor);
uint32_t				mix_colors(t_env *env, t_ray *ray, uint32_t color,
						int y);
void					renderer_aftereffect(t_env *env, t_elem *floor);
void					init_negativ(t_env *env);
void					rain2(t_env *env);
void					*raycast_thread(void *ptr);
void					*windowcast_thread(void *ptr);
void					start_threads(t_thread *threads, t_env *env,
						t_elem *floor, void *(fct(void*)));
void					ft_effects(t_env *env, t_elem *floor);
void					bullet_impact(t_elem *floor, t_tab_wall *tab,
						int nbtab);
void					bullet_impact_init(t_elem *floor);
void					verif_shotgun(t_elem *floor, int nwall, SDL_Rect *rect,
						t_wall *wall_impact);
int						ft_side(int side, double rdirx, double rdiry);
int						search_wall(t_elem *floor, t_ray *ray, t_tab_wall *tab);
int						search_wall2(t_elem *floor, t_ray *ray,
						t_tab_wall *tab);
void					init_negatifflash(t_elem *floor);
void					flashnegatif(t_elem *floor);
void					ft_enable_rain(t_env *env, t_elem *floor);
void					ft_disable_rain(t_env *env, t_elem *floor);
void					ft_stoprain(t_env *env, t_elem *floor);

/*
** SPRITES
*/

void					store_sprites(t_env *env, t_elem *floor);
void					calc_sprite(t_env *env, t_elem *floor,
						t_spritecast *spr);
uint32_t				mix_argb(uint32_t colora, uint32_t colorb);
void					set_sprites_texture_ids_p5(t_sprite_data *sprites_data,
						int i);
void					init_sprites_data(t_sprite_data *sprites_data);
void					init_sprites_data_p6(t_sprite_data *sprites_data);
void					set_sprites_texture_ids(t_sprite_data *sprites_data);
void					set_sprites_texture_ids_p5(t_sprite_data *sprites_data,
						int i);
uint32_t				torch_anim(uint32_t interval, void *param);
uint32_t				enemy1_anim(uint32_t interval, void *param);
uint32_t				enemy2_anim(uint32_t interval, void *param);
uint32_t				enemy3_anim(uint32_t interval, void *param);
uint32_t				enemy4_anim(uint32_t interval, void *param);
uint32_t				boss_anim(uint32_t interval, void *param);
uint32_t				devastator_anim(uint32_t interval, void *param);
uint32_t				warptowarp_anim(uint32_t interval, void *param);
uint32_t				warpfloor_anim(uint32_t interval, void *param);
uint32_t				enemy1_dead_anim(uint32_t interval, void *param);
uint32_t				enemy_dead_anim(uint32_t interval, void *param);
uint32_t				enemy_dead_boss_anim(uint32_t interval, void *param);
uint32_t				explosion_anim(uint32_t interval, void *param);
void					load_map_sprites(t_env *env, t_elem *floor);
t_sprite				*add_sprite(t_env *env, t_elem *floor, char *type);
t_sprite				*add_projectile(t_env *env, t_elem *floor, int type,
						t_sprite *param);
void					init_sprite(t_elem *floor, t_sprite *sprite);
t_sprite				*set_sprite_type(t_sprite *sprite, char *type);
void					free_spritefree_sprite(t_list *sprite);
void					remove_item(t_list **list, int x, int y);
void					remove_sprite(t_list **list, t_sprite *sprite);
void					attack_enemy(t_elem *floor, t_sprite *target,
						t_sprite *projectile, double dist);
void					killed_enemy(t_elem *floor, t_sprite *target);
void					normalize_vec2d(double *dirx, double *diry);
void					enemy_attack(t_env *env, t_elem *floor,
						t_sprite *sprite);
void					search_items(t_elem *floor, int num, int activate);
int						try_hit_projectile(t_elem *floor, t_sprite *sprite,
						double nextx, double nexty);
uint32_t				timer_hit(uint32_t interval, void *param);
void					handle_enemies(t_env *env, t_elem *floor);
void					enemy_idle(t_elem *floor, t_sprite *sprite);
void					fill_poswall_add(t_elem *floor, t_wall *mywall);
void					rotate_enemy(t_sprite *sprite);
int						try_move(t_elem *floor, t_sprite *sprite, double speed);
void					sight_hit(t_elem *floor, t_ray *ray);
uint32_t				timer_idle(uint32_t interval, void *param);
void					enemy_action(t_elem *floor, t_sprite *sprite,
						int action);
int						check_enemy(t_env *env, t_elem *floor, t_sprite *enemy);
int						check_sight(t_env *env, t_elem *floor, t_sprite *enemy,
						t_ray *ray);
void					raycast_sight(t_elem *floor, t_ray *ray);
void					remove_sprites(t_elem *floor);
void					place_sprite_hitbox(t_elem *floor, t_sprite *sprite,
						double nextposy, double nextposx);
void					update_enemies(t_elem *floor);

/*
** WEAPONS
*/
void					ft_set_weapons_rect(t_env *env);
void					ft_load_weapons_textures(t_env *env);
void					ft_set_weapon_struct(t_env *env);
void					ft_load_shotgun_textures(t_env *env);
void					ft_draw_dev(t_env *env, t_elem *floor);
void					ft_draw_pistol(t_env *env, t_elem *floor);
void					ft_draw_shotgun(t_env *env, t_elem *floor);
void					ft_draw_fist(t_env *env);
void					ft_render_weapons(t_env *env, t_elem *floor);
void					ft_weapons_events(t_env *env, t_elem *floor);
void					ft_event_dev(t_env *env, t_elem *floor);
void					ft_event_pistol(t_env *env, t_elem *floor);
void					ft_event_shotgun(t_env *env, t_elem *floor);
void					ft_event_fist(t_env *env, t_elem *floor);
uint32_t				ft_weapons_timer(uint32_t interval, void *param);
uint32_t				ft_set_fist_timer(t_env *env);
uint32_t				ft_reload_timer(uint32_t interval, void *param);
uint32_t				ft_spend_ammo_timer(uint32_t interval, void *param);
void					ft_set_floor_to_hud_weapons(t_env *env, t_elem *floor);
int						ft_shotgun_reload_amount(t_elem *floor);
uint32_t				ft_shotgun_amount_steps(t_env *env);
uint32_t				ft_shotgun_timer2(t_env	*env);
uint32_t				ft_pistol_timer2(t_env	*env);
void					ft_set_weapon(t_elem *floor, int pistol, int shotgun,
						int dev);
void					ft_switch_weapon_down(t_hud *hud, t_elem *floor);
void					ft_switch_weapon_up(t_hud *hud, t_elem *floor);
void					init_counter(t_elem *floor, int time);
void					ft_message_setup(t_env *env, t_elem *floor, char *str);
void					print_counter(t_env *env, t_elem *floor);
void					fill_poswall(t_elem *floor, t_ray *ray, t_wall *mywall);
void					fill_poswall2(t_elem *floor, t_ray *ray,
						t_wall *mywall);
#endif
