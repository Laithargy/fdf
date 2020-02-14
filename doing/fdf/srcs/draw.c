// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
// /*   Updated: 2020/02/14 21:13:35 by mzhu             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <fdf.h>

// void			draw(t_tab *map)
// {
// 	t_pos		*proj;
// 	t_pos		a;
// 	t_pos		b;
// 	t_pos		c;
// 	t_pos		d;
// 	int			i; // y-axis
// 	int			j; // x-axis

// 	i = 0;
// 	if (!(proj = (t_pos*)malloc(sizeof(t_pos))))
// 	while (i <= (map->height - 2))
// 	{
// 		j = 0;
// 		a = (t_pos){(j * map->scale), (i * map->scale)}; // [0, 0]
// 		while (j < (map->width - 1))
// 		{
// 			b = (t_pos){((j + 1) * map->scale), (i * map->scale)}; // [0,1]
// 			c = (t_pos){(j * map->scale), ((i + 1) * map->scale)}; // [1,0]
// 			d = (t_pos){(j + 1) * map->scale, (i + 1)* map->scale};// [1,1]
// 			init_var(a, b, map); //horizontal
// 			j == 0 ? init_var(a, c, map) : 0; //gauche hor
// 			i == (map->height - 2) ? init_var(c, d, map) : 0; // bot vert
// 			init_var(b, d, map); //vertical + 1 de l'origine
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int				projection(t_point *p, size_t size, t_tab *map)
// {
// 	int			x;
// 	int			y;
// 	int			i;
// 	t_point		*new;

// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			iso()
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void		iso(int *x, int *y, int z)
// {
// 	int previous_x;
// 	int previous_y;

// 	previous_x = *x;
// 	previous_y = *y;
// 	*x = (previous_x - previous_y) * cos(0.523599);
// 	*y = -z + (previous_x + previous_y) * sin(0.523599);
// }

// // x = i + z;
// // tablo de struc de pt
// // iter sur le tableau de struct
// // tant que ptr sur struct  x & y & z rempli
// // tracer des vecteur entre tous les points
// // applique les transfos
// // prends le tableau et passer a la ft des events keyboard
// // bouge le tableau