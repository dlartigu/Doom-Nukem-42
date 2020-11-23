/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:53:36 by jcharrou          #+#    #+#             */
/*   Updated: 2020/11/19 16:53:35 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void	init_structs(t_sdl *sdl, t_map *map, t_env *env)
{
	ft_bzero((void*)sdl, sizeof(t_sdl));
	ft_bzero((void*)map, sizeof(t_map));
	ft_bzero((void*)env, sizeof(t_env));
}

int			main(void)
{
	t_sdl	sdl;
	t_map	map;
	t_env	env;

	init_structs(&sdl, &map, &env);
	set_events_struct(&env);
	map.file = "maps/doom.frst";
	if (ft_parse_map_param(&map) != 0)
	{
		ft_free_structs(&env, &map, map.floor, 1);
		return (ft_error(4));
	}
	else
	{
		reload_sdlparams(&sdl, &env);
		ft_set_sdl(&sdl, &env, map.floor);
	}
	ft_free_structs(&env, &map, map.floor, 1);
	return (0);
}
