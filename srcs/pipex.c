/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:26:56 by gudias            #+#    #+#             */
/*   Updated: 2022/03/24 17:11:11 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	cmd_i;

	if (argc < 5)
		err_quit(1);
	if (!ft_strncmp(argv[1], "here_doc\0", 9))
	{
		if (argc < 6)
			err_quit(1);
		here_doc(argv[2]);
		outfile = openfile(argv[argc - 1], 2);
		cmd_i = 3;
	}
	else
	{
		infile = openfile(argv[1], 0);
		dup2(infile, 0);
		outfile = openfile(argv[argc - 1], 1);
		cmd_i = 2;
	}
	while (cmd_i < (argc - 2))
		run_cmd(argv[cmd_i++], envp, 0);
	run_cmd(argv[cmd_i], envp, outfile);
	return (0);
}
