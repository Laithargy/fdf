/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:53:48 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/27 19:35:17 by mzhu             ###   ########.fr       */
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
			if (ex < 0)
				y1 += yin;
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
			if (ey < 0)
			{
				x1 += xin;
				ey += dy;
			}
		}
	}
}
