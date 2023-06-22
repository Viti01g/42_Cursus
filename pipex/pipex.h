/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/06/21 14:12:59 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found.\n"

typedef struct pipe
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	*path;
	char	**paths_cmds;
	char	*command;
	char	**command_args;
	int		fd_tube[2];
}	t_pipe;

int		msg(char *err);
void	msg_error(char *err, int outfile);
void	child_free(t_pipe *pipe);
void	parent_free(t_pipe *pipe);
char	*get_path(char **env);
void	pipe1(t_pipe pipe, char *argv[], char *envp[]);
void	pipe2(t_pipe pipe, char *argv[], char *envp[], int open);
void	close_pipes(t_pipe *pipe);

#endif
