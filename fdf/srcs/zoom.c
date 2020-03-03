/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:38:20 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/03 22:38:54 by mzhu             ###   ########.fr       */
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
			map->plan[y][x] = (t_point){
				.x = map->plan[y][x].x *= 1.5,
				.y = map->plan[y][x].y *= 1.5,
				.z = map->plan[y][x].z *= 1
			};
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
			map->plan[y][x] = (t_point){
				.x = map->plan[y][x].x *= 0.5,
				.y = map->plan[y][x].y *= 0.5,
				.z = map->plan[y][x].z *= 1
			};
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
