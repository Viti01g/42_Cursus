/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:01 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/06/21 16:43:08 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_files(t_pipe *pipel, int argc, char **argv)
{
	int	i;

	i = 0;
	pipel->infile = open(argv[1], O_RDONLY);
	if (pipel->infile < 0)
	{
		msg_error(ERR_INFILE, 0);
		i++;
	}
	pipel->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipel->outfile < 0)
	{
		msg_error(ERR_OUTFILE, 0);
		i++;
	}
	return (i);
}

static void	aux_funct(t_pipe pipel)
{
	waitpid(pipel.pid1, NULL, 0);
	waitpid(pipel.pid2, NULL, 0);
	parent_free(&pipel);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipel;
	int		open;

	if (argc != 5)
		return (msg(ERR_INPUT));
	open = open_files(&pipel, argc, argv);
	if (open == 2)
		exit(EXIT_FAILURE);
	pipel.path = get_path(env);
	if (pipe(pipel.fd_tube) < 0)
		msg_error(ERR_PIPE, 1);
	pipel.paths_cmds = ft_split(pipel.path, ':');
	if (open < 1)
	{
		pipel.pid1 = fork();
		if (pipel.pid1 == 0)
			pipe1(pipel, argv, env);
	}
	pipel.pid2 = fork();
	if (pipel.pid2 == 0)
		pipe2(pipel, argv, env, open);
	close_pipes(&pipel);
	aux_funct(pipel);
	return (0);
}
