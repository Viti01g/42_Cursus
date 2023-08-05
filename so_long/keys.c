/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teclas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:34:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/05 17:20:55 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_key(t_game *game, t_obj *obj, t_disp *disp)
{
	if (game->map[game->ply_y - 1][game->ply_x] == 'C')
		obj->n_objs--;
	game->map[game->ply_y][game->ply_x] = '0';
	game->map[game->ply_y - 1][game->ply_x] = 'P';
	game->ply_y--;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	print_map(game, disp);
}

void	left_key(t_game *game, t_obj *obj, t_disp *disp)
{
	if (game->map[game->ply_y][game->ply_x - 1] == 'C')
		obj->n_objs--;
	game->map[game->ply_y][game->ply_x] = '0';
	game->map[game->ply_y][game->ply_x - 1] = 'P';
	game->ply_x--;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	print_map(game, disp);
}

void	right_key(t_game *game, t_obj *obj, t_disp *disp)
{
	if (game->map[game->ply_y][game->ply_x + 1] == 'C')
		obj->n_objs--;
	game->map[game->ply_y][game->ply_x] = '0';
	game->map[game->ply_y][game->ply_x + 1] = 'P';
	game->ply_x++;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	print_map(game, disp);
}

void	down_key(t_game *game, t_obj *obj, t_disp *disp)
{
	if (game->map[game->ply_y + 1][game->ply_x] == 'C')
		obj->n_objs--;
	game->map[game->ply_y][game->ply_x] = '0';
	game->map[game->ply_y + 1][game->ply_x] = 'P';
	game->ply_y++;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	print_map(game, disp);
}
