/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:50:40 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:57:33 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_sprite		*ft_sprit_add_lstorder(t_file *file, t_sprite *sprite)
{
	t_sprite	*beg_lst;

	if (F->SP == NULL)
		return (NULL);
	beg_lst = F->SP;
	while (beg_lst->next != NULL)
	{
		if (beg_lst->dist < sprite->dist)
			return (beg_lst);
		beg_lst = beg_lst->next;
	}
	return (beg_lst);
}

static void			ft_sprit_config_add_lst(t_file *file, t_sprite *sprite)
{
	t_sprite *beg_lst;

	beg_lst = ft_sprit_add_lstorder(F, sprite);
	if (F->SP == beg_lst)
	{
		if (beg_lst->dist < sprite->dist)
		{
			sprite->next = beg_lst;
			F->SP = sprite;
		}
		else
			beg_lst->next = sprite;
	}
	else
	{
		if (beg_lst->dist > sprite->dist)
			beg_lst->next = sprite;
		else
		{
			sprite->next = beg_lst;
			beg_lst = sprite;
		}
	}
}

static int			ft_sprit_add_lst(t_file *file, t_sprite *sprite)
{
	if (F == NULL || sprite == NULL)
		return (-1);
	if (F->SP == NULL)
		F->SP = sprite;
	else
		ft_sprit_config_add_lst(F, sprite);
	return (0);
}

static int			ft_sprit_check(t_file *file)
{
	t_sprite	*beg_lst;

	beg_lst = F->SP;
	while (beg_lst != NULL)
	{
		if (beg_lst->x == F->R->mapx && beg_lst->y == F->R->mapy)
			return (0);
		beg_lst = beg_lst->next;
	}
	return (1);
}

void				ft_sprit_verif_lst(t_file *file)
{
	float d;

	if (F->M->map[F->R->mapx][F->R->mapy] == '2' ||
		F->M->map[F->R->mapx][F->R->mapy] == '4' ||
		F->M->map[F->R->mapx][F->R->mapy] == '5' ||
		F->M->map[F->R->mapx][F->R->mapy] == '6')
		if (ft_sprit_check(F))
		{
			d = ((F->PL->x - 0.5 - F->R->mapx) * (F->PL->x - 0.5 - F->R->mapx)
			+ (F->PL->y - 0.5 - F->R->mapy) * (F->PL->y - 0.5 - F->R->mapy));
			if (ft_sprit_add_lst(F,
			ft_init_sprite(F, F->R->mapx, F->R->mapy, d)))
			{
				ft_printf("Error\nCreate sprite\n");
				ft_quit(F);
			}
		}
}
