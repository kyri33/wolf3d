NAME = wolf3d

SRC = libft/libft.a src/main.c src/map.c src/init.c

FLAGS = clang -Wall -Werror -Wextra -g3 -I includes -o

all: $(NAME)

$(NAME):
	@$(FLAGS) $(NAME) $(SRC) -lmlx -framework OpenGL -framework AppKit

fclean:
	@rm -f $(NAME)

re: fclean all
