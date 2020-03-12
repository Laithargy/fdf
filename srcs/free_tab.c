/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:02:57 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 17:45:21 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int					free_tab(t_tab *map)
{
	size_t			y;

	y = 0;
	while (y < map->height)
	{
		free(map->plan[y]);
		free(map->copy[y]);
		free(map->tab[y]);
		y++;
	}
	// free(map->plan);
	// free(map->copy);
	// free(map->tab);
	mlx_clear_window(map->mlx.ptr, map->mlx.window);
	map->plan = NULL;
	map->copy = NULL;
	map->tab = NULL;
	map->mlx.ptr = NULL;
	if (map->mlx.ptr && map->mlx.window)
		mlx_destroy_window(map->mlx.ptr, map->mlx.window);
	map->mlx.ptr = NULL;
	map->mlx.window = NULL;
	return (1);
}
