/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/21 19:40:04 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// void			create_amap(t_tab *map)
// {
// }

void			draw(t_tab *map)
{
	size_t i = 0;
	while (i < map->f_size - 1)
	{
		// mlx_pixel_put(map->mlx.ptr, map->mlx.window, 10, 10, 0xe31408);
		isometric(&map->plan[i],&map->plan[i + 1],&map->plan[(i / map->height) + 1]);
		init_var(map->plan[i], map->plan[i + 1], map);
		init_var(map->plan[i], map->plan[(i / map->height) + 1], map);
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