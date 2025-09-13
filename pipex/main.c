/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 09:28:53 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 14:28:34 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_files(char **argv, int *infile, int *outfile)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		error_and_exit("can't open file");
	*outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*outfile < 0)
		error_and_exit(argv[4]);
}

static void	close_all(t_pipex *px)
{
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	close(px->infile);
	close(px->outfile);
}

void	init_pipex(t_pipex *px)
{
	px->infile = -1;
	px->outfile = -1;
	px->pipefd[0] = -1;
	px->pipefd[1] = -1;
	px->pid1 = -1;
	px->pid2 = -1;
	px->status = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		status1;
	int		status2;

	init_pipex(&px);
	if (argc != 5)
		error_and_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	open_files(argv, &px.infile, &px.outfile);
	if (pipe(px.pipefd) == -1)
		error_and_exit("pipe");
	px.pid1 = start_first(px.infile, px.pipefd, argv, envp);
	px.pid2 = start_second(px.outfile, px.pipefd, argv, envp);
	close_all(&px);
	waitpid(px.pid1, &status1, 0);
	waitpid(px.pid2, &status2, 0);
	if ((WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
		|| (WIFEXITED(status2) && WEXITSTATUS(status2) != 0))
		return (WEXITSTATUS(status2));
	return (0);
}
