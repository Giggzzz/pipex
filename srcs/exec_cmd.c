/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:42:59 by gudias            #+#    #+#             */
/*   Updated: 2022/03/21 19:28:14 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_first_cmd(int	infile, char	*cmd, char	*path, int	*pipe_fd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_args[0] = find_cmd_path(path, cmd_args[0]);
	if (!cmd_args[0])
		err_quit(4);
	dup2(infile, 0);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}

void	exec_last_cmd(int	outfile, char *cmd, char *path, int *pipe_fd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_args[0] = find_cmd_path(path, cmd_args[0]);
	if (!cmd_args[0])
		err_quit(4);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	dup2(outfile, 1);
	close(pipe_fd[1]);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}
