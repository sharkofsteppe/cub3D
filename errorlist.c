/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:45:41 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:41:37 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		allexit(void)
{
	exit(0);
	return (0);
}

char	**checkfc(char *news)
{
	int		i;
	int		comma;
	char	**clr;
	char	*tmp;

	tmp = news;
	tmp = ft_strtrim(news, " ");
	i = -1;
	comma = 0;
	while (tmp[++i])
	{
		if (tmp[i] == ',')
			comma += 1;
	}
	if (comma > 2)
		exit(ft_errich(ERR_2));
	clr = ft_split(tmp, ',');
	free(tmp);
	return (clr);
}

void	onemorecheck(t_map *pt)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	while (pt->map[++i])
	{
		if (pt->map[i][0] != 0)
			flag = 1;
		if (pt->map[i][0] == 0 && flag == 1 && i != size_arr(pt->map) - 1)
			exit(ft_errich(ERR_9));
	}
}

int		ft_errich(int a)
{
	if (a == ERR_0)
		return (ps_cub("Error\nThe parameter was submitted twice\n", 1, ERR_0));
	if (a == ERR_1)
		return (ps_cub("Error\nWrong number of elements\n", 1, ERR_1));
	if (a == ERR_2)
		return (ps_cub("Error\nWrong element of color\n", 1, ERR_2));
	if (a == ERR_3)
		return (ps_cub("Error\nUnexpected symbols\n", 1, ERR_3));
	if (a == ERR_4)
		return (ps_cub("Error\nIncorrect resolution's elements\n", 1, ERR_4));
	if (a == ERR_5)
		return (ps_cub("Error\nInsufficient number of parameters\n", 1, ERR_5));
	if (a == ERR_6)
		return (ps_cub("Error\nUnexpected symbols in map\n", 1, ERR_6));
	if (a == ERR_7)
		return (ps_cub("Error\nNO MAP/The player is not alone\n", 1, ERR_7));
	if (a == ERR_8)
		return (ps_cub("Error\nThere is no player\n", 1, ERR_8));
	if (a == ERR_9)
		return (ps_cub("Error\nInvalid map\n", 1, ERR_9));
	if (a == ERR_10)
		return (ps_cub("Error\nTHERE IS NO TEXTURE\n", 1, ERR_10));
	if (a == ERR_11)
		return (ps_cub("Error\nINCORRECT ARGUMENTS\n", 1, ERR_11));
	return (0);
}
