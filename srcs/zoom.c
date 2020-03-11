/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:38:20 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:43:09 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			make_zoom(int keycode, t_tab *map)
{
	if (keycode == 69 && map->bonus.scale < 1000)
		map->bonus.scale += 5;
	if (keycode == 78 && map->bonus.scale > 10)
		map->bonus.scale -= 5;
}
