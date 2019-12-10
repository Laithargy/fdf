/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:50:21 by mzhu              #+#    #+#             */
/*   Updated: 2019/12/10 02:16:19 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		fd;
	int		*lines;
	
	lines = 0;
	fd = 0;
	if (ac == 2)
	{
		if (!((fd = open(av[1], O_RDONLY))))
			return (0);
		lines = check_first(fd);
		if (lines[0] == 0 && lines[1] == 0)
			return (ERROR);
		close(fd);
		if (!((fd = open(av[1], O_RDONLY))))
			return 0;
		if (parser(fd, lines[0], lines[1]) == -1)
			return (ERROR); 
	}
	else
		ft_putstr("Usage : ./fdf your_file");
	return (0);
}