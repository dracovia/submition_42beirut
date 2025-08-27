/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:58:10 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/27 17:09:41 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static	int	open_map_file(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit("ERROR: Failed to open map file", game);
	return (fd);
}

static char	**allocate_map(int lines, t_game *game)
{
	char	**map;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		error_and_exit("ERROR: Memory allocation failed", game);
	return (map);
}

static	void	free_partial_map(char **map, int filled)
{
	while (filled > 0)
		free(map[--filled]);
	free(map);
}

static	char	*read_map_line(int fd, t_game *game, char **map, int i)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	len = ft_strlen(line);
	if (!line)
	{
		free_partial_map(map, i);
		close(fd);
		error_and_exit("Error reading map", game);
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char	**read_map_file(char *filename, int lines, t_game *game)
{
	int		fd;
	char	**map;
	int		i;

	fd = open_map_file(filename, game);
	map = allocate_map(lines, game);
	i = 0;
	while (i < lines)
	{
		map[i] = read_map_line(fd, game, map, i);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
