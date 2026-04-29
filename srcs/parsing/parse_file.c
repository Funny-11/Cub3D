/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:07 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/23 15:37:57 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\n' || line[i] == '\0');
}

/*
** get_texture_side — converte l'identificatore (NO/SO/WE/EA) nel suo indice
*/

static int	get_texture_side(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (NO);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (SO);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (WE);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (EA);
	return (-1);
}

/*
** handle_line — smista la riga al parser giusto
**
** FIX: le chiamate originali passavano (game, &line[i]) a
** parse_texture e parse_color, ma le firme sono:
**   parse_texture(char *line, t_map *map, int side)
**   parse_color(char *line, t_map *map, int found_idx)
** Ora passiamo i parametri corretti.
*/

static int	handle_line(t_game *game, char *line, int *map_started)
{
	int	i;
	int	side;

	i = skip_spaces(line, 0);
	side = get_texture_side(&line[i]);
	if (!*map_started && side >= 0)
		return (parse_texture(&line[i], &game->map, side));
	if (!*map_started && ft_strncmp(&line[i], "F ", 2) == 0)
		return (parse_color(&line[i], &game->map, 4));
	if (!*map_started && ft_strncmp(&line[i], "C ", 2) == 0)
		return (parse_color(&line[i], &game->map, 5));
	if (is_map_char(line[i]) || line[i] == ' ')
	{
		*map_started = 1;
		return (parse_map_line(&game->map, &game->player, line));
	}
	return (error_msg(ERR_CHAR));
}

static int	read_loop(int fd, t_game *game)
{
	char	*line;
	int		map_started;

	map_started = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_empty_line(line))
		{
			if (handle_line(game, line, &map_started))
			{
				free(line);
				return (1);
			}
		}
		else if (map_started)
			return (free(line), error_msg(ERR_MAP));
		free(line);
		line = get_next_line(fd);
	}
	if (!map_started)
		return (error_msg(ERR_MAP));
	return (0);
}

int	parse_file(char *path, t_game *game)
{
	int	fd;
	int	ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg(ERR_OPEN));
	ret = read_loop(fd, game);
	close(fd);
	if (ret)
		return (1);
	if (check_elements(&game->map))
		return (1);
	return (validate_map(&game->map, &game->player));
}
