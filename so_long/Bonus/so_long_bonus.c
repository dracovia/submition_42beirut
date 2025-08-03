/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:46:13 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/03 10:46:13 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int game_loop(t_game *game)
{
	move_enemy(game);
	render_map(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 27);
		return (1);
	}
	load_map(argv[1], &game);
	validate_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE, game.map.height * TILE_SIZE, "so_long");
	// Load textures here
	render_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
