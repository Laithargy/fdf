/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/20 09:23:29 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			fdf(char *argv)
{
	t_tab			*map;
	t_mlx			*ptr;
	t_img			*img;
	int				fd;
	int				end;

	end = 0;
	end = (check_error(argv, *&map) == ERROR) ? ERROR: 0; //check le nb de ligne et de chr
	end = ((fd = open(argv, O_RDONLY)) == ERROR) ? ERROR : 0; //check lopen du fd
	initial_mlx(*&ptr); //initialisation de mlx window et mlxinit
	map->tab = parser(fd, map->height, map->width);
	draw_map(map, ptr, *&img);
	return (0);
}