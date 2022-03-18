/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:26:56 by gudias            #+#    #+#             */
/*   Updated: 2022/03/18 02:32:52 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		id;
	int		pipe1[2];
	int		pipe2[2];
	char	r;
	int	infile;
	int	outfile;

	//check_args(argc, argv, envp);
	infile = open(argv[1], O_WRONLY | O_CREAT, 0644);	
	outfile = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (!outfile)
		err_quit(3);
	if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
		err_quit(5);

	id = fork();
	if (id == -1)
		err_quit(6);

	char	*av1[3];
	av1[0] = "/usr/bin/cat";
	av1[1] = "infile";
	//1av[2] = "-c";
	//1av[3] = "4";
	av1[2] = NULL;
	char	*av2[3];
	av2[0] = "/usr/bin/grep";
	av2[1] = "aigh";
	av2[2] = NULL;
	if (id == 0)
	{
		close(pipe1[0]);
		dup2(pipe1[1],1);
		close(pipe1[1]);
		execve(av[0], av, envp);
		err_quit(7);	
	}
	else
	{
		//close(pipe1[1]);
	//	wait(NULL);
		while (read(pipe1[0], &r, 1)) 
			write(pipe2[1], &r, 1);
		
		id = fork();
		if (id == -1)
			err_quit(6);

		if (id == 0)
		{
			
		}
		else
		{

		}

		close(pipe1[0]);
	}
	return (0);
}
