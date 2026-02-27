NAME		=	libftprintf.a

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

INCLUDES	=	-I includes

SRC			=	src/ft_print_char.c \
				src/ft_print_hex.c \
				src/ft_print_int.c \
				src/ft_print_ptr.c \
				src/ft_print_str.c \
				src/ft_print_uint.c \
				src/ft_printf.c \

OBJ			=	$(SRC:.c=.o)

SRC_BONUS	=	src_bonus/ft_padding.c \
				src_bonus/ft_parse.c \
				src_bonus/ft_precision.c \
				src_bonus/ft_print_char.c \
				src_bonus/ft_print_hex.c \
				src_bonus/ft_print_int.c \
				src_bonus/ft_print_str.c \
				src_bonus/ft_print_uint.c \
				src_bonus/ft_printf.c \

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): ${LIBFT} $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

bonus: .bonus

.bonus: ${LIBFT} $(OBJ_BONUS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)
	touch .bonus

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	cc -Wall -Werror -Wextra $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	rm -f .bonus
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
