/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:31:59 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/23 15:13:07 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_texture(char *line, t_map *map, int side)
{
	int		i;
	char	*path;
	int		len;

	if (map->found[side])
		return (error_msg(ERR_ELEM));
	i = skip_spaces(line, 2);
	if (line[i] == '\0' || line[i] == '\n')
		return (error_msg(ERR_TEX));
	path = ft_strdup(&line[i]);
	if (!path)
		return (error_msg(ERR_TEX));
	len = ft_strlen(path);
	if (len > 0 && path[len - 1] == '\n')
		path[len - 1] = '\0';
	if (len == 0)
	{
		free(path);
		return (error_msg(ERR_TEX));
	}
	map->tex_path[side] = path;
	map->found[side] = 1;
	return (0);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parts_to_color(char **parts)
{
	int	r;
	int	g;
	int	b;

	if (!is_valid_number(parts[0]) || !is_valid_number(parts[1])
		|| !is_valid_number(parts[2]))
		return (-1);
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (rgb_to_color(r, g, b));
}

static void	free_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

/*
** parse_color — parsa una riga F o C con valori RGB
**
** FIX: il check originale era !parts[3] — significava che voleva
** QUATTRO elementi (0,1,2,3). Ma RGB ha solo 3 valori.
** Il check corretto e': parts[3] deve essere NULL (solo 3 elementi).
**
** found_idx: 4 = Floor, 5 = Ceiling (indici nell'array found[6])
*/

int	parse_color(char *line, t_map *map, int found_idx)
{
	int		i;
	char	**parts;
	int		color;
	int		len;

	if (map->found[found_idx])
		return (error_msg(ERR_ELEM));
	i = skip_spaces(line, 1);
	if (line[i] == '\0' || line[i] == '\n')
		return (error_msg(ERR_COLOR));
	parts = ft_split(&line[i], ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		if (parts)
			free_parts(parts);
		return (error_msg(ERR_COLOR));
	}
	len = ft_strlen(parts[2]);
	if (len > 0 && parts[2][len - 1] == '\n')
		parts[2][len - 1] = '\0';
	color = parts_to_color(parts);
	free_parts(parts);
	if (color == -1)
		return (error_msg(ERR_COLOR));
	return (set_map_color(map, found_idx, color));
}
