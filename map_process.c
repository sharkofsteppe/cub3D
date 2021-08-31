/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:03 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:25:03 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		check_params(t_map *pt)
{
	if (pt->no != 0 && pt->so != 0 && pt->ea != 0 && pt->we != 0 && pt->s != 0
		&& pt->r_x != 0 && pt->r_y != 0 && pt->clr_c != 0 && pt->clr_f != 0)
		return (1);
	else
		return (0);
}

void	map_creation(t_list *tmp, t_map *pt)
{
	int		i;

	pt->map = ft_calloc(ft_lstsize(tmp) + 1, sizeof(char *));
	i = -1;
	while (tmp)
	{
		pt->map[++i] = tmp->content;
		tmp = tmp->next;
	}
}

void	map_verify(t_map *pt)
{
	int i;
	int j;

	i = -1;
	while (pt->map[++i])
	{
		j = 0;
		while (pt->map[i][j])
		{
			if (pt->map[i][j] == '1' || pt->map[i][j] == '0' ||
				pt->map[i][j] == ' ' || pt->map[i][j] == 'N' ||
				pt->map[i][j] == 'S' || pt->map[i][j] == 'W' ||
				pt->map[i][j] == 'E' || pt->map[i][j] == '2')
				j++;
			else
				exit(ft_errich(ERR_6));
		}
	}
}

void	squeezer(char *s, t_map *pt)
{
	if (*s == 'R' && *(s + 1) == ' ')
		do_rsl(s, pt);
	else if (*s == 'N' && *(s + 1) == 'O' && *(s + 2) == ' ')
		pt->no = do_path(s, pt->no);
	else if (*s == 'S' && *(s + 1) == 'O' && *(s + 2) == ' ')
		pt->so = do_path(s, pt->so);
	else if (*s == 'W' && *(s + 1) == 'E' && *(s + 2) == ' ')
		pt->we = do_path(s, pt->we);
	else if (*s == 'E' && *(s + 1) == 'A' && *(s + 2) == ' ')
		pt->ea = do_path(s, pt->ea);
	else if (*s == 'S' && *(s + 1) == ' ')
		pt->s = do_path(s, pt->s);
	else if (*s == 'F' && *(s + 1) == ' ')
		pt->clr_f = do_color(s, pt->clr_f);
	else if (*s == 'C' && *(s + 1) == ' ')
		pt->clr_c = do_color(s, pt->clr_c);
}

void	guesswhat(t_list **head, t_map *pt)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		if (check_params(pt))
		{
			map_creation(tmp, pt);
			break ;
		}
		else
			squeezer(tmp->content, pt);
		if (tmp->next == NULL && !(check_params(pt)))
			exit(ft_errich(ERR_5));
		tmp = tmp->next;
	}
	map_verify(pt);
	map_player(pt);
	onemorecheck(pt);
	map_handling(pt);
	map_validation(pt);
	spriter(pt);
}
