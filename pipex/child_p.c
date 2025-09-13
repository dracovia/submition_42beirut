/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:40:21 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 15:03:23 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split_spaces(cmd);
	if (!args || !args[0])
	{
		write(2, "pipex: command not found\n", 25);
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

pid_t	start_first(int infile, int *pipefd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_and_exit("fork");
	if (pid == 0)
	{
		close(pipefd[0]);
		child1(infile, pipefd[1], argv[2], envp);
	}
	return (pid);
}

pid_t	start_second(int outfile, int *pipefd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_and_exit("fork");
	if (pid == 0)
	{
		close(pipefd[1]);
		child2(outfile, pipefd[0], argv[3], envp);
	}
	return (pid);
}
