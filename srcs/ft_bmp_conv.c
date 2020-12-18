/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:44:00 by ichougra          #+#    #+#             */
/*   Updated: 2020/12/17 15:05:49 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	bitmap_image(t_file *file, int fd, t_header2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = F->axe_x - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < F->axe_y)
		{
			ble = F->imgdata[y * F->axe_y + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void	save_bitmap(char *filename, t_file *file)
{
	int			fd;
	t_header	bfh;
	t_header2	bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = F->axe_y * F->axe_x * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = F->axe_y;
	bih.height = F->axe_x;
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = F->axe_y * F->axe_x * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	close(open(filename, O_RDWR | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, &bfh, 14);
	bitmap_image(F, fd, bih);
	close(fd);
}

void	ft_smile(t_file *file)
{
	int		bits;
	int		sizeline;
	int		end;

	F->save = 1;
	F->img = mlx_new_image(F->mlx, F->axe_y, F->axe_x);
	F->imgdata = (int *)mlx_get_data_addr(file->img, &bits, &sizeline, &end);
	raycast(file);
	save_bitmap("cube.bmp", F);
	ft_quit(F);
}
