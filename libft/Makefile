NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I. -c
FILES		= ft_atoi.c ft_split.c ft_isdigit.c ft_strlen.c ft_strlcpy.c ft_substr.c ft_strdup.c  ft_strcmp.c ft_isint.c ft_bzero.c
OBJ			= $(FILES:.c=.o)
CC 			= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re