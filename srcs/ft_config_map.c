/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:47:54 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/28 15:07:39 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_first_line_map(char *line, int i, int nb, t_file *file)
{
	F->M->height += 1;
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == ' ')
		{
			nb++;
			i++;
		}
		else if (line[i] != '\0')
		{
			free(line);
			ft_printf("Error: Map error type 1.\n");
			return (0);
		}
	}
	return (nb);
}

int	ft_config_map(int fd, char *line, t_file *file)
{
	int i;

	i = 0;
	if (!((F->M->width = ft_first_line_map(line, 0, 0, file)) &&
		(F->M->mapchar = ft_calloc(F->M->width + 2, 1))))
	{
		return (0);
	}
	memcpy(F->M->mapchar, line, F->M->width + 1);
	F->M->mapchar[F->M->width] = '\n';
	free(line);
	while (get_next_line(fd, &line) >= 0)
	{
		i = ft_config_map2(i, line, file);
		if (i == 1)
			return (1);
		if (i == 0)
			return (0);
	}
	return (1);
}
