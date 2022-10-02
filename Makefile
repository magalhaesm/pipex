NAME = pipex

FILES = main.c parse.c utils.c
SRC = $(addprefix src/, $(FILES))
INCLUDE = include/pipex.h libft/libft.h
LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):	$(SRC) $(INCLUDE) $(LIBFT)
	$(CC) $(SRC) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(LIBFT):
	@make -C libft

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
