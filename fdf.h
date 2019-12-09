#ifndef FDF_H
# define FDF_H
# define ERROR 3

#include "./Libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

int			parser(int fd, int nb_lines, int size_line);
int			*nb_line(int fd);
int			*split_line(char *str, int c, int size_line);
int			*check_first(int fd);
int			valid_line(char *str);

#endif