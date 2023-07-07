/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:58:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/05 15:42:56 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
	return ;
}

int	red_cross(t_obj *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}
