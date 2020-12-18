/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:25 by ichougra          #+#    #+#             */
/*   Updated: 2020/11/30 14:56:10 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_quit(t_file *file)
{
	mlx_destroy_window(F->mlx, F->win);
	mlx_destroy_image(F->mlx, file->img);
	ft_free_fil(F);
	exit(EXIT_SUCCESS);
	return (0);
}

int			ft_appui(int i, t_file *file)
{
	if (i == 53)
		ft_quit(F);
	if (i == 123)
		F->K->mvleft = 1;
	if (i == 124)
		F->K->mvright = 1;
	if (i == 13 || i == 126)
		F->K->up = 1;
	if (i == 1 || i == 125)
		F->K->down = 1;
	if (i == 0)
		F->K->left = 1;
	if (i == 2)
		F->K->right = 1;
	return (1);
}

int			ft_relache(int i, t_file *file)
{
	if (i == 123)
		F->K->mvleft = 0;
	if (i == 124)
		F->K->mvright = 0;
	if (i == 13 || i == 126)
		F->K->up = 0;
	if (i == 1 || i == 125)
		F->K->down = 0;
	if (i == 0)
		F->K->left = 0;
	if (i == 2)
		F->K->right = 0;
	return (1);
}
