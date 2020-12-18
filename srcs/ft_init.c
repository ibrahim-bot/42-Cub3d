/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:48:37 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/18 10:02:54 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		ft_init_ray(t_file *file)
{
	if (!(F->R = malloc(sizeof(t_ray))))
	{
		ft_free_fil(F);
		ft_printf("Error: malloc() failed ray.\n");
		return (0);
	}
	F->R->hit = 0;
	F->R->mapy = 0;
	F->R->mapx = 0;
	F->R->side = 0;
	F->R->sidex = 0;
	F->R->sidey = 0;
	F->R->stepy = 0;
	F->R->stepx = 0;
	F->R->raydiry = 0;
	F->R->raydirx = 0;
	F->R->deltdistx = 0;
	F->R->deltdisty = 0;
	F->R->perpwalldist = 0;
	return (1);
}

int		ft_init_color(t_file *file)
{
	if (!(F->FC = malloc(sizeof(t_color))))
	{
		ft_free_fil(F);
		ft_printf("Error: malloc() failed color.\n");
		return (0);
	}
	F->FC->f1 = -1;
	F->FC->f2 = -1;
	F->FC->f3 = -1;
	F->FC->c1 = -1;
	F->FC->c2 = -1;
	F->FC->c3 = -1;
	return (1);
}

int		ft_init_map(t_file *file)
{
	if (!(F->M = malloc(sizeof(t_map))))
	{
		ft_free_fil(F);
		ft_printf("Error: malloc() failed map.\n");
		return (0);
	}
	F->M->map = NULL;
	F->M->width = 0;
	F->M->height = 0;
	F->M->mapchar = NULL;
	return (1);
}

int		ft_init_player(t_file *file)
{
	if (!(F->PL = malloc(sizeof(t_player))))
	{
		ft_free_fil(F);
		ft_printf("Error: malloc() failed player.\n");
		return (0);
	}
	F->PL->direction = 0;
	F->PL->y = -1;
	F->PL->x = -1;
	F->PL->camx = 0;
	F->PL->diry = 0;
	F->PL->dirx = 0;
	F->PL->plany = 0;
	F->PL->planx = 0;
	F->PL->pv = 3;
	F->PL->etat = 0;
	F->PL->etatx = -1;
	F->PL->etaty = -1;
	return (1);
}

int		ft_init_path(t_file *file)
{
	if (!(F->PA = malloc(sizeof(t_path))))
	{
		ft_free_fil(F);
		ft_printf("Error: malloc() failed init.\n");
		return (0);
	}
	F->PA->north = NULL;
	F->PA->south = NULL;
	F->PA->east = NULL;
	F->PA->west = NULL;
	F->PA->sprite = NULL;
	return (1);
}
