/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/14 22:14:09 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			draw(t_tab *map)
{
	t_point		*tab;
	int			i;
	int			x;
	int			y;
	size_t		size;

	i = 0;
	x = 0;
	y = 0;
	size = map->height * map->width;
	if (!(tab = (t_point*)malloc(sizeof(t_point) * size))
		exit(1);
	projection(&tab, size, map);

}

void			projection(t_point *p, size_t size, t_tab *map)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tab[i] = {x, y, map->tab[x][y]};
			projection(tab[i], size, map);
			x++;
			i++;
		}
		y++;
	}
}

static void		iso(t_point *p)
{
	int			previous_x;
	int			previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = -p->z + (previous_x + previous_y) * sin(0.523599);
}

// x = i + z;
// tablo de struc de pt
// iter sur le tableau de struct
// tant que ptr sur struct  x & y & z rempli
// tracer des vecteur entre tous les points
// applique les transfos
// prends le tableau et passer a la ft des events keyboard
// bouge le tableau