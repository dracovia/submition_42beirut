/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:36:55 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/06 14:36:55 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define TILE_SIZE 64
# define ANIM_FRAMES 4

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

typedef struct s_enemy {
	int		x;
	int		y;
	int		dir; // 1 or -1 for patrol direction
}	t_enemy;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		collectibles;
	t_pos	player;
	t_pos	exit;

	// Images (arrays for animation frames)
	void	*img_wall;
	void	*img_floor;
	void	*img_player[ANIM_FRAMES];
	void	*img_exit;
	void	*img_collectible[ANIM_FRAMES];
	void	*img_enemy[ANIM_FRAMES];

	// Animation tracking
	int		frame;

	// Enemies
	t_enemy	*enemies;
	int		enemy_count;
}	t_game;

int		load_map(char *filename, t_game *game);
int		validate_map(t_game *game);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_game(t_game *game);
void	error_and_exit(char *msg);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);

int		enemy_move(t_game *game);
void	display_moves(t_game *game);

#endif
