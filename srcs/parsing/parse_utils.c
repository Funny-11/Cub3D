/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:25:58 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/23 15:39:05 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}

int	skip_spaces(char *line, int start)
{
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	return (start);
}

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

int	rgb_to_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	set_map_color(t_map *map, int found_idx, int color)
{
	if (found_idx == 4)
		map->floor_color = color;
	else
		map->ceiling_color = color;
	map->found[found_idx] = 1;
	return (0);
}
