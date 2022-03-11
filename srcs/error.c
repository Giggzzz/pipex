/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:46 by gudias            #+#    #+#             */
/*   Updated: 2022/03/11 17:48:53 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_quit(int errno)
{
	if (errno == 1)
		ft_putendl("ERROR: Bad arguments count");
	else if (errno == 2)
		ft_putendl("ERROR: Wrong arguments");
	else if (errno == 3)
		ft_putendl("ERROR: File error");
	else if (errno == 4)
		ft_putendl("ERROR: Command not found");
	exit(0);
}
