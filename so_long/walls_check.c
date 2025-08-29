/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:33:02 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/29 13:23:55 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_trapped(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == '1' &&
		game->map[y + 1][x] == '1' &&
		game->map[y][x + 1] == '1' &&
		game->map[y][x - 1] == '1')
	{
		if (game->map[y][x] == 'P')
			error_and_exit("player is trapped", game);
		if (game->map[y][x] == 'E')
			error_and_exit("exit is trapped", game);
		if (game->map[y][x] == 'C')
			error_and_exit("collectible is trapped", game);
		return (0);
	}
	return (1);
}

int	**alloc_2d(int h, int w)
{
	int	**arr;
	int	y;
	int	x;

	arr = malloc(sizeof(int *) * h);
	if (!arr)
		return (NULL);
	y = 0;
	while (y < h)
	{
		arr[y] = malloc(sizeof(int) * w);
		if (!arr[y])
			return (NULL);
		x = 0;
		while (x < w)
		{
			arr[y][x] = 0;
			x++;
		}
		y++;
	}
	return (arr);
}

void	free_2d(int **arr, int h)
{
	int	y;

	y = 0;
	while (y < h)
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

static void	flood_fill(t_game *game, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (game->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	flood_fill(game, x + 1, y, visited);
	flood_fill(game, x - 1, y, visited);
	flood_fill(game, x, y + 1, visited);
	flood_fill(game, x, y - 1, visited);
}

void	check_reachability(t_game *game, int px, int py)
{
	int	**visited;
	int	x;
	int	y;

	visited = alloc_2d(game->height, game->width);
	if (!visited)
		error_and_exit("Memory error", game);
	flood_fill(game, px, py, visited);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if ((game->map[y][x] == 'C' || game->map[y][x] == 'E')
				&& !visited[y][x])
			{
				free_2d(visited, game->height);
				error_and_exit("Unreachable collectible/exit", game);
			}
			x++;
		}
		y++;
	}
	free_2d(visited, game->height);
}
