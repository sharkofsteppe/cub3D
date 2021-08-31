/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptake.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:37:49 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:51:53 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"

int		key_press(int key, t_map *pt)
{
	if (key == 13)
		pt->key_w = 1;
	if (key == 1)
		pt->key_s = 1;
	if (key == 0)
		pt->key_a = 1;
	if (key == 2)
		pt->key_d = 1;
	if (key == 123)
		pt->key_l = 1;
	if (key == 124)
		pt->key_r = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int		key_release(int key, t_map *pt)
{
	if (key == 13)
		pt->key_w = 0;
	if (key == 1)
		pt->key_s = 0;
	if (key == 0)
		pt->key_a = 0;
	if (key == 2)
		pt->key_d = 0;
	if (key == 123)
		pt->key_l = 0;
	if (key == 124)
		pt->key_r = 0;
	return (0);
}

int		ponction(t_map *pt)
{
	raystep(pt);
	mlx_clear_window(pt->win->mlx, pt->win->win);
	mlx_put_image_to_window(pt->win->mlx, pt->win->win, pt->win->img, 0, 0);
	mlx_do_sync(pt->win->mlx);
	key_update(pt);
	return (0);
}

void	noidea(t_map *pt)
{
	pt->win->mlx = mlx_init();
	pt->win->win = mlx_new_window(pt->win->mlx, pt->r_x, pt->r_y, "Hey!");
	pt->win->img = mlx_new_image(pt->win->mlx, pt->r_x, pt->r_y);
	pt->win->addr = mlx_get_data_addr(pt->win->img, &pt->win->bpp,
	&pt->win->l_l, &pt->win->en);
	init_texture(pt);
	mlx_loop_hook(pt->win->mlx, &ponction, pt);
	mlx_hook(pt->win->win, 2, (1L << 0), &key_press, pt);
	mlx_hook(pt->win->win, 3, (1L << 0), &key_release, pt);
	mlx_hook(pt->win->win, 17, (1L << 0), &allexit, NULL);
	mlx_loop(pt->win->mlx);
}

int		main(int argc, char **argv)
{
	t_list	*head;
	t_map	*pt;
	char	*line;

	line = NULL;
	head = NULL;
	if (argc <= 3 && argc >= 2)
	{
		pt = init();
		checkarg(argc, argv, pt);
		if ((pt->fd = open(argv[1], O_RDONLY)) < 0)
			exit(ft_errich(ERR_11));
		while (get_next_line(pt->fd, &line))
			ft_lstadd_back(&head, ft_lstnew(line));
		ft_lstadd_back(&head, ft_lstnew(line));
		guesswhat(&head, pt);
		if (pt->flag == 1)
			screenmaker(pt);
		else
			noidea(pt);
	}
	else
		exit(ft_errich(ERR_11));
	return (0);
}
