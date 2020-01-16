/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:19:21 by mzhu              #+#    #+#             */
/*   Updated: 2019/12/02 21:53:17 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			valid_line(char *str)
{
	int ind;
	
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

int			*check_first(int fd)
{
	int		lines;
	int		nb_chr;
	int		cmp;
	char	*line;
	int		*tab;

	lines = 0;
	nb_chr = 0;
	cmp = 0;
	line = ft_strnew(1);
	if (!(tab = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		(nb_chr < (cmp = ft_count_word(line, ' '))) ? nb_chr = cmp : 0 ;
		if (valid_line(line) == 1)
		{
			tab[0] = 0;
			tab[1] = 0;
			break;
		}
		tab[0] = lines;
		tab[1] = nb_chr;
		lines++;
		free(line);
	}
	return (tab);
}