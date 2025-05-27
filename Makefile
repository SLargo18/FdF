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
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -lmlx -lXext -lX11 -lm

SRC_DIR = src
DRAW_DIR = $(SRC_DIR)/draw
EVENTS_DIR = $(SRC_DIR)/events
PARSE_DIR = $(SRC_DIR)/parse
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = $(SRC_DIR)/include

SRC_FILES = $(SRC_DIR)/main.c
DRAW_FILES = $(DRAW_DIR)/algorithm.c $(DRAW_DIR)/draw.c $(DRAW_DIR)/project.c $(DRAW_DIR)/utils_alg.c
EVENTS_FILES = $(EVENTS_DIR)/events.c
PARSE_FILES = $(PARSE_DIR)/fill_points.c $(PARSE_DIR)/init_map.c $(PARSE_DIR)/parse.c
UTILS_FILES = $(UTILS_DIR)/ft_split.c $(UTILS_DIR)/get_next_line.c $(UTILS_DIR)/get_next_line_utils.c $(UTILS_DIR)/utils.c

SRCS = $(SRC_FILES) $(DRAW_FILES) $(EVENTS_FILES) $(PARSE_FILES) $(UTILS_FILES)

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(MLX) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)FdF compiled successfully!$(RESET)"

$(MLX):
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/draw
	@mkdir -p $(OBJ_DIR)/events
	@mkdir -p $(OBJ_DIR)/parse
	@mkdir -p $(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(RESET) $<"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean

fclean: clean
	@echo "$(RED)Removing executable and libraries...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re