/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:47:28 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 18:53:54 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void		ft_free_sprite(t_file *file)
{
	t_sprite *beg_lst;
	t_sprite *temp;

	if (F->SP == NULL)
		return ;
	beg_lst = F->SP;
	while (beg_lst)
	{
		temp = beg_lst->next;
		free(beg_lst);
		beg_lst = temp;
	}
	F->SP = NULL;
}

static void	ft_free_path(t_file *file)
{
	if (F->PA)
	{
		if (F->PA->north)
			free(F->PA->north);
		if (F->PA->south)
			free(F->PA->south);
		if (F->PA->east)
			free(F->PA->east);
		if (F->PA->west)
			free(F->PA->west);
		if (F->PA->sprite)
			free(F->PA->sprite);
		free(F->PA);
		F->PA = NULL;
	}
}

static void	ft_free_map(t_file *file)
{
	int i;

	i = -1;
	free(F->M->mapchar);
	if (F->M->map)
	{
		while (F->M->map[++i])
			free(F->M->map[i]);
		free(F->M->map);
	}
	free(F->M);
	F->M = NULL;
}

static void	ft_destroy(t_file *file)
{
	F->IW->img[0] ? mlx_destroy_image(F->mlx, F->IW->img[0]) : 0;
	F->IW->img[1] ? mlx_destroy_image(F->mlx, F->IW->img[1]) : 0;
	F->IW->img[2] ? mlx_destroy_image(F->mlx, F->IW->img[2]) : 0;
	F->IW->img[3] ? mlx_destroy_image(F->mlx, F->IW->img[3]) : 0;
	F->IW->img[4] ? mlx_destroy_image(F->mlx, F->IW->img[4]) : 0;
	F->IW->img[5] ? mlx_destroy_image(F->mlx, F->IW->img[5]) : 0;
	F->IW->img[6] ? mlx_destroy_image(F->mlx, F->IW->img[6]) : 0;
	F->IW->img[7] ? mlx_destroy_image(F->mlx, F->IW->img[7]) : 0;
}

void		ft_free_fil(t_file *file)
{
	F->PA ? ft_free_path(F) : 0;
	F->R ? free(F->R) : 0;
	F->PL ? free(F->PL) : 0;
	F->D ? free(F->D) : 0;
	F->K ? free(F->K) : 0;
	F->FC ? free(F->FC) : 0;
	F->M ? ft_free_map(F) : 0;
	F->SP ? ft_free_sprite(F) : 0;
	F->IW ? ft_destroy(F) : 0;
	F->IW ? free(F->IW) : 0;
	F->DP ? free(F->DP) : 0;
	F->HD ? free(F->HD) : 0;
	free(F);
}
