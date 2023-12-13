/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:56:20 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/11 22:31:14 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_textures(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx, game->t_map->no,
			&game->north.weight, &game->north.height);
	game->north.addr = mlx_get_data_addr(game->north.img,
			&game->north.bits_per_pixel,
			&game->north.line_length, &game->north.endian);
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->t_map->so,
			&game->south.weight, &game->south.height);
	game->south.addr = mlx_get_data_addr(game->south.img,
			&game->south.bits_per_pixel,
			&game->south.line_length, &game->south.endian);
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->t_map->we,
			&game->west.weight, &game->west.height);
	game->west.addr = mlx_get_data_addr(game->west.img,
			&game->west.bits_per_pixel,
			&game->west.line_length, &game->west.endian);
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->t_map->ea,
			&game->east.weight, &game->east.height);
	game->east.addr = mlx_get_data_addr(game->east.img,
			&game->east.bits_per_pixel,
			&game->east.line_length, &game->east.endian);
}

int	check_color(t_game *game, int x_pos, int y_pos, t_wall wall)
{
	if (game->t_map->maps[y_pos / SIZE][((x_pos + 1) / SIZE)] == '1')
		return (get_pixel_img(game->east, wall.ofx, wall.ofy));
	else if (game->t_map->maps[((y_pos + 1) / SIZE)][x_pos / SIZE] == '1')
		return (get_pixel_img(game->south, wall.ofx, wall.ofy));
	else if (game->t_map->maps[(y_pos) / SIZE][((x_pos - 1) / SIZE)] == '1')
		return (get_pixel_img(game->west, wall.ofx, wall.ofy));
	else if (game->t_map->maps[((y_pos - 1) / SIZE)][x_pos / SIZE] == '1')
		return (get_pixel_img(game->north, wall.ofx, wall.ofy));
	return (0);
}

int	check_rays_2d(t_game *game, int pix, double x, double y)
{
	int	y_map;
	int	x_map;

	y_map = (y + (sin(game->rotatangle + game->rayangle) * pix));
	x_map = (x + (cos(game->rotatangle + game->rayangle) * pix));
	if (game->t_map->maps[(y_map - 1) / 10][(x_map / 10)] == '1')
		return (0);
	else if (game->t_map->maps[(y_map + 1) / 10][(x_map / 10)] == '1')
		return (0);
	else if (game->t_map->maps[(y_map) / 10][(x_map + 1) / 10] == '1')
		return (0);
	else if (game->t_map->maps[(y_map) / 10][(x_map - 1) / 10] == '1')
		return (0);
	return (1);
}

void	check_rotation(t_game *game)
{
	if ((game->rotaion == 1)
		|| (game->old_mouse_x < game->new_mouse_x
			&& game->new_mouse_x <= WIDTH && game->new_mouse_x >= 0
			&& game->new_mouse_y <= HEIGHT && game->new_mouse_y >= 0))
	{
		if (game->old_mouse_x < game->new_mouse_x)
			game->rotatangle += (PI / 180)
				* (game->new_mouse_x - game->old_mouse_x) / 2;
		else
			game->rotatangle += (PI / 180) * 4;
		game->old_mouse_x = game->new_mouse_x;
	}
	else if ((game->rotaion == -1)
		|| (game->old_mouse_x > game->new_mouse_x
			&& game->new_mouse_x <= WIDTH && game->new_mouse_x >= 0
			&& game->new_mouse_y <= HEIGHT && game->new_mouse_y >= 0))
	{
		if (game->old_mouse_x > game->new_mouse_x)
			game->rotatangle -= (PI / 180)
				* (game->old_mouse_x - game->new_mouse_x) / 2;
		else
			game->rotatangle -= (PI / 180) * 4;
		game->old_mouse_x = game->new_mouse_x;
	}
}
