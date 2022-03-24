/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:27:12 by gudias            #+#    #+#             */
/*   Updated: 2022/03/24 17:11:22 by gudias           ###   ########.fr       */
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
void	run_cmd(char *cmd, char **envp, int output);
void	exec_cmd(char *cmd, char **envp);
void	here_doc(char *limiter);
void	err_quit(int errno);

//utils
void	ft_println(char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
char	*ft_strchr_nl(char *str);
char	*ft_pathjoin(char *s1, char *s2);
int		openfile(char *filepath, int o_flag);
char	*get_next_line(int fd);

#endif
