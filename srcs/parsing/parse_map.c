/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:11 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/23 15:37:03 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_dir_est_west(t_player *p, char dir_char)
{
	if (dir_char == 'E')
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

static void	set_player_dir_nord_sud(t_player *p, char dir_char)
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
	else
		set_player_dir_est_west(p, dir_char);
}

static void	find_player_in_line(t_map *map, t_player *player,
	char *row, int row_idx)
{
	int	col;

	col = 0;
	while (row[col])
	{
		if (row[col] == 'N' || row[col] == 'S'
			|| row[col] == 'E' || row[col] == 'W')
		{
			player->pos_x = col + 0.5;
			player->pos_y = row_idx + 0.5;
			set_player_dir_nord_sud(player, row[col]);
			row[col] = '0';
			map->player_count++;
		}
		col++;
	}
}

static int	grow_grid(t_map *map, char *new_row)
{
	char	**tmp;
	int		len;

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

int	parse_map_line(t_map *map, t_player *player, char *line)
{
	char	*row;
	int		i;
	int		len;

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
			return (free(row), error_msg(ERR_CHAR));
		i++;
	}
	find_player_in_line(map, player, row, map->rows);
	if (grow_grid(map, row))
		return (free(row), 1);
	return (0);
}
