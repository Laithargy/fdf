/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:19:15 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 15:45:40 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				check_error(char *argv, t_tab *map)
{
	int			fd;

	if (!((fd = open(argv, O_RDONLY))))
		exit(1);
	check_first(fd, &map->width, &map->height);
	if (map->width == 0 && map->height == 0)
		exit(1);
	close(fd);
	return (1);
}
