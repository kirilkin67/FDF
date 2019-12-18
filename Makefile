# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 17:31:15 by wrhett            #+#    #+#              #
#    Updated: 2019/12/18 18:50:54 by wrhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRC_DIR = src/
SRC_LIST = main.c ft_atoi_base.c ft_get_color.c ft_get_map.c ft_read_map.c \
	ft_operation_key.c ft_operation_mouse.c ft_drawing_iso.c ft_drawing_iso_obl.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJECTS_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), fdf.h)

LIBFT = libft.a
LIBFT_DIR = libft/

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit

#FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I $(HEADER_DIR) \
		-L $(LIBFT_DIR) -lft $(MLX)
		@echo "\033[32m$(NAME): was created\033[0m"

$(OBJECTS_DIR):
		@mkdir -p $(OBJECTS_DIR)
		@echo "\033[32m$(NAME): $(OBJECTS_DIR)directory was created\033[0m"

$(OBJECTS_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
		$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

clean:
		@rm -rf $(OBJECTS_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
