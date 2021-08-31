/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:22:55 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/20 13:08:08 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	do_rsl(char *s, t_map *pt)
{
	char	**rsl;
	char	*t;

	t = s;
	rsl = ft_split(s, ' ');
	while (*t != '\0')
	{
		if (*t == 'R' || *t == ' ' || ft_isdigit(*t))
			t++;
		else
			exit(ft_errich(ERR_4));
	}
	if (size_arr(rsl) == 3)
	{
		if (pt->r_x == 0 && pt->r_y == 0)
			res_correct(pt, *(rsl + 1), *(rsl + 2));
		else
			exit(ft_errich(ERR_0));
	}
	else
		exit(ft_errich(ERR_1));
	ft_memory_free(rsl, size_arr(rsl));
}

char	*do_path(char *s, char *pt_s)
{
	char *newstr;
	char *tmp;

	tmp = s;
	newstr = NULL;
	if (pt_s == 0)
	{
		while (*tmp != '\0')
		{
			if (*tmp == ' ' && *(tmp + 1) != ' ')
			{
				newstr = ft_strdup(++tmp);
				break ;
			}
			tmp++;
		}
	}
	else
		exit(ft_errich(ERR_0));
	return (newstr);
}

int		diggrab(char *s)
{
	char	*tmp;
	int		res;

	while (s)
	{
		if (ft_isdigit(*s) || *s == '-')
		{
			s = ft_strtrim(s, " ");
			tmp = s;
			if (ft_strlen(s) <= 3)
			{
				res = ft_atoi(s);
				free(tmp);
				return (res);
			}
			else
				exit(ft_errich(ERR_2));
		}
		s++;
	}
	return (0);
}

int		extract_int(char *rs, char *gs, char *bs)
{
	int r;
	int g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	r = diggrab(rs);
	g = diggrab(gs);
	b = diggrab(bs);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		exit(ft_errich(ERR_2));
	return (r << 16 | g << 8 | b);
}

int		do_color(char *news, int ptclr)
{
	char	**clr;
	char	*t;
	int		res;

	res = 0;
	t = news;
	clr = checkfc(news);
	while (*t != '\0')
	{
		if (*t == 'F' || *t == 'C' || *t == ' ' || *t == ',' || ft_isdigit(*t))
			t++;
		else
			exit(ft_errich(ERR_3));
	}
	if (size_arr(clr) == 3)
	{
		if (ptclr == 0)
			res = (extract_int(*(clr), *(clr + 1), *(clr + 2)));
		else
			exit(ft_errich(ERR_0));
	}
	else
		exit(ft_errich(ERR_1));
	ft_memory_free(clr, size_arr(clr));
	return (res);
}
