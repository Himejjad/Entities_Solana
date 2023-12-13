/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:48:30 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/09 15:57:46 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		dst = game->addr + ((y * game->line_length)
				+ (x * (game->bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}

void	put_player(t_game *game)
{
	float	x;
	float	y;

	x = MINI_WIDTH / 2;
	y = MINI_HEIGHT / 2;
	my_mlx_pixel_put(game, x - 1, y - 1, 14549214);
	my_mlx_pixel_put(game, x - 1, y, 14549214);
	my_mlx_pixel_put(game, x - 1, y + 1, 14549214);
	my_mlx_pixel_put(game, x, y - 1, 14549214);
	my_mlx_pixel_put(game, x, y, 14549214);
	my_mlx_pixel_put(game, x, y + 1, 14549214);
	my_mlx_pixel_put(game, x + 1, y - 1, 14549214);
	my_mlx_pixel_put(game, x + 1, y, 14549214);
	my_mlx_pixel_put(game, x + 1, y + 1, 14549214);
}

void	draw_start(t_game *game)
{
	if (game->t_map->a >= 0 && game->t_map->a <= 86)
	{
		if (game->t_map->l++ > 1000 && game->t_map->l++ % 23 == 0)
		{
			mlx_destroy_image(game->mlx, game->xpm);
			put_image(game, game->path[game->t_map->a]);
			game->t_map->a++;
		}
	}
	else if (game->t_map->i >= 0 && game->t_map->i < 7)
	{
		if (game->t_map->l++ > 7000)
		{
			mlx_destroy_image(game->mlx, game->xpm);
			put_image(game, game->path[game->t_map->a + game->t_map->i]);
			game->t_map->i++;
		}
	}
	else
	{
		if (game->t_map->l++ > 10000)
			game->start = -1;
	}
}

void	welcome(t_game *game)
{
	if (game->welcome)
		put_image(game, "texture/welcome/Play.xpm");
	else
		put_image(game, "texture/welcome/Exit.xpm");
}

void	mini_map(t_game *game)
{
	mini_ground(game);
	mini_wall_1(game);
	mini_wall_2(game);
	mini_wall_3(game);
	mini_wall_4(game);
	put_player(game);
	shut_rays(game);
}
