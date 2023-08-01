/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas_teclas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:28:19 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/01 16:55:11 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	end_game(t_game *game, t_disp *disp)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	gest_keys(int key, t_game *game, t_disp *disp, t_obj *obj)
{
	if (key == ESC)
		end_game(game, disp);
	
}

void	pos_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
			{
				game->player_x == i;
				game->player_y == j;
				 return ;
			}
			i++;
		}
		j++;
	}
}
