/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_crd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:33:31 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/17 11:53:29 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	plr_north(t_map *pt)
{
	pt->dirx = 0.0;
	pt->diry = -1.0;
	pt->planex = -0.66;
	pt->planey = 0.0;
}

void	plr_south(t_map *pt)
{
	pt->dirx = 0.0;
	pt->diry = 1.0;
	pt->planex = 0.66;
	pt->planey = 0.0;
}

void	plr_west(t_map *pt)
{
	pt->dirx = -1.0;
	pt->diry = 0.0;
	pt->planex = 0.0;
	pt->planey = 0.66;
}

void	plr_east(t_map *pt)
{
	pt->dirx = 1.0;
	pt->diry = 0.0;
	pt->planex = 0.0;
	pt->planey = -0.66;
}

void	plr_crd(int i, int j, char c, t_map *pt)
{
	if (c == 'N')
	{
		pt->x = j + 0.5;
		pt->y = i + 0.5;
		plr_north(pt);
	}
	if (c == 'S')
	{
		pt->x = j + 0.5;
		pt->y = i + 0.5;
		plr_south(pt);
	}
	if (c == 'W')
	{
		pt->x = j + 0.5;
		pt->y = i + 0.5;
		plr_west(pt);
	}
	if (c == 'E')
	{
		pt->x = j + 0.5;
		pt->y = i + 0.5;
		plr_east(pt);
	}
}
