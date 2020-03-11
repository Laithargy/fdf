/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:30:28 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 11:51:00 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			isometric(t_point *a)
{
	t_point		p;

	p = *a;
	a->x = (p.x - p.y) * cos(0.46373398);
	a->y = (p.x + p.y) * cos(0.46373398) - a->z;
}

void			apply_iso(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			isometric(&map->copy[y][x]);
			x++;
		}
		y++;
	}
}
