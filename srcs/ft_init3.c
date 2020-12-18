/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:03 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/15 10:22:54 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int			ft_init_hubdraw(t_file *file)
{
	if (!(F->HD = malloc(sizeof(t_hubdr))))
	{
		ft_free_fil(F);
		ft_printf("Error: malloc() failed hub draw.\n");
		return (0);
	}
	return (1);
}
