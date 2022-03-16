/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:26:56 by gudias            #+#    #+#             */
/*   Updated: 2022/03/16 19:35:55 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		id;
	int		pipe1[2];
	char	s;
	char	r;
	
	check_args(argc, argv);

	if (pipe(pipe1) == -1)
		err_quit(5);

	id = fork();
	if (id == -1)
		err_quit(6);

	if (id == 0)
	{
		close(pipe1[0]);
		ft_printf("Im a child with pid: %d, my parent is: %d\n", getpid(), getppid());
		s = 'x';
		
		write(pipe1[1], &s, 1);
		ft_printf("sent: %c\n", s);
		close(pipe1[1]);
	}
	else
	{
		close(pipe1[1]);
		r = '0';
		ft_printf("Im the main with id: %d, r: %c\n", getpid(), r);
		wait(NULL);
		read(pipe1[0], &r, 1);
		ft_printf("r is now: %c\n", r);
		close(pipe1[0]);
	}
	return (0);
}
