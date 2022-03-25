/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:46 by gudias            #+#    #+#             */
/*   Updated: 2022/03/25 13:24:52 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_error(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
}

void	err_quit(int errno)
{
	if (errno == 1)
		print_error("Error: invalid arguments count");
	else if (errno == 2)
		print_error("Error: wrong arguments");
	else if (errno == 3)
		print_error("Error: no such file or directory");
	else if (errno == 4)
		print_error("Error: command not found");
	else if (errno == 5)
		print_error("Error: pipe");
	else if (errno == 6)
		print_error("Error: fork");
	else if (errno == 7)
		print_error("Error: execve");
	exit(1);
}
