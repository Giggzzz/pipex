/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:49 by gudias            #+#    #+#             */
/*   Updated: 2022/03/11 17:49:00 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_files(char *in, char *out)
{

}

static void	check_cmds(char *cmd1, char *cmd2)
{

}

void	check_args(int argc, char **argv)
{
	if (argc != 5)
		err_quit(1);
	argv++;

}
