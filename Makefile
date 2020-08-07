# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 17:31:15 by wrhett            #+#    #+#              #
#    Updated: 2020/08/07 12:02:00 by wrhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -g

SRC_DIR = ./src/
SRC_LIST = main.c ft_atoi_base.c ft_get_color.c ft_get_map.c ft_read_map.c \
	ft_operation_zoom.c ft_operation_key.c ft_operation_mouse.c \
	ft_drawing_line.c ft_drawing_iso.c ft_drawing_iso_obl.c ft_rotation.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJECTS_DIR = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

HEADER_DIR = ./includes/
HEADER_LIST = fdf.h error.h manual.h key_linux.h key_macos.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_DIR)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

ifeq ($(OS), Linux)
	MLX_DIR = ./minilibx/
	MLX = -L ./minilibx/ -lmlx -lXext -lX11 -lm -lpthread -lz
else
	MLX_DIR = ./minilibx_macos/
	MLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
endif

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I $(HEADER_DIR) \
		-L $(LIBFT_DIR) -lft $(MLX)
		@echo "✅\n\033[34m$(NAME):\033[32m was created\033[0m"

$(OBJECTS_DIR):
		@mkdir -p $(OBJECTS_DIR)
		@echo "✅\033[34m$(NAME):\033[32m $(OBJECTS_DIR)directory was created\033[0m"

$(OBJECTS_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
		@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
		@echo "✅\c"

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_DIR)
		@$(MAKE) -C $(MLX_DIR)

clean:
		@rm -rf $(OBJECTS_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
