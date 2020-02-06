/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mlx->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 03:20:37 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/30 15:06:39 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		initial_mlx(t_tab *map)
{
	int i = 0;
	int j = 0;
	int i2 = i + 1;
	int j2 = j + 1;
	// int x = map->tab[i][j] + i;
	// int y = map->tab[i][j] - j;
	// int x2 = map->tab[i2][j] + i2;
	// int y2 = map->tab[i][j2] - j2;
	int spacei = 30;
	int spacej = 30;
	map->mlx.ptr = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.ptr, WW, HH, "cc");
	printf("width : %d\nheight : %d\n", map->width, map->height);
	while (j2 < map->height)
	{
		i = 0;
		i2 = i +1;
		spacej = 30;
		while (i2 < map->width)
		{
			int x = map->tab[j][i] + i;
			int y = map->tab[j][i] - j;
			int x2 = map->tab[j2][i2] + i2;
			int y2 = map->tab[j2][i2] - j2;
			bresenham( x + spacei +30, y + spacej + 30 , x2 + spacei, y2+ spacej, map);
			// printf("%d|\n%d|\n", map->tab[i][j],map->tab[i2][j2]);
		//	bresenham( x  + spacei, x2 + spacej, y + spacei, y2 + spacej, map);
			i++;
			i2 = i + 1;
			spacej +=30;
		}
		j++;
		j2 = j + 1;
		spacei += 30;
	}
	mlx_loop(map->mlx.ptr);
}
