/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:39:14 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:42:36 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			rotax(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->copy[y][x].y = ((map->copy[y][x].y * cos(map->bonus.t_x))
				+ (map->copy[y][x].z * sin(map->bonus.t_x)));
			map->copy[y][x].z = ((-map->copy[y][x].y * sin(map->bonus.t_x)
				+ map->copy[y][x].z * cos(map->bonus.t_x)));
			x++;
		}
		y++;
	}
}

void			rotay(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->copy[y][x].x = ((map->copy[y][x].x * cos(map->bonus.t_y))
				+ (map->copy[y][x].z * sin(map->bonus.t_y)));
			map->copy[y][x].z = ((-map->copy[y][x].x * sin(map->bonus.t_y)
				+ map->copy[y][x].z * cos(map->bonus.t_y)));
			x++;
		}
		y++;
	}
}

void			rotaz(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->copy[y][x].x = ((map->copy[y][x].x * cos(map->bonus.t_z))
				- (map->copy[y][x].y * sin(map->bonus.t_z)));
			map->copy[y][x].y = ((map->copy[y][x].x * sin(map->bonus.t_z))
				+ (map->copy[y][x].y * cos(map->bonus.t_z)));
			x++;
		}
		y++;
	}
}

void			rotation(int keycode, t_tab *map)
{
	if (keycode == 0)
		map->bonus.t_x += 0.05f;
	if (keycode == 13)
		map->bonus.t_y += 0.05f;
	if (keycode == 2)
		map->bonus.t_z += 0.05f;
}
