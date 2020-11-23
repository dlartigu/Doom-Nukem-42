/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:54:09 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/16 11:36:20 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int				ft_checkfilename(char *file)
{
	int		i;
	char	*cmp;

	cmp = "tsrf.";
	i = 0;
	file = ft_strrev(file);
	while (i < 4)
	{
		if (file[i] != cmp[i])
			return (1);
		i++;
	}
	file = ft_strrev(file);
	return (0);
}

static	int		ft_putendlret(char *str, int ret)
{
	ft_putendl(str);
	return (ret);
}

int				ft_error(int error)
{
	if (error == INIT_SDL)
		return (ft_putendlret("Erreur initialisation SDL", 1));
	else if (error == INIT_WIN)
		return (ft_putendlret("Erreur initialisation de la fenetre", 1));
	else if (error == INIT_REN)
		return (ft_putendlret("Erreur inialisation du renderer", 1));
	else if (error == BAD_ARG)
		return (ft_putendlret("Missing Map!", 1));
	else if (error == BAD_FILE)
		return (ft_putendlret("Wrong file, please provide a right file.", 1));
	else if (error == BAD_FILENAME)
		return (ft_putendlret("Wrong file type!", 1));
	else if (error == BAD_MAP)
		return (ft_putendlret("Bad Map!", 1));
	else if (error == BAD_SPAWN)
		return (ft_putendlret("Bad Spawn!", 1));
	else if (error == BAD_BLOCK)
		return (ft_putendlret("Bad Blocks Size!", 1));
	else
		return (0);
}

void			ft_video_op_error(t_sdl *sdl, t_env *env)
{
	env->gpu_op = 0;
	env->vsync_op = 0;
	SDL_DestroyRenderer(env->ren);
	env->ren = NULL;
	SDL_DestroyWindow(env->win);
	env->win = NULL;
	SDL_Quit();
	reload_sdlparams(sdl, env);
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_sdl_error(NULL);
	if (SDL_Init(SDL_INIT_TIMER))
		ft_sdl_error(NULL);
	env->win = ft_create_window(sdl);
	SDL_GetWindowBrightness(env->win);
	SDL_SetWindowGrab(env->win, SDL_TRUE);
	env->ren = ft_init_renderer(env->win, sdl, env);
	env->error_vid = 1;
}
