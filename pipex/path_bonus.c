/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:32:25 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/11 13:32:53 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_path(const char *a, const char *b)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(a);
	len2 = ft_strlen(b);
	res = (char *) malloc (sizeof(char) * (len1 + len2 + 2));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		res[i++] = a[j++];
	res[i++] = '/';
	j = 0;
	while (j < len2)
		res[i++] = b[j++];
	res[i] = '\0';
	return (res);
}

char	*helper_find_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*candidate;

	i = 0;
	while (paths[i])
	{
		candidate = ft_strjoin_path(paths[i], cmd);
		if (candidate && access(candidate, X_OK) == 0)
		{
			ft_free_split(paths);
			return (candidate);
		}
		free(candidate);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;

	if (!cmd || !*cmd)
		return (NULL);
	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = ft_split (path_env, ':');
	if (!paths)
	{
		return (NULL);
	}
	return (helper_find_cmd_path(paths, cmd));
}
