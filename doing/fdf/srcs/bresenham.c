/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:40:34 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/12 05:35:15 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		bresenham(t_pos a, t_pos b, t_tab *map)
{
	while (1)
	{
		mlx_pixel_put(map->mlx.ptr, map->mlx.window, a.x, a.y, 0xFFFFFF);
		if (a.x == b.x && a.y == b.y)
			break ;
		map->point.e2 = map->point.err;
		if (map->point.e2 > -map->point.dx)
		{
			map->point.err -= map->point.dy;
			a.x += map->point.sx;
		}
		if (map->point.e2 < map->point.dy)
		{
			map->point.err += map->point.dx;
			a.y += map->point.sy;
		}
	}
}

void		init_var(t_pos a, t_pos b, t_tab *map)
{
	map->point.dx = abs(b.x - a.x);
	map->point.dy = abs(b.y - a.y);
	map->point.sx = a.x < b.x ? 1 : -1;
	map->point.sy = a.y < b.y ? 1 : -1;
	map->point.err = (map->point.dx > map->point.dy ?
	map->point.dx : -map->point.dy) / 2;
	bresenham(a, b, map);
}
