#ifndef TEST_H
#define TEST_H

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
	int			x;
	int			y;
	t_mlx		mlx;
	t_point		*point;
}					t_tab;

#endif