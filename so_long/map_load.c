/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:40:48 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/27 16:59:31 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

static int	get_line_count(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit("ERROR: Failed to open map file", NULL);
	count = 0;
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
	int		lines;
	char	**map;

	lines = get_line_count(filename);
	if (lines == 0)
		error_and_exit("Map file is empty", game);
	map = read_map_file(filename, lines, game);
	game->map = map;
	game->height = lines;
	game->width = ft_strlen(map[0]);
	return (1);
}







