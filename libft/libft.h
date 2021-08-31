/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:33:16 by gesperan          #+#    #+#             */
/*   Updated: 2021/02/19 18:51:05 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define NEW_LINER '\n'
# define END_STRING '\0'
# define TRUE 1
# define FALSE -1
# define ENDLINE_TOUCHED 1
# define ENDLINE_NOT_FOUND 0
# define EOF_REACHED 0
# define ERROR -1
# define BUFFER_SIZE 32

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_spr
{
	double x;
	double y;
}					t_spr;

typedef struct		s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			l_l;
	int			bpp;
	int			en;
	int			img_h;
	int			img_w;
}					t_win;

typedef struct		s_map
{
	t_win	*win;
	t_win	**tx;
	t_spr	**spr;
	char	**map;
	int		sprc;
	int		len_x;
	int		len_y;
	int		r_x;
	int		r_y;
	int		clr_c;
	int		clr_f;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;

	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_l;
	int		key_r;

	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	start;
	double	end;

	int		xmon;
	double	camx;
	double	raydx;
	double	raydy;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	pwalldist;
	double	wallx;
	double	step;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	texpos;
	int		texx;
	int		texy;

	int		lineheight;
	int		drawstart;
	int		drawend;

	double	*zbuf;
	int		*sorder;
	double	*sdist;
	double	sx;
	double	sy;
	double	invdet;
	double	formx;
	double	formy;
	int		sscreenx;
	int		sheight;
	int		swidth;
	int		dsx;
	int		dsy;
	int		dex;
	int		dey;
	int		stripe;
	int		sdiy;
	int		d;
	int		color;
	double	oldirx;
	double	oldplanex;
	double	ms;
	double	rs;
	int		flag;
	int		fd;
}					t_map;

enum				e_errorlist
{
	ERR_0 = -100,
	ERR_1,
	ERR_2,
	ERR_3,
	ERR_4,
	ERR_5,
	ERR_6,
	ERR_7,
	ERR_8,
	ERR_9,
	ERR_10,
	ERR_11
};

int					get_next_line(int fd, char **line);
int					finder(const char *str, const char c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *source);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *str, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_ps_cub(char *s, int fd, int err);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *str, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char				*ft_itoa_ptr(unsigned long long n);
char				*ft_itoa_ui(unsigned int n);
char				*ft_itoa_base(size_t num);
void				ft_zeroer(char *s, char c, int len);
int					ft_errich(int a);
int					ps_cub(char *s, int fd, int err);
char				*ft_fillstr(char c, int len);
int					size_arr(char **str);
void				*ft_memory_free(char **str, size_t count);
int					finder(const char *str, const char c);
void				guesswhat(t_list **head, t_map *pt);
void				map_handling(t_map *pt);
void				map_player(t_map *pt);
void				map_validation(t_map *pt);
void				do_rsl(char *s, t_map *pt);
int					do_color(char *news, int ptclr);
char				*do_path(char *s, char *pt_s);
void				check_sym(int i, int j, t_map *pt);
int					our_syms(char c);
int					do_color(char *news, int ptclr);
int					extract_int(char *rs, char *gs, char *bs);
int					diggrab(char *s);
char				*do_path(char *s, char *pt_s);
void				squeezer(char *s, t_map *pt);
void				map_verify(t_map *pt);
void				onemorecheck(t_map *pt);
char				**checkfc(char *news);
int					allexit();
void				map_creation(t_list *tmp, t_map *pt);
int					check_params(t_map *pt);
void				plr_crd(int x, int y, char c, t_map *pt);
void				res_correct(t_map *pt, char *r_x, char *r_y);
void				spriter(t_map *pt);
void				init_texture(t_map *pt);
void				p_put(t_win *win, int x, int y, int color);
void				raystep(t_map *pt);
void				draw_c_w_f(t_map *pt);
void				sprite_operation(t_map *pt);
int					key_release(int key, t_map *pt);
int					key_press(int key, t_map *pt);
t_map				*init(void);
void				raystep(t_map *pt);
int					key_update(t_map *pt);
void				screenmaker(t_map *pt);
int					checkarg(int argc, char **argv, t_map *pt);

#endif
