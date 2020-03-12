/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 07:23:02 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 17:01:43 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			var_bresen(t_p *first, t_p *second, t_algo *var)
{
	var->w = second->x - first->x;
	var->h = second->y - first->y;
	var->dx1 = 0;
	var->dy1 = 0;
	var->dx2 = 0;
	var->dy2 = 0;
	(var->w < 0) ? var->dx1 = -1 : 0;
	(var->w < 0) ? var->dx2 = -1 : 0;
	(!(var->w < 0)) ? var->dx1 = 1 : 0;
	(!(var->w < 0)) ? var->dx2 = 1 : 0;
	(var->h < 0) ? var->dy1 = -1 : 0;
	(!(var->h < 0)) ? var->dy1 = 1 : 0;
	var->longest = abs(var->w);
	var->shortest = abs(var->h);
	if (!(var->longest > var->shortest))
	{
		var->longest = abs(var->h);
		var->shortest = abs(var->w);
		(var->h < 0) ? var->dy2 = -1 : 0;
		(!(var->h < 0)) ? var->dy2 = 1 : 0;
		var->dx2 = 0;
	}
}

void			line(t_p *first, t_p *second, t_tab *map)
{
	t_algo		var;
	int			i;

	i = 0;
	var_bresen(first, second, &var);
	var.numerator = var.longest >> 1;
	while (i <= var.longest)
	{
		mlx_pixel_put(map->mlx.ptr, map->mlx.window,
				first->x, first->y, 0xFFFFFF);
		var.numerator += var.shortest;
		if (!(var.numerator < var.longest))
		{
			var.numerator -= var.longest;
			first->x += var.dx1;
			first->y += var.dy1;
		}
		else
		{
			first->x += var.dx2;
			first->y += var.dy2;
		}
		i++;
	}
}

void			init_var(t_point a, t_point b, t_tab *map)
{
	t_p			first;
	t_p			second;

	first.x = a.x;
	first.y = a.y;
	second.x = b.x;
	second.y = b.y;
	line(&first, &second, map);
}
