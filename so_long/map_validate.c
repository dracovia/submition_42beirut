/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:54:25 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/04 17:42:49 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_game *game)
{
	int x, y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1)
				&& game->map[y][x] != '1')
				error_and_exit("Map must be enclosed by walls");
			x++;
		}
		y++;
	}
}
static void	count_elements(t_game *game, int *player_count, int *exit_count, int *collect_count)
{
	int x, y;
	char c;

	*player_count = 0;
	*exit_count = 0;
	*collect_count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			c = game->map[y][x];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
				error_and_exit("Invalid map character");
			if (c == 'P')
				(*player_count)++;
			else if (c == 'E')
				(*exit_count)++;
			else if (c == 'C')
				(*collect_count)++;
			x++;
		}
		y++;
	}
}
static void	check_rectangular(t_game *game)
{
	int	y;
	int	len;

	y = 0;
	while (y < game->height)
	{
		len = 0;
		while (game->map[y][len])
			len++;
		if (len != game->width)
			error_and_exit("Map must be rectangular");
		y++;
	}
}
static void	set_player_position(t_game *game)
{
	int y, x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return;
			}
			x++;
		}
		y++;
	}
}

int	validate_map(t_game *game)
{
	int player_count;
	int exit_count;
	int collect_count;

	check_rectangular(game);
	check_walls(game);
	count_elements(game, &player_count, &exit_count, &collect_count);

	if (player_count != 1 || exit_count < 1 || collect_count < 1)
		error_and_exit("Map must contain 1 player, at least 1 exit, and 1 collectible");

	set_player_position(game);
	game->collectibles = collect_count;
	return (1);
}
