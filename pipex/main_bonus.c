/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:55:06 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 16:20:43 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_all_pipes(int **pipes, int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

static void	init_pipex(t_pipex *px, int argc, char **argv)
{
	px->n_cmd = argc - 3;
	px->pipes = malloc_pipes(px->n_cmd - 1);
	if (!px->pipes)
		error_and_exit("pipes malloc");
	open_files(argc, argv, &px->infile, &px->outfile);
}

static void	execute_commands(t_pipex *px, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < px->n_cmd)
	{
		fork_and_execute(px, i, argv[i + 2], envp);
		i++;
	}
	i = 0;
	while (i < px->n_cmd)
	{
		wait(NULL);
		i++;
	}
}

static void	cleanup_pipex(t_pipex *px)
{
	close_all_pipes(px->pipes, px->n_cmd - 1);
	free_part(px->pipes, px->n_cmd - 2);
	close(px->infile);
	close(px->outfile);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc < 5)
		error_and_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	init_pipex(&px, argc, argv);
	execute_commands(&px, argv, envp);
	cleanup_pipex(&px);
	return (0);
}
