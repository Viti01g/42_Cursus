/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teclas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:34:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/01 18:43:49 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	up_key(t_game *game, t_obj *obj, t_disp *disp)
{
	if (game->map[game->player_y - 1][game->player_x] == 'C')
        obj->n_cols--;
    game->map[game->player_y][game->player_x] = '0';
    game->map[game->player_y - 1][game->player_x] = 'P';
    game->player_y--;
    game->moves++;
    ft_printf("Movimientos: %d\n", game->moves);
    print_map(game, disp);
}
void	left_key(t_game *game, t_obj *obj, t_disp *disp)
{

}
void	right_key(t_game *game, t_obj *obj, t_disp *disp)
{

}
void	down_key(t_game *game, t_obj *obj, t_disp *disp)
{

}
