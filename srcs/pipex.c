/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:26:56 by gudias            #+#    #+#             */
/*   Updated: 2022/03/22 20:03:55 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		id;
	int		id2;
	int		pipe_fd[2];
	int		infile;
	int		outfile;

	if (argc < 5)
		err_quit(1);
	infile = openfile(argv[1], 0);
	outfile = openfile(argv[argc - 1], 1);
	if (pipe(pipe_fd) == -1)
		err_quit(5);
	id = fork();
	if (id == -1)
		err_quit(6);
	if (id == 0)
		exec_first_cmd(infile, argv[2], pipe_fd, envp);
	int i = 3;
	while (i < (argc - 2))
	{
		pipe(pipe_fd);
		id = fork();
		if (id == -1)
			err_quit(6);
		if (id == 0)
			exec_cmd(argv[i], pipe_fd, envp);
		wait(NULL);
		i++;
	}
	id2 = fork();
	if (id2 == -1)
		err_quit(6);
	if (id2 == 0)
		exec_last_cmd(outfile, argv[argc - 2], pipe_fd, envp);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
