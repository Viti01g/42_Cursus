/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:04:28 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/13 12:52:14 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_obj	obj;
	//t_game	game;
	char	**map;
	//int height = 20;
	//int weight = 20;
	//printf("hola\n");

	map = check_params(argc, argv, &obj);
	/* game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, obj.n_cols * 30, obj.n_floor * 30, "so_long");
	game.img_wll = mlx_new_image(game.mlx, 520, 520);
	game.img_wll = mlx_xpm_file_to_image(game.mlx, "./img/wall.xpm", &weight, &height);
	mlx_put_image_to_window(game.mlx, game.win, game.img_wll, 0 , 0);
	mlx_hook(game.win, DESTROY, 0, red_cross, &game);
	mlx_loop(game.mlx); */
	exit (0);
}
