/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:19:15 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/20 09:15:26 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			check_error(char *argv, t_tab *map)
{
	int			fd;
	
	if (!((fd = open(argv, O_RDONLY))))
		return (ERROR);
	check_first(fd, &map->width, &map->height);
	if (map->width == 0 && map->height == 0)
		return (ERROR);
	close(fd);
	return (OK);
}