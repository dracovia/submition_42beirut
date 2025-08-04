/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:40:48 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/04 17:30:29 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

static int	get_line_count(char *filename)
{
	int		fd;
	int		count = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit("Failed to open map file");
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

int	load_map(char *filename, t_game *game)
{
	int		fd;
	int		i = 0;
	int		lines = get_line_count(filename);
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit("Failed to open map file");
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		error_and_exit("Memory allocation failed");
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			error_and_exit("Error reading map");
		i++;
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
	game->height = lines;
	game->width = ft_strlen(map[0]);
	return (1);
}
