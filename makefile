NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/*.c

FRAMEWORKS = -framework OpenGL -framework Appkit

INCLUDE = -I includes

INCLUDE_MLX = -I minilibx
LINK_MLX = -L minilibx -lmlx
MLX = $(INCLUDE_MLX) $(LINK_MLX)

INCLUDE_LIBFT = -I libft
LINK_LIBFT = -L libft -lft
LIBFT = $(INCLUDE_LIBFT) $(LINK_LIBFT)

GNL = -I gnl

all: $(NAME)

libft.a:
	make -C libft

mlx.a:
	make -C minilibx

$(NAME): libft.a mlx.a
	$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(GNL) $(INCLUDE) $(FRAMEWORKS) $(SRC) -o $(NAME)

clean:
	make -C libft fclean
	make -C minilibx clean

fclean: clean
	rm -rf $(NAME)

re: clean all
