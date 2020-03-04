/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:23:02 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/04 20:53:32 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		bresenham(t_algo algo, t_tab *map)
{
	while (1)
	{
		mlx_pixel_put(map->mlx.ptr, map->mlx.window, algo.ax, algo.ay, 0xFFFFFF);
		if (algo.ax == algo.bx && algo.ay == algo.by)
			break ;
		algo.e2 = algo.err;
		if (algo.e2 > -algo.dx)
		{
			algo.err -= algo.dy;
			if (algo.ax < algo.bx)
				algo.ax++;
			else if( algo.ax > algo.bx)
				algo.ax--;
		}
		if (algo.e2 < algo.dy)
		{
			algo.err += algo.dx;
			if (algo.ay < algo.by)
				algo.ay++;
			else if (algo.ay > algo.by)
				algo.ay--;
		}
	}
}

void		init_var(t_point a, t_point b, t_tab *map)
{
	t_algo		algo;
	
	a.z = a.z / WW + 10;
	b.z = b.z / HH + 10;
	if (a.z < 1 || b.z < 1)
		return ;
	algo.ax = (int)roundf(a.x / a.z) + WW / 2;
	algo.ay = (int)roundf(a.y / a.z) + WW / 2;
	algo.bx = (int)roundf(b.x / b.z) + HH / 2;
	algo.by = (int)roundf(b.x / b.z) + HH / 2;
	if ((algo.ax < 0 || algo.ax > WW || algo.ay < 0
		|| algo.ay > WW) && (algo.bx < 0 || algo.bx > HH || algo.by < 0 || algo.by > (HH / 2)))
		return ;
	algo.dx = abs(algo.bx - algo.ax);
	algo.dy = abs(algo.by - algo.ay);
	algo.err = ((algo.dx > algo.dy ?
		algo.dx : -algo.dy)) / 2;
	bresenham(algo, map);
}
