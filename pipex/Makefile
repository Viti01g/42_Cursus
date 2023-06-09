# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 18:00:04 by vruiz-go          #+#    #+#              #
#    Updated: 2023/06/07 17:09:22 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_PATH = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c \
		error.c \
		pipe_utils.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: make_lib $(NAME)

make_lib:
	@make -sC ./libft
#	@echo "---- libft reaady ----" 
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft clean --silent

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean --silent

re: fclean all

.PHONY: all clean fclean re
