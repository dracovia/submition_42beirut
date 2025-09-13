/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 09:29:03 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/11 14:15:01 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
}	t_pipex;

void	error_and_exit(char *msg);
int		open_file(char *name);
char	**ft_split(char const *s, char c);
char	**ft_split_spaces(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_free_split(char **parts);
char	*ft_strjoin_path(const char *a, const char *b);
char	*find_cmd_path(char *cmd, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	exec_cmd(char *cmd, char **envp);
void	child1(int infile, int pipe_w, char *cmd, char **envp);
void	child2(int outfile, int pipe_r, char *cmd, char **envp);
pid_t	start_first(int infile, int *pipefd, char **argv, char **envp);
pid_t	start_second(int outfile, int *pipefd, char **argv, char **envp);

#endif