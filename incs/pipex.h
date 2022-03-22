/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:27:12 by gudias            #+#    #+#             */
/*   Updated: 2022/03/22 19:17:31 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*path;

}	t_pipex;

char	*get_path(char **envp);
char	*find_cmd_path(char *cmd, char **envp);

void	exec_first_cmd(int infile, char *cmd, int *pipe_fd, char **envp);
void	exec_cmd(char *cmd, int *pipe_fd, char **envp);
void	exec_last_cmd(int outfile, char *cmd, int *pipe_fd, char **envp);

void	err_quit(int errno);
int		openfile(char *filepath, int o_flag);

//utils
void	ft_println(char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
char	*ft_pathjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);

#endif
