/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:07:41 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/13 03:22:25 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	enter_key(t_game *game)
{
	if (game->welcome && game->start && game->condition == 1)
	{
		game->start = -1;
		game->condition = 0;
	}
	else if (game->welcome && game->start == -1 && !game->condition)
	{
		game->start = 0;
		mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
		mlx_mouse_hide(game->mlx, game->win);
	}
	else if (!game->welcome && game->start == -1)
		exit(0);
}

int	key_hook(int key, t_game *game)
{
	if (key == 65362 && game->start != 0)
		game->welcome = 1;
	else if (key == 65364 && game->start != 0)
		game->welcome = 0;
	else if (key == UP)
		game->walkdirection = 1;
	else if (key == DOWN)
		game->walkdirection = -1;
	else if (key == RIGHT)
		game->walk_r_l = 1;
	else if (key == LIFT)
		game->walk_r_l = -1;
	else if (key == ENTER)
		enter_key(game);
	else if (key == 65363)
		game->rotaion = 1;
	else if (key == 65361)
		game->rotaion = -1;
	else if (key == ESC)
	{
		printf("%s ______ YOU EXIT THE GAME _____ %s", "\033[7m\033[33m",
			"\033[0m");
		exit(0);
	}
	return (key);
}

int	release_key_hook(int key, t_game *game)
{
	if (key == UP)
		game->walkdirection = 0;
	else if (key == DOWN)
		game->walkdirection = 0;
	else if (key == RIGHT)
		game->walk_r_l = 0;
	else if (key == LIFT)
		game->walk_r_l = 0;
	else if (key == 65363)
		game->rotaion = 0;
	else if (key == 65361)
		game->rotaion = 0;
	return (key);
}

int	update(t_game *game)
{
	if (game->start == 1)
	{
		draw_start(game);
		mlx_put_image_to_window(game->mlx, game->win, game->xpm, 0, 0);
	}
	else if (game->start == -1)
	{
		mlx_destroy_image(game->mlx, game->xpm);
		welcome(game);
		mlx_put_image_to_window(game->mlx, game->win, game->xpm, 0, 0);
	}
	else
	{
		mlx_mouse_get_pos(game->mlx, game->win,
			&game->new_mouse_x, &game->new_mouse_y);
		check_moves(game);
		render_3d(game, game->t_map);
		mini_map(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	return (0);
}

void	start_mlx(t_game *game)
{	
	player_pos(game, game->t_map);
	init_rotation(game, game->t_map);
	set_animation(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, (char *)" GAME Entities_Solana BY : [toretto1337] ");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	init_textures(game);
	put_image(game, game->path[0]);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 3, 1L << 1, release_key_hook, game);
	mlx_hook(game->win, 17, 1L << 0, ft_exit, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}
