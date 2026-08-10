/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:37:13 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/10 16:42:10 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	is_set; // to detect duplicate
}	t_color;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction; // can be N S E W
	int		count; // should be one 
}	t_player;

typedef struct s_config
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_color		floor;
	t_color		ceiling;
	char		**map;
	int			map_height;
	int			map_width;
	t_player	player;
}	t_config;

typedef struct s_game
{
	t_config	config;
}	t_game;

void	init_color(t_color *color);
void	init_player(t_player *player);
void	init_config(t_config *config);

int		validate_filename(char *filename);
int		parse_file(char *filename, t_config *config);

#endif