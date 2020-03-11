/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 16:17:48 by mzhu             ###   ########.fr       */
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
	if ((cmp = check_error(argv, &map)) == -1)
		return (-1);
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	if ((map.tab = parser(fd, map.height, map.width)) == NULL)
		return (-1);
	if (!(map.plan = (t_point**)malloc(sizeof(t_point*) * map.height))
		|| !(map.copy = (t_point**)malloc(sizeof(t_point*) * map.height)))
		return (-1);
	if (map_construct(&map) == -1)
	{
		free_tab(&map);
		return (-1);
	}
	initial_mlx(&map);
	return (1);
}
