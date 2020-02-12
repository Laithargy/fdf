/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/12 05:43:35 by mzhu             ###   ########.fr       */
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
		a = (t_pos){(i * map->scale) + 20, (j * map->scale) + 20};
		while (j < map->width)
		{
			b = (t_pos){(i * map->scale )+ 20, ((j + 1) * map->scale) + 20}; // [0,1]
			c = (t_pos){((i + 1) * map->scale) + 20, (j * map->scale) + 20}; // [1,0]
			d = (t_pos){(i + 1)* map->scale + 20, (j + 1) * map->scale + 20};// [1,1]
			init_var(a, b, map);
			init_var(b, d, map);
			j++;
		}
		i++;
	}
}


// x = i + z;

// tablo de struc de pt
// iter sur le tableau de struct
// tant que ptr sur struct  x & y & z rempli 

// tracer des vecteur entre tous les points
// applique les transfos
// prends le tableau et passer a la ft des events keyboard
// bouge le tableau