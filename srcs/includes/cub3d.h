/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifanell <giuliafanelli111@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:35:45 by gifanell          #+#    #+#             */
/*   Updated: 2026/02/24 00:53:07 by gifanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

//COSTANTI SCHERMO
# define WINDOW_W		1280
# define WINDOW_H		720

//COSTANTI VELOCITA'
# define MOVE_SPEED		0.05
# define ROT_SPEED		0.03

// COSTANTI INDICI TEXTURE (tex_path[NO], tex_path(WE)...)
# define NO				0
# define SO				1
# define WE				2
# define EA				3

//COSTANTI KEYCODES
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIHGT		65363
# define KEY_ESC		65307

//COSTANTI MSG DI ERRORE
# define ERR_ARGS		"Usage: ./cub3D <map.cub>"
# define ERR_EXT		"Map file must have .cub extension"
# define ERR_OPEN		"Cannot open map file"
# define ERR_ELEM		"Missing or duplicate element in .cub file"
# define ERR_TEX		"Invalid or missing texture path"
# define ERR_COLOR		"Invalid color value (must be 0-255)"
# define ERR_MAP		"Map is not valid or not closed"
# define ERR_PLAYER		"Map must have exactly one player"
# define ERR_CHAR		"Invalid character in map"
# define ERR_MLX		"MLX initialization failed"

// ===============================================
//			       Strutture dati
// ===============================================

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_pixel;
	int		line_length;
	int		endian;
	int		width_pixel;
	int		height_pixel;
}	t_img;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct	s_map
{
	char	**grid;
	int		rows;
	int		cols;
	int		floor_color;
	int		ceiling_color;
	char	*tex_path[4];
	int		found[6];
	int		player_count;
}	t_map;

typedef struct	s_game
{
	void		*mlx;
	void		*window;
	t_img		frame;
	t_img		textures[4];
	t_player	player;
	t_map		map;
	int			keys[256];
}	t_game;

typedef struct	s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_dist;
	double	wall_x;
	double	wall_y;
	int		tex_x;
	int		line_h;
	int		draw_start;
	int		draw_end;
}	t_ray;

// === PARSING ===
int		parse_file(char *path, t_game *game);
int		parse_element(char *line, t_map *map);
int		parse_texture(char *line, t_map *map, int side);
int		parse_color(char *line, t_map *map, int target);
int		parse_map_line(t_map *map, t_game *game, char *line);
int		find_player(t_map *map, t_player *player);

// === VALIDAZIONE ===
int		check_elements(t_map *map);
int		find_player(t_map *map, t_player *player);
int		validate_map(t_map *map, t_player *player);

// === UTILS PARSING ===
char	is_map_char(char c);
int		rgb_to_color(int r, int g, int b);

// ==== ERRORI E PULIZIA ===
int		error_msg(char *msg);
void	free_game(t_game *game);
void	free_map(t_map *map);

// === MLX ===
int		init_game(t_game *game);
int		game_loop(t_game *game);
void	render_frame(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_game(t_game *game);

#endif