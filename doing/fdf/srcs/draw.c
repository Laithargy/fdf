// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/02/09 00:25:27 by mzhu              #+#    #+#             */
// /*   Updated: 2020/02/21 17:25:37 by mzhu             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include  <fdf.h>

// void			draw(t_tab *map)
// {
// 	t_pos		a;
// 	t_pos		b;
// 	t_pos		c;
// 	t_pos		d;
// 	int			i; // y-axis
// 	int			j; // x-axis

// 	i = 0;
// 	while (i <= (map->height - 2))
// 	{
// 		j = 0;
// 		a = (t_pos){(j * map->scale) + 100, (i * map->scale) + 100}; // [0, 0]
// 		while (j < (map->width - 1))
// 		{
// 			b = (t_pos){((j + 1) * map->scale) + 100, (i * map->scale) + 100}; // [0,1]
// 			c = (t_pos){(j * map->scale) + 100, ((i + 1) * map->scale) + 100}; // [1,0]
// 			d = (t_pos){((j + 1) * map->scale) + 100, ((i + 1)* map->scale )+ 100};// [1,1]
// 			init_var(a, b, map); //horizontal
// 			j == 0 ? init_var(a, c, map) : 0; //gauche hor
// 			i == (map->height - 2) ? init_var(c, d, map) : 0; // bot vert
// 			init_var(b, d, map); //vertical + 1 de l'origine
// 			j++;
// 		}
// 		i++;
// 	}
// }
