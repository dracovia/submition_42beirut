/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:43:38 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/03 10:43:38 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void move_enemy(t_game *game)
{
	int new_x = game->enemy.x;
	int new_y = game->enemy.y;

	// Simple horizontal movement
	if (game->enemy.dir == 1)
		new_x++;
	else
		new_x--;

	// Change direction if wall
	if (game->map.map[new_y][new_x] == '1')
		game->enemy.dir *= -1;
	else
	{
		game->enemy.x = new_x;
		game->enemy.y = new_y;
	}

	// Check if player touched enemy
	if (game->player.x == game->enemy.x && game->player.y == game->enemy.y)
		end_game(game, "You were caught by an enemy!\n");
}