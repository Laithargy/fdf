/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 04:49:00 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/18 05:18:12 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
// x = /*f == lines[1] ? f + tab[i][f] : */f +  tab[i][f];
// y = /*i == lines[0] ? i - tab[i][f]:*/ i - tab[i][f]; 
// int x2 = f == lines[1] ? f + tab[i][f - 1] : f + tab[i][f + 1];
// int y2 = i == lines[0] ? i - tab[i -1][f] : i - tab[i+1][f];

int		draw_map(t_tab *map, t_mlx *ptr, t_img *img)
{
	int			x;
	int			y;
	int			x2;
	int			y2;
}