/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:50:53 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/28 16:28:38 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_verif_reso(t_file *file)
{
	if ((F->axe_x <= 0 || F->axe_x <= 0))
	{
		ft_printf("Error: Bad resolution.\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}

int	ft_verif_path_img(t_file *file)
{
	if (open(F->PA->east, O_RDONLY) < 0 || open(F->PA->north, O_RDONLY) < 0 ||
		open(F->PA->west, O_RDONLY) < 0 || open(F->PA->south, O_RDONLY) < 0 ||
		open(F->PA->sprite, O_RDONLY) < 0
		|| open("./xpm/heart.xpm", O_RDONLY) < 0)
	{
		ft_printf("Error: Bad path.\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}
