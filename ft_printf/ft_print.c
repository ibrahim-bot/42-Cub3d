/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:36:24 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:51:53 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calcul_nb(t_bool *new)
{
	if (new->args == 'u')
		if (new->pre < cmpt_nb(new->unb))
			return (cmpt_nb(new->unb));
	if (new->pre < cmpt_nb(new->nb))
		return (cmpt_nb(new->nb));
	else
		return (new->pre);
}

void	print(t_bool *new)
{
	if (new->args != 'u')
	{
		if (new->nb < 0 && new->pre > cmpt_nb(new->nb))
			new->min -= 1;
		if (new->nb < 0 && new->pre == cmpt_nb(new->nb))
			new->min -= 1;
	}
	while (new->min > calcul_nb(new))
	{
		if (new->zero == 0)
			new->ret += ft_putchar(' ');
		else
			new->ret += ft_putchar('0');
		new->min--;
	}
}

void	print2(t_bool *new)
{
	if (new->args == 'c')
	{
		while (new->min > 1)
		{
			if (new->zero == 0)
				new->ret += ft_putchar(' ');
			else
				new->ret += ft_putchar('0');
			new->min--;
		}
	}
	tchek_nb(new);
	while (new->min > tchek_unsigned(new))
	{
		if (new->zero == 0)
			new->ret += ft_putchar(' ');
		else
			new->ret += ft_putchar('0');
		new->min--;
	}
}

void	print3(t_bool *new)
{
	int i;

	i = 0;
	if (new->nb < 0)
	{
		new->ret += 1;
		ft_putchar('-');
		new->nb *= -1;
		new->min--;
	}
	if (new->pre > new->min)
		new->min = 0;
	if (new->args != 'u')
		while (i < (new->pre - cmpt_nb(new->nb)))
		{
			new->ret += ft_putchar('0');
			i++;
		}
	else
		while (i < (new->pre - cmpt_nb(new->unb)))
		{
			new->ret += ft_putchar('0');
			i++;
		}
}

void	print4(t_bool *new)
{
	if (new->pre == -1)
		new->pre = 0;
	if (new->args == 'c')
		new->nb = 1;
	while (new->min > calcul_nb(new))
	{
		if (new->zero == 0)
			new->ret += ft_putchar(' ');
		else
			new->ret += ft_putchar('0');
		new->min--;
	}
}
