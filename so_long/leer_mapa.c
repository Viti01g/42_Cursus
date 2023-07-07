/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_mapa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:05:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/07 14:09:38 by vruiz-go         ###   ########.fr       */
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
	if (ft_strncmp(argv[1], ".ber", 4))
		msg_error("Invalid file type, use .ber!");
	return (check_map(fd, obj));
}

char	**check_map(int fd, t_obj *objs)
{
	char	*mapa_capon;
	char	**mapa;

	read_map(fd, &objs, &mapa_capon);
}

void	read_map(int fd, t_obj *obj, char **str)
{
	char		*line;
	char		*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!obj->n_cols)
				error_msg_params("Map is empty!", NULL);
			else
				ft_checklayout(last_line, obj, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_checklayout(line, obj, !obj->n_rows);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*str = ft_strenlarge(*str, line);
		obj->n_rows++;
	}
}
