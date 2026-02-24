/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:18 by gifanell          #+#    #+#             */
/*   Updated: 2026/02/24 01:11:35 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void free_grid_copy(char **grid, int rows)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

static char **copy_grid(t_map *map)
{
    char    **copy;
    int     i;

    copy = malloc(sizeof(char *) * (map->rows + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < map->rows)
    {
        copy[i] = ft_strdup(map->grid[i]);
        if (!copy[i])
        {
            free_grid_copy(copy, i);
            return (NULL);
        }
        i++;
    }
    copy[map->rows] = NULL;
    return (copy);
}

static int  flood_fill(char **grid, int x, int y, t_map *map)
{
    if (y < 0 || y >= map->rows || x < 0 || x >= map->cols)
        return (1);
    if (grid[y][x] == '1' || grid[y][x] == 'F')
        return (0);
    if (grid[y][x] == ' ' || grid[y][x] == '\0')
		return (1);
	grid[y][x] = 'F';
	if (flood_fill(grid, x + 1, y, map))
		return (1);
	if (flood_fill(grid, x - 1, y, map))
		return (1);
	if (flood_fill(grid, x, y + 1, map))
		return (1);
	if (flood_fill(grid, x, y - 1, map))
		return (1);
	return (0);
}

int validate_map(t_map *map, t_player *player)
{
    char    **copy;
	int		start_x;
	int		start_y;
	int		result;

	if (map->player_count != 1)
		return (error_msg(ERR_PLAYER));
	if (map->rows == 0 || map->cols == 0)
		return (error_msg(ERR_MAP));
	copy = copy_grid(map);
	if (!copy)
		return (error_msg(ERR_MAP));
	start_x = (int)player->pos_x;
	start_y = (int)player->pos_y;
	result = flood_fill(copy, start_x, start_y, map);
	free_grid_copy(copy, map->rows);
	if (result)
		return (error_msg(ERR_MAP));
	return (0);
}