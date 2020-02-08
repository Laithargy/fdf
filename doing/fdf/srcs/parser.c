/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 04:50:32 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/29 17:09:27 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

int			**parser(int fd, int nb_lines, int size_line)
{
	int		ind;
	int		**tab;
	char	*line;

	ind = 0;
	line = ft_strnew(1);
	if (!(tab = (int**)malloc(sizeof(int*) * nb_lines)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		tab[ind] = split_line(line, ' ', size_line + 1);
		ind++;
	}
	return (tab);
}
