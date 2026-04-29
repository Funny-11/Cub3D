/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:05:56 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/24 16:06:30 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/includes/cub3d.h"

/*
** close_game — chiamata da ESC o dalla X della finestra
**
** NON possiamo fare "return" dal main perche' siamo dentro
** una callback chiamata da mlx_loop(). L'unico modo per
** uscire pulitamente e' exit().
*/

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

/*
** game_loop — chiamata ad ogni frame da mlx_loop_hook
**
** Ad ogni frame:
** 1. Legge quali tasti sono premuti
** 2. Muove/ruota il giocatore
** 3. Ridisegna l'intero frame
**
** Movement: WASD tramite array keys[] (keycode < 256).
** Rotation: frecce sinistra/destra hanno keycode > 255
** (65361 e 65363), quindi non entrano in keys[256].
** Le gestiamo con due flag separati: keys[KEY_W] ecc.
** per WASD, e check diretto del keycode per le frecce
** in key_press/key_release che settano turn_left/turn_right.
**
** Nota: turn_left e turn_right sono campi che aggiungiamo
** alla struct t_game (vedi aggiornamento header).
*/

int	game_loop(t_game *game)
{
	if (game->keys[KEY_W])
		move_forward(game);
	if (game->keys[KEY_S])
		move_backward(game);
	if (game->keys[KEY_A])
		strafe_left(game);
	if (game->keys[KEY_D])
		strafe_right(game);
	if (game->turn_left)
		rotate_left(game);
	if (game->turn_right)
		rotate_right(game);
	render_frame(game);
	return (0);
}
