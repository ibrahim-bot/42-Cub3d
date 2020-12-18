/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_talgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:36:13 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:52:07 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_null(t_bool *new)
{
	int j;
	int nb;

	j = 0;
	new->str = "(null)";
	nb = ft_strlen(new->str);
	if (ft_strlen(new->str) > new->pre && new->pre > 0)
		nb = new->pre;
	if (print_nullneg(new, nb) == 1)
		return ;
	if (new->min > 0)
		while (new->min > nb)
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
	if (new->pre > 0)
		while (new->str[j] && new->pre > 0)
		{
			new->ret += ft_putchar(new->str[j]);
			j++;
			new->pre--;
		}
	else
		new->ret += ft_putstr("(null)");
}

int		print_cent(t_bool *new, const char *str, int i)
{
	if (str[i] == '%')
	{
		while (new->min > 1 && new->left == 0)
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
		new->ret += ft_putchar('%');
		while (new->min > 1 && new->left == 1)
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
		return (1);
	}
	return (0);
}

void	print_flags(t_bool *new)
{
	int i;

	i = 2;
	if (new->str == NULL && new->pre == 0)
		i = 1;
	new->str = ft_uitoa_base(new->str, "0123456789abcdef");
	while (new->min > ft_strlen(new->str) + i && new->left == 0)
	{
		new->ret += ft_putchar(' ');
		new->min--;
	}
	new->ret += ft_putstr("0x");
	if (i == 1 && new->pre == 0)
		return ;
	new->ret += ft_putstr(new->str);
	while (new->min > ft_strlen(new->str) + 2 && new->left == 1)
	{
		new->ret += ft_putchar(' ');
		new->min--;
	}
}

void	print_cas(t_bool *new)
{
	if (new->cas == 1 && (new->nb == 0 || new->unb == 0))
	{
		while (new->min)
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
		new->args = 'z';
	}
}

void	first_cas(t_bool *new)
{
	if ((new->args == 'x' || new->args == 'X') && new->nb < 0
	&& new->min > new->pre)
		while (new->min > calcul_t(new))
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
	else
		while (new->min > calcul_2(new))
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
}
