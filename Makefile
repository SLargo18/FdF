NAME = fdf

SRC = src/main.c src/pareriwafer.c etc..
OBJ = $(SRC:.C=.O)
CC = CC
CFLAGS = -Wall -Wextra -Werror (faltan las de la mlx)

all: $(NAME)

$(NAME): OBJ
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
