/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:47:05 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/10 16:16:31 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	read_file(t_map *map, int fd)
{
	int	i;

	i = 0;
	map->dst = get_next_line(fd);
	if (!map->dst)
	{
		printf("Error : empty file \n");
		exit(0);
	}
	while (map->dst != NULL)
	{
		map->map = ft_strjoin(map->map, map->dst);
		if (i > 0)
			free(map->dst);
		i++;
		map->dst = get_next_line(fd);
	}
	check_element(map);
	check_path_texture(map);
	check_c_f(map);
	check_if_cub_file_is_empty(map);
	check_map(map);
	map_closed(map);
	double_nl(map);
}

t_ft	*init_and_fill(t_map *map)
{
	t_ft	*tmp;

	tmp = (t_ft *)malloc(sizeof(t_ft));
	tmp->i = 0;
	tmp->j = -1;
	tmp->player = map->player;
	tmp->maps = ft_split((map->map) + map->i, '\n');
	tmp->colum = ft_wc_l(tmp->maps);
	while (tmp->maps[tmp->i])
	{
		tmp->j = item_chr(tmp->maps[tmp->i], ' ');
		if (tmp->j != -1)
			flood_fill(tmp, tmp->i, tmp->j);
		tmp->i++;
	}
	return (tmp);
}

void	check_map_and_cleanup(t_map *map, t_ft *tmp)
{
	int	i;

	i = 0;
	check_walls(map);
	ft_free_tmp(tmp->maps);
	free(tmp->maps);
	free(tmp);
}

int	element_is_full(t_map *map)
{
	if (map->c && map->f && map->ea && map->no && map->so && map->we)
		return (1);
	return (0);
}

void	check_element(t_map *map)
{
	map->i = 0;
	while (map->map[map->i] && !element_is_full(map))
	{
		while (map->map[map->i] && (map->map[map->i] == ' '
				|| map->map[map->i] == '\t' || map->map[map->i] == '\n'))
			map->i++;
		if (map->map[map->i] == 'N' || map->map[map->i] == 'S'
			|| map->map[map->i] == 'W' || map->map[map->i] == 'E'
			|| map->map[map->i] == 'F' || map->map[map->i] == 'C')
		{
			check_and_set(map, map->map);
		}
		else
		{
			printf("Error : check_element(%d) = %c\n", map->i,
				map->map[map->i]);
			exit(1);
		}
		map->i++;
	}
	while (map->map[map->i] && map->map[map->i] == '\n')
		map->i++;
	map->maps = ft_split((map->map) + map->i, '\n');
}
