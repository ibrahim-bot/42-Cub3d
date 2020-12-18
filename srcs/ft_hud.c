/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:48:29 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:56:21 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_draw_hud_life(t_file *file, int i, float x)
{
	F->HD->color = 0;
	F->HD->hmin = F->axe_x * 0.850;
	F->HD->hmax = F->axe_x * 0.950;
	F->HD->wmin = F->axe_y * x;
	F->HD->wmax = F->axe_y * (x + 0.1);
	F->HD->w = i - F->HD->wmin;
	F->HD->h = F->HD->hmin - 1;
	F->HD->percentw = (F->HD->w / (float)(F->HD->wmax - F->HD->wmin));
	while (++F->HD->h < F->HD->hmax)
	{
		F->HD->percenth = (F->HD->h - F->HD->hmin) /
		(float)(F->HD->hmax - F->HD->hmin);
		F->HD->color = F->IW->text[5][(int)(F->IW->width[5] * F->HD->percentw)
		+ F->IW->width[5] * (int)(F->IW->height[5] * F->HD->percenth)];
		(F->HD->color > 0) ? F->imgdata[(int)F->HD->h * F->axe_y + i] =
		10559749 : 0;
	}
}

void	ft_draw_hud(t_file *file, int i)
{
	i > (int)(F->axe_y * 0.65) && i <= (int)(F->axe_y * 0.65) +
		(int)(F->axe_y * 0.1) && F->PL->pv > 2
		? ft_draw_hud_life(F, i, 0.65) : 0;
	i > (int)(F->axe_y * 0.75) && i <= (int)(F->axe_y * 0.75) +
		(int)(F->axe_y * 0.1) && F->PL->pv > 1
		? ft_draw_hud_life(F, i, 0.75) : 0;
	i > (int)(F->axe_y * 0.85) && i <= (int)(F->axe_y * 0.85) +
		(int)(F->axe_y * 0.1) && F->PL->pv > 0
		? ft_draw_hud_life(F, i, 0.85) : 0;
}
