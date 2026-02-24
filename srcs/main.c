/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:33:09 by gifanell          #+#    #+#             */
/*   Updated: 2026/02/23 22:25:11 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int  check_extension(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 5)
        return (error_msg(ERR_EXT));
    if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
        return (error_msg(ERR_EXT));
    return (0);
}

static void init_struct(t_game *game)
{
    ft_memset(game, 0, sizeof(t_game));
}

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
        return (erro_msg(ERR_ARGS));
    if (check_extension(av[1]));
        return (1);
    init_struct(&game);
    if (parse_file(av[1], &game))
    {
        free_game(&game);
        return (1);
    }
    if (init_game(&game))
    {
        free_game(&game);
        return (1);
    }
    return (0);
}
