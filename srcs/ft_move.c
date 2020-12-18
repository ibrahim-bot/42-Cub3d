/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:38 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 18:52:47 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_verif_etat2(t_file *file)
{
	if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y)] == '4' ||
	F->M->map[(int)(F->PL->x)][(int)(F->PL->y)] == '6')
	{
		if (F->PL->pv < 3 && (F->PL->etatx != (int)F->PL->x
		|| F->PL->etaty != (int)F->PL->y))
		{
			F->PL->pv++;
			F->PL->etat = 1;
			F->PL->etatx = (int)F->PL->x;
			F->PL->etaty = (int)F->PL->y;
		}
	}
	else if (F->PL->etat != 0)
	{
		F->PL->etat = 0;
		F->PL->etatx = -1;
		F->PL->etaty = -1;
	}
}

static void	ft_verif_etat(t_file *file)
{
	if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y)] == '5')
	{
		if ((F->PL->etatx != (int)F->PL->x || F->PL->etaty !=
		(int)F->PL->y) && F->PL->pv > 0)
		{
			F->PL->pv-- == 1 ? ft_quit(F) : 0;
			F->PL->etat = 2;
			F->PL->etatx = (int)F->PL->x;
			F->PL->etaty = (int)F->PL->y;
		}
	}
	else if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y)] == '3')
	{
		if ((F->PL->etatx != (int)F->PL->x || F->PL->etaty != (int)F->PL->y))
		{
			F->PL->etat = 3;
			F->PL->etatx = (int)F->PL->x;
			F->PL->etaty = (int)F->PL->y;
		}
	}
	else
		ft_verif_etat2(F);
}

static void	ft_move3(t_file *file)
{
	float olddirx;
	float oldplanex;

	olddirx = F->PL->dirx;
	oldplanex = F->PL->planx;
	if (F->K->mvright)
	{
		F->PL->dirx = F->PL->dirx * cos(-0.050) -
		F->PL->diry * sin(-0.050);
		F->PL->diry = olddirx * sin(-0.050) + F->PL->diry * cos(-0.050);
		F->PL->planx = F->PL->planx * cos(-0.050) -
		F->PL->plany * sin(-0.050);
		F->PL->plany = oldplanex * sin(-0.050) + F->PL->plany * cos(-0.050);
	}
	olddirx = F->PL->dirx;
	oldplanex = F->PL->planx;
	if (F->K->mvleft)
	{
		F->PL->dirx = F->PL->dirx * cos(0.050) -
		F->PL->diry * sin(0.050);
		F->PL->diry = olddirx * sin(0.050) + F->PL->diry * cos(0.050);
		F->PL->planx = F->PL->planx * cos(0.050) -
		F->PL->plany * sin(0.050);
		F->PL->plany = oldplanex * sin(0.050) + F->PL->plany * cos(0.050);
	}
}

static void	ft_move2(t_file *file)
{
	if (F->K->right)
	{
		if (F->M->map[(int)(F->PL->x + F->PL->diry * 0.06)]
		[(int)(F->PL->y + 0.00001)] != '1' && F->M->map[(int)(F->PL->x +
		F->PL->diry * 0.06)][(int)(F->PL->y - 0.00001)] != '1')
			F->PL->x += F->PL->diry * 0.05;
		if (F->M->map[(int)(F->PL->x + 0.00001)][(int)(F->PL->y -
		F->PL->dirx * 0.06)] != '1' && F->M->map[(int)(F->PL->x -
		0.00001)][(int)(F->PL->y - F->PL->dirx * 0.06)] != '1')
			F->PL->y -= F->PL->dirx * 0.05;
	}
	if (F->K->left)
	{
		if (F->M->map[(int)(F->PL->x - F->PL->diry * 0.06)]
		[(int)(F->PL->y + 0.00001)] != '1' && F->M->map[(int)(F->PL->x -
		F->PL->diry * 0.06)][(int)(F->PL->y - 0.00001)] != '1')
			F->PL->x -= F->PL->diry * 0.05;
		if (F->M->map[(int)(F->PL->x - 0.00001)][(int)(F->PL->y +
		F->PL->dirx * 0.06)] != '1' && F->M->map[(int)(F->PL->x +
		0.00001)][(int)(F->PL->y + F->PL->dirx * 0.06)] != '1')
			F->PL->y += F->PL->dirx * 0.05;
	}
	ft_move3(F);
}

void		ft_move(t_file *file)
{
	if (F->K->up)
	{
		if (F->M->map[(int)(F->PL->x + F->PL->dirx * 0.06)]
		[(int)(F->PL->y + 0.00001)] != '1' && F->M->map[(int)(F->PL->x +
		F->PL->dirx * 0.06)][(int)(F->PL->y - 0.00001)] != '1')
			F->PL->x += F->PL->dirx * 0.05;
		if (F->M->map[(int)(F->PL->x)][(int)(F->PL->y +
		F->PL->diry * 0.06)] != '1' && F->M->map[(int)(F->PL->x)]
		[(int)(F->PL->y + F->PL->diry * 0.06)] != '1')
			F->PL->y += F->PL->diry * 0.05;
	}
	if (F->K->down)
	{
		if (F->M->map[(int)(F->PL->x - F->PL->dirx * 0.06)]
		[(int)(F->PL->y + 0.00001)] != '1' && F->M->map[(int)(F->PL->x -
		F->PL->dirx * 0.06)][(int)(F->PL->y - 0.00001)] != '1')
			F->PL->x -= F->PL->dirx * 0.05;
		if (F->M->map[(int)(F->PL->x + 0.00001)][(int)(F->PL->y -
		F->PL->diry * 0.06)] != '1' && F->M->map[(int)(F->PL->x - 0.00001)]
		[(int)(F->PL->y - F->PL->diry * 0.06)] != '1')
			F->PL->y -= F->PL->diry * 0.05;
	}
	ft_move2(F);
	ft_verif_etat(F);
}
