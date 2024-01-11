NAME	= push_swap
LIBFT	= libft/libft.a
PRINTF	= ft_printf/libftprintf.a
CFLAGS	= -Wall -Wextra -Werror -I.
FILES	= push_swap.c mid_point.c
OBJ		= $(FILES:.c=.o)
CC		= gcc

all: $(NAME)

$(LIBFT):
	cd libft && make

$(PRINTF):
	cd ft_printf && make

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lft_printf -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd libft && make clean
	cd ft_printf && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
	cd ft_printf && make fclean

re: fclean all

.PHONY: all clean fclean
