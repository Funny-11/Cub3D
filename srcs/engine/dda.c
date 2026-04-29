/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:23 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/23 14:18:05 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** init_ray — prepara il raggio per la colonna x dello schermo
**
** camera_x: posizione della colonna sul piano della camera.
**   Va da -1.0 (sinistra) a +1.0 (destra). La colonna
**   centrale ha camera_x = 0.
**
**   Formula: 2 * x / WINDOW_W - 1
**   Esempio con WINDOW_W = 1280:
**     x=0    → camera_x = -1.0   (bordo sinistro)
**     x=640  → camera_x =  0.0   (centro)
**     x=1279 → camera_x = +1.0   (bordo destro)
**
** dir: direzione del raggio = dir del player + plane * camera_x.
**   Il piano della camera "allarga" la direzione verso i lati.
**   plane ha lunghezza 0.66, che da' un FOV di circa 66 gradi.
**
** delta_dist: quanto deve viaggiare il raggio per attraversare
**   UNA cella intera in X o in Y.
**   Formula: |1 / dir_componente|
**   Se dir_x = 0 (raggio perfettamente verticale), delta_dist_x
**   sarebbe infinito. Usiamo 1e30 come sostituto di infinito
**   per evitare divisione per zero.
**
** map_x/map_y: cella della mappa in cui si trova il raggio
**   (coordinate intere, troncate dalla posizione del player).
*/

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2.0 * x / (double)WINDOW_W - 1.0;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->dir_y);
}

/*
** dda_step — calcola step e side_dist iniziale
**
** step_x/step_y: in che direzione si muove il raggio sulla griglia.
**   Se dir_x > 0, il raggio va verso destra → step_x = +1.
**   Se dir_x < 0, il raggio va verso sinistra → step_x = -1.
**
** side_dist: distanza dal player al PRIMO bordo di cella.
**   Se il raggio va verso destra (step_x = +1):
**     side_dist_x = distanza fino al bordo destro della cella attuale
**                 = (map_x + 1.0 - pos_x) * delta_dist_x
**
**   Se il raggio va verso sinistra (step_x = -1):
**     side_dist_x = distanza fino al bordo sinistro
**                 = (pos_x - map_x) * delta_dist_x
**
** Dopo l'inizializzazione, side_dist verra' incrementato di
** delta_dist ad ogni passo del DDA (vedi calc_wall_hit).
*/

void	dda_step(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

/*
** calc_wall_hit — loop DDA: avanza il raggio fino a colpire un muro
**
** Ad ogni iterazione, il raggio avanza di UNA cella nella
** direzione dove il prossimo bordo e' piu' vicino.
**
** Se side_dist_x < side_dist_y:
**   il bordo verticale (X) e' piu' vicino → avanziamo in X
**   side = 0 (muro verticale, texture est o ovest)
**
** Altrimenti:
**   il bordo orizzontale (Y) e' piu' vicino → avanziamo in Y
**   side = 1 (muro orizzontale, texture nord o sud)
**
** Dopo ogni passo, controlliamo se la nuova cella e' un muro ('1').
** Se si', usciamo dal loop.
**
** wall_dist: distanza perpendicolare dal player al muro.
**   NON e' la distanza euclidea! Usiamo la distanza perpendicolare
**   per evitare il fish-eye effect (i muri ai lati sembrerebbero
**   curvi se usassimo la distanza euclidea).
**
**   Formula: side_dist - delta_dist
**   Perche'? side_dist e' stato incrementato di delta_dist
**   nell'ultimo passo, quindi side_dist - delta_dist e'
**   la distanza PRIMA dell'ultimo passo, cioe' la distanza
**   perpendicolare al muro.
*/

void	calc_wall_hit_two(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->wall_dist < 0.001)
		ray->wall_dist = 0.001;
}

void	calc_wall_hit(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < map->rows
			&& ray->map_x >= 0 && ray->map_x < map->cols
			&& map->grid[ray->map_y]
			&& ray->map_x < (int)ft_strlen(map->grid[ray->map_y])
			&& map->grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	calc_wall_hit_two(ray);
}
