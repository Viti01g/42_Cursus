/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:04:28 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/05 17:26:59 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_obj	obj;
	char	**map;
	int height = 20;
	int weight = 20;

	map = check_params(argc, argv, &obj);
	obj.mlx = mlx_init();
	obj.win = mlx_new_window(obj.mlx, 520, 520, "so_long");
	obj.img_wll = mlx_new_image(obj.mlx, 520, 520);
	obj.img_wll = mlx_xpm_file_to_image(obj.mlx, "./img/wall.xpm", &weight, &height);
	mlx_put_image_to_window(obj.mlx, obj.win, obj.img_wll, 0 , 0);
	mlx_hook(obj.win, DESTROY, 0, red_cross, &obj);
	mlx_loop(obj.mlx);
	
}
