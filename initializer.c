/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:46:17 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:51:31 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

t_win	**init_win(void)
{
	t_win	**tx;
	int		i;

	i = -1;
	if (!(tx = (t_win **)ft_calloc(sizeof(t_win *), 5)))
		return (0);
	while (++i < 5)
	{
		if (!(tx[i] = (t_win *)ft_calloc(sizeof(t_win), 1)))
			return (0);
	}
	return (tx);
}

void	key_init(t_map *pt)
{
	pt->key_a = 0;
	pt->key_w = 0;
	pt->key_s = 0;
	pt->key_d = 0;
	pt->key_l = 0;
	pt->key_r = 0;
}

t_map	*init(void)
{
	t_map *pt;

	if (!(pt = (t_map*)ft_calloc(sizeof(t_map), 1)))
		return (0);
	if (!(pt->win = (t_win*)ft_calloc(sizeof(t_win), 1)))
		return (0);
	pt->tx = init_win();
	pt->map = NULL;
	pt->sprc = 0;
	pt->r_x = 0;
	pt->r_y = 0;
	pt->clr_f = 0;
	pt->clr_c = 0;
	pt->no = 0;
	pt->so = 0;
	pt->we = 0;
	pt->ea = 0;
	pt->s = 0;
	pt->hit = 0;
	pt->fd = 0;
	key_init(pt);
	return (pt);
}
