/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:50:32 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/21 19:39:15 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			map_construct(t_tab *map)
{
	size_t		i;
	size_t		cmp;

	cmp = map->height;
	
	i = 0;
	while (i < map->f_size)
	{
		map->plan[i] = (t_point) {
			.x = (i % map->width) * map->scale,
			.y = (i / map->height) *  map->scale,
			.z = map->tab[i % map->height][i / map->width] *  map->scale,
		};
		i++;
	}
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
