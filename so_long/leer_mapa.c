/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_mapa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:05:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/17 15:14:44 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_params(int argc, char **argv, t_obj *obj)
{
	int		fd;

	if (argc != 2)
		msg_error(ERR_INPUT);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		msg_error("File not found!");
	if (ft_strrncmp(argv[1], ".ber", 4))
		msg_error("Invalid file type, use .ber!");
	return (check_map(fd, obj));
}

static void	check_wall(t_obj **obj, char **mapa, int column)
{
	int	i;
	int	j;

	i = 0;
	(*obj)->n_cols = column;
	while (mapa[0][i])
		if (mapa[0][i++] != '1')
			msg_error("Map not surroundered by walls.");
	(*obj)->n_rows = i - 1;
	i = 0;
	while (mapa[column][i])
		if (mapa[column][i++] != '1')
			msg_error("Map not surroundered by walls.");
	j = 1;
	while (j < column)
	{
		if (mapa[j++][0] != '1' || mapa[j++][(*obj)->n_rows] != '1')
			msg_error("Map not surroundered by walls.");
	}
}

static int	check_items(t_obj **obj, char **mapa)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapa[j])
	{
		i = 0;
		while (mapa[j][i])
		{
			if (mapa[j][i] == 'P')
				(*obj)->n_plyr++;
			if (mapa[j][i] == 'E')
				(*obj)->n_exit++;
			if (mapa[j][i] == 'C')
				(*obj)->n_objs++;
			i++;
		}
		j++;
	}
	if ((*obj)->n_exit != 1 || (*obj)->n_plyr != 1 || (*obj)->n_objs < 1)
		msg_error("Invalid map.");
	return (j);
}

char	**check_map(int fd, t_obj *objs)
{
	char	*mapa_capon;
	char	**mapa;
	int		j;
	int		k;

	k = 0;
	j = 0;
	mapa_capon = NULL;
	read_map(fd, &objs, &mapa_capon);
	mapa = ft_split(mapa_capon, '\n');
	if (!mapa)
		msg_error("Empty map.");
	while (mapa[j])
	{
		printf("--%s--\n", mapa[j]);
		j++;
	}
	k = check_items(&objs, mapa);
	check_wall(&objs, mapa, k - 1);
	return (mapa);
}

void	read_map(int fd, t_obj **obj, char **str)
{
	char	*line;
	int		count;
	int		bool;

	count = 0;
	bool = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!(*obj)->n_cols && count == 0)
				msg_error("Empty map.");
			else
				bool++;
			break ;
		}
		if (bool > 0)
			break ;
		*str = ft_strjoin(*str, line);
		(*obj)->n_rows++;
		count++;
	}
}
