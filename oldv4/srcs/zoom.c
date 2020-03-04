/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:38:20 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/04 23:25:40 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		zoomin(t_tab *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			// printf("ww = %d|\n", map->plan[y][x].x);
			// if (map->plan[y][x].x <= 0)
				map->plan[y][x].x =  (map->plan[y][x].x + x) * 2;
			// else
				// map->plan[y][x].x =  map->plan[y][x].x * 2;
			
			// if (map->plan[y][x].y <= 0)
				map->plan[y][x].y =  (map->plan[y][x].y + y) * 2;
			// else
				// map->plan[y][x].y =  map->plan[y][x].y * 2;
				
			// map->plan[y][x].z *= 2 + map->plan[y][x].z;
			// printf("ww = %d|\n", map->plan[y][x].x);
			x++;
		}
		y++;
	}
}

static void		zoomout(t_tab *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->plan[y][x].x =  (map->plan[y][x].x + x) /2;
			map->plan[y][x].y =  (map->plan[y][x].y + y) /2;
				// map->plan[y][x].x /= 2;
				// map->plan[y][x].y /= 2;
				// map->plan[y][x].z /= 2;
			x++;
		}
		y++;
	}
}

void			make_zoom(int keycode, t_tab *map)
{
	if (keycode == 69)
		zoomin(map);
	if (keycode == 78)
		zoomout(map);
}
