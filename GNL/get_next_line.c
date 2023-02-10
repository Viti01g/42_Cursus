/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:19:10 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/02/10 13:23:44 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static char	*get_long_line(char *str)
{
	int	cont;

	cont = 0;
	
	while (s && s[x])
	{
		if (s[x] != '\n')
		{
			cont++;
			while (s[x] != '\n' && s[x])
				x++;
		}
		else
			x++;
	}
	return (cont);
}

void	*writeLine(char *linea, int fd)
{
	if (!linea)
	{
		free (linea);
		break ;
	}
	while (linea)
	{
		write(fd, &linea, 1);
		linea++;
	}
}

char open_file()
{
	int		fds;
	int		len;
	char	*str;


	int len = 0;
	fds = open("prueba", O_RDONLY);
	if (fds <= 0)
		return (NULL);
	
}

char	*get_next_line(int fd)
{
	int filed;
	ssize_t	read;
	char *buffer;
	
	buffer = 6000;
	filed = open("prueba", O_RDONLY);
	read = read(filed, buffer,);
}

int main ()
{
	printf("%s", open_file());
	return (0);
}
