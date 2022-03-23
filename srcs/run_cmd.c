/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:42:59 by gudias            #+#    #+#             */
/*   Updated: 2022/03/23 18:56:48 by gudias           ###   ########.fr       */
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
	free(dirs);
	return (NULL);
}

void	run_cmd(char *cmd, char **envp, int output)
{
	int	id;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		err_quit(5);
	id = fork();
	if (id == -1)
		err_quit(6);
	if (id == 0)
	{
		close(pipe_fd[0]);
		if (output)
			dup2(output, 1);
		else
			dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		exec_cmd(cmd, envp);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	waitpid(id, NULL, 0);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (*cmd_args[0] != '/' && *cmd_args[0] != '.' && *cmd_args[0] != '~')
		cmd_args[0] = find_cmd_path(cmd_args[0], envp);
	if (!cmd_args[0])
		err_quit(4);
	execve(cmd_args[0], cmd_args, envp);
	err_quit(7);
}