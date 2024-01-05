NAME	= libftprintf.a
FILES	= print_char.c print_str.c print_dec.c print_hex_lc.c print_hex_uc.c \
		print_addr.c print_unsigned_dec.c ft_printf.c print_percent.c
OBJ		= print_char.o print_str.o print_dec.o print_hex_lc.o print_hex_uc.o \
		print_addr.o print_unsigned_dec.o ft_printf.o print_percent.o
CFLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

print_char.o: print_char.c
	$(CC) $(CFLAGS) -c print_char.c -o print_char.o

print_str.o: print_str.c
	$(CC) $(CFLAGS) -c print_str.c -o print_str.o

print_dec.o: print_dec.c
	$(CC) $(CFLAGS) -c print_dec.c -o print_dec.o

print_hex_lc.o: print_hex_lc.c
	$(CC) $(CFLAGS) -c print_hex_lc.c -o print_hex_lc.o

print_hex_uc.o: print_hex_uc.c
	$(CC) $(CFLAGS) -c print_hex_uc.c -o print_hex_uc.o

print_addr.o: print_addr.c
	$(CC) $(CFLAGS) -c print_addr.c -o print_addr.o

print_unsigned_dec.o: print_unsigned_dec.c
	$(CC) $(CFLAGS) -c print_unsigned_dec.c -o print_unsigned_dec.o

ft_printf.o: ft_printf.c
	$(CC) $(CFLAGS) -c ft_printf.c -o ft_printf.o

print_percent.o: print_percent.c
	$(CC) $(CFLAGS) -c print_percent.c -o print_percent.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re