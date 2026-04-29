/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:50 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/24 15:31:44 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	free_textures(t_map *map)
{
	int	i;

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

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img && game->mlx)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->frame.img && game->mlx)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->window && game->mlx)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(&game->map);
	free_textures(&game->map);
}
