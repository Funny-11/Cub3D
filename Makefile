# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 19:28:06 by gifanell          #+#    #+#              #
#    Updated: 2026/03/03 16:46:04 by gifanell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3d_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =		./srcs/main.c \
			./srcs/utils/error.c \
			./srcs/utils/cleanup.c \
			./srcs/utils/init.c \
			./srcs/engine/dda.c \
			./srcs/engine/raycaster.c \
			./srcs/engine/render.c \
			./srcs/engine/textures.c \
			./srcs/parsing/parse_elements.c \
			./srcs/parsing/parse_file.c \
			./srcs/parsing/parse_map.c \
			./srcs/parsing/parse_textures.c \
			./srcs/parsing/parse_utils.c \
			./parsing/validate_map.c \
			./player/movement.c \
			./player/rotation.c \
			./texture/east.xpm \
			./texture/north.xpm \
			./texture/south.xpm \
			./texture/west.xpm \

SRCS_BONUS =		./parse_bonus.c \
					./utils_bonus.c \

MAKEFLAGS += -s

LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR)/libft.a -lft

MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR)/libmlx.a -lmlx -lXext -lX11 -lX -l, -lz ext

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
GRAY		= \033[0;90m
RESET		= \033[0m

all:	$(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS)
	@echo "$(GRAY)Linking$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME)Compiled successfully!$(RESET)"

bonus: $(LIBFT) $(MLX)

$(LIBFT):
	@echo "$(GRAY)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
$(MLX):
	@echo "$(GRAY)Compiling MiniLibx...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory > /dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1
	@rm -f *.o

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory > /dev/null 2>&1
	@echo "$(GREEN)All cleaned!$(RESET)"


re: fclean all

.PHONY: all clean fclean re