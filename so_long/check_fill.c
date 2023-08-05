/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:46:39 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/05 17:36:37 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_cur(t_game *game, int i, int j)
{
	if (game->map_cpy[i][j] == 'P' &&
	(game->map_cpy[i + 1][j] == 'C'
	|| game->map_cpy[i + 1][j] == '0'
	|| game->map_cpy[i - 1][j] == 'C'
	|| game->map_cpy[i - 1][j] == '0'
	|| game->map_cpy[i][j + 1] == 'C'
	|| game->map_cpy[i][j + 1] == '0'
	|| game->map_cpy[i][j - 1] == 'C'
	|| game->map_cpy[i][j - 1] == '0'))
		return (1);
	return (0);
}

static void	fill(t_game *game, int i, int j)
{
	if (game->map_cpy[i][j] == '0' || game->map_cpy[i][j] == 'C')
		game->map_cpy[i][j] = 'P';
}

static int	complete_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y_max)
	{
		j = 0;
		while (j < game->x_max)
		{
			if ((game->map_cpy[i][j] == 'E' && game->map_cpy[i + 1][j] == 'P')
			|| (game->map_cpy[i][j] == 'E' && game->map_cpy[i - 1][j] == 'P')
			|| (game->map_cpy[i][j] == 'E' && game->map_cpy[i][j + 1] == 'P')
			|| (game->map_cpy[i][j] == 'E' && game->map_cpy[i][j - 1] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	msg_error("Unable to find a valid path");
	return (0);
}

static int	check_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y_max)
	{
		j = 0;
		while (j < game->x_max)
		{
			if (game->map_cpy[i][j] == 'C')
				msg_error("Unable to reach all collectibles");
			printf("aqui\n");
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y_max)
	{
		j = 0;
		while (j < game->x_max)
		{
			if (check_cur(game, i, j))
			{
				fill(game, i + 1, j);
				fill(game, i - 1, j);
				fill(game, i, j + 1);
				fill(game, i, j - 1);
				i = 0;
			}
			j++;
		}
		i++;
	}
	ft_liberar(game->map_cpy);
	if (check_collect(game) && complete_path(game))
		return (1);
	return (0);
}
