/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mlx->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 03:20:37 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/07 22:42:07 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
/*
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
	while (i2 < map->height)
	{
		j = 0;
		j2 = j +1;
		spacej = 30;
		while (j2 < map->width)
		{
			// int x = map->tab[i][j];
			// int y =map->tab[i][j];
			// int x2 =  map->tab[i][j2];
			// int y2 =  map->tab[i2][j];
			bresenham( j +spacej, i+spacei  ,j2+spacej , i2+spacei, map);
			// printf("%d|\n%d|\n", map->tab[i][j],map->tab[i2][j2]);
		//	bresenham( x  + spacei, x2 + spacej, y + spacei, y2 + spacej, map);
			j++;
			j2 = j + 1;
			spacej +=30;
		}
		i++;
		i2 = i + 1;
		spacei += 30;
	}
	mlx_loop(map->mlx.ptr);
}
*/
void		initial_mlx(t_tab *map)
{
	t_pos	a;
	t_pos	b;
	t_pos	c;
	int		i;
	int		j;

	map->mlx.ptr = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.ptr, WW, HH, "cc");
	printf("width : %d\nheight : %d\n", map->width, map->height);
	i = 0;
	map->scale = 10.0f;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d\n", i);
			a = (t_pos){j * map->scale, i * map->scale};
			b = (t_pos){(j + 1) * map->scale, i * map->scale};
			c = (t_pos){j * map->scale, (i + 1) * map->scale};
			printf("a = %d %d | b = %d %d | c = %d %d", a.x, a.y, b.x, b.y, c.x, c.y);
			bresenham(a, b, map);
			bresenham(a, c, map);
			j++;
		}
		i++;
	}
	mlx_loop(map->mlx.ptr);
}
