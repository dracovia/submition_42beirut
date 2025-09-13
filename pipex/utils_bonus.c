/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:01:03 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/11 13:28:35 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	error_and_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free_split(char **parts)
{
	size_t	i;

	i = 0;
	if (!parts)
		return ;
	while (parts[i])
		free(parts[i++]);
	free(parts);
}

void	free_part(int **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

int	**malloc_pipes(int argc)
{
	int	**pipes;
	int	n_cmd;
	int	i;

	n_cmd = argc - 3;
	pipes = malloc(sizeof(int *) * (n_cmd - 1));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < (n_cmd - 1))
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			free_part(pipes, i - 1);
			return (NULL);
		}
		if (pipe(pipes[i]) == -1)
		{
			free_part(pipes, i - 1);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}
