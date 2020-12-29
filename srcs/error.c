/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:54:35 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/29 08:02:41 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_error_parse(t_file *file, int fd, char *line)
{
	if (fd > 0)
	{
		free(line);
		close(fd);
		return (1);
	}
	close(fd);
	ft_free_fil(F);
	return (0);
}

int	error_main(int ac, char **av)
{
	if (ac < 2 || (ac > 2 && ft_strcmp(&av[2][0], "--save")))
	{
		if (ac <= 2)
			ft_printf("Error: no map specified. Write %s [.cub] [--save]\n",
			av[0]);
		else
			ft_printf("Error: Used => [--save]\n");
		return (1);
	}
	return (0);
}

int	skip_space(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}
