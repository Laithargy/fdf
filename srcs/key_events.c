/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:24:55 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 17:34:27 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				ending_it(void *param)
{
	t_tab		*map;

	map = (t_tab*)param;
	free_tab(map);
//	while (1);
	exit(0);
	return (0);
}

int				key_pressed(int keycode, void *param)
{
	t_tab		*map;

	map = (t_tab*)param;
	map->mlx.clear = mlx_clear_window(map->mlx.ptr, map->mlx.window);
	if (keycode == 53)
		ending_it(map);
	if (keycode == 78 || keycode == 69)
		make_zoom(keycode, map);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		arrows_move(keycode, map);
	if (keycode == 0 || keycode == 13 || keycode == 2
		|| keycode == 7 || keycode == 1)
		rotation(keycode, map);
	copy_tab(map);
	apply_zoom(map);
	apply_rot(map);
	apply_iso(map);
	apply_decal(map);
	draw(map);
	return (0);
}
