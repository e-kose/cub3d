NAME = cub3d
SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c cub3d.c display/display.c display/draw.c display/key.c display/mouse_destroy.c display/raycast.c \
		parse/extract.c parse/map.c parse/map2d.c parse/mapcheck.c parse/parser.c parse/parsing.c \
		parse/rgb.c utils/extract_utils.c utils/free.c utils/parse_utils.c utils/utils.c \
		utils/utils_2.c utils/utils_3.c error/error.c

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m"
	@make -C ./libft
	@make -C ./mlx
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)


clean:
	@echo "\033[0;34m"
	@make clean -C ./libft
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[33m"
	@make fclean -C ./libft
	@make clean -C ./mlx
	@rm -f $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING!\n"

re: fclean all

.PHONY: all clean fclean re
