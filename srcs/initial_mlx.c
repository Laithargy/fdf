/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:18:50 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 17:13:46 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		initial_mlx(t_tab *map)
{
	map->mlx.ptr = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.ptr, WW, HH, NAME);
	map->bonus.scale = 10;
	map->bonus.t_x = 0.2;
	map->bonus.t_y = 0.3;
	map->bonus.t_z = 0.1;
	map->bonus.decaley = 350;
	map->bonus.decalex = 350;
	copy_tab(map);
	apply_zoom(map);
	apply_rot(map);
	apply_iso(map);
	apply_decal(map);
	draw(map);
	mlx_hook(map->mlx.window, 2, 0, key_pressed, map);
	mlx_hook(map->mlx.window, 17, 1L << 17, ending_it, map);
	map->mlx.loop = mlx_loop(map->mlx.ptr);
}
