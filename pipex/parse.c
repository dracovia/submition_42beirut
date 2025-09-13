/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:30:43 by mfassad           #+#    #+#             */
/*   Updated: 2025/09/13 11:38:32 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**read_cmd(char *cmdstr)
{
	char	**cmd;
	int		i;

	cmd = ft_split_spaces(cmdstr);
	if (!cmd)
	{
		error_and_exit("failed to run command");
		return (NULL);
	}
	i = 0;
	while (cmd[i])
		i++;
	if (i == 0)
	{
		ft_free_split(cmd);
		error_and_exit("empty command");
		return (NULL);
	}
	return (cmd);
}
