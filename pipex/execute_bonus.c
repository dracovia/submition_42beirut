/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:23:24 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 16:13:50 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child_first(t_pipex *px, char *cmd, char **envp)
{
	if (close(px->pipes[0][0]) < 0)
		error_and_exit("close pipe read end");
	child1(px->infile, px->pipes[0][1], cmd, envp);
}

static void	child_last(t_pipex *px, char *cmd, char **envp, int i)
{
	child2(px->outfile, px->pipes[i - 1][0], cmd, envp);
}

static void	child_middle(t_pipex *px, char *cmd, char **envp, int i)
{
	int	j;

	j = 0;
	if (dup2(px->pipes[i - 1][0], STDIN_FILENO) < 0)
		error_and_exit("dup2 middle stdin");
	if (dup2(px->pipes[i][1], STDOUT_FILENO) < 0)
		error_and_exit("dup2 middle stdout");
	while (j < px->n_cmd - 1)
	{
		close(px->pipes[j][0]);
		close(px->pipes[j][1]);
		j++;
	}
	exec_cmd(cmd, envp);
}

void	fork_and_execute(t_pipex *px, int i, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_and_exit("fork failed");
	if (pid == 0)
	{
		if (i == 0)
			child_first(px, cmd, envp);
		else if (i == px->n_cmd - 1)
			child_last(px, cmd, envp, i);
		else
			child_middle(px, cmd, envp, i);
	}
	else
	{
		if (i > 0)
			close(px->pipes[i - 1][0]);
		if (i < px->n_cmd - 1)
			close(px->pipes[i][1]);
	}
}
