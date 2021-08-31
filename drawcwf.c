/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcwf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:22:55 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/18 13:45:31 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	init_txt(t_map *pt, int num, char *path)
{
	if (!(pt->tx[num]->img = mlx_xpm_file_to_image(pt->win->mlx, path, \
	&pt->tx[num]->img_w, &pt->tx[num]->img_h)))
		exit(ft_errich(ERR_10));
	pt->tx[num]->addr = mlx_get_data_addr(pt->tx[num]->img, &pt->tx[num]->bpp,\
	&pt->tx[num]->l_l, &pt->tx[num]->en);
}

void	init_texture(t_map *pt)
{
	init_txt(pt, 0, pt->no);
	init_txt(pt, 1, pt->so);
	init_txt(pt, 2, pt->we);
	init_txt(pt, 3, pt->ea);
	init_txt(pt, 4, pt->s);
}

void	txtdef(t_map *pt, int height, int width, void *addr)
{
	int y;
	int color;

	pt->texx = (int)(pt->wallx * width);
	if (pt->side == 0 && pt->raydx > 0)
		pt->texx = width - pt->texx - 1;
	if (pt->side == 1 && pt->raydy < 0)
		pt->texx = width - pt->texx - 1;
	pt->step = 1.0 * height / pt->lineheight;
	pt->texpos = (pt->drawstart - pt->r_y / 2 + pt->lineheight / 2) * pt->step;
	y = pt->drawstart;
	while (y++ < pt->drawend)
	{
		pt->texy = (int)pt->texpos & (height - 1);
		pt->texpos += pt->step;
		color = ((int *)addr)[height * pt->texy + pt->texx];
		p_put(pt->win, pt->xmon, y, color);
	}
}

void	draw_c_f(t_map *pt)
{
	pt->end = pt->drawend;
	pt->start = 0;
	while (pt->start < pt->drawstart)
	{
		p_put(pt->win, pt->xmon, pt->start, pt->clr_c);
		pt->start++;
	}
	while (pt->end < pt->r_y)
	{
		p_put(pt->win, pt->xmon, pt->end, pt->clr_f);
		pt->end++;
	}
}

void	draw_c_w_f(t_map *pt)
{
	if (pt->side == 1)
	{
		if (pt->stepy > 0)
			txtdef(pt, pt->tx[1]->img_h, pt->tx[1]->img_w, pt->tx[1]->addr);
		if (pt->stepy < 0)
			txtdef(pt, pt->tx[0]->img_h, pt->tx[0]->img_w, pt->tx[0]->addr);
	}
	if (pt->side == 0)
	{
		if (pt->stepx > 0)
			txtdef(pt, pt->tx[3]->img_h, pt->tx[3]->img_w, pt->tx[3]->addr);
		if (pt->stepx < 0)
			txtdef(pt, pt->tx[2]->img_h, pt->tx[2]->img_w, pt->tx[2]->addr);
	}
	pt->zbuf[pt->xmon] = pt->pwalldist;
	draw_c_f(pt);
}
