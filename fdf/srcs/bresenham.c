/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:23:02 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/03 21:46:36 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		bresenham(t_point a, t_point b, t_tab *map)
{
	while (1)
	{
		mlx_pixel_put(map->mlx.ptr, map->mlx.window,
			a.x, a.y, 0xFFFFFF);
		if (a.x == b.x && a.y == b.y)
			break ;
		map->algo.e2 = map->algo.err;
		if (map->algo.e2 > -map->algo.dx)
		{
			map->algo.err -= map->algo.dy;
			a.x += map->algo.sx;
		}
		if (map->algo.e2 < map->algo.dy)
		{
			map->algo.err += map->algo.dx;
			a.y += map->algo.sy;
		}
	}
}

void		init_var(t_point a, t_point b, t_tab *map)
{
	map->algo.dx = abs(b.x - a.x);
	map->algo.dy = abs(b.y - a.y);
	map->algo.sx = a.x < b.x ? 1 : -1;
	map->algo.sy = a.y < b.y ? 1 : -1;
	map->algo.err = (map->algo.dx > map->algo.dy ?
	map->algo.dx : -map->algo.dy) / 2;
	bresenham(a, b, map);
}
