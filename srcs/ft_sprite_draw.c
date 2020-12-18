/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:50 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:57:26 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_draw_sp_2(t_file *file, int i, t_sprite *sprite)
{
	while (F->DP->drawstarty < F->DP->drawendy)
	{
		F->DP->d = (F->DP->drawstarty - F->DP->vmovescreen) * 256 -
		F->axe_x * 128 + F->DP->height * 128;
		F->DP->texy = ((F->DP->d * F->IW->height[SP->nb]) /
		F->DP->height) / 256;
		F->DP->color = (F->IW->width[SP->nb] * F->DP->texy + F->DP->texx >=
		(int)F->IW->text[SP->nb] ? 0 :
		F->IW->text[SP->nb][F->IW->width[SP->nb] *
		F->DP->texy + F->DP->texx]);
		(F->DP->color > 0) ? F->imgdata[F->DP->drawstarty *
		F->axe_y + i] = F->DP->color : 0;
		F->DP->drawstarty++;
	}
}

static void	ft_draw_sprite_it(t_file *file, int i, t_sprite *sprite)
{
	F->DP->color = 0;
	F->DP->vmovescreen = (int)(0.0 / F->DP->y);
	F->DP->width = abs((int)(F->axe_x / (F->DP->y))) / F->DP->inverse;
	F->DP->drawstartx = -F->DP->width / 2 + F->DP->screen;
	(F->DP->drawstartx < 0) ? F->DP->drawstartx = 0 : 0;
	F->DP->drawendx = F->DP->width / 2 + F->DP->screen;
	(F->DP->drawendx >= F->axe_y) ? F->DP->drawendx = F->axe_y - 1 : 0;
	if (i >= F->DP->drawstartx && i < F->DP->drawendx)
	{
		F->DP->texx = (int)(256 * (i - (-F->DP->width / 2 +
		F->DP->screen)) * F->IW->width[SP->nb] / F->DP->width) / 256;
		if (F->DP->y > 0 && i >= 0 && i < F->axe_y && F->DP->y)
			ft_draw_sp_2(F, i, sprite);
	}
}

static void	ft_draw_sprite_calc(t_file *file, int i, t_sprite *sprite)
{
	double spritex;
	double spritey;

	spritex = 0.0;
	spritey = 0.0;
	spritex = sprite->x - F->PL->x;
	spritey = sprite->y - F->PL->y;
	F->DP->inverse = 1 / (F->PL->planx * F->PL->diry - F->PL->dirx
	* F->PL->plany);
	F->DP->x = F->DP->inverse * (F->PL->diry * spritex - F->PL->dirx
	* spritey);
	F->DP->y = F->DP->inverse * (-F->PL->plany * spritex + F->PL->planx
	* spritey);
	F->DP->screen = (int)((F->axe_y / 2) * (1 + F->DP->x / F->DP->y));
	F->DP->height = abs((int)(F->axe_x / F->DP->y)) / F->DP->inverse;
	F->DP->start = -F->DP->height / 2 + F->axe_x / 2 + F->DP->screen;
	F->DP->end = F->DP->height / 2 + F->axe_x / 2 + F->DP->screen;
	F->DP->start < 0 ? F->DP->start = 0 : 0;
	F->DP->end >= F->axe_x ? F->DP->end = F->axe_x - 1 : 0;
	F->DP->drawstarty = -F->DP->height / 2 + F->axe_x / 2 + 0.0;
	(F->DP->drawstarty < 0) ? F->DP->drawstarty = 0 : 0;
	F->DP->drawendy = F->DP->height / 2 + F->axe_x / 2 + 0.0;
	(F->DP->drawendy >= F->axe_x) ? F->DP->drawendy = F->axe_x - 1 : 0;
	ft_draw_sprite_it(F, i, sprite);
}

void		ft_draw_sprite(t_file *file, int i)
{
	t_sprite	*beg_lst;
	t_sprite	*tmp;

	beg_lst = F->SP;
	F->SP = NULL;
	free(F->SP);
	F->SP = NULL;
	while (beg_lst != NULL)
	{
		ft_draw_sprite_calc(F, i, beg_lst);
		tmp = beg_lst->next;
		free(beg_lst);
		beg_lst = tmp;
	}
}
