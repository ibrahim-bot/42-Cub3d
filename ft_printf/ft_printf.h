/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:00:58 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:52:51 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_bool
{
	int				ret;
	int				nb;
	long			cp_nb;
	unsigned int	unb;
	int				left;
	int				pre;
	int				zero;
	int				cas;
	int				min;
	char			args;
	char			*str;
}				t_bool;

int				ft_printf(const char *str, ...)
	 __attribute__((format(printf,1,2)));
void			display(const char *str, int i, t_bool *new);
size_t			ft_putstr(char *str);
void			cas_max(t_bool *new);
int				tchek_null(t_bool *new);
size_t			ft_putchar(char c);
void			ft_putnbr(long nb);
void			ft_putnbr_un(unsigned int n);
int				ft_strlen(char *str);
int				ft_atoi(const char *str);
void			init_struct(t_bool *new);
int				cmpt_nb(long nb);
void			print(t_bool *new);
void			print2(t_bool *new);
void			print3(t_bool *new);
void			print4(t_bool *new);
void			print_neg(t_bool *new);
void			print2_neg(t_bool *new);
void			print3_neg(t_bool *new);
void			print4_neg(t_bool *new);
int				scan_line(const char *str, int *i, t_bool *new, va_list ap);
char			*ft_itoa_base(long n, char *base);
char			*ft_uitoa_base(void *n, char *base);
int				charset(char c, const char *set);
void			disp_neg(t_bool *new);
int				print_cent(t_bool *new, const char *str, int i);
void			print_null(t_bool *new);
void			print_flags(t_bool *new);
void			print_cas(t_bool *new);
void			first_cas(t_bool *new);
int				calcul_t(t_bool *new);
int				calcul_2(t_bool *new);
void			print_leftmin(t_bool *new);
void			print_left(t_bool *new);
void			print_pre(t_bool *new);
int				print_nullneg(t_bool *new, int nb);
int				tchek_unsigned(t_bool *new);
void			tchek_nb(t_bool *new);

#endif
