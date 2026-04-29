/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:35 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/10 22:49:15 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** is_free — controlla se una posizione sulla mappa e' calpestabile
**
** Restituisce 1 se la cella e' '0' (pavimento), 0 altrimenti.
**
** Bounds check: se x o y escono dalla mappa, restituiamo 0
** (= muro) per evitare segfault. Controlliamo anche che la
** riga esista e che il carattere esista (righe di lunghezza
** diversa nella mappa).
*/

static int	is_free(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map.cols
		|| map_y < 0 || map_y >= game->map.rows)
		return (0);
	if (!game->map.grid[map_y])
		return (0);
	if (map_x >= (int)ft_strlen(game->map.grid[map_y]))
		return (0);
	return (game->map.grid[map_y][map_x] == '0');
}

/*
** move_forward — W: muove nella direzione in cui guarda
**
** SLIDING: controlliamo X e Y separatamente.
**
** Perche'? Se controlli X+Y insieme, quando cammini verso
** un angolo il gioco ti blocca completamente.
** Controllando separatamente, se X e' bloccato (muro) ma Y
** e' libero, il player "scivola" lungo il muro.
**
** Esempio: stai camminando verso nord-est (dir = 0.7, -0.7).
** C'e' un muro a est. Senza sliding: ti fermi.
** Con sliding: la componente X viene bloccata, ma la Y (nord)
** passa. Risultato: scivoli lungo il muro verso nord.
**
** Il margine 0.2 nella direzione del movimento impedisce
** al player di avvicinarsi troppo al muro (evita che la
** camera "entri" nella texture).
*/

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	if (is_free(game, new_x + game->player.dir_x * 0.2, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_free(game, game->player.pos_x, new_y + game->player.dir_y * 0.2))
		game->player.pos_y = new_y;
}

/*
** move_backward — S: stessa logica ma direzione invertita
*/

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	if (is_free(game, new_x - game->player.dir_x * 0.2, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_free(game, game->player.pos_x, new_y - game->player.dir_y * 0.2))
		game->player.pos_y = new_y;
}

/*
** strafe_left — A: spostamento laterale a sinistra
**
** La direzione perpendicolare a sinistra nel sistema di
** coordinate della mappa (dove Y cresce verso il BASSO) e':
**   perp_x = dir_y
**   perp_y = -dir_x
**
** Verifica: guardi nord (dir = 0, -1)
**   perp = (-1, 0) = ovest = sinistra sullo schermo. OK!
**
** Verifica: guardi est (dir = 1, 0)
**   perp = (0, -1) = nord = sinistra sullo schermo. OK!
*/

void	strafe_left(t_game *game)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = game->player.dir_y;
	perp_y = -game->player.dir_x;
	new_x = game->player.pos_x + perp_x * MOVE_SPEED;
	new_y = game->player.pos_y + perp_y * MOVE_SPEED;
	if (is_free(game, new_x + perp_x * 0.2, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_free(game, game->player.pos_x, new_y + perp_y * 0.2))
		game->player.pos_y = new_y;
}

/*
** strafe_right — D: spostamento laterale a destra
**
** Direzione perpendicolare a destra: opposta a sinistra.
**   perp_x = -dir_y
**   perp_y = dir_x
**
** Verifica: guardi nord (dir = 0, -1)
**   perp = (1, 0) = est = destra sullo schermo. OK!
*/

void	strafe_right(t_game *game)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	new_x = game->player.pos_x + perp_x * MOVE_SPEED;
	new_y = game->player.pos_y + perp_y * MOVE_SPEED;
	if (is_free(game, new_x + perp_x * 0.2, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_free(game, game->player.pos_x, new_y + perp_y * 0.2))
		game->player.pos_y = new_y;
}
