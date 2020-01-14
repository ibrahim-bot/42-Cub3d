/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 13:04:58 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:39:13 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub.h"
#include "minilibx/mlx.h"

int deal_key(int key, void *params)
{
    if (key == 53)
        exit(0);
    return (0);
}

int map(data_t *data)
{
    int y;
    int x;

    if ((data->mlx_ptr = mlx_init()) == NULL)
            return (EXIT_FAILURE);
    if ((data->win_ptr = mlx_new_window(data->mlx_ptr, 640, 480, "WESH")) == NULL)
        return (EXIT_FAILURE);
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, 250, 250, 0xFFFFFF);
    y = 100;
    while (y < 200)
    {
        x = 100;
        while (x < 200)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFF0000);
            x++;
        }
        y++;
    }
    mlx_key_hook(data->win_ptr, deal_key, (void *)0);
    mlx_loop(data->mlx_ptr);
    return (0);
}

int charset(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W'))
            return (1);
        i++;
    }
    return (0);
}

int parset(int file, data_t *data)
{
    char **str;
    int i;

    i = 1;
    while (get_next_line(file, str))
    {
        if (str[0][0] == 'R')
        {
            data->resx = ft_atoi(sup_space(str[0], &i));
            data->resy = ft_atoi(sup_space(str[0], &i));
        }
        if (str[0][0] == 'F')
        {
           // data->resx = ft_atoi(sup_space(str[0]));
           // printf("%d\n", data->resx);
        }
        if (str[0][0] == 'C')
        {
            //data->resx = ft_atoi(sup_space(str[0]));
            //printf("%d\n", data->resx);
        }
        if (*str[0] == '1')
            break;
    }
    if (verif_map(file, str) == 1)
    {
        printf("MAP ERROR\n");
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    data_t data;
    int file;

    if (ac == 2)
    {
        if ((file = open(av[1], O_RDONLY)) < 0)
            return (1);
        if (parset(file, &data) == 1)
            return (0);
        map(&data);
    }
    if (ac == 3)
    {
        if (ft_strcmp(av[2], "-save") == 0)
            printf("wesh");
    }
    else 
        printf("Error: no map specified.   %s [.cub] [-save]\n", av[0]);
    return (0);
}