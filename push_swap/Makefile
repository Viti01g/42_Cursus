# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 15:42:18 by vruiz-go          #+#    #+#              #
#    Updated: 2023/05/18 18:26:45 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	push_swap.c \
		lst_utils.c \
		swap_error.c \
		swap_r.c \
		swap_sp.c \
		swap_revr.c \
		alg_lessten.c \
		alg_radi.c \
		swap_tools.c \
		check_arg.c \
		check_alg.c \
		swap_tools_2.c

OBJS = $(SRCS:.c=.o)


RM = rm -f

all: make_lib $(NAME)

make_lib:
	@make -sC ./libft
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft clean --silent

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean --silent

re: fclean $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) clean --silent

.PHONY: all clean fclean re
