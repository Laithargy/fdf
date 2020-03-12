/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:50:32 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 17:59:06 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point			*allocate_struct(int x, int y, t_tab *map)
{
	t_point		*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = map->tab[y][x];
	return (point);
}

int				map_construct(t_tab *map)
{
	size_t		x;
	size_t		y;
	t_point		*point;

	x = 0;
	y = 0;
	point = NULL;
	while (y < map->height)
	{
		x = 0;
		if (!(map->plan[y] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (-1);
		while (x < map->width)
		{
			if (!(point = allocate_struct(x, y, map)))
				return (-1);
			map->plan[y][x].x = point->x;
			map->plan[y][x].y = point->y;
			map->plan[y][x].z = point->z;
			free(point);
			x++;
		}
		y++;
	}
	return (1);
}

int				**parser(int fd, int nb_lines, int size_line)
{
	int			ind;
	int			**tab;
	char		*line;

	ind = 0;
	line = NULL;
	tab = NULL;
	if (!(tab = (int**)malloc(sizeof(int*) * nb_lines)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(tab[ind] = split_line(line, ' ', size_line + 1)))
			return (NULL);
		free(line);
		ind++;
	}
	free(line);
	return (tab);
}
