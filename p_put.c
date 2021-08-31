/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:43:42 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 12:43:02 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

void	p_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->l_l + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}
