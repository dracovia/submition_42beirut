#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	wait_launched_children(int count)
{
	while (count > 0)
	{
		wait(NULL);
		count--;
	}
}

int	picoshell(char **cmds[])
{
	int		pipe_fd[2];
	int		previous_read;
	int		children;
	int		has_next;
	int		i;
	int		error;
	pid_t	pid;

	if (cmds == NULL)
		return (1);
	i = 0;
	children = 0;
	previous_read = -1;
	while (cmds[i] != NULL)
	{
		has_next = (cmds[i + 1] != NULL);
		if (has_next && pipe(pipe_fd) == -1)
		{
			if (previous_read != -1)
				close(previous_read);
			wait_launched_children(children);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			if (previous_read != -1)
				close(previous_read);
			if (has_next)
			{
				close(pipe_fd[0]);
				close(pipe_fd[1]);
			}
			wait_launched_children(children);
			return (1);
		}
		if (pid == 0)
		{
			if (previous_read != -1
				&& dup2(previous_read, STDIN_FILENO) == -1)
			{
				close(previous_read);
			    if (has_next)
                {
                    close(pipe_fd[0]);
                    close(pipe_fd[1]);
                }
				exit(1);
			}
			if (has_next
				&& dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			{
				if (previous_read != -1)
					close(previous_read);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				exit(1);
			}
			if (previous_read != -1)
				close(previous_read);
			if (has_next)
			{
				close(pipe_fd[0]);
				close(pipe_fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		children++;
		if (previous_read != -1)
			close(previous_read);
		if (has_next)
		{
			close(pipe_fd[1]);
			previous_read = pipe_fd[0];
		}
		else
			previous_read = -1;
		i++;
	}
	error = 0;
	while (children > 0)
	{
		if (wait(NULL) == -1)
			error = 1;
		children--;
	}
	return (error);
}
