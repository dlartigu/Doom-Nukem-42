/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_arcade.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:11:38 by jcharrou          #+#    #+#             */
/*   Updated: 2020/09/08 02:04:27 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void	load_menu_image(t_env *env)
{
	if (env->arcade_choice == 0 && env->arcade_map == 0 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_CIRCUS_0)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 1 && env->arcade_map == 0 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_CIRCUS_1)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 0 && env->arcade_map == 1 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_MINE_0)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 1 && env->arcade_map == 1 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_MINE_1)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 0 && env->arcade_map == 2 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_MAGMA_0)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 1 && env->arcade_map == 2 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_MAGMA_1)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 0 && env->arcade_map == 3 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_CUSTOM_0)))
		ft_fct_error("load_bmp");
	else if (env->arcade_choice == 1 && env->arcade_map == 3 &&
		!(env->text = load_bmp_to_texture(env->ren, ARCADE_CUSTOM_1)))
		ft_fct_error("load_bmp");
}

void		draw_menu_arcade(t_env *env)
{
	SDL_RenderClear(env->ren);
	ft_free_texture(&env->text);
	load_menu_image(env);
	SDL_RenderCopy(env->ren, env->text, NULL, NULL);
}
