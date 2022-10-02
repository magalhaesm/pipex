NAME = pipex

FILES = main.c parse.c error.c utils.c
SRC = $(addprefix src/, $(FILES))
INCLUDE = include/pipex.h libft/libft.h

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):	$(SRC) $(INCLUDE)
	$(CC) $(SRC) $(CFLAGS) -I include -I libft -L libft -lft -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
