# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 12:36:00 by vruiz-go          #+#    #+#              #
#    Updated: 2023/02/08 13:00:27 by vruiz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
MY_SOURCES = ft_isalpha.c \
			 			ft_isdigit.c  \
						ft_isalnum.c \
						ft_isascii.c \
						ft_isprint.c \
						ft_strlen.c \
						ft_toupper.c \
						ft_tolower.c \
						ft_strchr.c \
						ft_strrchr.c \
						ft_strncmp.c \
						ft_memset.c \
						ft_bzero.c \
						ft_memchr.c \
						ft_memcpy.c \
						ft_memcmp.c \
						ft_memmove.c \
						ft_strnstr.c \
						ft_strlcpy.c \
						ft_strlcat.c \
						ft_atoi.c \
						ft_calloc.c \
						ft_strdup.c \
						ft_substr.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_split.c \
						ft_itoa.c \
						ft_strmapi.c \
						ft_striteri.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)
BONUS_SOURCES = ft_lstnew_bonus.c \
                    ft_lstadd_front_bonus.c \
                    ft_lstsize_bonus.c \
                    ft_lstlast_bonus.c \
                    ft_lstadd_back_bonus.c \
                    ft_lstdelone_bonus.c \
                    ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
$(NAME): $(MY_OBJECTS)
			@ar r $(NAME) $(MY_OBJECTS)
bonus: $(BONUS_OBJECTS)
			@ar r $(NAME) $(BONUS_OBJECTS)
all:	$(NAME)
clean:
		@rm -f $(MY_OBJECTS) $(BONUS_OBJECTS)
fclean: clean
		@rm -f $(NAME)
re:	fclean all
.PHONY: all clean fclean re