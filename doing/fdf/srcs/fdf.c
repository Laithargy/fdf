/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/21 19:35:21 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			fdf(char *argv)
{
	t_tab			*map;
	int				fd;
	int				end;
	int				cmp;

	end = 0;
	map = (t_tab*)malloc(sizeof(t_tab));
	cmp = check_error(argv, *&map);
	fd = open(argv, O_RDONLY);
	map->tab = parser(fd, map->height, map->width);
	map->f_size = map->height * map->width;
	if (!(map->plan = (t_point*)malloc(sizeof(t_point) * map->f_size + 1)))
		printf("malloc du plan");
	map_construct(map);
	initial_mlx(map);
	return (!cmp || !fd);
}
