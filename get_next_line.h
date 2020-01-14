/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 13:43:21 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 13:22:24 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_l(char const *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_sub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif
