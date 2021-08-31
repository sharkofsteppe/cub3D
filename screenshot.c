/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:03:41 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 16:34:50 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	bitmapper(t_map *pt, int fd)
{
	unsigned char	res[54];
	int				filesize;

	filesize = pt->r_x * (pt->win->bpp / 8) * pt->r_y + 54;
	ft_bzero(res, 54);
	res[0] = (unsigned char)('B');
	res[1] = (unsigned char)('M');
	res[2] = (unsigned char)(filesize);
	res[3] = (unsigned char)(filesize >> 8);
	res[4] = (unsigned char)(filesize >> 16);
	res[5] = (unsigned char)(filesize >> 24);
	res[10] = (unsigned char)(54);
	res[14] = (unsigned char)(40);
	res[18] = (unsigned char)(pt->r_x);
	res[19] = (unsigned char)(pt->r_x >> 8);
	res[20] = (unsigned char)(pt->r_x >> 16);
	res[21] = (unsigned char)(pt->r_x >> 24);
	res[22] = (unsigned char)(pt->r_y);
	res[23] = (unsigned char)(pt->r_y >> 8);
	res[24] = (unsigned char)(pt->r_y >> 16);
	res[25] = (unsigned char)(pt->r_y >> 24);
	res[26] = (unsigned char)(1);
	res[28] = (unsigned char)(32);
	if ((write(fd, res, 54)) != 54)
		exit(0);
}

int		create_bmp(char *str)
{
	int fd;

	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
	{
		write(2, "ERROR\nCANNOT CREATE FILE\n", 25);
		exit(-1);
	}
	return (fd);
}

void	writeinto(int fd, t_map *pt)
{
	int x;
	int y;
	int color;

	y = pt->r_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < pt->r_x)
		{
			color = ((int *)pt->win->addr)[y * pt->win->l_l / 4 + x];
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void	screenmaker(t_map *pt)
{
	int fd;

	pt->win->mlx = mlx_init();
	pt->win->img = mlx_new_image(pt->win->mlx, pt->r_x, pt->r_y);
	pt->win->addr = mlx_get_data_addr(pt->win->img, &pt->win->bpp,
	&pt->win->l_l, &pt->win->en);
	init_texture(pt);
	raystep(pt);
	fd = create_bmp("screen.bmp");
	bitmapper(pt, fd);
	writeinto(fd, pt);
	close(fd);
}
