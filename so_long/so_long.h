/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:03:58 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/08/05 17:15:16 by vruiz-go         ###   ########.fr       */
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

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT 123
# define RGHT 124
# define DW 125
# define UP 126

# define PLY "./textures/personaje/plyr_normal.xpm"
# define WLL "./textures/wall.xpm"
# define OBJ "./textures/colleccionable.xpm"
# define EX "./textures/exit.xpm"
# define FLR "./textures/floor.xpm"

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
}	t_obj;

typedef struct disp
{
	void	*ex;
	void	*ply;
	void	*colec;
	void	*flr;
	void	*wll;
}	t_disp;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wll;
	int		x_max;
	int		y_max;
	int		ply_x;
	int		ply_y;
	char	**map;
	char	**map_cpy;
	int		moves;
	t_disp	*disp;
	t_obj	*obj;
}	t_game;

int		msg(char *err);
void	msg_error(char *err);
void	check_params_so(int argc, char **argv, t_obj *obj, t_game *game);
int		red_cross(t_game *game);
void	check_map(int fd, t_obj *objs, t_game *game);
char	*read_map(int fd, t_obj **obj, char *str);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
void	check_rect_map(t_game **game);
void	init_img(t_game *game, t_disp *disp);
void	print_map(t_game *game, t_disp *disp);
void	up_key(t_game *game, t_obj *obj, t_disp *disp);
void	left_key(t_game *game, t_obj *obj, t_disp *disp);
void	right_key(t_game *game, t_obj *obj, t_disp *disp);
void	down_key(t_game *game, t_obj *obj, t_disp *disp);
int		gest_keys(int key, t_game *game);
void	pos_player(t_game *game);
void	ft_liberar(char **str);
int		valid_path(t_game *game);
void	ft_free_so(char *str, char *str1);

#endif
