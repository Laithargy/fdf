/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:18:50 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/29 19:07:31 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		initial_mlx(t_tab *map)
{
	map->mlx.ptr = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.ptr, WW, HH, NAME);
	mlx_hook(map->mlx.window, 2, 0, key_pressed, map);
	// draw(map);
	mlx_loop(map->mlx.ptr);
}
