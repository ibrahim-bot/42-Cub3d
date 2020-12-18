/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:31 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/15 12:18:17 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		ft_ray_cast_suite(t_file *file)
{
	if (F->R->raydirx < 0)
	{
		F->R->stepx = -1;
		F->R->sidex = (F->PL->x - F->R->mapx) * F->R->deltdistx;
	}
	else
	{
		F->R->stepx = 1;
		F->R->sidex = (F->R->mapx + 1.0 - F->PL->x) * F->R->deltdistx;
	}
	if (F->R->raydiry < 0)
	{
		F->R->stepy = -1;
		F->R->sidey = (F->PL->y - F->R->mapy) * F->R->deltdisty;
	}
	else
	{
		F->R->stepy = 1;
		F->R->sidey = (F->R->mapy + 1.0 - F->PL->y) * F->R->deltdisty;
	}
}

void			raycast(t_file *file)
{
	int	i;

	i = -1;
	F->R->mapx = (int)F->PL->x;
	F->R->mapy = (int)F->PL->y;
	mlx_clear_window(F->mlx, F->win);
	while (++i < F->axe_y)
	{
		F->R->hit = 0;
		F->PL->camx = 2 * i / (double)F->axe_y - 1;
		F->R->raydirx = F->PL->dirx + F->PL->planx * F->PL->camx;
		F->R->raydiry = F->PL->diry + F->PL->plany * F->PL->camx;
		F->R->mapx = (int)F->PL->x;
		F->R->mapy = (int)F->PL->y;
		F->R->deltdistx = fabs(1 / F->R->raydirx);
		F->R->deltdisty = fabs(1 / F->R->raydiry);
		ft_ray_cast_suite(file);
		ft_hit_wall(file);
		ft_draw(file, i);
		ft_draw_sprite(F, i);
		ft_draw_hud(F, i);
	}
	F->save == 0 ? mlx_put_image_to_window(F->mlx, F->win, F->img, 0, 0) : 0;
}

int				ft_snakeoil(t_file *file)
{
	raycast(F);
	ft_move(F);
	return (1);
}
