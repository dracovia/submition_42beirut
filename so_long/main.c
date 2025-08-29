/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:26:02 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/28 15:40:26 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

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
				game->under_player = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	error_and_exit("Error\nPlayer position not found in map", game);
}

static	void	init_game_struct(t_game *game)
{
	game->moves = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_collectible = NULL;
}

static	void	setup_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_and_exit("Failed to initialize MLX", game);
	game->win = mlx_new_window(game->mlx,
			game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
	if (!game->win)
		error_and_exit("Failed to create window", game);
}

static	void	start_game_loop(t_game *game)
{
	load_textures(game);
	render_map(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game_struct(&game);
	if (argc != 2)
		error_and_exit("Usage: ./so_long map.ber", NULL);
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		error_and_exit
		("Map file extention is wrong (It should be .ber).", &game);
	load_map(argv[1], &game);
	validate_map(&game);
	find_player_position(&game);
	setup_window(&game);
	start_game_loop(&game);
	cleanup_game(&game);
	return (0);
}
