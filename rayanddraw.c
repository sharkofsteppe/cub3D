/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayanddraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:51:44 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 13:14:18 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	initial_calcs(t_map *pt)
{
	pt->camx = 2 * (pt->r_x - pt->xmon) / (double)pt->r_x - 1;
	pt->raydx = pt->dirx + pt->planex * pt->camx;
	pt->raydy = pt->diry + pt->planey * pt->camx;
	pt->mapx = (int)(pt->x);
	pt->mapy = (int)(pt->y);
	pt->deltadistx = fabs(1 / pt->raydx);
	pt->deltadisty = fabs(1 / pt->raydy);
}

void	stepnstep(t_map *pt)
{
	if (pt->raydx < 0)
	{
		pt->stepx = -1;
		pt->sidedistx = (pt->x - pt->mapx) * pt->deltadistx;
	}
	else
	{
		pt->stepx = 1;
		pt->sidedistx = (pt->mapx + 1.0 - pt->x) * pt->deltadistx;
	}
	if (pt->raydy < 0)
	{
		pt->stepy = -1;
		pt->sidedisty = (pt->y - pt->mapy) * pt->deltadisty;
	}
	else
	{
		pt->stepy = 1;
		pt->sidedisty = (pt->mapy + 1.0 - pt->y) * pt->deltadisty;
	}
}

void	dda_realise(t_map *pt)
{
	pt->hit = 0;
	while (pt->hit == 0)
	{
		if (pt->sidedistx < pt->sidedisty)
		{
			pt->sidedistx += pt->deltadistx;
			pt->mapx += pt->stepx;
			pt->side = 0;
		}
		else
		{
			pt->sidedisty += pt->deltadisty;
			pt->mapy += pt->stepy;
			pt->side = 1;
		}
		if (pt->map[pt->mapy][pt->mapx] == '1')
			pt->hit = 1;
	}
}

void	draw_calcs(t_map *pt)
{
	if (pt->side == 0)
		pt->pwalldist = (pt->mapx - pt->x + (1 - pt->stepx) / 2) / pt->raydx;
	else
		pt->pwalldist = (pt->mapy - pt->y + (1 - pt->stepy) / 2) / pt->raydy;
	pt->lineheight = (int)(pt->r_y / pt->pwalldist);
	pt->drawstart = -pt->lineheight / 2 + pt->r_y / 2;
	if (pt->drawstart < 0)
		pt->drawstart = 0;
	pt->drawend = pt->lineheight / 2 + pt->r_y / 2;
	if (pt->drawend >= pt->r_y)
		pt->drawend = pt->r_y - 1;
	if (pt->side == 0)
		pt->wallx = pt->y + pt->pwalldist * pt->raydy;
	else
		pt->wallx = pt->x + pt->pwalldist * pt->raydx;
	pt->wallx -= floor(pt->wallx);
}

void	raystep(t_map *pt)
{
	pt->xmon = -1;
	while (++pt->xmon < pt->r_x)
	{
		initial_calcs(pt);
		stepnstep(pt);
		dda_realise(pt);
		draw_calcs(pt);
		draw_c_w_f(pt);
	}
	sprite_operation(pt);
}
