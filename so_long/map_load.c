/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:40:48 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/24 16:27:12 by mfassad          ###   ########.fr       */
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
		error_and_exit("Failed to open map file", NULL);
	count = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static char **read_map_file(char *filename, int lines, t_game *game)
{
    int fd;
    int i;
    char **map;
    char *line;
    size_t len;

    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        error_and_exit("Memory allocation failed", game);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_and_exit("Failed to open map file", game);

    i = 0;
    while (i < lines)
    {
        line = get_next_line(fd);
        if (!line)
        {
            while (i > 0)
                free(map[--i]);
            free(map);
            close(fd);
            error_and_exit("Error reading map", game);
        }
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        map[i++] = line;
    }
    map[i] = NULL;
    close(fd);
    return map;
}

int load_map(char *filename, t_game *game)
{
    int lines;
    char **map;

    lines = get_line_count(filename);
    map = read_map_file(filename, lines, game);
    game->map = map;
    game->height = lines;
    game->width = ft_strlen(map[0]);
    return 1;
}







