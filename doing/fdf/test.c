/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:53:48 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/04 03:44:51 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void algo(int x1, int y1, int x2, int y2, void *win_ptr, void *win)
{
	int ex = abs(x2 - x1);
	int ey = abs(y2 - y1);
	int dx = 2 * ex;
	int dy = 2 * ey;
	int Dx = ex;
	int Dy = ey;
	int xin;
	int yin;
	int i;

	i = 0;
	xin = x1 > x2 ? -1 : 1;
	yin = y1 > y2 ? -1 : 1;
	if (Dx >= Dy)
	{
		while (i <= Dx)
		{
			mlx_pixel_put(win_ptr, win, x1, y1, 0xFFFFFF);
			i++;
			x1 += xin;
			ex -= dy;
			(ex < 0) ? y1 += yin : 0;
			(ex < 0) ? ex += dx : 0;
		}
	}
	if (Dx < Dy)
	{
		while (i <= Dy)
		{
			mlx_pixel_put(win_ptr, win, x1, y1, 0xFFFFFF);
			i++;
			y1 += yin;
			ey -= dx;
			(ey < 0)  ? x1 += xin : 0;
			(ey < 0) ? ey += dy : 0 ;
		}
	}
}

int			main(void)
{
	void *ptr;
	void *window;
	int  x = 10;
	int  y = 10;
	int x2 = 50;
	int y2 = 50;
	
	ptr = mlx_init();
	window = mlx_new_window(ptr, 1000, 1000, "cc");
	algo(x+250, y+250, x2+250, y2+250, ptr, window);
	mlx_loop(ptr);
	return 0;
}