/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:23:10 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/03 10:23:10 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player.y][game->player.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
}

static void	check_tile_action(t_game *game, char tile)
{
	if (tile == 'C')
		game->collectibles--;
	else if (tile == 'E' && game->collectibles == 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0); // Win condition
	}
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	char tile = game->map[new_y][new_x];

	if (tile == '1')
		return; // Wall, can't move
	check_tile_action(game, tile);
	update_player_position(game, new_x, new_y);
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 'w' || keycode == 65362)
		move_player(game, game->player.x, game->player.y - 1);
	else if (keycode == 's' || keycode == 65364)
		move_player(game, game->player.x, game->player.y + 1);
	else if (keycode == 'a' || keycode == 65361)
		move_player(game, game->player.x - 1, game->player.y);
	else if (keycode == 'd' || keycode == 65363)
		move_player(game, game->player.x + 1, game->player.y);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

