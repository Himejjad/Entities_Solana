/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:47:05 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/09 09:20:27 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_if_cub_file_is_empty(t_map *map)
{
	int	i;

	if (map->map == NULL || map->map[0] == '\0')
	{
		printf("Erreur: Le fichier .cub est vide ou non initialisé\n");
		exit(1);
	}
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] != ' ' && map->map[i] != '\n')
			return ;
		i++;
	}
	printf("Erreur: Le fichier .cub est vide\n");
	exit(1);
}

void	double_nl(t_map *map)
{
	int	i;

	i = map->i;
	while (map->map[i])
	{
		if (map->map[i] == '\n' && map->map[map->i + 1] && map->map[i
				+ 1] == '\n')
		{
			printf("Error : double_nl()\n");
			exit(1);
		}
		i++;
	}
}

void	wc_space(t_map *map, char **str)
{
	int	i;
	int	j;

	i = 0;
	map->spaces = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				map->spaces++;
			j++;
		}
		i++;
	}
}

void	check_path_texture(t_map *map)
{
	map->nord = open(map->no, O_RDWR);
	if (map->nord < 0)
		error_texture(map->no, map->nord);
	map->sud = open(map->so, O_RDWR);
	if (map->sud < 0)
		error_texture(map->so, map->sud);
	map->ouest = open(map->we, O_RDWR);
	if (map->ouest < 0)
		error_texture(map->we, map->ouest);
	map->east = open(map->ea, O_RDWR);
	if (map->east < 0)
		error_texture(map->ea, map->east);
}

void	ft_free_tmp(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
}
