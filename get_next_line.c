/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 13:42:42 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 15:57:50 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buf(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*loop(char *stat, int fd, int *ret)
{
	char	*buff;
	char	*tmp;

	if (stat == NULL)
	{
		stat = malloc(sizeof(char) * BUFFER_SIZE + 1);
		*stat = '\0';
	}
	*ret = 0;
	if (!(buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	*buff = '\0';
	while ((check_buf(buff) == -1) && (*ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[*ret] = '\0';
		tmp = stat;
		stat = ft_strjoin(stat, buff);
		free(tmp);
	}
	free(buff);
	return (stat);
}

char	*cut_stat(char *stat, int i, char **line)
{
	char *tmp;

	*line = ft_sub(stat, 0, i);
	tmp = stat;
	stat = ft_sub(stat, i + 1, ft_l(stat) - ft_l(*line));
	free(tmp);
	return (stat);
}

int		get_next_line(int fd, char **line)
{
	static char	*stat;
	int			i;
	int			ret;
	char		errbuf[1];

	if (!line || read(fd, errbuf, 0))
		return (-1);
	stat = loop(stat, fd, &ret);
	if ((i = check_buf(stat)) >= 0)
		stat = cut_stat(stat, i, line);
	else
	{
		if (!(*line = ft_strdup(stat)))
			return (-1);
		stat[0] = 0;
		if (ret == 0)
		{
			free(stat);
			stat = NULL;
			return (0);
		}
	}
	return (1);
}
