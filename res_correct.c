/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_correct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:01:48 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/20 13:41:53 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

int		checkfirst(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = len;
	if (ft_strncmp(str + len - 4, ".cub", 5) == 0)
		return (0);
	else
		exit(ft_errich(ERR_11));
}

int		checkseck(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = len;
	if (ft_strncmp(str, "--save", 7) == 0)
		return (1);
	else
		exit(ft_errich(ERR_11));
}

int		checkarg(int argc, char **argv, t_map *pt)
{
	if (argc == 2)
		checkfirst(argv[1]);
	if (argc == 3)
	{
		checkfirst(argv[1]);
		if (checkseck(argv[2]))
			pt->flag = 1;
	}
	return (0);
}

void	res_correct(t_map *pt, char *r_x, char *r_y)
{
	int r_x_max;
	int r_y_max;

	mlx_get_screen_size(pt->win->mlx, &r_x_max, &r_y_max);
	if (ft_strlen(r_x) <= 10 && ft_strlen(r_x) <= 10)
	{
		if (ft_atoi(r_x) <= 2147483647 && ft_atoi(r_y) <= 2147483647)
		{
			pt->r_x = ft_atoi(r_x);
			pt->r_y = ft_atoi(r_y);
		}
		else
			exit(ft_errich(ERR_4));
	}
	else
		exit(ft_errich(ERR_4));
	if (pt->r_x < 320 || pt->r_y < 200)
		exit(ft_errich(ERR_4));
	if (pt->r_x > 2560 || pt->r_y > 1440)
	{
		pt->r_x = r_x_max;
		pt->r_y = r_y_max;
	}
	pt->zbuf = ft_calloc(sizeof(double), pt->r_x + 1);
}
