NAME		:=	fractal

SOURCES		:=	$(wildcard scripts/*.c)
OBJECTS		:=	$(SOURCES:.c=.o)

LIBFT_PATH	:= ./libft
LIBFT		:= -I $(LIBFT_PATH) -L $(LIBFT_PATH) -l ft

FLAGS		:= -Wall -Wextra -Werror
INCLUDES	:= -I ./scripts

FLAGS		+= $(INCLUDES) $(LIBFT) -framework OpenGL -framework AppKit

MSG = \033[38;5;214m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJECTS)
	@gcc $(OBJECTS) -o $(NAME) $(FLAGS) ./mlx/libmlx.a
	@echo "$(MSG)Done!$(END)"

$(LIBFT_PATH)/libft.a:
	@make -C libft

%.o: %.c
	@printf "gcc %25s ==> %s\n" $< $@
	@gcc $(FLAGS) -w -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)
	@echo "$(MSG)Objects removed!$(END)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(MSG)Targets removed!$(END)"

re: fclean all
