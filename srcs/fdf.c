/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:26:56 by mzhu              #+#    #+#             */
/*   Updated: 2019/12/09 23:25:44 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>

int main(void)
{
  void *mlx;
  void *window;
  int pixel;
  int tamer;
  int i = 0;
  mlx = mlx_init();
  window = mlx_new_window(mlx,1000, 1000, "ntm");
  while ()
  pixel = mlx_pixel_put(mlx, window, 500, 500, 222);
  tamer = mlx_string_put(mlx, window, 50, 36, 222, ".");

  mlx_loop(mlx);
  return (0);
}