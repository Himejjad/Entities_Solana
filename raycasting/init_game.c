/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:40:00 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/09 17:55:38 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_animation(t_game *game)
{	
	game->t_map->l = 0;
	game->start = 1;
	game->welcome = 1;
	game->condition = 1;
	game->t_map->i = 0;
	game->t_map->j = 0;
	game->t_map->a = 0;
}

char	*utils_animation(t_game *game)
{
	char	*contune;

	init_animation(game);
	contune = ft_strdup("texture/start/43.xpm|texture/start/44.xpm|"
			"texture/start/45.xpm|texture/start/46.xpm|texture/start/47.xpm|"
			"texture/start/48.xpm|texture/start/49.xpm|texture/start/50.xpm|"
			"texture/start/51.xpm|texture/start/52.xpm|texture/start/53.xpm|"
			"texture/start/54.xpm|texture/start/55.xpm|texture/start/56.xpm|"
			"texture/start/57.xpm|texture/start/58.xpm|texture/start/59.xpm|"
			"texture/start/60.xpm|texture/start/61.xpm|texture/start/62.xpm|"
			"texture/start/63.xpm|texture/start/64.xpm|texture/start/65.xpm|"
			"texture/start/66.xpm|texture/start/67.xpm|texture/start/68.xpm|"
			"texture/start/69.xpm|texture/start/70.xpm|texture/start/71.xpm|"
			"texture/start/72.xpm|texture/start/73.xpm|texture/start/74.xpm|"
			"texture/start/75.xpm|texture/start/76.xpm|texture/start/77.xpm|"
			"texture/start/78.xpm|texture/start/79.xpm|texture/start/80.xpm|"
			"texture/start/81.xpm|texture/start/82.xpm|texture/start/83.xpm|"
			"texture/start/84.xpm|texture/start/85.xpm|texture/start/86.xpm|"
			"texture/succes/1.xpm|texture/succes/2.xpm|texture/succes/3.xpm|"
			"texture/succes/4.xpm|texture/succes/5.xpm|texture/succes/6.xpm|"
			"texture/succes/7.xpm|texture/succes/8.xpm");
	return (contune);
}

void	set_animation(t_game *game)
{
	char	*succes;
	char	*dst;

	succes = ft_strdup("texture/start/01.xpm|texture/start/02.xpm|"
			"texture/start/03.xpm|texture/start/04.xpm|texture/start/05.xpm|"
			"texture/start/06.xpm|texture/start/07.xpm|texture/start/08.xpm|"
			"texture/start/09.xpm|texture/start/10.xpm|texture/start/11.xpm|"
			"texture/start/12.xpm|texture/start/13.xpm|texture/start/14.xpm|"
			"texture/start/15.xpm|texture/start/16.xpm|texture/start/17.xpm|"
			"texture/start/18.xpm|texture/start/19.xpm|texture/start/20.xpm|"
			"texture/start/21.xpm|texture/start/22.xpm|texture/start/23.xpm|"
			"texture/start/24.xpm|texture/start/25.xpm|texture/start/26.xpm|"
			"texture/start/27.xpm|texture/start/28.xpm|texture/start/29.xpm|"
			"texture/start/30.xpm|texture/start/31.xpm|texture/start/32.xpm|"
			"texture/start/33.xpm|texture/start/34.xpm|"
			"texture/start/35.xpm|texture/start/36.xpm|"
			"texture/start/37.xpm|texture/start/38.xpm|"
			"texture/start/39.xpm|texture/start/40.xpm|"
			"texture/start/41.xpm|texture/start/42.xpm|");
	dst = utils_animation(game);
	succes = ft_strjoin(succes, dst);
	game->path = ft_split(succes, '|');
	free(dst);
	free(succes);
}

void	init_rotation(t_game *game, t_map *map)
{
	if (map->player == 'N')
		game->rotatangle = 3 * PI / 2;
	else if (map->player == 'E')
		game->rotatangle = PI;
	else if (map->player == 'S')
		game->rotatangle = PI / 2;
	else if (map->player == 'W')
		game->rotatangle = 0;
	game->rotatspeed = (PI / 3) / WIDTH;
}
