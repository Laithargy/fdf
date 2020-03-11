/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:02:57 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:53:35 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int					free_tab(t_tab *map)
{
	size_t			x;
	size_t			y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			free(&map->plan[y][x]);
			free(&map->copy[y][x]);
			free(&map->tab[y][x]);
			x++;
		}
	}
	return (1);
}
