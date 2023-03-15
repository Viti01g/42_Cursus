# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 15:42:18 by vruiz-go          #+#    #+#              #
#    Updated: 2023/03/13 17:06:52 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftswap.a
MY_SOURCES = push_swap.c \
MY_OBJECTS = $(MY_SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
$(NAME): $(MY_OBJECTS)
			@ar rcs $(NAME) $(MY_OBJECTS)
all:	$(NAME)
clean:
		@rm -f $(MY_OBJECTS)
fclean: clean
		@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
