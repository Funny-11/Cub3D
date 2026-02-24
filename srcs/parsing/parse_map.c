/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:11 by gifanell          #+#    #+#             */
/*   Updated: 2026/02/24 01:00:17 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void set_player_dir(t_player *parse_utils, char dir_char)
{
    if (dir_char == 'N')
    {
        p->dir_x = 0.0;
        p->dir_y = -1.0;
        p->plane_x = 0.66;
        p->plane_y = 0.0;
    }
    else if (dir_char == 'S')
    {
        p->dir_x = 0.0;
        p->dir_y = 1.0;
        p->plane_x = -0.66;
        p->plane_y = 0.0;
    }
    else if (dir_char == 'E')
    {
        p->dir_x = 1.0;
        p->dir_y = 0.0;
        p->plane_x = 0.0;
        p->plane_y = 0.66;
    }
    else if (dir_char == 'W')
    {
        p->dir_x = -1.0;
        p->dir_y = 0.0;
        p->plane_x = 0.0;
        p->plane_y = -0.66;
    }
}

static void find_player_in_line(t_map *map, ct_player *player, char *row, int row_idx)
{
    int col;

    col = 0;
    while (line[col])
    {
        if (line[col] == 'N' || line[col] == 'S'
            || line[col] == 'E' || line[col] == 'W')
        {
            player.pos_x = col + 0.5;
            player.pos_y = row_idx + 0.5;
            set_player_dir(player, row[col]);
            row[col] = '0';
            map->player_count++;
        }
        col++;
    }
}

static int  grow_grid(t_map *map, char *new_row)
{
    char    **tmp;
    int     len;

    tmp = ft_realloc(map->grid,
        (map->rows) * sizeof(char *),
        (map->rows + 2) * sizeof(char *));
    if (!tmp)
        return (error_msg(ERR_MAP));
    map->grid = tmp;
    map->grid[map->rows] = new_row;
    map->grid[map->rows + 1] = NULL;
    len = ft_strlen(new_row);
    if (len > map->cols)
        map->cols = len;
    map->rows++;
    return (0);
}

int parse_map_line(t_map *map, char *line)
{
    char    *row;
    int     i;
    int     len;

    row = ft_strdup(line);
    if (!row)
        return (error_msg(ERR_MAP));
    len = ft_strlen(row);
    if (len > 0 && row[len - 1] == '\n')
        row[len - 1] = '\0';
    i = 0;
    while (row[i])
    {
        if (!is_map_char(row[i]))
        {
            free(row);
            return (error_msg(ERR_CHAR));
        }
        i++;
    }
    find_player_in_line((t_game *)map, row, map->rows);
    if (grow_grid(map, row))
    {
        free(row);
        return (1);
    }
    return (0);
    
}
