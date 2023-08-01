/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:04:28 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/31 17:31:42 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_obj	obj;
	t_game	game;
	t_disp	disp;
	//int height = 20;
	//int weight = 20;
	//printf("hola\n");

	check_params(argc, argv, &obj, &game);
	init_img(&game, &disp);
	print_map(&game, &disp);
	mlx_key_hook(game.win, , &game);
	mlx_hook(game.win, DESTROY, 0, red_cross, &game);
	mlx_loop(game.mlx);
	exit (0);
}
