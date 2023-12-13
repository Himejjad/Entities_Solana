/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:57:48 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/09 12:10:06 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mini_wall_1(t_game *game)
{
	int		x;
	int		y;
	float	xp;
	float	yp;

	yp = ((float)game->yplayer / SIZE) * 10;
	y = MINI_HEIGHT / 2;
	while (y > 10)
	{
		x = MINI_WIDTH / 2;
		xp = ((float)game->xplayer / SIZE) * 10;
		while (x > 10)
		{
			if ((yp > 0) && (xp > 0)
				&& (xp < ft_len(game->t_map->maps[(int )(yp / 10)]) * 10)
				&& (game->t_map->maps[(int )(yp / 10)][(int )(xp / 10)] == '1'))
				my_mlx_pixel_put(game, x, y, 0);
			x--;
			xp--;
		}
		y--;
		yp--;
	}
}

void	mini_wall_2(t_game *game)
{
	int		x;
	int		y;
	float	xp;
	float	yp;

	yp = ((float)game->yplayer / SIZE) * 10;
	x = 0;
	y = MINI_HEIGHT / 2;
	while (y < MINI_HEIGHT)
	{
		x = MINI_WIDTH / 2;
		xp = ((float)game->xplayer / SIZE) * 10;
		while (x > 10)
		{
			if ((yp < ft_wc_l(game->t_map->maps) * 10) && (xp > 0)
				&& (xp < ft_len(game->t_map->maps[(int )(yp / 10)]) * 10)
				&& (game->t_map->maps[(int )(yp / 10)][(int )(xp / 10)] == '1'))
				my_mlx_pixel_put(game, x, y, 0);
			x--;
			xp--;
		}
		y++;
		yp++;
	}
}

void	mini_wall_3(t_game *game)
{
	int		x;
	int		y;
	float	xp;
	float	yp;

	yp = ((float)game->yplayer / SIZE) * 10;
	x = 0;
	y = MINI_HEIGHT / 2;
	while (y < MINI_HEIGHT)
	{
		x = MINI_WIDTH / 2;
		xp = ((float)game->xplayer / SIZE) * 10;
		while (x < MINI_WIDTH)
		{
			if (yp < ft_wc_l(game->t_map->maps) * 10
				&& xp < ft_len(game->t_map->maps[(int )(yp / 10)]) * 10
				&& game->t_map->maps[(int )(yp / 10)][(int )(xp / 10)] == '1')
				my_mlx_pixel_put(game, x, y, 0);
			x++;
			xp++;
		}
		y++;
		yp++;
	}
}

void	mini_wall_4(t_game *game)
{
	int		x;
	int		y;
	float	xp;
	float	yp;

	y = MINI_HEIGHT / 2;
	x = 0;
	yp = ((float)game->yplayer / SIZE) * 10;
	while (y > 10)
	{
		x = MINI_WIDTH / 2;
		xp = ((float)game->xplayer / SIZE) * 10;
		while (x < MINI_WIDTH)
		{
			if (yp > 0 && xp < ft_len(game->t_map->maps[(int )(yp / 10)]) * 10
				&& game->t_map->maps[(int )(yp / 10)][(int )(xp / 10)] == '1')
				my_mlx_pixel_put(game, x, y, 0);
			x++;
			xp++;
		}
		y--;
		yp--;
	}
}

void	mini_ground(t_game *game)
{
	game->x = 9;
	game->y = 10;
	while (++game->x < MINI_WIDTH)
		my_mlx_pixel_put(game, game->x, game->y, 0);
	game->y++;
	while (game->y + 1 < MINI_HEIGHT)
	{
		game->x = 10;
		my_mlx_pixel_put(game, game->x, game->y, 0);
		game->x++;
		while (game->x + 1 < MINI_WIDTH)
		{
			my_mlx_pixel_put(game, game->x, game->y, 14142664);
			game->x++;
		}
		my_mlx_pixel_put(game, game->x, game->y, 0);
		game->x++;
		game->y++;
	}
	game->x = 9;
	while (++game->x < MINI_WIDTH)
		my_mlx_pixel_put(game, game->x, game->y, 0);
}
