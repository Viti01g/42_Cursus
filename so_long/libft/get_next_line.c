/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:22:22 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/16 16:33:45 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*read_line(int fd, char *backup)
{
	int		leido;
	char	*aux;
	char	buf[BUFFER_SIZE + 1];

	leido = 1;
	while (leido != 0)
	{
		leido = read(fd, buf, BUFFER_SIZE);
		if (leido < 0)
			return (NULL);
		else if (leido == 0)
			break ;
		buf[leido] = '\0';
		if (!backup)
			backup = ft_strdup_gnl("");
		if (!backup)
			return (NULL);
		aux = backup;
		backup = ft_strjoini_gnl(aux, buf);
		free(aux);
		if (ft_strchr_gnl(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*separador(char *lineaEntera)
{
	int		i;
	char	*aux;

	i = 0;
	aux = NULL;
	if (!lineaEntera)
	{
		free(lineaEntera);
		lineaEntera = NULL;
		return (0);
	}
	while (lineaEntera[i] && lineaEntera[i] != '\n')
		i++;
	aux = ft_substr_gnl(lineaEntera, 0, i + 1);
	return (aux);
}

void	sobrante(char **lineaEntera)
{
	int		i;
	char	*aux;

	i = 0;
	aux = NULL;
	if (!*lineaEntera)
	{
		free(*lineaEntera);
		*lineaEntera = NULL;
		return ;
	}
	while ((*lineaEntera)[i] && (*lineaEntera)[i] != '\n')
		i++;
	aux = ft_substr_gnl(*lineaEntera, i + 1, ft_strlen_(*lineaEntera) - i);
	free(*lineaEntera);
	*lineaEntera = aux;
}

char	*get_next_line(int fd)
{
	static char	*rcvr;
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		free(rcvr);
		rcvr = NULL;
		return (NULL);
	}
	rcvr = read_line(fd, rcvr);
	linea = separador(rcvr);
	sobrante(&rcvr);
	if (linea && *linea == '\0')
	{
		free(linea);
		free(rcvr);
		linea = NULL;
		rcvr = NULL;
	}
	return (linea);
}
/*
void leaks()
{
	system("leaks -q a.out");
	//atexit(leaks); se añade en el main para mirar leaks.
}*/
/*
int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("prueba", O_RDONLY);
	while ((i <= 6))
	{
		str = get_next_line(fd);
		printf("line %i => [%s]", i + 1, str);
		if (!str)
			break;
		free(str);
		i++;
	}
	//printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	return (0);
}*/
