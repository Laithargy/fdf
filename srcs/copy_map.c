/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 04:13:04 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:52:09 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				alloc_copy(t_tab *map)
{
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		if (!(map->copy[y] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (-1);
		y++;
	}
	return (0);
}

void			copy_tab(t_tab *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	if (map->copy[y] == NULL)
		if ((alloc_copy(map) == -1))
			return ;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->copy[y][x].x = map->plan[y][x].x;
			map->copy[y][x].y = map->plan[y][x].y;
			map->copy[y][x].z = map->plan[y][x].z;
			x++;
		}
		y++;
	}
}
