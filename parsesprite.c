/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:23:44 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/18 15:55:49 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sprtostruct(t_map *pt)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (pt->map[++i])
	{
		j = -1;
		while (pt->map[i][++j] != '\0')
		{
			if (pt->map[i][j] == '2')
			{
				if (k < pt->sprc)
				{
					pt->spr[k]->x = j + 0.5;
					pt->spr[k]->y = i + 0.5;
					k++;
				}
			}
		}
	}
}

int		init_spr(t_map *pt)
{
	int i;

	if (!(pt->spr = (t_spr **)ft_calloc(sizeof(t_spr *), pt->sprc + 1)))
		return (0);
	i = -1;
	while (++i < pt->sprc)
	{
		if (!(pt->spr[i] = (t_spr *)ft_calloc(sizeof(t_spr), 1)))
			return (0);
	}
	sprtostruct(pt);
	return (0);
}

void	spriter(t_map *pt)
{
	int i;
	int j;

	i = -1;
	while (pt->map[++i])
	{
		j = -1;
		while (pt->map[i][++j] != '\0')
		{
			if (pt->map[i][j] == '2')
				pt->sprc += 1;
		}
	}
	init_spr(pt);
	pt->sorder = (int *)ft_calloc(sizeof(int), pt->sprc + 1);
	pt->sdist = (double *)ft_calloc(sizeof(double), pt->sprc + 1);
}
