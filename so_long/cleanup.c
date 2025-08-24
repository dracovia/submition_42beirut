/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:53:51 by mfassad           #+#    #+#             */
/*   Updated: 2025/08/24 15:53:55 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void free_map(t_game *game)
{
    if (game->map)
    {
        int i = 0;
        while (i < game->height)
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
        game->map = NULL;
    }
}

void destroy_images(t_game *game)
{
    if (!game->mlx)
        return;
    if (game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_floor)
        mlx_destroy_image(game->mlx, game->img_floor);
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);
    if (game->img_collectible)
        mlx_destroy_image(game->mlx, game->img_collectible);
}

void cleanup_game(t_game *game)
{
    destroy_images(game);
    free_map(game);
    if (game->mlx && game->win)
        mlx_destroy_window(game->mlx, game->win);
}
