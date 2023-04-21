# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 15:42:18 by vruiz-go          #+#    #+#              #
#    Updated: 2023/04/18 17:24:47 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap.c \
						lst_utils.c \
						swap_error.c \
						swap_r.c \
						swap_sp.c \
						swap_revr.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_PATH = ./libft/

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) --silent
	@$(CC) -o $(NAME) $? -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean --silent

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean --silent

re: fclean $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) clean --silent

.PHONY: all clean fclean re
