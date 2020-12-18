/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tchek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:31:50 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:52:11 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tchek_nb(t_bool *new)
{
	if (new->nb < 0 && new->min > 0 &&
	(new->pre > 0 || new->zero == 1))
		new->min -= 1;
	if (new->nb < 0 && new->min < 0)
		new->min += 1;
	if (new->nb < 0 && (new->pre > 0 || new->zero == 1))
	{
		new->ret += ft_putchar('-');
		if (new->nb == -2147483648)
		{
			new->cp_nb = new->nb;
			new->cp_nb *= -1;
			new->nb /= 10;
		}
		else
			new->nb *= -1;
	}
}

int		tchek_unsigned(t_bool *new)
{
	if (new->args == 'u')
		return (cmpt_nb(new->unb));
	else
		return (cmpt_nb(new->nb));
}

int		tchek_null(t_bool *new)
{
	if (new->str == NULL)
	{
		print_null(new);
		return (1);
	}
	return (0);
}

void	cas_max(t_bool *new)
{
	if (new->pre > 0)
	{
		if (new->nb == -2147483648)
		{
			new->cp_nb = new->nb;
			new->cp_nb *= -1;
			new->pre += 1;
		}
	}
}
