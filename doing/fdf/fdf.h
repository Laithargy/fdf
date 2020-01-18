#ifndef FDF_H
# define FDF_H
# define ERROR -1
# define OK 1
# define NAME "fdf_proj"
# define HH 1080
# define WW 1920
# define SPACE 250

#include "./Libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_tab {
    int		**tab; //map
    int		height; //nb line
    int		width; //size line
	t_mlx	*draw;
}					t_tab;

typedef	struct	s_img
{
	int		bpp; //bytes per pixel
	int		size_l; //size line * 4
	int		endian; // 1 or 0
}				t_img;

typedef struct		s_mlx
{
	void	*ptr; //mlx_init
	void	*window; //mlx_window
}					t_mlx;

void			*check_first(int fd, int *size_line, int *nb_line);
int				valid_line(char *str);
int				check_error(char *argv, t_tab *map);
void			initial_mlx(t_mlx *ptr);
int				**parser(int fd, int nb_lines, int size_line);
int				fdf(const char *argv);
int				*split_line(char *str, int c, int size_line);

#endif