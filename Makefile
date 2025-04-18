NAME = fdf

SRC = src/draw/algorithm.c \
	src/draw/draw.c \
	src/draw/put_pixel.c \
	src/parse/fill_points.c \
	src/parse/init_map.c \
	src/parse/parse.c

UTILS = src/utils/get_next_line.c \
	  src/utils/get_next_line_utils.c \
	  src/utils/utils.c

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

#cc -g3 src/draw/*.c src/parse/*.c src/utils/*.c src/main.c src/events/events.c -Iminilibx-linux -Lminilibx-linux -lXext -lX11 -lm libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all