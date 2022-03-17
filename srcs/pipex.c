/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:26:56 by gudias            #+#    #+#             */
/*   Updated: 2022/03/17 17:32:22 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		id;
	int		pipe1[2];
	char	r;
	
	check_args(argc, argv, envp);

	if (pipe(pipe1) == -1)
		err_quit(5);

	id = fork();
	if (id == -1)
		err_quit(6);

	char	*av[5];
	//av[0] = NULL;

	av[0] = "/sbin/ping";
	av[1] = "www.google.com";
	av[2] = "-c";
	av[3] = "4";
	av[4] = NULL;
	if (id == 0)
	{
		close(pipe1[0]);
		dup2(pipe1[1],1);
		close(pipe1[1]);
		execve("/sbin/ping", av, envp);
		err_quit(7);	
	}
	else
	{
		close(pipe1[1]);
	//	wait(NULL);
		while (read(pipe1[0], &r, 1)) 
			write(pipe1[1], &r, 1);


		//write(1, "\n", 1);
		close(pipe1[0]);
	}
	return (0);
}
