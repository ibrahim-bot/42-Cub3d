/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:45 by ichougra          #+#    #+#             */
/*   Updated: 2020/11/30 14:46:02 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void		ft_readxpm(t_file *file, char *str, int n)
{
	int		bits;
	int		sl;
	int		endian;

	if ((F->IW->img[n] = mlx_xpm_file_to_image(F->mlx, str, &F->IW->width[n],
	&F->IW->height[n])))
		F->IW->text[n] = (int *)mlx_get_data_addr(F->IW->img[n],
		&bits, &sl, &endian);
}

int			ft_rgbtoint(int red, int green, int blue)
{
	return ((256 * 256 * red) + (256 * green) + blue);
}
