/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:53:29 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/25 11:43:13 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./get_next_line/get_next_line.h"
# include "linux/mlx.h"
# include "linux/mlx_int.h"
# include <math.h>

# define RED "\033[7m\033[31m"
# define DEFFAULT "\033[0m"
# define GREEN "\033[7m\033[32m"
# define YOLLOW "\033[7m\033[33m"

# define ESC 65307
# define ENTER 65293
# define UP 119      
# define DOWN 115
# define RIGHT 100
# define LIFT 97

# define MINI_HEIGHT 170
# define MINI_WIDTH 250
# define WIDTH 1730
# define HEIGHT 919
# define ANGLE 90
# define SIZE 64
# define PI 3.14159265359

typedef struct s_data
{
	void		*img;

}				t_data;

typedef struct s_ft
{
	int			i;
	int			j;
	int			colum;
	int			spaces;
	char		player;
	char		**maps;
}				t_ft;

typedef struct s_c
{
	char		**numbers;
	int			r;
	int			g;
	int			b;
}				t_c;

typedef struct rays
{
	int			color;
	double		yp;
	double		xp;
	double		y;
	double		x;
	double		pix;
}				t_ray;

typedef struct s_f
{
	char		**numbers;
	int			r;
	int			g;
	int			b;
}				t_f;

typedef struct s_wall
{
	int			color;
	int			ofx;
	int			ofy;
	int			ceiling;
	int			floor;
	int			top;
	int			bottom;
}				t_wall;

typedef struct s_shadow
{
	char		*dst;
	int			pixel_index;
	int			blue;
	int			red;
	int			green;
	int			darkenedcolor;
}				t_shadow;

typedef struct s_map
{
	int			j;
	int			l;
	int			a;
	int			i;
	int			spaces;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*c;
	char		*f;
	char		*map;
	char		**maps;
	char		*dst;
	int			nord;
	int			sud;
	int			ouest;
	int			east;
	char		player;
	int			width;
	int			height;
	char		wall_textures;
	t_c			ceiling;
	t_f			floor;
}				t_map;

typedef struct s_imag
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			weight;
	int			next;
}				t_imag;

typedef struct s_game
{
	int			size;
	int			start;
	float		dark;
	int			welcome;
	int			condition;
	int			walkdirection;
	int			rotaion;
	int			walk_r_l;
	float		xplayer;
	float		yplayer;
	int			new_mouse_x;
	int			new_mouse_y;
	int			old_mouse_x;
	int			old_mouse_y;
	int			x;
	int			y;
	double		rayangle;
	double		rotatangle;
	double		rotatspeed;
	int			movespeed;
	void		*win;
	void		*mlx;
	void		*xpm;
	void		*img;
	t_imag		north;
	t_imag		south;
	t_imag		west;
	t_imag		east;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		distance;
	double		new_distance;
	double		projectedwallheight;
	int			hight;
	int			chight;
	int			virti;
	int			width;
	int			cwidth;
	char		**path;
	char		**bomb;
	t_map		*t_map;
}				t_game;

void			read_file(t_map *map, int fd);
char			**ft_split(char const *s, char c);
int				ft_atoi(char *str);
int				ft_is_digit(int c);
void			check_element(t_map *map);
void			check_map(t_map *map);
void			check_c_f(t_map *map);
void			c_f_end(t_map *map);
void			c_f_first(char **numbers);
void			map_closed(t_map *map);
void			flood_fill(t_ft *tmp, int i, int j);
int				ft_len(char *str);
int				ft_wc_l(char **str);
void			check_element_count(char **numbers);
void			check_number_string(char *number);
void			validate_character(char *number, int *j, int *last_digit);
void			handle_error(char c);
void			validate_map_character(t_map *map, int *player, int *i);
void			check_single_player(int player);
int				check_commas(const char *str, int start);
void			check_map(t_map *map);
char			*set_path(t_map *map, char *str);
int				set_texture_path(t_map *map, char *str, char *texture_id,
					char **texture_path);
int				check_texture(t_map *map, char *str);
void			set_path_with_check(t_map *map, char *str, char type);
void			check_and_set(t_map *map, char *str);
void			map_closed(t_map *map);
t_ft			*init_and_fill(t_map *map);
void			check_map_and_cleanup(t_map *map, t_ft *tmp);
int				element_is_full(t_map *map);

void			start_mlx(t_game *game);
void			put_game(t_game *game, t_map *map);
void			direction(t_game *game, t_map *map);
void			put_player(t_game *game);
void			ft_up(t_game *game);
void			draw_grid(t_game *game, t_map *map);
void			draw_start(t_game *game);

// moves
void			ft_up(t_game *game);
void			ft_down(t_game *game);
void			ft_right(t_game *game);
void			ft_lift(t_game *game);
void			put_ground(t_game *game, t_map *map);
void			ft_rotat_right(t_game *game);
void			ft_rotat_lift(t_game *game);

// my mlx
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
void			mlx_put_squar(t_game *game, int color);

void			cub_3d(t_game *game);
void			cub_2d(t_game *game);

void			black_screen(t_game *game);
void			shut_rays(t_game *game);
void			render_3d(t_game *game, t_map *map);

int				check_path(char *str, char *extension);
void			load_texture(void *mlx, char *path, t_imag img);
void			init_textures(t_game *game);
int				check_color(t_game *game, int x_pos, int y_pos, t_wall wall);
unsigned int	get_pixel_img(t_imag img, int x, int y);
void			check_if_cub_file_is_empty(t_map *map);
void			double_nl(t_map *map);
void			wc_space(t_map *map, char **str);
void			check_path_texture(t_map *map);
void			ft_free_tmp(char **tmp);

void			check_wall_line(char *line, int width, char *error_message);
void			check_side_walls(char **lines, int height, char *error_message);
void			check_walls(t_map *map);
void			ft_free_tmp_g(char **tmp);
int				item_chr(char *s, char c);
int				ft_len(char *str);
int				ft_iss_digit(char c);
void			flood_fill(t_ft *tmp, int i, int j);
void			shadow(t_game *game, int color, float darknessFactor);
void			error_texture(char *str, int fd);

void			init_rotation(t_game *game, t_map *map);
void			mini_wall_1(t_game *game);
void			mini_wall_2(t_game *game);
void			mini_wall_3(t_game *game);
void			mini_wall_4(t_game *game);
void			mini_ground(t_game *game);
int				ft_exit(int key, t_game *game);
void			player_pos(t_game *game, t_map *map);
void			check_moves(t_game *game);
unsigned int	get_pixel_img(t_imag img, int x, int y);
void			put_image(t_game *game, char *filename);
void			welcome(t_game *game);
void			mini_map(t_game *game);
void			set_animation(t_game *game);
char			*utils_animation(t_game *game);
void			init_animation(t_game *game);

int				check_rays_3d(t_game *game, t_map *map, int pix);
void			set_ceiling(t_game *game, int color);
void			set_texture(t_game *game, int x_pos, int y_pos, t_wall wall);
void			set_floor(t_game *game, t_wall wall);
int				set_ofx(t_game *game, int x_pos, int y_pos);

void			init_textures(t_game *game);
int				check_color(t_game *game, int x_pos, int y_pos, t_wall wall);
int				check_rays_2d(t_game *game, int pix, double x, double y);
int				check_zero(char *str, int j);
void			check_rotation(t_game *game);

#endif
