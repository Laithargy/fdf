/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:50:32 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/04 23:45:28 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point			*allocate_struct(int x, int y, t_tab *map)
{
	t_point		*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x * 10;
	point->y = y * 10;
	point->z = map->tab[y][x];
	return (point);
}

int				map_construct(t_tab *map)
{
	int			x;
	int			y;
	t_point		*point;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		if (!(map->plan[y] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (-1);
		while (x < map->width)
		{
			point = allocate_struct(x, y, map);
			map->plan[y][x] = *point;
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
	line = ft_strnew(1);
	if (!(tab = (int**)malloc(sizeof(int*) * nb_lines)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		tab[ind] = split_line(line, ' ', size_line + 1);
		ind++;
	}
	return (tab);
}
