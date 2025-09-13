/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:01:46 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 16:20:48 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int	**pipes;
	int	infile;
	int	outfile;
	int	n_cmd;
}	t_pipex;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
void	error_and_exit(char *msg);
int		**malloc_pipes(int argc);
char	**ft_split_spaces(const char *s);
char	*find_cmd_path(char *cmd, char **envp);
void	fork_and_execute(t_pipex *px, int i, char *cmd, char **envp);
void	free_part(int **arr, int i);
void	close_all_pipes(int **pipes, int n_pipes);
size_t	ft_strlen(const char *s);
void	ft_free_split(char **parts);
void	exec_cmd(char *cmd, char **envp);
void	child1(int infile, int pipe_w, char *cmd, char **envp);
void	child2(int outfile, int pipe_r, char *cmd, char **envp);
void	open_files(int argc, char **argv, int *infile, int *outfile);

#endif