/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:00:28 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/11 22:30:52 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_exit(int key, t_game *game)
{
	(void)game;
	printf("%s ______ YOU EXIT THE GAME _____ %s", "\033[7m\033[33m",
		"\033[0m");
	exit(0);
	return (key);
}

void	put_image(t_game *game, char *filename)
{
	game->xpm = mlx_xpm_file_to_image(game->mlx, filename, &game->width,
			&game->hight);
}

void	player_pos(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->maps[y])
	{
		x = 0;
		while (map->maps[y][x])
		{
			if (map->maps[y][x] == map->player)
			{
				map->maps[y][x] = '0';
				game->xplayer = ((x + 1) * SIZE) - (SIZE / 2);
				game->yplayer = ((y + 1) * SIZE) - (SIZE / 2);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_moves(t_game *game)
{
	if (game->walkdirection == 1)
		ft_up(game);
	else if (game->walkdirection == -1)
		ft_down(game);
	if (game->walk_r_l == 1)
		ft_right(game);
	else if (game->walk_r_l == -1)
		ft_lift(game);
	check_rotation(game);
}

unsigned int	get_pixel_img(t_imag img, int x, int y)
{
	unsigned int	color;

	if (x < 0 || y < 0 || x >= img.weight || y >= img.height)
		return (0);
	color = *(unsigned int *)((img.addr + (y * img.line_length)
				+ (x * img.bits_per_pixel / 8)));
	return (color);
}
