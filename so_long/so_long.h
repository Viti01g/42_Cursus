/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: VR <VR@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:03:58 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/10 18:41:32 by VR               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
//# include <mlx.h>
# include <./minilibx/mlx.h>

# define DESTROY 17
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_FILE "File"

typedef struct s_obj
{
	void	*mlx;	
	void	*win;
	void	*img_wll;
	int		n_cols;
	int		n_rows;
	int		n_objs;
	int		n_exit;
	int		n_floor;
	int		n_plyr;
}   t_obj;

typedef struct s_ply
{

}	t_ply;


int		msg(char *err);
void	msg_error(char *err);
char	**check_params(int argc, char **argv, t_obj *obj);
int	red_cross(t_obj *game);

#endif
