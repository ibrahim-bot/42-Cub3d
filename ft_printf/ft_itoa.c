/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:46:08 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:51:45 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_config_ptr(long long nb, long long i, char *ptr, char *base)
{
	long long		reste;
	long long		j;
	long long		len;

	j = -1;
	len = i;
	if (nb < 0)
	{
		nb *= -1;
		ptr[++j] = '-';
	}
	while (nb >= i)
		i *= len;
	while (i >= len)
	{
		i /= len;
		reste = nb % i;
		ptr[++j] = base[((nb - reste) / i)];
		nb = reste;
	}
	ptr[++j] = 0;
}

int		ft_count_nbr_base(long long n, long long len)
{
	long long	i;
	long long	count;

	count = 1;
	i = len;
	while (n >= i)
	{
		i *= len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(long n, char *base)
{
	char			*ptr;
	long long		nb;
	long long		i;

	nb = n;
	i = ft_strlen(base);
	if (!(ptr = malloc(ft_count_nbr_base(nb, i) + 1)))
		return (NULL);
	*ptr = 0;
	ft_config_ptr(nb, i, ptr, base);
	return (ptr);
}
