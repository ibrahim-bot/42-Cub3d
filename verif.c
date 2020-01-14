/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   verif.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 16:09:28 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 15:39:35 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub.h"
#include "get_next_line.h"

int verif_first(int file, int i, char **str, int len)
{
    int j;

    j = 0;
    while (str[i][j])
    {
        if (ft_l(str[i]) != len)
            return (1);
        if (str[i][j] != '1')
            return (1);
        j++;
    }
    return (0);
}

int verif_map(int file, char **str)
{
    int i;
    int len;

    i = 0;
    len = ft_l(str[i]);
    if (verif_first(file, i, str, len) == 1)
        return (1);
    while (42)
    {
        if (ft_l(str[i]) != len)
            return (1);
        if (str[i][0] != '1' && str[i][len] != '1')
            return (1);
        if (charset(str[i]) == 1)
            return (1);
        i++;
        if (get_next_line(file, &str[i]) == 0)
            break;
    }
    if (verif_first(file, i, str, len) == 1)
        return (1);
    return (0);
}

char *sup_space(char *str, int *i)
{
    char *tmp;
    int j;
    
    j = 0;
    if (tmp != NULL)
        free(tmp);
    tmp = NULL;
    tmp = malloc(sizeof(char *) * ft_l(str));
    tmp[0] = '\0';
    while (str[*i] > '9' || str[*i] < '0')
    {
        *i = *i + 1;
    }
    while (str[*i] != ' ')
    {
        tmp[j] = str[*i];
        j++;
        *i = *i + 1;
    }
    tmp[j] = '\0';
    return (tmp);
}