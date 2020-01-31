/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:22:12 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/30 14:47:55 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			main(int ac, char **av)
{
	int		check;
	check = 0;
	if (ac == 2)
	{
		check = fdf(av[1]);
		if (check == ERROR)
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	else
		write(1, "usage : .fdf 'yourfilename'", 27);
	return (0);
}
