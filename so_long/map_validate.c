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

static void	check_top_bottom_walls(t_game *game)
{
	int x;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			error_and_exit("Map must be enclosed by walls");
		x++;
	}
}

static void	check_side_walls(t_game *game)
{
	int y;

	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			error_and_exit("Map must be enclosed by walls");
		y++;
	}
}

static void	check_rectangular(t_game *game)
{
	int y;
	int len;

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

static void	count_map_elements(t_game *game, int *p, int *e, int *c)
{
	int x, y;
	char ch;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			ch = game->map[y][x];
			if (ch != '0' && ch != '1' && ch != 'P' && ch != 'E' && ch != 'C')
				error_and_exit("Invalid map character");
			if (ch == 'P')
				(*p)++;
			else if (ch == 'E')
				(*e)++;
			else if (ch == 'C')
				(*c)++;
			x++;
		}
		y++;
	}
}

int	validate_map(t_game *game)
{
	int p, e, c;

	check_rectangular(game);
	check_top_bottom_walls(game);
	check_side_walls(game);
	count_map_elements(game, &p, &e, &c);
	if (p != 1 || e < 1 || c < 1)
		error_and_exit("Map must contain 1 player, at least 1 exit, and 1 collectible");
	game->collectibles = c;
	return (1);
}

