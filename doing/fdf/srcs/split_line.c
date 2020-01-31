/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:16:33 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/28 13:05:46 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				*split_line(char *str, int c, int size_line)
{
	int			*tab;
	int			ind;
	int			result;
	int			nb_int;
	int			pos;

	pos = 0;
	ind = 0;
	result = 0;
	nb_int = ft_count_word(str, ' ');
	if (!(tab = (int*)malloc(sizeof(int) * size_line + 1)))
		return (NULL);
	while (str[ind])
	{
		while (str[ind] == c && str[ind])
			ind++;
		if (str[ind] != c && str[ind])
			tab[pos++] = ft_atoi(str + ind);
		while (str[ind] != c && str[ind])
			ind++;
	}
	while (size_line > pos)
		tab[pos++] = 0;
	return (tab);
}
