/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:53 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/24 16:08:04 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/includes/cub3d.h"

/*
** init_mlx — crea la connessione MLX e la finestra
**
** mlx_init() restituisce un puntatore opaco alla connessione
** con il server X11. Se fallisce, restituisce NULL.
** mlx_new_window() crea la finestra vera e propria.
*/

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg(ERR_MLX));
	if (load_textures(game))
		return (1);
	game->window = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "cub3D");
	if (!game->window)
		return (error_msg(ERR_MLX));
	return (0);
}

/*
** init_frame — crea l'immagine in memoria (double buffer)
**
** Perche' un'immagine in memoria e non mlx_pixel_put()?
**
** mlx_pixel_put() scrive direttamente sulla finestra, un pixel
** alla volta. Ogni pixel e' una chiamata al server X11: lentissimo.
** Con 1280x720 = 921.600 pixel, il gioco andrebbe a 2 FPS.
**
** Invece: scrivi tutti i pixel nel buffer in RAM (con put_pixel),
** poi con UNA sola chiamata mlx_put_image_to_window() copi tutto
** sulla finestra. Questo e' il double buffering.
*/

static int	init_frame(t_game *game)
{
	game->frame.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	if (!game->frame.img)
		return (error_msg(ERR_MLX));
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bits_pixel,
			&game->frame.line_length,
			&game->frame.endian);
	if (!game->frame.addr)
		return (error_msg(ERR_MLX));
	return (0);
}

/*
** key_press / key_release — gestione input da tastiera
**
** Perche' un array keys[] e non muovere direttamente qui?
**
** Se muovi in key_press, il movimento dipende da quanto
** velocemente X11 ripete il tasto. Su ogni PC e' diverso,
** e c'e' un ritardo iniziale (provi a muoverti: uno scatto,
** pausa, poi parte).
**
** Con keys[]: key_press segna "W premuto", key_release segna
** "W rilasciato". game_loop() controlla OGNI frame quali tasti
** sono premuti e muove. Risultato: movimento fluido fin dal
** primo frame.
**
** NOTA: le frecce hanno keycode 65361/65363, che sfora
** l'array keys[256]. Usiamo due flag separati nella struct
** t_game: turn_left e turn_right. key_press li setta a 1,
** key_release a 0, game_loop li legge ogni frame.
*/

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_LEFT)
		game->turn_left = 1;
	else if (keycode == KEY_RIHGT)
		game->turn_right = 1;
	else if (keycode >= 0 && keycode < 256)
		game->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->turn_left = 0;
	else if (keycode == KEY_RIHGT)
		game->turn_right = 0;
	else if (keycode >= 0 && keycode < 256)
		game->keys[keycode] = 0;
	return (0);
}

/*
** init_game — funzione principale di inizializzazione
**
** Ordine importante:
** 1. init_mlx    — senza MLX non possiamo fare nulla
** 2. init_frame  — crea il buffer di disegno
** 3. (load_textures — la scrivera' Giulia)
** 4. hooks       — collega tastiera e loop
** 5. mlx_loop    — LOOP INFINITO, non ritorna mai
**
** Hook events:
**   2, mask 1L<<0  = KeyPress (tasto premuto)
**   3, mask 1L<<1  = KeyRelease (tasto rilasciato)
**   17, mask 0     = DestroyNotify (click X della finestra)
**   mlx_loop_hook  = chiamata ad ogni iterazione del loop
*/

int	init_game(t_game *game)
{
	if (init_mlx(game))
		return (1);
	if (init_frame(game))
		return (1);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
