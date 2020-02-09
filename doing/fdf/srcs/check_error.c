/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:19:15 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/09 01:23:36 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				check_error(char *argv, t_tab *map)
{
	int			fd;
	int			ret;

	ret = 1;
	if (!((fd = open(argv, O_RDONLY))))
		exit(1);
	check_first(fd, &map->width, &map->height);
	if (map->width == 0 && map->height == 0)
		ret = 0;
	if (!(close(fd)))
		ret = 0;
	return (ret);
}
