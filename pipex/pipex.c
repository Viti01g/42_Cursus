/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:01 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/06/07 17:29:11 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipel;

	if (argc != 5)
		return (msg(ERR_INPUT));
	pipel.infile = open(argv[1], O_RDONLY);
	if (pipel.infile < 0)
		msg_error(ERR_INFILE);
	pipel.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipel.outfile < 0)
		msg_error(ERR_OUTFILE);
	if (pipe(pipel.fd_tube) < 0)
		msg_error(ERR_PIPE);
	pipel.path = get_path(env);
	pipel.paths_cmds = ft_split(pipel.path, ':');
	pipel.pid1 = fork();
	if (pipel.pid1 == 0)
		pipe1(pipel, argv, env);
	pipel.pid2 = fork();
	if (pipel.pid2 == 0)
		pipe2(pipel, argv, env);
	close_pipes(&pipel);
	waitpid(pipel.pid1, NULL, 0);
	waitpid(pipel.pid2, NULL, 0);
	parent_free(&pipel);
	return (0);
}
