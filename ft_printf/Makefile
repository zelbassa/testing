NAME	= libftprintf.a
FILES	= print_char.c print_str.c print_dec.c print_hex_lc.c print_hex_uc.c \
		print_addr.c print_unsigned_dec.c ft_printf.c print_percent.c
OBJ		= $(FILES:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re