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

int			initial_mlx(t_tab *map)
{

	if ((map->mlx.ptr = mlx_init()) == NULL)
		return (-1);
	if ((map->mlx.window = mlx_new_window(map->mlx.ptr, 640, 480, "Hello world")) == NULL)
		return (-1);
	mlx_pixel_put(map->mlx.ptr, map->mlx.window, 10, 10, 0xFFFFFF);
	mlx_loop(map->mlx.ptr);
	return (0);
}
