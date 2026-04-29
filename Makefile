# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 19:28:06 by gifanell          #+#    #+#              #
#    Updated: 2026/04/24 16:07:08 by gifanell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =		./srcs/main.c \
			./srcs/utils/error.c \
			./srcs/utils/cleanup.c \
			./srcs/utils/init.c \
			./srcs/utils/game_loop.c \
			./srcs/engine/dda.c \
			./srcs/engine/raycaster.c \
			./srcs/engine/render.c \
			./srcs/engine/textures.c \
			./srcs/parsing/parse_elements.c \
			./srcs/parsing/parse_file.c \
			./srcs/parsing/parse_map.c \
			./srcs/parsing/parse_textures.c \
			./srcs/parsing/parse_utils.c \
			./srcs/parsing/validate_map.c \
			./srcs/player/movement.c \
			./srcs/player/rotation.c

OBJS = $(SRCS:.c=.o)

MAKEFLAGS += -s

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
GRAY		= \033[0;90m
RESET		= \033[0m

all:	$(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(GRAY)Linking$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -I./srcs/includes -I./libft -I./minilibx-linux -c $< -o $@

$(LIBFT):
	@echo "$(GRAY)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(GRAY)Compiling MiniLibx...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory > /dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory > /dev/null 2>&1
	@echo "$(GREEN)All cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
