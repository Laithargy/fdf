#ifndef FDF_H
# define FDF_H
# define ERROR 3

#include "./Libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_tab {
    int     **tab;
    int     height;
    int     width;
}					t_tab;

typedef	struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
}					t_mlx;

int			**parser(int fd, int nb_lines, int size_line);
int			*nb_line(int fd);
int			*split_line(char *str, int c, int size_line);
int			*check_first(int fd);
int			valid_line(char *str);
void line(int x,int y,int x2, int y2, void *window, void *mlx);

#endif