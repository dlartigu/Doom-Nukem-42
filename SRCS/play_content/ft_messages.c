/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:22:07 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 01:54:44 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_game_msg_setup(t_env *env, t_elem *floor, char *str)
{
	int		w;
	int		h;

	w = env->res_width / 2;
	h = env->res_width / 20;
	floor->msg.r = 255;
	floor->msg.g = 255;
	floor->msg.b = 255;
	floor->msg.a = 0;
	if (env->hud.mtxt)
		SDL_DestroyTexture(env->hud.mtxt);
	env->hud.rect_mtxt = s_rect(env->res_width / 2 - w / 2, env->res_width / 10,
		env->res_width / 2, h);
	env->hud.mtxt = load_ttf_to_texture(env->ren, str, floor->fpsfont,
		floor->msg);
	SDL_RenderCopy(env->ren, env->hud.mtxt, NULL, &env->hud.rect_mtxt);
}

void			ft_game_msg(t_env *env, t_elem *floor)
{
	if (floor->game_msg == 0)
	{
		if (env->hud.mtxt)
			SDL_DestroyTexture(env->hud.mtxt);
	}
	else if (floor->game_msg == 1)
		ft_game_msg_setup(env, floor, "            Press [F] to Fly          ");
	else if (floor->game_msg == 2)
		ft_game_msg_setup(env, floor, "  Press [C] to Dive / [V] to Emmerge  ");
}

void			ft_message_setup(t_env *env, t_elem *floor, char *str)
{
	int		w;
	int		h;

	w = env->res_width / 2;
	h = env->res_width / 20;
	floor->msg.r = 255;
	floor->msg.g = 255;
	floor->msg.b = 255;
	floor->msg.a = 0;
	if (env->hud.stxt)
		SDL_DestroyTexture(env->hud.stxt);
	env->hud.rect_stxt = s_rect(env->res_width / 2 - w / 2, env->res_width / 7,
		env->res_width / 2, h);
	env->hud.stxt = load_ttf_to_texture(env->ren, str, floor->fpsfont,
		floor->msg);
	SDL_RenderCopy(env->ren, env->hud.stxt, NULL, &env->hud.rect_stxt);
}

void			ft_messages(t_env *env, t_elem *floor)
{
	if (floor->message == 0)
	{
		if (env->hud.stxt)
			SDL_DestroyTexture(env->hud.stxt);
	}
	else if (floor->message == 1)
		ft_message_setup(env, floor, "        You Need a Ticket Noob!       ");
	else if (floor->message == 2)
		ft_message_setup(env, floor, "    Press [E] to enlighten your mind  ");
	else if (floor->message == 3)
		ft_message_setup(env, floor, " Press [E] to return into the shadows ");
	else if (floor->message == 4)
		ft_message_setup(env, floor, "       Press [E] to heal yourself     ");
}
