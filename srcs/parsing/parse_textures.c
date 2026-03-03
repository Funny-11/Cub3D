/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:14 by gifanell          #+#    #+#             */
/*   Updated: 2026/03/03 16:41:08 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_elements(t_map *map)
{
	int	i;

	i = 0;
	while(i < 6)
	{
		if (!map->found[i])
			return (error_msg(ERR_ELEM));
		i++:
	}
	return (0);
}