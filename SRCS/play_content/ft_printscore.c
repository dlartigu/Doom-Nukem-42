/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printscore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:53:35 by dlartigu          #+#    #+#             */
/*   Updated: 2020/11/18 01:54:46 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	int		ft_printscore_setupy(t_env *env, int alive)
{
	int			y;

	if (alive == 0)
		y = env->res_hight / 20;
	if (alive == 1)
		y = env->res_hight / 4;
	return (y);
}

static	int		ft_printscore_setupx(t_env *env, int alive)
{
	int			x;

	if (alive == 0)
		x = env->res_width / 8;
	if (alive == 1)
		x = env->res_width / 20;
	return (x);
}

static	void	ft_printscore_free(char *res, char *str)
{
	ft_strdel(&res);
	ft_strdel(&str);
}

static	void	ft_printscore_helper(t_env *env, int x, int y)
{
	env->hud.rect_pscore = s_rect(x, y,
			env->res_hight / 4, env->res_hight / 20);
	SDL_RenderCopy(env->ren, env->hud.pscore, NULL, &env->hud.rect_pscore);
}

void			ft_printscore(t_env *env, t_elem *floor, int alive)
{
	char		*res;
	char		*str;

	if (env->hud.pscore)
		SDL_DestroyTexture(env->hud.pscore);
	if (floor->printscore == 1)
	{
		res = ft_itoa((int)floor->score);
		str = ft_strjoin("Your Score: ", res);
		env->hud.pscore = load_ttf_to_texture(env->ren, str,
			floor->fpsfont, floor->msg);
		ft_printscore_helper(env, ft_printscore_setupx(env, alive),
			ft_printscore_setupy(env, alive));
		ft_printscore_free(res, str);
	}
}
