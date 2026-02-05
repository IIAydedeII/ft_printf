NAME		=	libftprintf.a

LIBFT_DIR	=	Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

SRC			=	src/ft_printf.c \
				src/ft_print_char.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): ${LIBFT} $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
