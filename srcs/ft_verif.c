/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:50:46 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/28 16:28:05 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_verif_player_config(t_file *file, char line, int nb)
{
	if (F->PL->direction != 0 && F->PL->y != 0 && F->PL->x != 0)
	{
		ft_printf("Error: player.\n");
		return (0);
	}
	F->PL->direction = line;
	if (line == 'N' || line == 'S')
	{
		F->PL->dirx = line == 'N' ? -1 : 1;
		F->PL->plany = line == 'N' ? 0.66f : -0.66f;
		F->PL->diry = 0;
		F->PL->planx = 0;
	}
	if (line == 'W' || line == 'E')
	{
		F->PL->diry = line == 'W' ? -1 : 1;
		F->PL->planx = line == 'W' ? -0.66f : 0.66f;
		F->PL->dirx = 0;
		F->PL->plany = 0;
	}
	F->PL->x = ft_strcount_char(F->M->mapchar, '\n') + 0.5;
	F->PL->y = nb + 0.5;
	return (1);
}

int			ft_verif_color_path(t_file *file)
{
	if (F->FC->f1 < 0 || F->FC->f1 > 255 || F->FC->f2 < 0
	|| F->FC->f2 > 255 || F->FC->f3 < 0 || F->FC->f3 > 255
	|| F->FC->c1 < 0 || F->FC->c1 > 255 || F->FC->c2 < 0
	|| F->FC->c2 > 255 || F->FC->c3 < 0 || F->FC->c3 > 255)
	{
		ft_printf("Error: Missing colors.\n");
		ft_free_fil(F);
		return (0);
	}
	if (!F->PA->north || !F->PA->south ||
			!F->PA->east || !F->PA->west || !F->PA->sprite)
	{
		ft_printf("Error: Missing path.\n");
		ft_free_fil(F);
		return (0);
	}
	if (F->PA->north[0] == '\0' || F->PA->south[0] == '\0' ||
			F->PA->east[0] == '\0' || F->PA->west[0] == '\0' ||
			F->PA->sprite[0] == '\0')
	{
		ft_printf("Error: Missing path.\n");
		ft_free_fil(F);
		return (0);
	}
	return (1);
}

static int	ft_verif_map2(t_file *file)
{
	int i;
	int y;

	i = -1;
	y = 0;
	while (F->M->map[++i])
	{
		if (i == 0)
		{
			if (check_f_line(F) == 84)
				return (0);
		}
		else if (i == F->M->height - 2)
		{
			if (check_l_line(F) == 84)
				return (0);
		}
		else
		{
			if (check_line(F) == 84)
				return (0);
		}
	}
	return (1);
}

int			ft_verif_map(t_file *file)
{
	if (!F->PL->direction)
	{
		ft_free_fil(F);
		ft_printf("Error: Missing starting point.\n");
		return (0);
	}
	if (F->M->height < 3 || F->M->width < 3)
	{
		ft_free_fil(F);
		ft_printf("Error: Map too small.\n");
		return (0);
	}
	if (!(ft_verif_map2(F)))
		return (0);
	return (1);
}

int			ft_start_verif(t_file *file, char **av)
{
	F->SP = NULL;
	F->save = 0;
	if (!(ft_init_color(F) && ft_init_path(F) && ft_init_map(F)
	&& ft_init_player(F) && ft_init_ray(F) && ft_init_key(F)
	&& ft_init_draw(F) && ft_init_draw_sprite(F) && ft_init_imgw(F)
	&& ft_init_hubdraw(F)))
		return (0);
	if (!(ft_parse_cube(av[1], F)))
		return (0);
	if (!(F->M->map = ft_split(F->M->mapchar, '\n')))
	{
		ft_free_fil(F);
		ft_printf("Error: Map not found.\n");
		return (0);
	}
	if (!(ft_verif_color_path(F) && ft_verif_map(F) && ft_verif_reso(F)
	&& ft_verif_path_img(F)))
		return (0);
	return (1);
}
