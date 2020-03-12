/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:19:21 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 16:44:41 by mzhu             ###   ########.fr       */
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

int				check_first(int fd, size_t *size_line, size_t *nb_line)
{
	size_t		lines;
	size_t		cmp;
	char		*line;
	int			ret;

	lines = 0;
	line = NULL;
	*size_line = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		cmp = ft_count_word(line, ' ');
		*size_line < cmp ? *size_line = cmp : 0;
		if (valid_line(line) == 1)
		{
			*nb_line = 0;
			*size_line = 0;
			free(line);
			write(1, "file error\n", 11);
			return (-1);
		}
		lines++;
		*nb_line = lines;
		free(line);
	}
	free(line);
	return (ret);
}
