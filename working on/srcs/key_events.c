/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:24:55 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/01 17:11:22 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				ending_it(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int				key_pressed(int keycode, void *param)
{
	t_tab		*map;

	map = (t_tab*)param;
	map->scale = 10;
	write(1, "c", 1);
	(void)param;
	// (void)keycode;
	// mlx_clear_window(map->mlx.ptr, map->mlx.window);
	// mlx_pixel_put(map->mlx.ptr, map->mlx.window, 200, 200, 0xFFFFFF);
	if (keycode == 53)
		ending_it(map);
	if (keycode == 78 || keycode == 69)
		make_zoom(keycode, map);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		arrows_move(keycode, map);
	draw(map);
	return (0);
}
