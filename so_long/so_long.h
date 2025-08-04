/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:26:48 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/04 17:29:31 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define TILE_SIZE 64

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

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

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
}	t_game;

int		load_map(char *filename, t_game *game);
int		validate_map(t_game *game);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_game(t_game *game);
void	error_and_exit(char *msg);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);


#endif
