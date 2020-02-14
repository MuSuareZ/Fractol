# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 14:48:23 by msuarez-          #+#    #+#              #
#    Updated: 2020/02/14 17:35:21 by msuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c key.c solve.c koch.c julia.c mandelbrot.c

OBJECTS = $(subst .c,.o,$(SRC))

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		@make -C libft/
		@cc $(FLAGS) -I/usr/local/include $(SRC) $(LIBFT) \
		-L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		@make clean -C libft/
		@/bin/rm -f $(OBJECTS)

fclean: clean
		@/bin/rm -f $(LIBFT)
		@/bin/rm -f $(NAME)

re: fclean all
