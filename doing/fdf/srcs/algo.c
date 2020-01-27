/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:40:34 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/27 19:26:49 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void line(int x, int y, int x2, int y2, void *window, void *mlx)
{
    int w = x2 - x;
    int h = y2 - y;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
    if (w < 0)
        dx1 = -1;
    else if (w > 0)
        dx1 = 1;
    if (h < 0)
        dy1 = -1;
    else if (h > 0)
        dy1 = 1;
    if (w < 0)
        dx2 = -1;
    else if (w > 0)
        dx2 = 1;
    int longest = abs(w);
    int shortest = abs(h);
    if (!(longest > shortest))
    {
        longest = abs(h);
        shortest = abs(w);
        if (h < 0)
            dy2 = -1;
        else if (h > 0)
            dy2 = 1;
        dx2 = 0;
    }
    int numerator = longest >> 1;
    for (int i = 0; i <= longest; i++)
    {
        mlx_pixel_put(mlx, window, x, y, 0xFFFFFF);
        numerator += shortest;
        if (!(numerator < longest))
        {
            numerator -= longest;
            x += dx1;
            y += dy1;
        }
        else
        {
            x += dx2;
            y += dy2;
        }
    }
}

void vert(int x, int y, int x2, int y2, t_tab *map)
{
    if (y < y2)     //octant 2/3 -- HAUT
        if (y2 < y) //octant 6/7 -- BAS
}

void algo1(int x, int y, int x2, int y2, t_tab *map)
{
    int x1 = x;
    int y1 = y;
    int dx = x2 - x;
    int dy = y2 - y;
    int p = 2 * dx - dy;
    while (x <= x2)
    {
        mlx_pixel_put(map->draw.ptr, map->draw.window, x1, y1, 0xFFFFFF);
        x++;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            p = p + 2 * dy - 2 * dx;
            y1++;
        }
    }
}