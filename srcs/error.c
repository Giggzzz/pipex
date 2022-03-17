/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:46 by gudias            #+#    #+#             */
/*   Updated: 2022/03/17 15:26:05 by gudias           ###   ########.fr       */
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
		ft_println("ERROR: File error");
	else if (errno == 4)
		ft_println("ERROR: Command not found");
	else if (errno == 5)
		ft_println("ERROR: PIPE FAILED");
	else if (errno == 6)
		ft_println("ERROR: FORK FAILED");
	else if (errno == 7)
		ft_println("ERROR: EXECVE FAILED");
	exit(0);
}
