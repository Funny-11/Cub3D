/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:07 by gifanell          #+#    #+#             */
/*   Updated: 2026/03/03 16:42:08 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
			i++;
	return (line[i] == '\n' || line[i] == '\0');
}

static int	handle_line(t_game *game, char *line, int *map_started)
{
	int	i;

	i = skip_spaces(line, 0);
	if ((!*map_started) && (ft_strncmp(&line[i], "NO ", 3) == 0
		|| ft_strncmp(&line[i], "SO ", 3) == 0
		|| ft_strncmp(&line[i], "WE ", 3) == 0
		|| ft_strncmp(&line[i], "EA ", 3) == 0))
		return (parse_texture(game, &line[i]));
	if ((!*map_started) && (ft_strncmp(&line[i], "F ", 2) == 0
		|| ft_strncmp(&line[i], "C ", 2) == 0))
		return (parse_color(game, &line[i]));
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
		{
			free(line);
			return (error_msg(ERR_MAP));
		}
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
