NAME = cub3d

SRCS = inc/GNL/get_next_line.c cub3d.c utils/free.c utils/error.c \
       utils/utils.c utils/read_map.c utils/parse_map.c utils/flod_fill.c \
       utils/check_map.c utils/rgb_utils.c utils/texture_utils.c raycast/mlx_tools.c \
	   raycast/raycast.c raycast/keycode.c raycast/movement.c raycast/raycast_utils.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    LDFLAGS = -Linc/mlx_linux -lmlx -Linc/libft -lft -lX11 -lXext -lm -lz
    MLX_DIR = inc/mlx_linux
else ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -Linc/mlx_mac -lmlx -Linc/libft -lft -framework OpenGL -framework AppKit
    MLX_DIR = inc/mlx_mac
endif

all: $(NAME)

$(NAME): $(OBJS)
	@clear >/dev/null 2>&1
	@echo "\033[3;32m"
	@echo '________/\\\\\\\\\\________________/\\\____________/\\\\\\\\\\__________/\\\__'
	@echo ' _____/\\\////////________________\/\\\__________/\\\///////\\\________\/\\\__'
	@echo '  ___/\\\/_________________________\/\\\_________\///______/\\\_________\/\\\__'
	@echo '   __/\\\______________/\\\____/\\\_\/\\\________________/\\\//__________\/\\\__'
	@echo '    _\/\\\_____________\/\\\___\/\\\_\/\\\\\\\\\_________\////\\\____/\\\\\\\\\__'
	@echo '     _\//\\\____________\/\\\___\/\\\_\/\\\////\\\___________\//\\\__/\\\////\\\__'
	@echo '      __\///\\\__________\/\\\___\/\\\_\/\\\__\/\\\__/\\\______/\\\__\/\\\__\/\\\__'
	@echo '       ____\////\\\\\\\\\_\//\\\\\\\\\__\/\\\\\\\\\__\///\\\\\\\\\/___\//\\\\\\\/\\_'
	@echo '        _______\/////////___\/////////___\/////////_____\/////////______\///////\//__'
	@echo "\033[0m"
	@echo "\033[32mBuilding $(NAME)...\033[0m"
	@make bonus -C inc/libft >/dev/null 2>&1
	@make -C $(MLX_DIR) >/dev/null 2>&1
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\033[32m$(NAME) build complete!\033[0m"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;34mCleaning object files...\033[0m"
	@make clean -C inc/libft
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJS)
	@echo "\033[32mObject files cleaned.\033[0m"

fclean: clean
	@echo "\033[33mPerforming full clean...\033[0m"
	@make fclean -C inc/libft >/dev/null 2>&1
	@make clean -C $(MLX_DIR) >/dev/null 2>&1
	@rm -f $(NAME)
	@echo "\n\033[31mEverything deleted!\033[0m"

re: fclean all

.PHONY: all clean fclean re
