/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:31 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/10 22:51:04 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** load_one_texture — carica UNA texture .xpm in memoria
**
** mlx_xpm_file_to_image: legge il file .xpm e lo converte
**   in un'immagine MLX. Restituisce il puntatore all'immagine
**   e scrive width/height nelle variabili passate.
**
** mlx_get_data_addr: come per il frame, ci da' l'indirizzo
**   del buffer di pixel in memoria, cosi' possiamo leggere
**   i colori direttamente senza chiamate MLX.
**
** Restituisce 0 se OK, 1 se errore.
*/

static int	load_one_texture(t_game *game, int idx)
{
	t_img	*tex;

	tex = &game->textures[idx];
	tex->img = mlx_xpm_file_to_image(game->mlx,
			game->map.tex_path[idx],
			&tex->width_pixel,
			&tex->height_pixel);
	if (!tex->img)
		return (error_msg(ERR_TEX));
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bits_pixel,
			&tex->line_length,
			&tex->endian);
	if (!tex->addr)
		return (error_msg(ERR_TEX));
	return (0);
}

/*
** load_textures — carica tutte e 4 le texture
**
** Chiamata da init_game() dopo init_mlx e init_frame.
** L'ordine e' NO=0, SO=1, WE=2, EA=3 (come le define).
*/

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_one_texture(game, i))
			return (1);
		i++;
	}
	return (0);
}

/*
** get_texture_color — legge UN pixel dalla texture
**
** tex_x: colonna della texture (calcolata dal raycaster)
** tex_y: riga della texture (calcolata dal render)
**
** La formula per trovare il byte giusto nel buffer e':
**   addr + (tex_y * line_length + tex_x * (bits_pixel / 8))
**
** Esattamente come put_pixel, ma al contrario: invece di
** scrivere un colore, lo leggiamo.
**
** Guard: se tex_x o tex_y escono dai limiti, restituiamo 0
** (nero) per evitare segfault. Non dovrebbe succedere, ma
** e' una sicurezza contro bug di arrotondamento.
*/

int	get_texture_color(t_img *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0 || tex_x >= tex->width_pixel
		|| tex_y < 0 || tex_y >= tex->height_pixel)
		return (0);
	pixel = tex->addr + (tex_y * tex->line_length
			+ tex_x * (tex->bits_pixel / 8));
	return (*(unsigned int *)pixel);
}
