/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:20:04 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/24 15:21:16 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_tile(t_game *game, int x, int y)
{
    char c = game->map[y][x];
    void *img = NULL;

    if (c == '1')
        img = game->img_wall;
    else if (c == '0')
        img = game->img_floor;
    else if (c == 'P')
        img = game->img_player;
    else if (c == 'E')
        img = game->img_exit;
    else if (c == 'C')
        img = game->img_collectible;

    if (img)
        mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
}


void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	load_textures(game);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}



