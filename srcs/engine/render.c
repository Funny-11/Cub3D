/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:28 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/10 22:51:02 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** put_pixel — scrive UN pixel nel frame in memoria
**
** Stessa funzione che c'e' in init.c. Quando questo file
** e' completo, rimuovi put_pixel e render_frame da init.c.
*/

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_W || y < 0 || y >= WINDOW_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
** draw_ceiling_floor — disegna ceiling e floor per la colonna x
**
** Per ogni colonna, il ceiling va da y=0 a y=draw_start-1,
** e il floor da y=draw_end+1 a y=WINDOW_H-1.
** La parte tra draw_start e draw_end e' il muro (disegnata dopo).
*/

static void	draw_ceiling_floor(t_game *game, int x, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(&game->frame, x, y, game->map.ceiling_color);
		y++;
	}
	y = ray->draw_end + 1;
	while (y < WINDOW_H)
	{
		put_pixel(&game->frame, x, y, game->map.floor_color);
		y++;
	}
}

/*
** draw_wall_column — disegna la porzione di muro per la colonna x
**
** Per ogni pixel verticale del muro (da draw_start a draw_end),
** calcoliamo quale riga della texture campionare.
**
** step: quanto "avanziamo" nella texture per ogni pixel sullo schermo.
**   step = altezza_texture / altezza_muro_sullo_schermo
**   Se il muro e' alto 200px sullo schermo e la texture e' 64px,
**   step = 64/200 = 0.32 → ogni pixel dello schermo avanza di
**   0.32 pixel nella texture.
**
** tex_pos: posizione corrente nella texture (valore frazionario).
**   Parte dal punto corretto anche se il muro e' parzialmente
**   fuori schermo (draw_start > 0, cioe' il muro e' troppo alto
**   per entrare nella finestra).
**
** tex_y: riga intera della texture, ottenuta troncando tex_pos.
**   Clippata a height-1 per sicurezza.
*/

static void	draw_wall_column(t_game *game, int x, t_ray *ray)
{
	int		tex_idx;
	t_img	*tex;
	double	step;
	double	tex_pos;
	int		y;

	tex_idx = get_tex_idx(ray);
	tex = &game->textures[tex_idx];
	step = (double)tex->height_pixel / (double)ray->line_h;
	tex_pos = (ray->draw_start - WINDOW_H / 2 + ray->line_h / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(&game->frame, x, y,
			get_texture_color(tex, ray->tex_x, (int)tex_pos
				& (tex->height_pixel - 1)));
		tex_pos += step;
		y++;
	}
}

/*
** render_frame — ridisegna l'intero frame
**
** Per ogni colonna dello schermo (x da 0 a WINDOW_W-1):
** 1. cast_ray — lancia il raggio e calcola dove colpisce il muro
** 2. draw_ceiling_floor — disegna sopra e sotto il muro
** 3. draw_wall_column — disegna il muro con la texture
**
** Alla fine, copia il frame sulla finestra con
** mlx_put_image_to_window.
*/

void	render_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WINDOW_W)
	{
		cast_ray(game, &ray, x);
		draw_ceiling_floor(game, x, &ray);
		draw_wall_column(game, x, &ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img, 0, 0);
}
