/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:39:14 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/04 18:43:48 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		rotX(t_tab *map)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->plan[y][x] = (t_point) {
				.x = map->plan[y][x].x,
				.y = ((map->plan[y][x].y * cos(0.17)) + (map->plan[y][x].z * sin(0.17))),
				.z = ((-map->plan[y][x].y * sin(0.17) + map->plan[y][x].z * cos(0.17)))
			};
			x++;
		}
		y++;
	}
}

static void		rotY(t_tab *map)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->plan[y][x] = (t_point) {
				.x = ((map->plan[y][x].x * cos(0.17)) + (map->plan[y][x].z * sin(0.17))),
				.y = map->plan[y][x].y,
				.z = ((-map->plan[y][x].x * sin(0.17) + map->plan[y][x].z * cos(0.17)))
			};
			x++;
		}
		y++;
	}
}

static void		rotZ(t_tab *map)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->plan[y][x] = (t_point) {
				.x = ((map->plan[y][x].x * cos(0.17)) - (map->plan[y][x].y * sin(0.17))),
				.y = ((map->plan[y][x].x * sin(0.17)) + (map->plan[y][x].y * cos(0.17))),
				.z = map->plan[y][x].z
			};
			x++;
		}
		y++;
	}
}

void		rotation3D(int keycode, t_tab *map)
{
	if (keycode == 'x')
		rotX(map);
	if (keycode == 'y')
		rotY(map);
	if (keycode == 'z')
		rotZ(map);
}