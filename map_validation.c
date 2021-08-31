/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:58:01 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/16 08:40:34 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	map_handling(t_map *pt)
{
	int		j;
	int		i;
	int		maxlen;
	char	*nstr;

	maxlen = 0;
	i = -1;
	while (pt->map[++i])
	{
		j = ft_strlen(pt->map[i]);
		if (j > maxlen)
			maxlen = j;
	}
	i = -1;
	while (pt->map[++i])
	{
		if ((int)ft_strlen(pt->map[i]) < maxlen)
		{
			j = maxlen - ft_strlen(pt->map[i]);
			nstr = ft_fillstr(' ', j);
			pt->map[i] = ft_strjoin(pt->map[i], nstr);
			free(nstr);
		}
	}
}

void	map_player(t_map *pt)
{
	int i;
	int j;
	int player;

	i = -1;
	player = 0;
	while (pt->map[++i])
	{
		j = 0;
		while (pt->map[i][j])
		{
			plr_crd(i, j, pt->map[i][j], pt);
			player += our_syms(pt->map[i][j]);
			j++;
		}
	}
	if (player != 1)
		exit(ft_errich(ERR_7));
}

int		our_syms(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		return (1);
	}
	return (0);
}

void	check_sym(int i, int j, t_map *pt)
{
	if (i + 1 == size_arr(pt->map) || i - 1 == -1)
		exit(ft_errich(ERR_9));
	if (pt->map[i][j - 1] != '1' && pt->map[i][j - 1] != '0' &&
		our_syms(pt->map[i][j - 1]) == 0 && pt->map[i][j - 1] != '2')
		exit(ft_errich(ERR_9));
	if (pt->map[i][j + 1] != '1' && pt->map[i][j + 1] != '0' &&
		our_syms(pt->map[i][j + 1]) == 0 && pt->map[i][j + 1] != '2')
		exit(ft_errich(ERR_9));
	if (pt->map[i - 1][j] != '1' && pt->map[i - 1][j] != '0' &&
		our_syms(pt->map[i - 1][j]) == 0 && pt->map[i - 1][j] != '2')
		exit(ft_errich(ERR_9));
	if (pt->map[i + 1][j] != '1' && pt->map[i + 1][j] != '0' &&
		our_syms(pt->map[i + 1][j]) == 0 && pt->map[i + 1][j] != '2')
		exit(ft_errich(ERR_9));
}

void	map_validation(t_map *pt)
{
	int i;
	int j;

	i = 0;
	while (pt->map[i])
	{
		j = 0;
		while (pt->map[i][j])
		{
			if (pt->map[i][j] == '0' || our_syms(pt->map[i][j]) == 1 ||
				pt->map[i][j] == '2')
				check_sym(i, j, pt);
			j++;
		}
		i++;
	}
}
