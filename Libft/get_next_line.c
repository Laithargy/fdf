/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:00:24 by mzhu              #+#    #+#             */
/*   Updated: 2020/03/12 16:31:45 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char			*ft_read_line(char **stock, int fd)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;

	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if ((int)ft_strlen(buf) != rd)
			return (NULL);
		if (!*stock)
			*stock = ft_strdup(buf);
		else
			*stock = ft_strjoin_free(*stock, buf);
		if (ft_strchr(*stock, '\n'))
			break ;
	}
	return (*stock);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stock[1024];
	char			*tmp;
	int				i;

	i = 0;
	if (!line || fd < 0 || fd > 1024)
		return (-1);
	if (!(stock[fd] = ft_read_line(&stock[fd], fd)))
		return (-1);
	while (stock[fd][i] && stock[fd][i] != '\n')
		i++;
	*line = (ft_strchr(stock[fd], '\n'))
		? ft_strsub(stock[fd], 0, i) : ft_strcdup(stock[fd], '\n');
	tmp = stock[fd];
	stock[fd] = (ft_strchr(stock[fd], '\n'))
		? ft_strsub(stock[fd], i + 1, ft_strlen(stock[fd])) : ft_strdup("");
	if (stock[fd][i] == '\0' && i == 0 && tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		ft_strdel(&stock[fd]);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}
