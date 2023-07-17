/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:03:58 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/13 15:54:47 by vruiz-go         ###   ########.fr       */
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
# include <mlx.h>
//# include <./minilibx/mlx.h>

# define DESTROY 17
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_FILE "File"

typedef struct s_obj
{
	int		n_cols;
	int		n_rows;
	int		n_objs;
	int		n_exit;
	int		n_floor;
	int		n_plyr;
}   t_obj;

typedef struct images
{
	void	*img;
	int		wid;
	int		hei;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void	*mlx;	
	void	*win;
	void	*img_wll;
}	t_game;


int		msg(char *err);
void	msg_error(char *err);
char	**check_params(int argc, char **argv, t_obj *obj);
int		red_cross(t_game *game);
char	**check_map(int fd, t_obj *objs);
void	read_map(int fd, t_obj **obj, char **str);
int	ft_strrncmp(const char *s1, const char *s2, size_t n);

#endif
