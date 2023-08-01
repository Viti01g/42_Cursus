/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas_cosas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:32:04 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/31 16:57:14 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *game, t_disp *disp)
{
	int w;
	int h;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->x_max * 30, game->y_max * 30,
			"So_Long");
	disp->colec = mlx_xpm_file_to_image(game->mlx, OBJ, &w, &h);
	if (!disp->colec)
		msg_error("\nImage couldn't be opened!\n");
	disp->ply = mlx_xpm_file_to_image(game->mlx, PLY, &w, &h);
	if (disp->ply == NULL)
		msg_error("\nImage couldn't be opened!\n");
	disp->flr = mlx_xpm_file_to_image(game->mlx, FLR, &w, &h);
	if (disp->flr == NULL)
	msg_error("\nmage couldn't be opened!\n");
	disp->ex = mlx_xpm_file_to_image(game->mlx, EX, &w, &h);
	if (disp->ex == NULL)
		msg_error("\nImage couldn't be opened!\n");
	disp->wll = mlx_xpm_file_to_image(game->mlx, WLL, &w, &h);
	if (disp->wll == NULL)
		msg_error("\nImage couldn't be opened!\n");
}

void	check_rect_map(t_game **game)
{
	int	i;

	i = 0;
	(*game)->x_max = ft_strlen((*game)->map[i]);
	while ((*game)->map[i])
	{
		if ((int)ft_strlen((*game)->map[i]) == (*game)->x_max)
			i++;
		else
			msg_error("Map isn't rectangle\n");
	}
	(*game)->y_max = i;
}

static void	all_floor(t_game *game, t_disp *disp)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, disp->flr, x * 30, y * 30);
			x++;
		}
		y++;
	}
}

static void	print_img(t_game *game, t_disp *disp, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, disp->wll, x * 30, y * 30);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, disp->ply, x * 30, y * 30);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, disp->colec, x * 30, y * 30);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, disp->ex, x * 30, y * 30);
}

void	print_map(t_game *game, t_disp *disp)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	all_floor(game, disp);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			print_img(game, disp, x, y);
			x++;
		}
		y++;
	}
}
