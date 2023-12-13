/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:07:40 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/08 21:27:13 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	c_f_end(t_map *map)
{
	if (map->ceiling.r > 255 || map->ceiling.g > 255 || map->ceiling.b > 255)
	{
		printf("Error : number c_f_end()\n");
		exit(0);
	}
	if (map->ceiling.r < 0 || map->ceiling.g < 0 || map->ceiling.b < 0)
	{
		printf("Error : number c_f_end()\n");
		exit(0);
	}
	if (map->floor.r > 255 || map->floor.g > 255 || map->floor.b > 255)
	{
		printf("Error : number c_f_end()\n");
		exit(0);
	}
	if (map->floor.r < 0 || map->floor.g < 0 || map->floor.b < 0)
	{
		printf("Error : number c_f_end()\n");
		exit(0);
	}
}

void	check_single_player(int player)
{
	if (player != 1)
	{
		printf("Error : check_map(player) \n");
		exit(1);
	}
}

void	validate_map_character(t_map *map, int *player, int *i)
{
	char	c;

	c = map->map[*i];
	if (c == '1' || c == '0' || c == 'W' || c == 'S' || c == 'E' || c == 'N'
		|| c == ' ' || c == '\n')
	{
		if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		{
			map->player = c;
			(*player)++;
		}
		(*i)++;
	}
	else
	{
		printf("Error : check_map(%d) %c\n", *i, c);
		exit(1);
	}
}

void	check_map(t_map *map)
{
	int	i;
	int	player;

	i = map->i;
	player = 0;
	while (map->map[i] != '\0')
		validate_map_character(map, &player, &i);
	check_single_player(player);
}

void	map_closed(t_map *map)
{
	t_ft	*tmp;

	tmp = init_and_fill(map);
	check_map_and_cleanup(map, tmp);
}
