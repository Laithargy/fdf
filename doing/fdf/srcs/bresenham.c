/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:40:34 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/30 15:08:14 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			init_var(int x1, int y1, int x2, int y2, t_tab *map)
{
	map->point->ex = abs(x2 - x1);
	map->point->ey = abs(y2 - y1);
	map->point->dx = 2 * map->point->ex;
	map->point->dy = 2 * map->point->ey;
	map->point->dex = map->point->ex;
	map->point->dey = map->point->ey;
	map->point->xin = x1 > x2 ? -1 : 1;
	map->point->yin = y1 > y2 ? -1 : 1;
}

void			calc(int x1, int y1, t_tab *map)
{
	int		i;
	
	i = -1;
	if (map->point->dex >= map->point->dey)
	{
		while (i++ <= map->point->dex)
		{
			mlx_pixel_put(map->mlx.ptr, map->mlx.window, x1, y1, 0xFFFFFF);
			x1 += map->point->xin;
			map->point->ex -= map->point->dy;
			(map->point->ex < 0) ? y1 += map->point->yin : 0;
			(map->point->ex < 0) ? map->point->ex += map->point->dx : 0;
		}
	}
	if (map->point->dex < map->point->dey)
	{
		while (i++ <= map->point->dey)
		{
			mlx_pixel_put(map->mlx.ptr, map->mlx.window, x1, y1, 0xFFFFFF);
			y1 += map->point->yin;
			map->point->ey -= map->point->dx;
			(map->point->ey < 0) ? x1 += map->point->xin : 0;
			(map->point->ey < 0) ? map->point->ey += map->point->dy : 0;
		}
	}
}

void		bresenham(int x1, int y1, int x2, int y2, t_tab *map)
{
	int		i;

	i = 0;
	init_var(x1, y1, x2, y2, map);
	calc(x1, y1, map);
}