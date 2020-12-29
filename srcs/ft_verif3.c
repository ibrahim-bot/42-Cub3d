/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:25:08 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/28 16:39:11 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_f_line(t_file *file)
{
	int y;

	y = 0;
	while (F->M->map[0][y])
	{
		if ((F->M->map[0][y] == ' ' && F->M->map[1][y] == '0') ||
		(F->M->map[0][y] == ' ' && F->M->map[1][y] == '2') ||
		(F->M->map[0][y] == ' ' && F->M->map[1][y] == '3') ||
		(F->M->map[0][y] == ' ' && F->M->map[1][y] == '4') ||
		(F->M->map[0][y] == ' ' && F->M->map[1][y] == '5') ||
		(F->M->map[0][y] == ' ' && F->M->map[1][y] == '6'))
			return (84);
		y++;
	}
	return (0);
}

int	check_l_line(t_file *file)
{
	int y;
	int x;

	y = 0;
	x = F->M->height - 2;
	while (F->M->map[x][y])
	{
		if ((F->M->map[x][y] == ' ' && F->M->map[x - 1][y] == '0') ||
		(F->M->map[x][y] == ' ' && F->M->map[x - 1][y] == '2') ||
		(F->M->map[x][y] == ' ' && F->M->map[x - 1][y] == '3') ||
		(F->M->map[x][y] == ' ' && F->M->map[x - 1][y] == '4') ||
		(F->M->map[x][y] == ' ' && F->M->map[x - 1][y] == '5') ||
		(F->M->map[x][y] == ' ' && F->M->map[x - 1][y] == '6'))
			return (84);
		y++;
	}
	return (0);
}

int	search_one(t_file *file, int x, int y)
{
	if (F->M->map[x][y - 1] == ' ' || F->M->map[x][y + 1] == ' ' ||
	F->M->map[x][y + 1] == '\0' || F->M->map[x + 1][y] == ' ' ||
	F->M->map[x - 1][y] == ' ')
		return (84);
	return (0);
}

int	check_line(t_file *file)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (x != F->M->height - 2)
	{
		while (F->M->map[x][y])
		{
			if (F->M->map[x][y] == '0' || F->M->map[x][y] == '2' ||
			F->M->map[x][y] == '3' || F->M->map[x][y] == '4' ||
			F->M->map[x][y] == '5' || F->M->map[x][y] == '6')
			{
				if (search_one(F, x, y) == 84)
					return (84);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
