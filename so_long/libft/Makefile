# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 16:04:15 by vruiz-go          #+#    #+#              #
#    Updated: 2023/08/05 17:22:40 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_PATH = ./libft/libft.a
CC = gcc
MLX = ./mlx/libmlx.a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra

SRCS = so_long.c \
			error.c \
			read_map.c \
			more_things.c \
			keys.c \
			more_keys.c \
			check_fill.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: make_lib $(NAME)

make_lib:
	@make -sC ./libft
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_PATH) -o $(NAME)
	@echo $(NAME)": ready to be executed"

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft clean --silent

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean --silent

re: fclean all

.PHONY: all clean fclean re
