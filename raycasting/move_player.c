/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:17:12 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/09 11:38:10 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_player_move(t_game *game, int x, int y)
{
	if (game->t_map->maps[(y / SIZE)][(x / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[(y / SIZE)][((x + 8) / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[(y / SIZE)][((x - 8) / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[((y + 8) / SIZE)][((x + 8) / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[((y + 8) / SIZE)][((x - 8) / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[((y + 8) / SIZE)][(x / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[((y - 8) / SIZE)][((x + 8) / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[((y - 8) / SIZE)][((x - 8) / SIZE)] == '1')
		return (0);
	if (game->t_map->maps[((y - 8) / SIZE)][(x / SIZE)] == '1')
		return (0);
	return (1);
}

void	ft_up(t_game *game)
{
	float	x;
	float	y;

	x = game->xplayer + cos(game->rotatangle) * 8;
	y = game->yplayer;
	if (check_player_move(game, x, y))
		game->xplayer = x;
	x = game->xplayer;
	y = game->yplayer + sin(game->rotatangle) * 8;
	if (check_player_move(game, x, y))
		game->yplayer = y;
}

void	ft_down(t_game *game)
{
	float	x;
	float	y;

	x = game->xplayer - cos(game->rotatangle) * 8;
	y = game->yplayer;
	if ((y < ft_wc_l(game->t_map->maps) * SIZE)
		&& (check_player_move(game, x, y)))
		game->xplayer = x;
	x = game->xplayer;
	y = game->yplayer - sin(game->rotatangle) * 8;
	if ((y < ft_wc_l(game->t_map->maps) * SIZE)
		&& (check_player_move(game, x, y)))
		game->yplayer = y;
}

void	ft_right(t_game *game)
{
	double	east ;
	float	x;
	float	y;

	east = fmod((game->rotatangle + PI / 2), (2 * PI));
	x = game->xplayer + cos(east) * 8;
	y = game->yplayer;
	if (x < ft_len(game->t_map->maps[(int)(y / SIZE)]) * SIZE
		&& check_player_move(game, x, y))
		game->xplayer = x;
	x = game->xplayer;
	y = game->yplayer + sin(east) * 8;
	if (x < ft_len(game->t_map->maps[(int)(y / SIZE)]) * SIZE
		&& check_player_move(game, x, y))
		game->yplayer = y;
}

void	ft_lift(t_game *game)
{
	double	west;
	float	x;
	float	y;

	west = fmod((game->rotatangle - PI / 2 + 2 * PI), (2 * PI));
	x = game->xplayer + cos(west) * 8;
	y = game->yplayer;
	if (check_player_move(game, x, y))
		game->xplayer = x;
	x = game->xplayer;
	y = game->yplayer + sin(west) * 8;
	if (check_player_move(game, x, y))
		game->yplayer = y;
}
