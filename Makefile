NAME = wolf3d

SRC = libft/libft.a src/main.c src/map.c src/init.c src/game.c src/draw.c

FLAGS = clang -Wall -Werror -Wextra -g3 -I includes -o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME) $(SRC) -lmlx -framework OpenGL -framework AppKit

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
