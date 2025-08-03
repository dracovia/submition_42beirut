/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:42:56 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/03 10:42:56 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "get_next_line.h"

# define TILE_SIZE 32

typedef struct s_player {
	int x;
	int y;
	int moves;
} t_player;

typedef struct s_enemy {
	int x;
	int y;
	int dir; // 1 = right, -1 = left
} t_enemy;

typedef struct s_map {
	char **map;
	int width;
	int height;
	int collectibles;
	int exits;
	int players;
} t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_map	map;
	t_player player;
	t_enemy enemy;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_enemy;
} t_game;

void load_map(char *filename, t_game *game);
void validate_map(t_game *game);
void render_map(t_game *game);
int handle_key(int keycode, t_game *game);
void end_game(t_game *game, char *msg);
void move_enemy(t_game *game);

#endif