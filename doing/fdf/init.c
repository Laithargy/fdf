/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/16 06:40:42 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			initialization(const char *av, t_tab *map)
{
	if (!((fd = open(argv, O_RDONLY))))
		return (0);
	check_first(fd, map->width, map->height);
	if (lines[0] == 0 && lines[1] == 0)
		return (ERROR);
	close(fd);
	if (!((fd = open(argv, O_RDONLY))))
		return 0;
}