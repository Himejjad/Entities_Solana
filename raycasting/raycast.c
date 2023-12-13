/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:11:09 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/09 17:13:55 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_rays_3d(t_game *game, t_map *map, int pix)
{
	int	y_map;
	int	x_map;

	y_map = (game->yplayer + (sin(game->rotatangle + game->rayangle) * pix));
	x_map = (game->xplayer + (cos(game->rotatangle + game->rayangle) * pix));
	if (map->maps[(y_map - 1) / SIZE][x_map / SIZE] == '1')
		return (0);
	else if (map->maps[(y_map + 1) / SIZE][x_map / SIZE] == '1')
		return (0);
	else if (map->maps[(y_map) / SIZE][(x_map + 1) / SIZE] == '1')
		return (0);
	else if (map->maps[(y_map) / SIZE][(x_map - 1) / SIZE] == '1')
		return (0);
	return (1);
}

void	set_ceiling(t_game *game, int color)
{
	if (game->y + 150 >= HEIGHT / 2)
	{
		shadow(game, color, game->dark);
		if (game->dark > 0.05 && game->y % 4 == 0)
			game->dark -= 0.05;
	}
	else
		my_mlx_pixel_put(game, game->x, game->y, color);
	game->y++;
}

void	set_texture(t_game *game, int x_pos, int y_pos, t_wall wall)
{
	int	num;

	num = ((game->y - (HEIGHT - game->projectedwallheight) / 2) * SIZE);
	wall.ofy = fmod(num / game->projectedwallheight, SIZE);
	wall.color = check_color(game, x_pos, y_pos, wall);
	if (game->distance > 900)
		shadow(game, wall.color,
			(10 - (game->distance / 100)));
	else if (wall.color != -16777216)
		my_mlx_pixel_put(game, game->x, game->y, wall.color);
	if (game->y > (HEIGHT / 2) + 40 && game->y < (HEIGHT / 2) + 300)
	{
		if (game->dark < 1 && game->y % 4 == 0)
			game->dark += 0.03;
	}
	game->y++;
}

void	set_floor(t_game *game, t_wall wall)
{
	if (game->y > (HEIGHT / 2) + 30 && game->y < (HEIGHT / 2) + 300)
	{
		shadow(game, wall.floor, game->dark);
		if (game->dark < 1 && game->y % 4 == 0)
			game->dark += 0.03;
		if (game->dark > 1)
			game->dark = 1;
	}
	else
		my_mlx_pixel_put(game, game->x, game->y, wall.floor);
	game->y++;
}

int	set_ofx(t_game *game, int x_pos, int y_pos)
{
	int	ofx;

	ofx = 0;
	if (game->virti == 0)
	{
		ofx = fmod(x_pos, SIZE);
		if (ofx >= SIZE - 1 || ofx == 0)
			ofx = fmod(y_pos, SIZE);
	}
	else if (game->virti == 1)
	{
		ofx = fmod(x_pos, SIZE);
		if (ofx >= SIZE - 1 || ofx == 0)
			ofx = fmod(y_pos, SIZE);
	}
	return (ofx);
}
