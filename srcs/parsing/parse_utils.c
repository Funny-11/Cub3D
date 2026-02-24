/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:25:58 by gifanell          #+#    #+#             */
/*   Updated: 2026/02/24 01:01:46 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void    *new;

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

int is_char_map_valid(char c)
{
    return (c == '0' || c == '1' || c == 'N'
        || c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

int rgb_to_color(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}

