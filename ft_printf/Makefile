# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 16:13:27 by vruiz-go          #+#    #+#              #
#    Updated: 2023/03/07 17:36:34 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MY_SOURCES = ft_printf.c \
				printf_nums.c \
				printf_str.c
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
