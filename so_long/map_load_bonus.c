/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:38:05 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/06 14:38:05 by mfassad          ###   ########.fr       */
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
	int		enemies_found = 0;
	int		y, x;

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

	// Count enemies ('N') and allocate enemy array
	for (y = 0; y < game->height; y++)
		for (x = 0; x < game->width; x++)
			if (map[y][x] == 'N')
				enemies_found++;
	game->enemy_count = enemies_found;
	if (enemies_found > 0)
	{
		game->enemies = malloc(sizeof(t_enemy) * enemies_found);
		if (!game->enemies)
			error_and_exit("Memory allocation failed for enemies");
		enemies_found = 0;
		for (y = 0; y < game->height; y++)
		{
			for (x = 0; x < game->width; x++)
			{
				if (map[y][x] == 'N')
				{
					game->enemies[enemies_found].x = x;
					game->enemies[enemies_found].y = y;
					game->enemies[enemies_found].dir = 1; // start moving right
					enemies_found++;
				}
			}
		}
	}
	return (1);
}
