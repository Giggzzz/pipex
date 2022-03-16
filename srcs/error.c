/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:46 by gudias            #+#    #+#             */
/*   Updated: 2022/03/16 17:21:41 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_quit(int errno)
{
	if (errno == 1)
		ft_printf("ERROR: Bad arguments count\n");
	else if (errno == 2)
		ft_printf("ERROR: Wrong arguments\n");
	else if (errno == 3)
		ft_printf("ERROR: File error\n");
	else if (errno == 4)
		ft_printf("ERROR: Command not found\n");
	else if (errno == 5)
		ft_printf("ERROR: PIPE FAIL\n");
	else if (errno == 6)
		ft_printf("ERROR: FORK FAIL\n");
	exit(0);
}
