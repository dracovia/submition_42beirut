/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:26:02 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/03 10:26:02 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_and_exit("Usage: ./so_long map.ber");

	load_map(argv[1], &game);
	validate_map(&game);

	game.mlx = mlx_init();
	if (!game.mlx)
		error_and_exit("Failed to initialize MLX");
	game.win = mlx_new_window(game.mlx,
		game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");
	if (!game.win)
		error_and_exit("Failed to create window");

	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);

	return (0);
}
