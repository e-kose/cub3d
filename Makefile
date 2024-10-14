NAME = cub3d

SRCS =  inc/GNL/get_next_line.c  cub3d.c utils/free.c utils/error.c utils/utils.c utils/read_map.c \
		utils/check_map.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Linc/mlx -lmlx -Linc/libft -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m"
	@$(echo) make -C inc/libft
	@make -C inc/mlx
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@echo "\033[0;34m"
	@make clean -C inc/libft
	@make clean -C inc/mlx
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[33m"
	@make fclean -C inc/libft
	@make clean -C inc/mlx
	@rm -f $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING!\n"

re: fclean all

.PHONY: all clean fclean re
