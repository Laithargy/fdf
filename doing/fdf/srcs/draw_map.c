/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 04:49:00 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/20 09:27:22 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
// x = /*f == lines[1] ? f + tab[i][f] : */f +  tab[i][f];
// y = /*i == lines[0] ? i - tab[i][f]:*/ i - tab[i][f]; 
// int x2 = f == lines[1] ? f + tab[i][f - 1] : f + tab[i][f + 1];
// int y2 = i == lines[0] ? i - tab[i -1][f] : i - tab[i+1][f];
// line(space + x + car, car2 + space + y, space + car + 25 + x2 , space + car2 + y2, window, mlx);
// 			f++;
// 				car+=25;
// 			}
// 			car2+=25;
// 			printf("\n");
// 			i++;
// 		}
// 		mlx_loop(mlx);

int		draw_map(t_tab *map, t_mlx *ptr, t_img *img)
{
	int			x;
	int			y;
	int			x2;
	int			y2;
}