/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:49 by gudias            #+#    #+#             */
/*   Updated: 2022/03/16 19:36:02 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_files(char *infile, char *outfile)
{
	int	fd1;
	int	fd2;

	fd1 = open(infile, O_RDONLY | O_CREAT, 0644);
	if (fd1 == -1)
		err_quit(3);
	fd2 = open(outfile, O_RDONLY | O_CREAT, 0644);
	if (fd2 == -1)
		err_quit(3);
	close(fd1);
	close(fd2);
}

static void	check_cmds(char *cmd1, char *cmd2)
{
	if (0)
		err_quit(4);
}

void	check_args(int argc, char **argv)
{
	if (argc != 5)
		err_quit(1);
	check_files(argv[1], argv[4]);
	check_cmds(argv[2], argv[3]);
}
