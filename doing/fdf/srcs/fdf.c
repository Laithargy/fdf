/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:26:56 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/16 06:04:35 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>

int main(int ac, char **av)
{
	void *mlx;
	void *window;
	//int pixel;
	int		fd;
	int		*lines;
	int		**tab;
	int		space;
	int x = 0;
	int y = 0;

	lines = 0;
	fd = 0;
	tab = NULL;
	space = 250;
	if (ac == 2)
	{
		int i = 0;
		mlx = mlx_init();
		if (!((fd = open(av[1], O_RDONLY))))
			return (0);
		lines = check_first(fd);
		if (lines[0] == 0 && lines[1] == 0)
			return (ERROR);
		close(fd);
		if (!((fd = open(av[1], O_RDONLY))))
			return 0;
		int f = 0;
		tab = parser(fd, lines[0], lines[1]);
		window = mlx_new_window(mlx,1000, 1000, "ntm");
		int car = 0;
		int car2 = 0;
		while (i <=lines[0])
		{
			f = 0;
			car = 0;
			while (f <= lines[1])
			{
				x = /*f == lines[1] ? f + tab[i][f] : */f +  tab[i][f];
				y = /*i == lines[0] ? i - tab[i][f]:*/ i - tab[i][f]; 
				int x2 = f == lines[1] ? f + tab[i][f - 1] : f + tab[i][f + 1];
				int y2 = i == lines[0] ? i - tab[i -1][f] : i - tab[i+1][f];
				printf("%d", y2);
				// mlx_pixel_put(mlx, window, car + space + x, car2 +space + x2, 0xFF0000);
				// if (i <= 2 && f <= 2)
				// {
				// 	// mlx_pixel_put(mlx, window, car + space + x, car2 +space + x2, 0xFF0000);
				// 	line(space + x2 + car, car2 + space + x, space + car + 25 + y , space + car2 + y2, window, mlx);
				// 	//line(space + y + car, car2 + space +x2, space + y2 + car, car2 +space + x2, window, mlx);
				// }
				line(space + x + car, car2 + space + y, space + car + 25 + x2 , space + car2 + y2, window, mlx);
				f++;
				car+=25;
			}
			car2+=25;
			printf("\n");
			i++;
		}
		mlx_loop(mlx);
	}
	else
		ft_putstr("Usage : ./fdf your_file");

	return (0);
}