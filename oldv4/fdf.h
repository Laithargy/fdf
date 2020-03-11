/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:44:34 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/11 07:47:41 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERROR -1
# define OK 1
# define NAME "fdf_proj"
# define HH 1080
# define WW 1920
# define SPACE 250

# include "./Libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

typedef struct		s_point
{
	double long		x;
	double long		y;
	double long		z;
}					t_point;

typedef struct		s_mlx
{
	void			*ptr;
	void			*window;
	int				loop;
}					t_mlx;

typedef struct		s_p
{
	int x;
	int y;
}					t_p;

typedef struct		s_algo
{
	int				w;
	int				h;
	int				dx1;
	int				dy1;
	int				dx2;
	int				dy2;
	int				longest;
	int				shortest;
	int				numerator;
}					t_algo;

typedef struct		s_bonus
{
	float			t_x;
	float			t_y;
	float			t_z;
	int				scale;
	size_t			decalex;
	size_t			decaley;
}					t_bonus;

typedef struct		s_tab
{
	int				**tab;
	size_t			height;
	size_t			width;
	t_point			**plan;
	t_point			**copy;
	t_mlx			mlx;
	t_algo			algo;
	t_bonus			bonus;
}					t_tab;

void				check_first(int fd, size_t *size_line, size_t *nb_line);
int					valid_line(char *str);
int					alloc_copy(t_tab *map);
int					check_error(char *argv, t_tab *map);
void				initial_mlx(t_tab *map);
int					**parser(int fd, int nb_lines, int size_line);
int					fdf(char *argv);
int					*split_line(char *str, int c, int size_line);
int					draw_map(t_tab *map);
int					map_construct(t_tab *map);
void				draw(t_tab *map);
int					key_press(int keycode, void *param);
void				init_var(t_point a, t_point b, t_tab *map);
void				make_zoom(int keycode, t_tab *map);
void				arrows_move(int keycode, t_tab *map);
int					key_pressed(int keycode, void *param);
int					ending_it(void *param);
void				apply_rot(t_tab *map);
void				apply_zoom(t_tab *map);
void				rotation(int keycode, t_tab *map);
void				rotax(t_tab *map);
void				rotay(t_tab *map);
void				rotaz(t_tab *map);
void				copy_tab(t_tab *map);
int					free_tab(t_tab *map);
void				apply_decal(t_tab *map);

#endif
