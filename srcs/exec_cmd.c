/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:42:59 by gudias            #+#    #+#             */
/*   Updated: 2022/03/22 20:03:59 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	**dirs;
	char	*cmd_path;
	char	*path;

	path = get_path(envp);
	dirs = ft_split(path, ':');
	while (*dirs)
	{
		cmd_path = ft_pathjoin(*dirs, cmd);
		if (access(cmd_path, 0) == 0)
			return (cmd_path);
		free(cmd_path);
		dirs++;
	}
	return (NULL);
}

void	exec_cmd(char *cmd, int *pipe_fd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_args[0] = find_cmd_path(cmd_args[0], envp);
	if (!cmd_args[0])
		err_quit(4);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}

void	exec_first_cmd(int infile, char *cmd, int *pipe_fd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!ft_strchr(cmd_args[0], '/'))
		cmd_args[0] = find_cmd_path(cmd_args[0], envp);
	if (!cmd_args[0])
		err_quit(4);
	dup2(infile, 0);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}

void	exec_last_cmd(int outfile, char *cmd, int *pipe_fd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!ft_strchr(cmd_args[0], '/'))
		cmd_args[0] = find_cmd_path(cmd_args[0], envp);
	if (!cmd_args[0])
		err_quit(4);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	dup2(outfile, 1);
	close(pipe_fd[1]);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}

void	exec(char *cmd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!ft_strchr(cmd_args[0], '/'))
		cmd_args[0] = find_cmd_path(cmd_args[0], envp);
	if(!cmd_args[0])
		err_quit(4);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}
