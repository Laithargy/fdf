/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:38:37 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			fdf(char *argv)
{
	t_tab			map;
	int				fd;
	int				end;
	int				cmp;

	end = 0;
	cmp = check_error(argv, &map);
	fd = open(argv, O_RDONLY);
	map.tab = parser(fd, map.height, map.width);
	if (!(map.plan = (t_point**)malloc(sizeof(t_point*) * map.height))
		|| !(map.copy = (t_point**)malloc(sizeof(t_point*) * map.height)))
		return (-1);
	map_construct(&map);
	initial_mlx(&map);
	free_tab(&map);
	return (!cmp || !fd);
}
