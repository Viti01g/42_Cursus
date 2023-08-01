/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_mapa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:05:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/01 15:57:35 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_params(int argc, char **argv, t_obj *obj, t_game *game)
{
	int		fd;

	if (argc != 2)
		msg_error(ERR_INPUT);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		msg_error("File not found!");
	if (ft_strrncmp(argv[1], ".ber", 4))
		msg_error("Invalid file type, use .ber!");
	check_map(fd, obj, game);
}

static void	check_wall(t_obj **obj, char **mapa, int column)
{
	int	i;
	int	j;

	i = 0;
	(*obj)->n_rows = column + 1;
	while (mapa[0][i])
		if (mapa[0][i++] != '1')
			msg_error("Map not surroundered by walls.");
	(*obj)->n_cols = i - 1;
	i = 0;
	while (mapa[column][i])
		if (mapa[column][i++] != '1')
			msg_error("Map not surroundered by walls.");
	j = 1;
	while (j < column)
	{
		if (mapa[j++][0] != '1' || mapa[j++][(*obj)->n_cols] != '1')
			msg_error("Map not surroundered by walls.");
	}
	(*obj)->n_cols++;
}

static int	check_items(t_obj *obj, char **mapa)
{
	int	i;
	int	j;

	j = 0;
	while (mapa[j])
	{
		i = 0;
		while (mapa[j][i])
		{
			if (mapa[j][i] == 'P')
				obj->n_plyr++;
			else if (mapa[j][i] == 'E')
				obj->n_exit++;
			else if (mapa[j][i] == 'C')
				obj->n_objs++;
			else if (mapa[j][i] != '0' && mapa[j][i] != '1')
				msg_error("Invalid map");
			i++;
		}
		j++;
	}
	if (obj->n_exit != 1 || obj->n_plyr != 1 || obj->n_objs < 1)
		msg_error("entra aqui\n");
	return (j);
}

void	check_map(int fd, t_obj *objs, t_game *game)
{
	char	*mapa_capon;
	int		j;
	int		k;

	k = 0;
	j = 0;
	mapa_capon = NULL;
	read_map(fd, &objs, &mapa_capon);
	while (mapa_capon[k])
	{
		if (mapa_capon[k] == '\n' && mapa_capon[k + 1] == '\n')
			msg_error("Invalid map");
		k++;	
	}
	k = 0;
	game->map = ft_split(mapa_capon, '\n');
	if (!game->map)
		msg_error("Empty map.");
	check_rect_map(&game);
	while (game->map[j])
	{
		printf("--%s--\n", game->map[j]);
		j++;
	}
	k = check_items(objs, game->map);
	check_wall(&objs, game->map, k - 1);
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
