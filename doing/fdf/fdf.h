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
	int		x;
	int		y;
}					t_pos;

typedef struct		s_img
{
	int bpp;	//bytes per pixel
	int size_l; //size line * 4
	int endian; // 1 or 0
}					t_img;

typedef struct		s_mlx
{
	void		*ptr;	//mlx_init
	void		*window; //mlx_window
}					t_mlx;

typedef struct s_point
{
	int			ex;
	int			ey;
	int			dx;
	int			dy;
	int			dex;
	int			dey;
	int			xin;
	int			yin;
}					t_point;

typedef struct		s_tab
{
	int			**tab;  //map
	int			height; //nb line
	int			width;  //size line
	float		scale;
	t_mlx		mlx;
	t_point		point;
}					t_tab;



void 				check_first(int fd, int *size_line, int *nb_line);
int					valid_line(char *str);
int					check_error(char *argv, t_tab *map);
void				initial_mlx(t_tab *map);
int					**parser(int fd, int nb_lines, int size_line);
int					fdf(char *argv);
int					*split_line(char *str, int c, int size_line);
int					draw_map(t_tab *map);
void				init_var(int x1, int y1, int x2, int y2, t_tab *map);
void				calc(int x1, int y1, t_tab *map);
void				bresenham(t_pos a, t_pos b, t_tab *map);

#endif
