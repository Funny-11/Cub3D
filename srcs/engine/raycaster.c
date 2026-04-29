/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:25 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/10 22:50:58 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** get_tex_idx — sceglie quale delle 4 texture usare
**
** Dipende da quale LATO del muro e' stato colpito:
**
**   side == 0 → muro verticale (bordo est o ovest della cella)
**     Se step_x < 0: il raggio andava verso sinistra,
**       quindi ha colpito il lato EST del muro → texture EA (3)
**     Se step_x > 0: il raggio andava verso destra,
**       quindi ha colpito il lato OVEST del muro → texture WE (2)
**
**   side == 1 → muro orizzontale (bordo nord o sud della cella)
**     Se step_y < 0: il raggio andava verso l'alto,
**       quindi ha colpito il lato SUD del muro → texture SO (1)
**     Se step_y > 0: il raggio andava verso il basso,
**       quindi ha colpito il lato NORD del muro → texture NO (0)
**
** Nota: sembra controintuitivo, ma ha senso. Se cammini verso
** EST e colpisci un muro, stai guardando il suo lato OVEST
** (la faccia rivolta verso di te).
*/

int	get_tex_idx(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x < 0)
			return (EA);
		return (WE);
	}
	if (ray->step_y < 0)
		return (SO);
	return (NO);
}

/*
** calc_wall_x — calcola il punto esatto dove il raggio colpisce il muro
**
** wall_x: coordinata frazionaria (0.0 - 1.0) lungo la faccia del muro.
**   0.0 = bordo sinistro del muro, 1.0 = bordo destro.
**
**   Se side == 0 (muro verticale):
**     wall_x = pos_y + wall_dist * dir_y
**     (usiamo la Y perche' il muro e' verticale, e la X e' fissa)
**
**   Se side == 1 (muro orizzontale):
**     wall_x = pos_x + wall_dist * dir_x
**     (usiamo la X perche' il muro e' orizzontale, e la Y e' fissa)
**
**   Poi prendiamo solo la parte frazionaria con floor():
**     wall_x -= floor(wall_x)
**   Cosi' otteniamo un valore tra 0.0 e 1.0.
*/

static void	calc_wall_x(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/*
** calc_tex_x — converte wall_x nella coordinata X della texture
**
** tex_x: colonna della texture da campionare (0 - 63 per texture 64px).
**
** Correzione della specchiatura:
**   Senza correzione, le texture sui lati opposti sarebbero
**   specchiate (il testo apparirebbe al contrario). Correggiamo
**   invertendo tex_x in due casi specifici:
**     - side == 0 e step_x > 0 (muro ovest)
**     - side == 1 e step_y < 0 (muro sud)
*/

static void	calc_tex_x(t_ray *ray, t_img *tex)
{
	ray->tex_x = (int)(ray->wall_x * tex->width_pixel);
	if (ray->tex_x >= tex->width_pixel)
		ray->tex_x = tex->width_pixel - 1;
	if (ray->side == 0 && ray->step_x > 0)
		ray->tex_x = tex->width_pixel - 1 - ray->tex_x;
	if (ray->side == 1 && ray->step_y < 0)
		ray->tex_x = tex->width_pixel - 1 - ray->tex_x;
}

/*
** cast_ray — lancia UN raggio per la colonna x dello schermo
**
** Flusso completo:
** 1. init_ray    — calcola direzione e delta_dist
** 2. dda_step    — calcola step e side_dist iniziale
** 3. calc_wall_hit — loop DDA fino al muro
** 4. line_h      — altezza della colonna da disegnare
** 5. draw_start/draw_end — dove inizia e finisce la colonna
** 6. get_tex_idx — quale texture usare
** 7. calc_wall_x — punto esatto sul muro
** 8. calc_tex_x  — colonna della texture
**
** line_h = WINDOW_H / wall_dist
**   Piu' il muro e' vicino, piu' line_h e' grande.
**   A distanza 1.0, la colonna riempie tutto lo schermo.
**
** draw_start e draw_end sono centrati verticalmente:
**   draw_start = centro - meta' altezza
**   draw_end = centro + meta' altezza
**   Clippati a 0 e WINDOW_H - 1 per non disegnare fuori.
*/

void	cast_ray(t_game *game, t_ray *ray, int x)
{
	int		tex_idx;
	t_img	*tex;

	init_ray(ray, &game->player, x);
	dda_step(ray, &game->player);
	calc_wall_hit(ray, &game->map);
	ray->line_h = (int)(WINDOW_H / ray->wall_dist);
	ray->draw_start = -ray->line_h / 2 + WINDOW_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + WINDOW_H / 2;
	if (ray->draw_end >= WINDOW_H)
		ray->draw_end = WINDOW_H - 1;
	tex_idx = get_tex_idx(ray);
	tex = &game->textures[tex_idx];
	calc_wall_x(ray, &game->player);
	calc_tex_x(ray, tex);
}
