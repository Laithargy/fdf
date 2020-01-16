#ifndef FDF_H
# define FDF_H
# define ERROR 3

#include "./Libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_tab {
    int     **tab; //map
    int     height; //nb line
    int     width; //size line
}					t_tab;

typedef	struct	s_img
{
	int		bpp; //bytes per pixel
	int		size_l; //size line * 4
	int		endian; // 1 or 0
}				t_img;

typedef struct		s_mlx
{
	void	*mlx_ptr; //mlx_init
	void	*mlx_window; //mlx_window
}					t_mlx;

int			**parser(int fd, int nb_lines, int size_line);
int			*nb_line(int fd);
int			*split_line(char *str, int c, int size_line);
int			*check_first(int fd);
int			valid_line(char *str);
void line(int x,int y,int x2, int y2, void *window, void *mlx);

#endif