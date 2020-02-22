/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:30:28 by mzhu              #+#    #+#             */
/*   Updated: 2020/02/22 16:27:27 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <fdf.h>

void		isometric(t_point *a)
{
	t_point		p;

	p = *a;
	a->x = (p.x- p.y) * cos(0.523599);
	a->y = (p.x + p.y) * sin(0.523599) - a->z;
}