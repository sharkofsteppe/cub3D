/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:10:55 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:52:48 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	gof_gob(t_map *pt)
{
	if (pt->key_w)
	{
		if (pt->map[(int)(pt->y)][(int)(pt->x + pt->dirx * pt->ms)] != '1')
			pt->x += pt->dirx * pt->ms;
		if (pt->map[(int)(pt->y + pt->diry * pt->ms)][(int)(pt->x)] != '1')
			pt->y += pt->diry * pt->ms;
	}
	if (pt->key_s)
	{
		if (pt->map[(int)(pt->y)][(int)(pt->x - pt->dirx * pt->ms)] != '1')
			pt->x -= pt->dirx * pt->ms;
		if (pt->map[(int)(pt->y - pt->diry * pt->ms)][(int)(pt->x)] != '1')
			pt->y -= pt->diry * pt->ms;
	}
}

void	gol_gor(t_map *pt)
{
	if (pt->key_a)
	{
		if (pt->map[(int)(pt->y + pt->planey * pt->ms)][(int)pt->x] != '1')
			pt->y += pt->planey * pt->ms;
		if (pt->map[(int)pt->y][(int)(pt->x + pt->planex * pt->ms)] != '1')
			pt->x += pt->planex * pt->ms;
	}
	if (pt->key_d)
	{
		if (pt->map[(int)(pt->y - pt->planey * pt->ms)][(int)pt->x] != '1')
			pt->y -= pt->planey * pt->ms;
		if (pt->map[(int)pt->y][(int)(pt->x - pt->planex * pt->ms)] != '1')
			pt->x -= pt->planex * pt->ms;
	}
}

void	turn_lnr(t_map *pt)
{
	if (pt->key_r)
	{
		pt->oldirx = pt->dirx;
		pt->dirx = pt->dirx * cos(pt->rs) - pt->diry * sin(pt->rs);
		pt->diry = pt->oldirx * sin(pt->rs) + pt->diry * cos(pt->rs);
		pt->oldplanex = pt->planex;
		pt->planex = pt->planex * cos(pt->rs) - pt->planey * sin(pt->rs);
		pt->planey = pt->oldplanex * sin(pt->rs) + pt->planey * cos(pt->rs);
	}
	if (pt->key_l)
	{
		pt->oldirx = pt->dirx;
		pt->dirx = pt->dirx * cos(-pt->rs) - pt->diry * sin(-pt->rs);
		pt->diry = pt->oldirx * sin(-pt->rs) + pt->diry * cos(-pt->rs);
		pt->oldplanex = pt->planex;
		pt->planex = pt->planex * cos(-pt->rs) - pt->planey * sin(-pt->rs);
		pt->planey = pt->oldplanex * sin(-pt->rs) + pt->planey * cos(-pt->rs);
	}
}

int		key_update(t_map *pt)
{
	pt->ms = 0.15;
	pt->rs = 0.05;
	gof_gob(pt);
	gol_gor(pt);
	turn_lnr(pt);
	return (0);
}
