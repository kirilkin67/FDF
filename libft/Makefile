# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 15:16:11 by wrhett            #+#    #+#              #
#    Updated: 2020/08/07 12:03:32 by wrhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_swap.c \
		ft_swap_tab.c \
		ft_sort_wordtab.c \
		ft_print_argv.c \
		ft_lennumber.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c get_next_line_list.c\

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER_F = libft.h

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(OBJECTS): %.o: %.c $(HEADER_F)
		@gcc $(FLAGS) -o $@ -c $<
		@echo "\033[32m⏩\033[0m\c"

$(NAME): $(OBJECTS)
		@ar rc $@ $^
		@ranlib $(NAME)
		@echo "\033[32m$(NAME) file: was created\033[0m"

clean:
		@/bin/rm -f $(OBJECTS)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
