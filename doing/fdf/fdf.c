/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/18 05:18:09 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			fdf(const char *argv)
{
	t_tab			*map;
	t_mlx			*ptr;
	t_img			*img;
	int				fd;
	
	check_error(argv, map) == ERROR ? return (ERROR) : 0; //check le nb de ligne et de chr
	(fd = open(argv, O_RDONLY)) == ERROR ? return (ERROR) : 0; //check lopen du fd
	initial_mlx(ptr); //initialisation de mlx window et mlxinit
	map->tab = parser(fd, map->height, map->width);
	draw_map(map, ptr, img);
}