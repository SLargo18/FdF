NAME = fdf

SRC = src/main.c src/parse.c src/draw.c src/events.c
UTILS = utils/get_next_line.c utils/get_next_line_utils.c utils/utils.c

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

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