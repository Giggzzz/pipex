/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:46 by gudias            #+#    #+#             */
/*   Updated: 2022/03/23 19:08:32 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_quit(int errno)
{
	if (errno == 1)
		ft_println("ERROR: Bad arguments count");
	else if (errno == 2)
		ft_println("ERROR: Wrong arguments");
	else if (errno == 3)
		perror("ERROR: File error");
	else if (errno == 4)
		perror("ERROR: Command not found");
	else if (errno == 5)
		perror("ERROR: PIPE FAILED");
	else if (errno == 6)
		perror("ERROR: FORK FAILED");
	else if (errno == 7)
		perror("ERROR: EXECVE FAILED");
	exit(0);
}
