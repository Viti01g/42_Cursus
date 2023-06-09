/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:58:52 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/06/08 14:39:41 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipe *pipe)
{
	close(pipe->fd_tube[0]);
	close(pipe->fd_tube[1]);
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	command = NULL;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK & R_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	pipe1(t_pipe pipe, char *argv[], char *envp[])
{
	dup2(pipe.fd_tube[1], 1);
	close(pipe.fd_tube[0]);
	dup2(pipe.infile, 0);
	pipe.command_args = ft_split(argv[2], ' ');
	pipe.command = get_cmd(pipe.paths_cmds, pipe.command_args[0]);
	if (!pipe.command)
	{
		child_free(&pipe);
		msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipe.command, pipe.command_args, envp);
}

void	pipe2(t_pipe pipe, char *argv[], char *envp[])
{
	dup2(pipe.fd_tube[0], 0);
	close(pipe.fd_tube[1]);
	dup2(pipe.outfile, 1);
	pipe.command_args = ft_split(argv[3], ' ');
	pipe.command = get_cmd(pipe.paths_cmds, pipe.command_args[0]);
	if (!pipe.command)
	{
		child_free(&pipe);
		msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipe.command, pipe.command_args, envp);
}
