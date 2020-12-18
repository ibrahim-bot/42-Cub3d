/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:24:22 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:51:44 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_nb(t_bool *new, va_list ap)
{
	if (new->args == 'd' || new->args == 'c' || new->args == 'i')
		new->nb = va_arg(ap, int);
	if (new->args == 'u')
		new->unb = va_arg(ap, unsigned int);
	if (new->args == 'x' || new->args == 'X')
		new->nb = va_arg(ap, unsigned int);
	if (new->args == 'p')
		new->str = va_arg(ap, void *);
	if (new->args == 's')
		new->str = va_arg(ap, char *);
	if (new->nb != 0)
		new->unb = 1;
}

void	parset_pre(const char *str, int *i, t_bool *new, va_list ap)
{
	*i = *i + 1;
	new->pre = 0;
	new->zero = 0;
	if (str[*i] != '*')
		new->pre = ft_atoi(&str[*i]);
	if (str[*i] == '*')
	{
		new->pre = va_arg(ap, int);
		new->cas = 2;
		return ;
	}
	if (charset(str[*i], "cspdiuxX%") == 1)
		*i = *i - 1;
	*i = *i + cmpt_nb(ft_atoi(&str[*i])) - 1;
}

void	parset_star(t_bool *new, va_list ap)
{
	if (new->min == 0)
		new->min = va_arg(ap, int);
}

void	loop_parse(const char *str, int *i, t_bool *new, va_list ap)
{
	if (str[*i] == '.' && new->pre == -1)
		parset_pre(str, i, new, ap);
	else if (str[*i] >= '1' && str[*i] <= '9')
	{
		new->min = ft_atoi(&str[*i]);
		*i = *i + cmpt_nb(new->min) - 1;
	}
	if (str[*i] == '-')
	{
		new->left = 1;
		new->zero = 0;
	}
	if (str[*i] == '*' && new->cas != 2)
		parset_star(new, ap);
}

int		scan_line(const char *str, int *i, t_bool *new, va_list ap)
{
	if (str[*i] == '\n')
	{
		new->ret += write(1, "\n", 1);
		new->cas = 4;
		return (0);
	}
	init_struct(new);
	if (str[*i] == '0')
		new->zero = 1;
	while (str[*i] && charset(str[*i], "cspdiuxX%") != 1)
	{
		loop_parse(str, i, new, ap);
		*i = *i + 1;
	}
	new->args = str[*i];
	init_nb(new, ap);
	if (charset(new->args, "up%") == 1)
		new->nb++;
	if ((new->nb == 0 || new->unb == 0) && new->pre == 0
	&& new->args != 'c' && new->args != 'p')
		return (1);
	return (0);
}
