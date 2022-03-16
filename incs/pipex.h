/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:27:12 by gudias            #+#    #+#             */
/*   Updated: 2022/03/16 17:03:03 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "ft_printf.h"

void	check_args(int argc, char **argv);
void	err_quit(int errno);
//utils
void	ft_printl(char *str);


#endif
