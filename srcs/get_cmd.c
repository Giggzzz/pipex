/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:49 by gudias            #+#    #+#             */
/*   Updated: 2022/03/21 19:28:02 by gudias           ###   ########.fr       */
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

char	*find_cmd_path(char *path, char *cmd)
{
	char	**dirs;
	char	*cmd_path;

	dirs = ft_split(path, ':');
	while (*dirs)
	{
		cmd_path = ft_pathjoin(*dirs, cmd);
		if (access(cmd_path, 0) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		dirs++;
	}
	return (NULL);
}

char	**get_cmd_args
