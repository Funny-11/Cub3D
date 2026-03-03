/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:50 by gifanell          #+#    #+#             */
/*   Updated: 2026/03/03 16:46:58 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    cleaning_mlx(t_game *game)
{
    if (!game)
        return ;
    free_screen(game);
    if (game->win && game->mlx_init)
        mlx_destroy_window(game->mlx_init, game->win);
    if (game->mlx_init)
    {
        mlx_destroy_display(game->mlx_init);
        free(game->mlx_init);
    }
}

void    free_map(t_map *map)
{
    int i;

    if (!map->grid)
        return ;
    i = 0;
    while (map->grid[i])
    {
        free(map->grid[i]);
        i++;
    }
    free(map-grid);
    map->grid = NUL;
}

static void free_textures(t_map *map)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (map->tex_path[i])
        {
            free(map->tex_path[i]);
            map->tex_path[i] = NULL;
        }
        i++;
    }
}

void    free_game(t_game *game)
{
    if (!game)
        return ;
    free_map(&game->map);
    free_textures(&game->map);
}