/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:47:40 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/28 15:18:15 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		verif_r(char *line, t_file *var)
{
	int i;

	i = 1;
	if (compt_cara(line) == 84)
		return (84);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			chang_xy(var);
			return (0);
		}
		if (ft_isdigit(line[i]) == 0)
			return (84);
		i++;
	}
	chang_xy(var);
	return (0);
}

int		ft_resochr(char *line, t_file *file)
{
	int i;
	int tmp;

	i = 1;
	while (line[i] == ' ')
		i++;
	F->axe_x = ft_isdigit(line[i]) ? (int)(ft_atoi((char *)line + i)) : -1;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	F->axe_y = ft_isdigit(line[i]) ? (int)(ft_atoi((char *)line + i)) : -1;
	if (verif_r(line, file) == 84)
	{
		ft_printf("Error : Bad Resolution\n");
		return (84);
	}
	tmp = F->axe_y;
	F->axe_y = F->axe_x;
	F->axe_x = tmp;
	return (0);
}

int		ft_colorchrs(char *line, t_file *file, int p, int i)
{
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		p == 1 ? (F->FC->c1 = ft_atoi((char *)line + i)) :
		(F->FC->f1 = ft_atoi((char *)line + i));
	}
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != ',')
		return (84);
	line[i] == ',' ? i++ : 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		p == 1 ? (F->FC->c2 = ft_atoi((char *)line + i)) :
		(F->FC->f2 = ft_atoi((char *)line + i));
	}
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

void	ft_colorchr(char *line, t_file *file, int p, int i)
{
	if (ft_colorchrs(line, file, p, i) == 84)
		return ;
	i = ft_colorchrs(line, file, p, i);
	while (line[i] == ' ')
		i++;
	if (line[i] != ',')
		return ;
	line[i] == ',' ? i++ : 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		p == 1 ? (F->FC->c3 = ft_atoi((char *)line + i)) :
		(F->FC->f3 = ft_atoi((char *)line + i));
	}
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		F->FC->f3 = -1;
}

void	ft_pathchr(char *line, t_file *file, int p)
{
	int i;
	int j;

	i = (p == 4 ? 1 : 2);
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] != ' ' && line[i])
		i++;
	p == 0 ? (F->PA->south = ft_substr(line, j, i)) : 0;
	p == 1 ? (F->PA->north = ft_substr(line, j, i)) : 0;
	p == 2 ? (F->PA->west = ft_substr(line, j, i)) : 0;
	p == 3 ? (F->PA->east = ft_substr(line, j, i)) : 0;
	p == 4 ? (F->PA->sprite = ft_substr(line, j, i)) : 0;
}
