/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:22:54 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/16 16:33:50 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int c);
size_t	ft_strlen_(const char *str);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoini_gnl(char const *s1, char const *s2);

#endif
