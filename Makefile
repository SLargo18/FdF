# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 17:42:27 by slargo-b          #+#    #+#              #
#    Updated: 2025/04/18 17:42:27 by slargo-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 17:38:44 by slargo-b          #+#    #+#              #
#    Updated: 2025/04/18 17:38:44 by slargo-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
MLX_FLAGS	= -lmlx -lXext -lX11 -lm

SRC_DIR		= src/
OBJ_DIR		= obj/

SRC_FILES	= main.c \
			  draw/algorithm.c \
			  draw/draw.c \
			  draw/project.c \
			  draw/utils_alg.c \
			  events/events.c \
			  parse/fill_points.c \
			  parse/init_map.c \
			  parse/parse.c \
			  utils/ft_split.c \
			  utils/get_next_line.c \
			  utils/get_next_line_utils.c \
			  utils/utils.c

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

OBJ_DIRS	= $(sort $(dir $(OBJ)))

MLX_PATH	= minilibx-linux/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33mCompilando MiniLibX...\033[0m"
	@make -C $(MLX_PATH) > /dev/null 2>&1
	@echo "\033[32mMiniLibX compilado con éxito\033[0m"
	@echo "\033[33mCompilando FdF...\033[0m"
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX_PATH) $(MLX_FLAGS)
	@echo "\033[32mFdF compilado con éxito\033[0m"

$(OBJ_DIRS):
	@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[33mLimpiando archivos objeto...\033[0m"
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_PATH) clean > /dev/null 2>&1
	@echo "\033[32mArchivos objeto eliminados\033[0m"

fclean: clean
	@echo "\033[33mLimpiando ejecutable...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mEjecutable eliminado\033[0m"

re: fclean all

.PHONY: all clean fclean re