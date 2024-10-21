NAME = cub3d

SRCS = inc/GNL/get_next_line.c cub3d.c utils/free.c utils/error.c \
       utils/utils.c utils/read_map.c utils/parse_map.c utils/flod_fill.c \
	   utils/check_map.c utils/rgb_utils.c utils/texture_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# İşletim sistemi tespiti
UNAME_S := $(shell uname -s)

# Kütüphaneler ve derleme talimatları işletim sistemine göre ayarlandı
ifeq ($(UNAME_S), Linux)
    LDFLAGS = -Linc/mlx_linux -lmlx -Linc/libft -lft -lX11 -lXext -lm -lz -fsanitize=address
    MLX_DIR = inc/mlx_linux
else ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -Linc/mlx_mac -lmlx -Linc/libft -lft -framework OpenGL -framework AppKit -fsanitize=address
    MLX_DIR = inc/mlx_mac
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m"
	@$(MAKE) bonus -C inc/libft
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@echo "\033[0;34m"
	@$(MAKE) clean -C inc/libft
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[33m"
	@$(MAKE) fclean -C inc/libft
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING!\n"

re: fclean all

.PHONY: all clean fclean re
