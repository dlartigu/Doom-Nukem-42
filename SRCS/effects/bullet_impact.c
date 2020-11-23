/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_impact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:00:17 by idris             #+#    #+#             */
/*   Updated: 2020/11/15 03:43:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	draw_shotgun(t_elem *floor, int nwall, t_wall *wall_impact)
{
	SDL_Rect	rect;
	int			i;
	int			x;
	int			y;

	i = 0;
	x = floor->taketexx - floor->bullet->w / 2;
	y = floor->taketexy - floor->bullet->h / 2;
	rect.h = floor->bullet->h;
	rect.w = floor->bullet->w;
	while (i < 5)
	{
		if (rand() % 2 == 1)
		{
			rect.x = x + rand() % 5;
			rect.y = y + rand() % 5;
		}
		else
		{
			rect.x = x - rand() % 5;
			rect.y = y - rand() % 5;
		}
		verif_shotgun(floor, nwall, &rect, wall_impact);
		i++;
	}
}

int		search_wall_add(t_elem *floor, t_tab_wall *tab)
{
	int	i;

	i = 0;
	while (i < tab->number_wall)
	{
		if (tab->wall_impact[i].mapx == floor->lastwall.mapx
		&& tab->wall_impact[i].mapy == floor->lastwall.mapy
		&& tab->wall_impact[i].side == floor->lastwall.side
		&& tab->wall_impact[i].blockheight == floor->lastwall.blockheight)
			return (i);
		i++;
	}
	return (-1);
}

void	draw_impact(t_elem *floor, int nwall, t_wall *wall_impact)
{
	SDL_Rect	rect;
	SDL_Rect	verif;

	if (floor->pistol_selected)
	{
		rect.h = floor->bullet->h;
		rect.w = floor->bullet->w;
		rect.x = floor->taketexx - floor->bullet->w / 2;
		rect.y = floor->taketexy - floor->bullet->h / 2;
		if (floor->taketexx < wall_impact[nwall].tex->w / 2)
			verif.x = rect.x;
		else
			verif.x = floor->taketexx + floor->bullet->w / 2;
		if (floor->taketexy < wall_impact[nwall].tex->w / 2)
			verif.y = rect.y;
		else
			verif.y = floor->taketexy + floor->bullet->h / 2;
		if ((verif.x > 0 && verif.x < wall_impact[nwall].tex->w
		&& verif.y > 0 && verif.y < wall_impact[nwall].tex->h)
		&& ft_readpixel(wall_impact[nwall].tex, verif.x, verif.y) && 0xff > 0)
			SDL_BlitSurface(floor->bullet, NULL, wall_impact[nwall].tex, &rect);
	}
	if (floor->shotgun_selected)
		draw_shotgun(floor, nwall, wall_impact);
}

void	bullet_impact2(t_elem *floor, t_tab_wall *tab, int nbtab, int *nwall)
{
	if (nbtab == 0)
	{
		tab[nbtab].wall_impact[tab[nbtab].number_wall].tex =
		SDL_CreateRGBSurface(0,
		floor->walltext[floor->taketxtnum]->w,
		floor->walltext[floor->taketxtnum]->h,
		32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
		SDL_BlitSurface(floor->walltext[floor->taketxtnum],
		NULL, tab[nbtab].wall_impact[tab[nbtab].number_wall].tex, NULL);
	}
	else
	{
		tab[nbtab].wall_impact[tab[nbtab].number_wall].tex =
		SDL_CreateRGBSurface(0,
		floor->animatedwalltext[floor->ntext]->w,
		floor->animatedwalltext[floor->ntext]->h,
		32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
		SDL_BlitSurface(floor->animatedwalltext[floor->ntext],
		NULL, tab[nbtab].wall_impact[tab[nbtab].number_wall].tex, NULL);
	}
	*nwall = tab[nbtab].number_wall;
	tab[nbtab].number_wall++;
}

void	bullet_impact(t_elem *floor, t_tab_wall *tab, int nbtab)
{
	int	nwall;

	nwall = search_wall_add(floor, &tab[nbtab]);
	if (nwall == -1)
	{
		if (tab[nbtab].number_wall < WALLIMPSIZE)
			bullet_impact2(floor, tab, nbtab, &nwall);
		else
		{
			if (tab[nbtab].oldest_wall == WALLIMPSIZE)
				tab[nbtab].oldest_wall = 0;
			if (nbtab == 0)
				SDL_BlitSurface(floor->walltext[floor->taketxtnum],
				NULL, tab[nbtab].wall_impact[tab[nbtab].oldest_wall].tex, NULL);
			else
				SDL_BlitSurface(floor->animatedwalltext[floor->ntext],
				NULL, tab[nbtab].wall_impact[tab[nbtab].oldest_wall].tex, NULL);
			nwall = tab[nbtab].oldest_wall;
			tab[nbtab].oldest_wall++;
		}
		fill_poswall_add(floor, &tab[nbtab].wall_impact[nwall]);
	}
	draw_impact(floor, nwall, tab[nbtab].wall_impact);
}
