/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:40:37 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/29 18:57:18 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		left_right(int keycode, t_tab *map)
{
	int			x;
	int			y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			((keycode == 123) ? (map->plan[y][x].x -= 50)
				: (map->plan[y][x].x += 50));
			x++;
		}
		y++;
	}
}

static void		up_down(int keycode, t_tab *map)
{
	int			x;
	int			y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			((keycode == 126) ? (map->plan[y][x].z += 50)
				: (map->plan[y][x].z -= 50));
			x++;
		}
		y++;
	}
}

void			arrows_move(int keycode, t_tab *map)
{
	if (keycode == 123 || keycode == 124)
		left_right(keycode, map);
	if (keycode == 125 || keycode == 126)
		up_down(keycode, map);
}
