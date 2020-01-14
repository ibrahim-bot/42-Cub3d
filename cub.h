/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 13:05:09 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:30:38 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct    data_s
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     resy;
    int     resx;    
}                 data_t;

int	ft_strcmp(const char *s1, const char *s2);
int charset(char *str);
int	ft_atoi(const char *str);
char *sup_space(char *str, int *i);
int verif_map(int file, char **str);
int verif_first(int file, int i, char **str, int len);

#endif