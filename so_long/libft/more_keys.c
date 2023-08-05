/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas_teclas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:28:19 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/05 17:02:29 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_liberar(game->map);
	exit(EXIT_SUCCESS);
}

int	gest_keys(int ky, t_game *gm)
{
	if (ky == ESC)
		end_game(gm);
	if (gm->obj->n_objs <= 0
		&& (((ky == W || ky == UP) && gm->map[gm->ply_y - 1][gm->ply_x] == 'E')
		|| ((ky == A || ky == LEFT) && gm->map[gm->ply_y][gm->ply_x - 1] == 'E')
		|| ((ky == D || ky == RGHT) && gm->map[gm->ply_y][gm->ply_x + 1] == 'E')
		|| ((ky == S || ky == DW) && gm->map[gm->ply_y + 1][gm->ply_x] == 'E')))
	{
		ft_printf("\n--Congrats, you escape the garden--\n");
		end_game(gm);
	}
	if (((ky == W || ky == UP)) && (gm->map[gm->ply_y - 1][gm->ply_x] != '1'
		&& gm->map[gm->ply_y - 1][gm->ply_x] != 'E'))
		up_key(gm, gm->obj, gm->disp);
	if (((ky == A || ky == LEFT)) && (gm->map[gm->ply_y][gm->ply_x - 1] != '1'
		&& gm->map[gm->ply_y][gm->ply_x - 1] != 'E'))
		left_key(gm, gm->obj, gm->disp);
	if (((ky == D || ky == RGHT)) && (gm->map[gm->ply_y][gm->ply_x + 1] != '1'
		&& gm->map[gm->ply_y][gm->ply_x + 1] != 'E'))
		right_key(gm, gm->obj, gm->disp);
	if (((ky == S || ky == DW)) && (gm->map[gm->ply_y + 1][gm->ply_x] != '1'
		&& gm->map[gm->ply_y + 1][gm->ply_x] != 'E'))
		down_key(gm, gm->obj, gm->disp);
	return (0);
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
				game->ply_x = i;
				game->ply_y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}
