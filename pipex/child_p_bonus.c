/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_p_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:29:21 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 16:20:59 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split_spaces(cmd);
	if (!args || !args[0])
	{
		write(2, "pipex: : command not found\n", 27);
		ft_free_split(args);
		exit(127);
	}
	path = find_cmd_path(args[0], envp);
	if (!path)
	{
		write(2, "pipex: ", 7);
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		ft_free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	ft_free_split(args);
	exit(EXIT_FAILURE);
}

void	child1(int infile, int pipe_w, char *cmd, char **envp)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		error_and_exit("dup2 infile");
	if (dup2(pipe_w, STDOUT_FILENO) < 0)
		error_and_exit("dup2 pipe");
	close(infile);
	close(pipe_w);
	exec_cmd(cmd, envp);
}

void	child2(int outfile, int pipe_r, char *cmd, char **envp)
{
	if (dup2(pipe_r, STDIN_FILENO) < 0)
		error_and_exit("dup2 pipe_r");
	if (dup2(outfile, STDOUT_FILENO) < 0)
		error_and_exit("dup2 outfile");
	close(outfile);
	close(pipe_r);
	exec_cmd(cmd, envp);
}

void	open_files(int argc, char **argv, int *infile, int *outfile)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		perror("can't open file");
	*outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*outfile < 0)
		perror(argv[argc - 1]);
}
