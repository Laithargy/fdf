#ifndef FDF_H
#define FDF_H

#define ERROR -1
#define OK 1
#define NAME "fdf_proj"
#define HH 1080
#define WW 1920
#define SPACE 250

#include "./Libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_img
{
	int				bpp;	//bytes per pixel
	int				size_l; //size line * 4
	int				endian; // 1 or 0
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;	//mlx_init
	void			*window; //mlx_window
}					t_mlx;

typedef struct		s_algo
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_algo;

typedef struct		s_tab
{
	int				**tab;  //map
	int				height; //nb line
	int				width;  //size line
	size_t			f_size;
	float			scale;
	t_point			**plan;
	t_mlx			mlx;
	t_algo			algo;
}					t_tab;

void 				check_first(int fd, int *size_line, int *nb_line);
int					valid_line(char *str);
int					check_error(char *argv, t_tab *map);
void				initial_mlx(t_tab *map);
int					**parser(int fd, int nb_lines, int size_line);
int					fdf(char *argv);
int					*split_line(char *str, int c, int size_line);
int					draw_map(t_tab *map);
int					map_construct(t_tab *map);
void				draw(t_tab *map);
int					key_press(int keycode, void *param);
void				isometric(t_point *a);
void				init_var(t_point a, t_point b, t_tab *map);
void				bresenham(t_point a, t_point b, t_tab *map);
void				make_zoom(int keycode, t_tab *map);
void				arrows_move(int keycode, t_tab *map);
int					key_pressed(int keycode, void *param);

#endif
