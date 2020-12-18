/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:43:51 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/18 13:00:07 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_parse_cube2(t_file *file, char *line, int i, int *j)
{
	if (!ft_strncmp(&line[i], "C ", 2))
		ft_colorchr(&line[i], F, 1, 1);
	else if (!ft_strncmp(&line[i], "F ", 2))
		ft_colorchr(&line[i], F, 0, 1);
	else if (!ft_strncmp(&line[i], "SO ", 3) && !F->PA->south)
		ft_pathchr(&line[i], F, 0);
	else if (!ft_strncmp(&line[i], "NO ", 3) && !F->PA->north)
		ft_pathchr(&line[i], F, 1);
	else if (!ft_strncmp(&line[i], "WE ", 3) && !F->PA->west)
		ft_pathchr(&line[i], F, 2);
	else if (!ft_strncmp(&line[i], "EA ", 3) && !F->PA->east)
		ft_pathchr(&line[i], F, 3);
	else if (!ft_strncmp(&line[i], "S ", 2) && !F->PA->sprite)
		ft_pathchr(&line[i], F, 4);
	else if (line[i] != '\0' && line[i] != '1')
	{
		free(line);
		ft_printf("Error: No map outline.\n");
		return (0);
	}
	else if (line[i] == '1')
		*j = 1;
	if (line[0] == '\0' && *j == 1)
	{
		free(line);
		ft_printf("Error: No map outline.\n");
		return (0);
	}
	return (1);
}

int			 ft_parse_cube(char *fichier, t_file *file)
{
	char	*line;
	int		i;
	int		fd;
	static int j;

	j = 0;
	if ((fd = open(fichier, O_RDONLY)) < 0)
		ft_printf("Error open(): the file does not exist.\n");
	while ((get_next_line(fd, &line) > 0))
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (!ft_strncmp(&line[i], "R ", 2))
		{
			if (ft_resochr(&line[i], F) == 84)
				return (0);
		}
		else if (!(ft_parse_cube2(F, line, i, &j)))
			return (0);
		if (ft_strncmp(&line[i], "1", 1))
			free(line);
		else if (!ft_config_map(fd, line, file))
			return (0);
	}
	return (ft_error_parse(F, fd, line));
}

static void	ft_cube(t_file *file)
{
	int		bits;
	int		sizeline;
	int		end;

	F->mlx = mlx_init();
	F->win = mlx_new_window(F->mlx, F->axe_y, F->axe_x, "OUIOUI");
	F->img = mlx_new_image(F->mlx, F->axe_y, F->axe_x);
	ft_readxpm(F, F->PA->north, 0);
	ft_readxpm(F, F->PA->south, 2);
	ft_readxpm(F, F->PA->east, 1);
	ft_readxpm(F, F->PA->west, 3);
	ft_readxpm(F, F->PA->sprite, 4);
	ft_readxpm(F, "./xpm/ciela.xpm", 5);
	ft_readxpm(F, "./xpm/eye.xpm", 6);
	ft_readxpm(F, "./xpm/heart.xpm", 7);
	F->imgdata = (int *)mlx_get_data_addr(F->img, &bits, &sizeline, &end);
	F->save ? ft_smile(F) : 0;
	mlx_loop_hook(F->mlx, ft_snakeoil, (void *)F);
	mlx_hook(F->win, 2, 0, ft_appui, (void *)F);
	mlx_hook(F->win, 3, 0, ft_relache, (void *)F);
	mlx_hook(F->win, 17, 0, ft_quit, (void *)F);
	mlx_loop(F->mlx);
}

int			main(int ac, char **av)
{
	t_file	*file;
	int		i;

	if (error_main(ac, av) == 1)
		return (1);
	i = ft_strlen(av[1]);
	if (ft_strcmp(&av[1][i - 4], ".cub"))
	{
		ft_printf("Error: Bad extention.\nWrite %s [.cub] ([--save])\n", av[0]);
		return (1);
	}
	if (!(F = malloc(sizeof(t_file))))
	{
		ft_printf("Error: memory not allocated.\n");
		return (0);
	}
	if ((ft_start_verif(F, av)) == 0)
		return (84);
	ac == 3 ? F->save = 1 : 0;
	ft_cube(F);
	return (0);
}