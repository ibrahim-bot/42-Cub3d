/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:58:59 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:52:18 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uconfig_ptr(unsigned long nb, char *ptr, char *base,
								long count)
{
	long				reste;
	long				j;
	unsigned long long	len;
	long				c;
	int					i;

	i = ft_strlen(base);
	c = count;
	len = i;
	c == 1 ? len /= i : 0;
	while (c-- - 1 > 1)
		len *= i;
	j = -1;
	if (count == 0)
		ptr[++j] = base[0];
	while (count > 0)
	{
		reste = nb % len;
		ptr[++j] = base[((nb - reste) / len)];
		len /= i;
		nb = reste;
		count--;
	}
	ptr[++j] = 0;
}

int		ft_ucount_nbr_base(unsigned long long nb, unsigned long long len)
{
	unsigned long long	i;
	long long			count;

	count = 0;
	i = nb;
	while (i)
	{
		i /= len;
		count++;
	}
	return (count);
}

char	*ft_uitoa_base(void *n, char *base)
{
	char				*ptr;
	unsigned long long	nb;
	unsigned long long	i;
	long long			count;

	nb = (unsigned long long)n;
	i = ft_strlen(base);
	count = ft_ucount_nbr_base(nb, i);
	if (!(ptr = malloc(count + 1)))
		return (NULL);
	*ptr = 0;
	ft_uconfig_ptr(nb, ptr, base, count);
	return (ptr);
}
