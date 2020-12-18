/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:47:31 by ichougra          #+#    #+#             */
/*   Updated: 2020/02/25 15:57:43 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		ft_strcount_char(char *str, char find)
{
	int nb;
	int i;

	nb = 0;
	i = -1;
	while (str[++i])
		if (str[i] == find)
			nb++;
	return (nb);
}
