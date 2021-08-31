/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:45:57 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:25:09 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	sortsprite(int *order, double *dist, t_map *pt)
{
	int i;
	int j;
	int tmp;
	int ord;

	i = -1;
	while (++i < pt->sprc)
	{
		j = -1;
		while (++j < pt->sprc - i - 1)
		{
			if (dist[j] > dist[j + 1])
			{
				ord = order[j];
				order[j] = order[j + 1];
				order[j + 1] = ord;
				tmp = dist[j];
				dist[j] = dist[j + 1];
				dist[j + 1] = tmp;
			}
		}
	}
}

void	distorder(t_map *pt)
{
	int i;

	i = -1;
	while (++i < pt->sprc)
	{
		pt->sorder[i] = i;
		pt->sdist[i] = ((pt->x - pt->spr[i]->x) * (pt->x - pt->spr[i]->x) +
		(pt->y - pt->spr[i]->y) * (pt->y - pt->spr[i]->y));
	}
	sortsprite(pt->sorder, pt->sdist, pt);
}

void	sprite_calcs(t_map *pt, int i)
{
	pt->sx = pt->spr[pt->sorder[i]]->x - pt->x;
	pt->sy = pt->spr[pt->sorder[i]]->y - pt->y;
	pt->invdet = 1.0 / (pt->planex * pt->diry - pt->dirx * pt->planey);
	pt->formx = pt->invdet * (pt->diry * pt->sx - pt->dirx * pt->sy);
	pt->formy = pt->invdet * (-(pt->planey) * pt->sx + pt->planex * pt->sy);
	pt->sscreenx = (int)(pt->r_x - pt->r_x / 2 * (1 + pt->formx / pt->formy));
	pt->sheight = abs((int)(pt->r_y / (pt->formy)));
	pt->dsy = -pt->sheight / 2 + pt->r_y / 2;
	if (pt->dsy < 0)
		pt->dsy = 0;
	pt->dey = pt->sheight / 2 + pt->r_y / 2;
	if (pt->dey >= pt->r_y)
		pt->dey = pt->r_y - 1;
	pt->swidth = abs((int)(pt->r_y / (pt->formy)));
	pt->dsx = -pt->swidth / 2 + pt->sscreenx;
	if (pt->dsx < 0)
		pt->dsx = 0;
	pt->dex = pt->swidth / 2 + pt->sscreenx;
	if (pt->dex >= pt->r_x)
		pt->dex = pt->r_x - 1;
	pt->stripe = pt->dsx;
}

void	drawinsprite(t_map *pt)
{
	if (pt->formy > 0 && pt->stripe > 0 && pt->stripe < pt->r_x &&
		pt->formy < pt->zbuf[pt->stripe])
	{
		pt->sdiy = pt->dsy;
		while (pt->sdiy < pt->dey)
		{
			pt->d = pt->sdiy * 256 - pt->r_y * 128 + pt->sheight * 128;
			pt->texy = ((pt->d * pt->tx[4]->img_h) / pt->sheight) / 256;
			pt->color =
			((int *)pt->tx[4]->addr)[pt->tx[4]->img_w * pt->texy + pt->texx];
			if (pt->color >= 0)
				p_put(pt->win, pt->stripe, pt->sdiy, pt->color);
			pt->sdiy++;
		}
	}
}

void	sprite_operation(t_map *pt)
{
	int i;

	distorder(pt);
	i = pt->sprc;
	while (--i >= 0)
	{
		if (pt->sdist[i] > 0.2)
		{
			sprite_calcs(pt, i);
			while (pt->stripe < pt->dex)
			{
				pt->texx = (int)(256 * (pt->stripe -
				(-pt->swidth / 2 + pt->sscreenx))
				* pt->tx[4]->img_w / pt->swidth) / 256;
				drawinsprite(pt);
				pt->stripe++;
			}
		}
	}
}
