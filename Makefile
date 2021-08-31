# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 11:37:50 by gesperan          #+#    #+#              #
#    Updated: 2021/02/19 17:11:52 by gesperan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cubd.a
CUBD = maptake.c map_process.c map_validation.c params.c errorlist.c plr_crd.c \
		res_correct.c p_put.c initializer.c rayanddraw.c drawcwf.c sprites.c \
		movements.c parsesprite.c screenshot.c
FLAGS =  -c -Wall -Wextra -Werror
EXEC = gcc -Wall -Wextra -Werror cubd.a libmlx.dylib -framework OpenGL -framework AppKit -o CUB3D
LIBFT_BUILD = cd libft && make && mv libft.a ../ && cd ..
LIBMLX = cd minilibx && make && mv libmlx.dylib ../ && cd ..
LIBFT_FCLEAN = cd libft && make fclean && cd ..
LIBFT_FILES = 	libft/ft_atoi.o libft/ft_bzero.o libft/ft_substr.o \
				libft/ft_putchar_fd.o libft/ft_calloc.o libft/ft_isalnum.o \
				libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o \
				libft/ft_isprint.o libft/ft_memccpy.o libft/ft_memchr.o \
				libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o \
				libft/ft_memset.o libft/ft_strchr.o libft/ft_strdup.o \
				libft/ft_strlcat.o libft/ft_putstr_fd.o libft/ft_strlcpy.o \
				libft/ft_strlen.o libft/ft_strncmp.o libft/ft_putnbr_fd.o \
				libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_putendl_fd.o \
				libft/ft_strjoin.o libft/ft_tolower.o libft/ft_toupper.o \
				libft/ft_strtrim.o libft/ft_itoa.o libft/ft_strmapi.o \
				libft/ft_split.o libft/ft_itoa_ptr.o libft/ft_itoabase.o \
				libft/ft_itoa_ui.o libft/ft_zeroer.o libft/ft_size_arr.o \
				libft/ft_memory_free.o libft/ft_fillstr.o libft/ft_ps_cub.o \
				libft/get_next_line.o libft/ft_finder.o libft/ft_lstnew.o \
				libft/ft_lstadd_front.o libft/ft_lstadd_back.o libft/ft_lstsize.o \
				libft/ft_lstlast.o libft/ft_lstdelone.o libft/ft_lstclear.o \
				libft/ft_lstiter.o libft/ft_lstmap.o

CUBD_BUILD = ar rc $(NAME)
CUBD_INDEX = ranlib $(NAME)

CUBD_OBJ = $(CUBD:.c=.o)

all : $(NAME)

$(NAME): $(CUBD_OBJ) $(LIBFT_FILES)  libft/libft.h
	@$(LIBFT_BUILD) $(LIBFT_FILES)
	@$(CUBD_BUILD) $(CUBD_OBJ) $(LIBFT_FILES)
	@$(CUBD_INDEX)
	@$(LIBMLX)
	@$(EXEC)

%.o: %.c
	gcc $(FLAGS) $< -o $@

clean:
	@ $(LIBFT_FCLEAN)
	@ rm -f libft.a
	@ rm -f *.o
	@ rm -f *.a
	@ rm -f *.bmp

fclean: clean
	@ rm -f cubd.a
	@ rm -f CUB3D
	@ rm -f libft.a
	@ rm -f libmlx.dylib
re:	fclean all
