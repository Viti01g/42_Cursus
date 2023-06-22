/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:20:18 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/06/19 13:06:18 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err, int outfile)
{
	perror(err);
	if (outfile == 1)
		exit (1);
	return ;
}

void	parent_free(t_pipe *pipe)
{
	int	i;

	i = 0;
	close(pipe->outfile);
	close(pipe->infile);
	while (pipe->paths_cmds[i])
	{
		free(pipe->paths_cmds[i]);
		i++;
	}
	free(pipe->paths_cmds);
}

void	child_free(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (pipe->command_args[i])
	{
		free(pipe->command_args[i]);
		i++;
	}
	free(pipe->command);
	free(pipe->command_args);
}
