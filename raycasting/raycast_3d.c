/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:50 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/09 17:15:00 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_wall(t_game *game, int x_pos, int y_pos)
{
	t_wall	wall;

	wall.ceiling = (game->t_map->ceiling.r << 16) + \
				(game->t_map->ceiling.g << 8) + \
				game->t_map->ceiling.b;
	wall.floor = (game->t_map->floor.r << 16) + \
				(game->t_map->floor.g << 8) + \
				game->t_map->floor.b;
	wall.top = (HEIGHT / 2) - game->projectedwallheight / 2;
	wall.bottom = wall.top + game->projectedwallheight;
	wall.ofy = 0;
	wall.ofx = 0;
	game->dark = 1;
	game->y = 0;
	while (game->y < wall.top)
		set_ceiling(game, wall.ceiling);
	wall.ofx = set_ofx(game, x_pos, y_pos);
	game->dark = 0.0;
	while (game->y <= wall.bottom)
		set_texture(game, x_pos, y_pos, wall);
	while (game->y < HEIGHT)
		set_floor(game, wall);
}

void	shadow(t_game *game, int color, float darknessFactor)
{
	t_shadow	sh;

	sh.pixel_index = (game->y * game->line_length) + \
				(game->x * game->bits_per_pixel / 8);
	sh.red = color >> 16 & 0xFF;
	sh.green = color >> 8 & 0xFF;
	sh.blue = color & 0xFF;
	sh.red = (int)(sh.red * darknessFactor);
	sh.green = (int)(sh.green * darknessFactor);
	sh.blue = (int)(sh.blue * darknessFactor);
	sh.dst = game->addr + sh.pixel_index;
	sh.darkenedcolor = (sh.red << 16) | (sh.green << 8) | sh.blue;
	*(unsigned int *)sh.dst = sh.darkenedcolor;
}

void	shut_rays(t_game *game)
{
	t_ray	r;

	r.x = ((double)game->xplayer / SIZE) * 10;
	r.xp = MINI_WIDTH / 2;
	r.yp = MINI_HEIGHT / 2;
	r.y = ((double)game->yplayer / SIZE) * 10;
	game->x = 0;
	game->rayangle = -PI / 6;
	while (game->rayangle <= PI / 6 && game->x < WIDTH)
	{
		r.pix = 0.0;
		r.color = 15790080;
		while (r.pix <= 50 && check_rays_2d(game, r.pix, r.x, r.y))
		{
			my_mlx_pixel_put(game,
				(r.xp + (cos(game->rotatangle + game->rayangle) * r.pix)),
				(r.yp + (sin(game->rotatangle + game->rayangle) * r.pix)),
				r.color);
			r.pix++;
		}
		game->rayangle += game->rotatspeed;
		game->x++;
	}
}

void	init_distence(t_game *game, int pix)
{
	double	angle;

	angle = fabs(game->rayangle);
	game->distance = pix;
	if ((game->rayangle) < PI / 2)
		game->new_distance = game->distance * cos(angle);
	else
		game->new_distance = game->distance * cos(PI - (angle));
	game->projectedwallheight = (SIZE * WIDTH) / game->new_distance;
}

void	render_3d(t_game *game, t_map *map)
{
	double	pix;

	game->distance = 0;
	game->rayangle = (-1 * PI) / 6;
	game->x = 0;
	while (game->rayangle <= PI / 6 && game->x < WIDTH)
	{
		pix = 0.0;
		while (pix < 1000 && check_rays_3d(game, map, pix))
			pix++;
		init_distence(game, pix);
		if (roundf(fmod(game->xplayer + \
			(cos(game->rotatangle + game->rayangle) * (pix)), SIZE)) == 0)
			game->virti = 0;
		else if (roundf(fmod(game->yplayer + \
			(sin(game->rotatangle + game->rayangle) * (pix)), SIZE)) == 0)
			game->virti = 1;
		print_wall(game, game->xplayer + \
			(cos(game->rotatangle + game->rayangle) * (pix)), game->yplayer + \
			(sin(game->rotatangle + game->rayangle) * (pix)));
		game->rayangle += game->rotatspeed;
		game->x++;
	}
}
