/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:48:12 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/28 15:08:57 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_join_char_more(t_file *file, char *join, int nb)
{
	char	*tmp;

	join[++nb] = '\n';
	join[++nb] = '\0';
	tmp = ft_strjoin(F->M->mapchar, join);
	free(F->M->mapchar);
	free(join);
	F->M->mapchar = tmp;
	return (1);
}

int			ft_join_charmap(t_file *file, char *line, int i, int nb)
{
	char	*join;

	if (!(join = malloc(sizeof(char) * 1000)))
	{
		ft_printf("Error: Malloc failed.\n");
		return (0);
	}
	i = 0;
	nb = -1;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
		|| line[i] == 'W')
			if (!(ft_verif_player_config(F, line[i], (nb + 1))))
				return (0);
		line[i] == '\0' ? 0 : (join[++nb] = line[i]);
		line[i] == '\0' ? 0 : i++;
	}
	return (ft_join_char_more(F, join, nb));
}

int			ft_set_line(t_file *file, char *line, int nb, int i)
{
	F->M->height += 1;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '2' || line[i] == '1' || line[i] == '0' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '3'
		|| line[i] == '4' || line[i] == '5' || line[i] == '6')
		{
			nb += 1;
			i++;
		}
		else if (line[i] != '\0')
		{
			ft_printf("Error: Map bad character.\n");
			return (0);
		}
	}
	if (nb == 0)
		return (1);
	else
		return (2);
	ft_printf("Error: Map error type 0.\n");
	return (0);
}

int			ft_config_map2(int i, char *line, t_file *file)
{
	if (!(i = ft_set_line(F, line, 0, 0)))
	{
		free(line);
		return (0);
	}
	else if (i == 1)
	{
		free(line);
		return (1);
	}
	else if (!(ft_join_charmap(F, line, 0, i)))
	{
		free(line);
		return (0);
	}
	free(line);
	return (2);
}
