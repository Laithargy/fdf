/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/09 05:06:12 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			draw(t_tab *map)
{
	t_pos		a;
	t_pos		b;
	t_pos		c;
	t_pos		d;
	int			i;
	int			j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		a = (t_pos){j * map->scale + 20, i * map->scale + 20};
		while (j < map->width)
		{
		//	printf("%d\n", i);
			b = (t_pos){j * map->scale + 20, (i + 1) * map->scale + 20}; // [0,1]
			c = (t_pos){(j + 1) * map->scale + 20, i * map->scale + 20}; // [1,0]
			d = (t_pos){(j + 1)* map->scale + 20, (0 + 1) * map->scale + 20};// [1,1]
			// bresenham(a, b, map);
			// bresenham(b, c, map);
			// bresenham(b, d, map);
			j++;
		}
		i++;
	}
}
