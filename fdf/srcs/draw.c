/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/04 20:18:18 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			apply_iso(t_tab *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			isometric(&map->plan[y][x]);
			x++;
		}
		y++;
	}
}

void			draw(t_tab *map)
{
	int			x;
	int			y;

	y = 0;
	while (y <= (map->height - 2))
	{
		x = 0;
		while (x < (map->width - 1))
		{
			init_var(map->plan[y][x], map->plan[y][x + 1], map);
			x == 0 ? init_var(map->plan[y][x], map->plan[y + 1][x], map) : 0;
			y == (map->height - 2) ? init_var(map->plan[y + 1][x],
				map->plan[y + 1][x + 1], map) : 0;
			init_var(map->plan[y][x + 1], map->plan[y + 1][x + 1], map);
			x++;
		}
		y++;
	}
}
