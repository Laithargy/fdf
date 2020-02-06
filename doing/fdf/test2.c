/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 02:41:30 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/06 18:07:39 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "./test.h"

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
	
	i = -1;
	init_var(x1, y1, x2, y2, map);
	// map->point->ex = abs(x2 - x1);
	// map->point->ey = abs(y2 - y1);
	// map->point->dx = 2 * map->point->ex;
	// map->point->dy = 2 * map->point->ey;
	// map->point->dex = map->point->ex;
	// map->point->dey = map->point->ey;
	// map->point->xin = x1 > x2 ? -1 : 1;
	// map->point->yin = y1 > y2 ? -1 : 1;
	// if (map->point->dex >= map->point->dey)
	// {
	// 	while (i++ <= map->point->dex)
	// 	{
	// 		mlx_pixel_put(map->mlx.ptr, map->mlx.window, x1, y1, 0xFFFFFF);
	// 		x1 += map->point->xin;
	// 		map->point->ex -= map->point->dy;
	// 		(map->point->ex < 0) ? y1 += map->point->yin : 0;
	// 		(map->point->ex < 0) ? map->point->ex += map->point->dx : 0;
	// 	}
	// }
	// if (map->point->dex < map->point->dey)
	// {
	// 	while (i++ <= map->point->dey)
	// 	{
	// 		mlx_pixel_put(map->mlx.ptr, map->mlx.window, x1, y1, 0xFFFFFF);
	// 		y1 += map->point->yin;
	// 		map->point->ey -= map->point->dx;
	// 		(map->point->ey < 0) ? x1 += map->point->xin : 0;
	// 		(map->point->ey < 0) ? map->point->ey += map->point->dy : 0;
	// 	}
	// }
	calc(x1, y1, map);
}

// int main(void)
// {
// 	int x;
// 	int y;
// 	int x2;
// 	int y2;

// 	x = 0;
// 	y = 0;
// 	x2 = x + 1;
// 	y2 = y + 1;
// 	while (x2 < 10)
// 	{
// 		y = 0;
// 		y2 = y + 1 ;
// 		while (y2 < 10)
// 		{
// 			bresenham(x + spacex, y + spacey, x2 + spacex, y2 + spacey, map);
// 			y++;
// 			y2 = y + 1;
// 			spacey +=10;
// 		}
// 		spacex += 10;
// 		x++;
// 		x2 = x + 1;
// 	}
// 	mlx_loop(map->mlx.ptr);
// }

void		lol(t_tab *map)
{
	map->mlx.ptr = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.ptr, 1000, 1000, "cc");
	bresenham(10+250, 110+250, 50+250, 50+250, map);
	mlx_loop(map->mlx.ptr);
}

int			main(void)
{
	t_tab *map;
	// int  x = 10;
	// int  y = 10;
	// int x2 = 50;
	// int y2 = 50;
	lol(map);
	// map->mlx.ptr = mlx_init();
	// map->mlx.window = mlx_new_window(map->mlx.ptr, 1000, 1000, "cc");
	// bresenham(x+250, y+250, x2+250, y2+250, map);
	// mlx_loop(map->mlx.ptr);
	return 0;
}