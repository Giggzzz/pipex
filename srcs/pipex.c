/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:26:56 by gudias            #+#    #+#             */
/*   Updated: 2022/03/23 18:02:20 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	if (argc < 5)
		err_quit(1);
	infile = openfile(argv[1], 0);
	outfile = openfile(argv[argc - 1], 1);
	if (!infile || !outfile)
		err_quit(3);
	dup2(infile, 0);
	i = 2;
	while (i < (argc - 2))
		run_cmd(argv[i++], envp, 0);
	run_cmd(argv[i], envp, outfile);
	return (0);
}
