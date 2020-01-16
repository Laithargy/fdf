/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:26:56 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/16 06:04:48 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>

int main(int ac, char **av)
{
	void *mlx;
	void *window;
	int pixel;
	int		fd;
	int		*lines;
	int		**tab;

	lines = 0;
	fd = 0;
	if (ac == 2)
	{
		int i = 0;
		mlx = mlx_init();
		window = mlx_new_window(mlx,1000, 1000, "ntm");
		if (!((fd = open(av[1], O_RDONLY))))
			return (0);
		lines = check_first(fd);
		if (lines[0] == 0 && lines[1] == 0)
			return (ERROR);
		close(fd);
		if (!((fd = open(av[1], O_RDONLY))))
			return 0;
		if ((tab = parser(fd, lines[0], lines[1])) == 0)
			return (ERROR);
		int f = 0;
		while (i < lines[0])
		{
			f = -1;
			while (f++ < lines[1] && tab[i][f + 1])
				pixel = mlx_pixel_put(mlx, window, tab[i][f], tab[i][f + 1], 222);
		}
		mlx_loop(mlx);
	}
	else
		ft_putstr("Usage : ./fdf your_file");
	return (0);
}
