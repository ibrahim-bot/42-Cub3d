/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_struct2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:11:48 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/29 08:04:11 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	chang_xy(t_file *file)
{
	if (F->axe_x > 2560)
		F->axe_x = 2560;
	if (F->axe_y > 1400)
		F->axe_y = 1400;
}

int		compt_cara(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] != '\0' && line[i + 1] != ' ')
			j++;
		i++;
	}
	if (j != 2)
		return (84);
	return (0);
}
