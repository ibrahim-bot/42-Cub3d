/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:45:02 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:57:20 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int		ft_is_charset(char const *str, char c)
{
	if (str[0] == c)
		return (1);
	return (0);
}

static int		ft_to_malloc(char const *str, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (ft_is_charset(&str[i], c) == 1)
			i++;
		while (ft_is_charset(&str[i], c) == 0 && str[i] != '\0')
			i++;
		if (ft_is_charset(&str[i - 1], c) == 0)
			n++;
		if (str[i] != '\0')
			i++;
	}
	return (n);
}

static char		*ft_copy_w(char const *str, int n, int *sign, char *dest)
{
	int		i;

	i = -1;
	if (!(dest = malloc(sizeof(char) * n + 1)))
		*sign = 1;
	*dest = 0;
	while (++i != n)
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

static void		ft_do(char const *str, char c, char **split, int *sign)
{
	int		i;
	int		j;
	int		n;
	char	*dest;

	i = 0;
	j = 0;
	dest = 0;
	while (str[i] != '\0')
	{
		while (ft_is_charset(&str[i], c) == 1)
			i++;
		n = 0;
		while (ft_is_charset(&str[i + n], c) == 0 && str[i + n] != '\0')
			n++;
		if (n != 0)
		{
			split[j] = ft_copy_w(&str[i], n, sign, &dest[j]);
			j++;
			i += n;
		}
		if (*sign == 1)
			break ;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		sign;

	sign = 0;
	if (s == NULL)
		return (0);
	if (!(split = malloc(sizeof(char *) * (ft_to_malloc(s, c) + 1))))
		return (0);
	*split = 0;
	ft_do(s, c, split, &sign);
	if (sign == 1)
	{
		sign = -1;
		while (split[++sign])
			free(split[sign]);
		free(split);
		return (0);
	}
	split[ft_to_malloc(s, c)] = 0;
	return (split);
}
