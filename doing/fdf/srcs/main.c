/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhu <mzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:22:12 by mzhu              #+#    #+#             */
/*   Updated: 2020/01/27 12:28:07 by mzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int         main(int ac, char **av)
{
    if (ac == 2)
    {
        if (fdf(av[1]) == ERROR)
        {
            write(1, "error\n", 6);
            return (0);
        }
    }
    else
        write(1, "usage : .fdf 'yourfilename'", 27);
    return (0);
}