/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <gifanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:32:38 by gifanell          #+#    #+#             */
/*   Updated: 2026/04/10 22:49:18 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** apply_rotation — ruota dir e plane di un angolo dato
**
** La formula e' la matrice di rotazione 2D:
**
**   | cos(a)  -sin(a) |   | x |   | x*cos(a) - y*sin(a) |
**   | sin(a)   cos(a) | * | y | = | x*sin(a) + y*cos(a) |
**
** Applicata sia al vettore direzione (dir) che al piano
** della camera (plane). Se ruoti solo dir senza plane,
** il campo visivo si deforma progressivamente.
**
** ATTENZIONE alla variabile temporanea old_dir_x:
**
**   SBAGLIATO:
**     dir_x = dir_x * cos - dir_y * sin;   // dir_x ora e' cambiato!
**     dir_y = dir_x * sin + dir_y * cos;   // usa il dir_x NUOVO!
**
**   CORRETTO:
**     old = dir_x;                          // salvo il valore originale
**     dir_x = dir_x * cos - dir_y * sin;   // dir_x cambia
**     dir_y = old * sin + dir_y * cos;      // uso il valore ORIGINALE
**
** Questo e' un bug classico che fa ruotare in modo storto.
** Succede perche' la seconda riga della moltiplicazione
** ha bisogno del valore di dir_x PRIMA della modifica.
** Stessa cosa per plane_x.
*/

static void	apply_rotation(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos_a - p->dir_y * sin_a;
	p->dir_y = old_dir_x * sin_a + p->dir_y * cos_a;
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos_a - p->plane_y * sin_a;
	p->plane_y = old_plane_x * sin_a + p->plane_y * cos_a;
}

/*
** rotate_left — freccia sinistra: ruota in senso antiorario
**
** Angolo negativo = antiorario nel sistema con Y verso il basso.
**
** Perche' negativo = antiorario?
** Nel sistema di coordinate standard (Y verso l'alto),
** angolo positivo = antiorario. Ma nella mappa Y cresce
** verso il BASSO (riga 0 e' in alto), quindi il sistema
** e' specchiato: positivo = orario, negativo = antiorario.
**
** ROT_SPEED e' definita nell'header come 0.03 radianti
** (circa 1.7 gradi per frame). Abbastanza lenta per
** essere controllabile, abbastanza veloce per non
** sembrare in slow motion.
*/

void	rotate_left(t_game *game)
{
	apply_rotation(&game->player, -ROT_SPEED);
}

/*
** rotate_right — freccia destra: ruota in senso orario
**
** Angolo positivo = orario (vedi spiegazione sopra).
*/

void	rotate_right(t_game *game)
{
	apply_rotation(&game->player, ROT_SPEED);
}
