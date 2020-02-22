/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/22 19:40:29 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <fdf.h>

// void			create_amap(t_tab *map)
// {
// }

void			draw(t_tab *map)
{
		// printf("ISO APPLIED");
	size_t i;
	i = 0;
	// printf("ISO APPLIED");
	//appliquer les isos une fois a tous les pts
	while (i < map->f_size)
	{
		isometric(&map->plan[i]);
		printf("%zu| ", i);
		i++;
	}
	i = 0;
	while (i < map->f_size)
	{
		((i + map->width) < map->f_size) ? init_var(map->plan[i], map->plan[i + map->width], map) : 0;
		(((i + 1) / map->width) < (size_t)map->width) ? 0 : init_var(map->plan[i], map->plan[i + 1], map);
		init_var(map->plan[i], map->plan[i + 1], map);
		//mlx_pixel_put(map->mlx.ptr, map->mlx.window, 10 + i, 10 + i, 0xe31408);
		i++;
	}
	// t_point		check;
	// t_point		c2;

	// check = (t_point) {
	// 	165,
	// 	125,
	// 	140
	// };
	// c2 = (t_point) {
	// 	166,
	// 	125,
	// 	100
	// };
	// isometric(&check);
	// isometric(&c2);
	// mlx_pixel_put(map->mlx.ptr, map->mlx.window, check.x + 50, check.y + 50, 0xFFFFFF);
	// mlx_pixel_put(map->mlx.ptr, map->mlx.window, c2.x + 50, c2.y + 50, 0xFFFFFF);
	// mlx_pixel_put(map->mlx.ptr, map->mlx.window, 10, 10, 0xe31408);
	// init_var(check, c2, map);
}
// point a = X  & Y
// point b = X+1 & Y
// point c = X & Y+1
// point d = X+1 & Y+1