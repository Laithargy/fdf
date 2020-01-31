/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 06:22:40 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/30 15:37:20 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			fdf(char *argv)
{
	t_tab			*map;
	int				fd;
	int				end;

	end = 0;
	(check_error(argv, *&map) == ERROR) ? end = ERROR : 0;
	(fd = open(argv, O_RDONLY)) == ERROR ? end = ERROR : 0;
	(*map).tab = parser(fd, (*map).height, (*map).width);
	initial_mlx(map);
	return (0);
}
