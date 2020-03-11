/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:24:55 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:42:48 by mzhu             ###   ########.fr       */
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
	mlx_clear_window(map->mlx.ptr, map->mlx.window);
	if (keycode == 53)
		ending_it(map);
	if (keycode == 78 || keycode == 69)
		make_zoom(keycode, map);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		arrows_move(keycode, map);
	if (keycode == 0 || keycode == 13 || keycode == 2)
		rotation(keycode, map);
	copy_tab(map);
	apply_rot(map);
	apply_zoom(map);
	apply_decal(map);
	draw(map);
	return (0);
}
