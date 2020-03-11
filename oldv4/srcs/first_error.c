/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:19:21 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/07 04:35:56 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				valid_line(char *str)
{
	int			ind;

	ind = 0;
	while (str[ind])
	{
		if (str[ind] != ' ' && str[ind] != '-'
		&& !(str[ind] >= '0' && str[ind] <= '9'))
			return (1);
		ind++;
	}
	return (0);
}

void			check_first(int fd, size_t *size_line, size_t *nb_line)
{
	int			lines;
	int			nb_chr;
	int			cmp;
	char		*line;

	lines = 0;
	nb_chr = 0;
	cmp = 0;
	line = ft_strnew(1);
	while (get_next_line(fd, &line) == 1)
	{
		cmp = ft_count_word(line, ' ');
		nb_chr < cmp ? nb_chr = cmp : 0;
		if (valid_line(line) == 1)
		{
			*nb_line = 0;
			*size_line = 0;
			break ;
		}
		lines++;
		*nb_line = lines;
		*size_line = nb_chr;
		free(line);
	}
}
