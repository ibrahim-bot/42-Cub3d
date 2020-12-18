/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:50:59 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:58:08 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		ft_draw_suite2(t_file *file, int x, int texnum, int y)
{
	F->D->d = y * 256 - F->axe_x * 128 + F->D->lineheight * 128;
	F->D->texy = ((F->D->d * F->IW->height[texnum])
	/ F->D->lineheight) / 256;
	F->D->texy < 0 ? F->D->texy = 0 : 0;
	if (!((F->D->texy * F->IW->width[texnum] + F->D->texx) >=
	(int)F->IW->text[texnum]) && (F->D->texy * F->IW->width[texnum] +
	F->D->texx) >= 0)
	{
		F->imgdata[y * F->axe_y + x] = F->IW->text[texnum][(F->D->texy *
		F->IW->width[texnum] + F->D->texx)];
		if (y > 0 && !(F->IW->height[texnum] * F->IW->width[texnum] >
		(F->D->texy * F->IW->width[texnum] + F->D->texx)))
			F->imgdata[y * F->axe_y + x] = F->imgdata[(y - 1) * F->axe_y + x];
	}
}

static void		ft_draw_suite(t_file *file, int x, int texnum)
{
	int y;

	y = -1;
	while (++y < F->axe_x)
	{
		if (y < F->D->start)
			F->imgdata[y * F->axe_y + x] =
			ft_rgbtoint(F->FC->c1, F->FC->c2, F->FC->c3);
		if (y >= F->D->start && y <= F->D->end)
			ft_draw_suite2(F, x, texnum, y);
		if (y > F->D->end)
			F->imgdata[y * F->axe_y + x] =
			ft_rgbtoint(F->FC->f1, F->FC->f2, F->FC->f3);
	}
}

void			ft_draw(t_file *file, int x)
{
	int		texnum;
	double	wallx;

	texnum = 10;
	(F->R->side == 0 && F->R->mapx > F->PL->x) ? (texnum = 2) : 0;
	(F->R->side == 0 && F->R->mapx < F->PL->x) ? (texnum = 0) : 0;
	(F->R->side == 1 && F->R->mapy > F->PL->y) ? (texnum = 1) : 0;
	(F->R->side == 1 && F->R->mapy < F->PL->y) ? (texnum = 3) : 0;
	wallx = F->R->side == 0 ? F->PL->y + F->R->perpwalldist
	* F->R->raydiry :
	F->PL->x + F->R->perpwalldist * F->R->raydirx;
	wallx -= floor(wallx);
	F->D->texx = (int)(wallx * (double)F->IW->width[texnum]);
	if ((F->R->side == 0 && F->R->raydirx > 0) ||
		(F->R->side == 1 && F->R->raydiry < 0))
		F->D->texx = F->IW->width[texnum] - F->D->texx - 1;
	F->D->lineheight = (int)(F->axe_x / F->R->perpwalldist);
	F->D->start = -F->D->lineheight / 2 + F->axe_x / 2;
	F->D->end = F->D->lineheight / 2 + F->axe_x / 2;
	(F->D->start < 0) ? F->D->start = 0 : 0;
	(F->D->end >= F->axe_x) ? F->D->end = F->axe_x - 1 : 0;
	ft_draw_suite(F, x, texnum);
}

void			ft_hit_wall_verif_first_sprite(t_file *file)
{
	F->M->map[F->R->mapx][F->R->mapy] == '2' ? ft_sprit_verif_lst(F) : 0;
	F->M->map[F->R->mapx][F->R->mapy] == '4' ? ft_sprit_verif_lst(F) : 0;
	F->M->map[F->R->mapx][F->R->mapy] == '5' ? ft_sprit_verif_lst(F) : 0;
}

void			ft_hit_wall(t_file *file)
{
	ft_hit_wall_verif_first_sprite(F);
	while (F->R->hit == 0)
	{
		if (F->R->sidex < F->R->sidey)
		{
			F->R->sidex += F->R->deltdistx;
			F->R->mapx += F->R->stepx;
			F->R->side = 0;
		}
		else
		{
			F->R->sidey += F->R->deltdisty;
			F->R->mapy += F->R->stepy;
			F->R->side = 1;
		}
		if (F->M->map[F->R->mapx][F->R->mapy] == '1')
			F->R->hit = 1;
		else if (F->M->map[F->R->mapx][F->R->mapy] == '3')
			F->R->hit = 1;
		else if (F->M->map[F->R->mapx][F->R->mapy] != '0')
			ft_sprit_verif_lst(F);
	}
	F->R->perpwalldist = (F->R->side == 0) ? (F->R->mapx - F->PL->x +
	(1 - F->R->stepx) / 2) / F->R->raydirx : (F->R->mapy - F->PL->y +
	(1 - F->R->stepy) / 2) / F->R->raydiry;
}
