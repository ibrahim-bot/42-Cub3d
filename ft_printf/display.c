/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:28:50 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:51:27 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nullneg(t_bool *new, int nb)
{
	int j;

	j = 0;
	if (new->left != 1)
		return (0);
	if (new->pre > 0)
		while (new->str[j] && new->pre > 0)
		{
			new->ret += ft_putchar(new->str[j]);
			j++;
			new->pre--;
		}
	else
		new->ret += ft_putstr("(null)");
	if (new->min > 0)
		while (new->min > nb)
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
	return (1);
}

void	print_string(t_bool *new)
{
	if (tchek_null(new) == 1)
		return ;
	if (ft_strlen(new->str) == 0)
		new->left = 0;
	if (new->pre > 0 && new->left == 0)
		first_cas(new);
	else
		while (new->min > ft_strlen(new->str) && new->left == 0)
		{
			if (new->zero == 0)
				new->ret += ft_putchar(' ');
			else
				new->ret += ft_putchar('0');
			new->min--;
		}
	if (new->pre > 0)
		print_pre(new);
	else
		new->ret += ft_putstr(new->str);
	if (new->pre > 0 && new->left == 1)
		print_left(new);
	if (new->min > 0 && new->left == 1 && new->pre <= 0)
		print_leftmin(new);
	return ;
}

void	disp_d(t_bool *new)
{
	if (new->cp_nb == 2147483648)
	{
		ft_putnbr(new->cp_nb);
		new->ret += cmpt_nb(new->cp_nb);
	}
	else
	{
		ft_putnbr(new->nb);
		new->ret += cmpt_nb(new->nb);
	}
}

void	display_cont(t_bool *new)
{
	if (new->min != 0 && new->pre > 0 && new->left == 0)
		print(new);
	else if (new->min != 0 && new->left == 0)
		print2(new);
	if (new->pre > 0)
		print3(new);
	if (new->args == 'u' && new->cas != 1)
	{
		ft_putnbr_un(new->unb);
		new->ret += cmpt_nb(new->unb);
	}
	if ((new->args == 'd' || new->args == 'i') && new->cas != 1)
		disp_d(new);
	if (new->args == 'c')
		new->ret += ft_putchar(new->nb);
	if (new->min != 0 && new->left != 0)
		print4(new);
}

void	display(const char *str, int i, t_bool *new)
{
	if (print_cent(new, str, i) == 1)
		return ;
	if (new->cas == 1 && new->min == 0)
		return ;
	if (new->args == 'p')
	{
		print_flags(new);
		free(new->str);
		return ;
	}
	print_cas(new);
	cas_max(new);
	if (new->args == 'x')
		new->str = ft_itoa_base((unsigned int)new->nb, "0123456789abcdef");
	if (new->args == 'X')
		new->str = ft_itoa_base((unsigned int)new->nb, "0123456789ABCDEF");
	if (new->args == 's' || new->args == 'x' || new->args == 'X')
		print_string(new);
	if (new->args == 's' || new->args == 'x' || new->args == 'X')
	{
		new->min = 0;
		new->pre = 0;
		new->left = 0;
	}
	display_cont(new);
}
