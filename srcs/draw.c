/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:42:09 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			apply_rot(t_tab *map)
{
	rotax(map);
	rotay(map);
	rotaz(map);
}

void			apply_zoom(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->copy[y][x].x *= map->bonus.scale;
			map->copy[y][x].y *= map->bonus.scale;
			map->copy[y][x].z *= map->bonus.scale;
			x++;
		}
		y++;
	}
}

void			apply_decal(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->copy[y][x].x += map->bonus.decalex;
			map->copy[y][x].y += map->bonus.decaley;
			x++;
		}
		y++;
	}
}

void			draw(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y <= (map->height - 2))
	{
		x = 0;
		while (x < (map->width - 1))
		{
			init_var(map->copy[y][x], map->copy[y][x + 1], map);
			x == 0 ? init_var(map->copy[y][x], map->copy[y + 1][x], map) : 0;
			y == (map->height - 2) ? init_var(map->copy[y + 1][x],
				map->copy[y + 1][x + 1], map) : 0;
			init_var(map->copy[y][x + 1], map->copy[y + 1][x + 1], map);
			x++;
		}
		y++;
	}
}
