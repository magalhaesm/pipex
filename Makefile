NAME = pipex
BONUS = pipex_bonus

FILES = pipex.c parse.c utils.c
SRC = $(addprefix src/, $(FILES))
INCLUDE = include/pipex.h libft/libft.h
LIBFT = libft/libft.a

B_FILES = pipex_bonus.c parse_bonus.c utils_bonus.c here_doc_bonus.c
B_SRC = $(addprefix src_bonus/, $(B_FILES))
B_INCLUDE = include/pipex_bonus.h libft/libft.h

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

bonus: $(BONUS)

$(BONUS):	$(B_SRC) $(B_INCLUDE) $(LIBFT)
	$(CC) $(B_SRC) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(NAME):	$(SRC) $(INCLUDE) $(LIBFT)
	$(CC) $(SRC) $(CFLAGS) -I include -I libft -L libft -lft -o $@

$(LIBFT):
	@make -C libft

clean:
	rm -rf $(NAME)
	rm -rf $(BONUS)

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re
