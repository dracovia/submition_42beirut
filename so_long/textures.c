/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:49:52 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/24 16:30:33 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int w;
	int h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collectible)
		error_and_exit("Failed to load textures", &game);
}
