/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:40:37 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:37:06 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			arrows_move(int keycode, t_tab *map)
{
	if (keycode == 123)
		map->bonus.decalex -= 50;
	if (keycode == 124)
		map->bonus.decalex += 50;
	if (keycode == 125)
		map->bonus.decaley += 50;
	if (keycode == 126)
		map->bonus.decaley -= 50;
}
