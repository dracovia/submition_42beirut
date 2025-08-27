/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:23:10 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/27 16:53:45 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static	void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	game->map[game->player.y][game->player.x] = game->under_player;
	next_tile = game->map[new_y][new_x];
	if (next_tile == 'C')
		game->collectibles--;
	if (next_tile == 'C' || next_tile == '0')
		game->under_player = '0';
	else
		game->under_player = next_tile;
	game->map[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
}

static	void	check_exit(t_game *game, char tile)
{
	if (tile == 'E' && game->collectibles == 0)
	{
		cleanup_game(game);
		exit(0);
	}
}


void	move_player(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	update_player_position(game, new_x, new_y);
	check_exit(game, tile);
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (close_game(game), 0);
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
	cleanup_game(game);
	exit(0);
}



